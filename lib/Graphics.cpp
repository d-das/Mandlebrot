#include <iostream>
using namespace std;
#include "Graphics.h"
#include "Timer.h"
#include "about.h"

// class variables ------------------------------------------------------------
const double Graphics::FRAME_MSEC = 1.0 / Graphics::FPS * 1000.0; // millisecs
Graphics * Graphics::instance = NULL;
int Graphics::frames = 0;

// default constructor --------------------------------------------------------
Graphics::Graphics() {
    elapsed_time = 0;
    fractal.init( WINDOW_WIDTH, WINDOW_HEIGHT );
    fractal.initBitmap();
}

// start the graphics application ---------------------------------------------
void Graphics::start( void ) {
    cout << "GLUT app running" << endl;
    cout << "  framerate = " << FPS;
    cout << " (" << FRAME_MSEC << " msecs/frame)" << endl;
}

void Graphics::glut_init( int argc, char * argv[] ) {
    setInstance();  
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowPosition( WINDOW_X, WINDOW_Y );
    glutInitWindowSize( WINDOW_WIDTH, WINDOW_HEIGHT );
    glutCreateWindow( name.c_str() );

    glutDisplayFunc( displayWrapper );
    glutKeyboardFunc( keyboardWrapper );
    glutSpecialFunc( specialKeyboardWrapper );
    glutMouseFunc( mouseWrapper );
    glutIdleFunc( animateWrapper );
    glutMainLoop();
}

// helper functions
void Graphics::setInstance() {
    instance = this;
}

// GLUT display methods -------------------------------------------------------
void Graphics::display() {
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    unsigned char * buffer = fractal.generate();
    glDrawPixels( WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, buffer );
    ++frames;
    glutSwapBuffers();
}

void Graphics::displayWrapper() {
    instance->display();
}

// animation method -----------------------------------------------------------

void Graphics::animateWrapper() {
    instance->animate();
}

void Graphics::animate() {
    if(!timer.running()) {
        timer.start();
    }
    timer.stop();
    double milliseconds = timer.get_elapsed_time();
    elapsed_time += FRAME_MSEC;
    if( elapsed_time >= FRAME_MSEC ) {
        glutPostRedisplay();
        elapsed_time -= FRAME_MSEC;
    }
    timer.start();
}

// mouse handler code --------------------------------------------------------
// This impliments Glut's Mouse function so that the image recenters
// on any point that the user left clicks, and recenters if the user 
// right clicks.

void Graphics::mouse( int button, int state, int x, int y) {
    if( button == GLUT_LEFT_BUTTON ) {
        if( state == GLUT_DOWN ) { 
            // the following was the hardest part of the project for me-
            // so that the center of the image is defined as 0,0 the 
            // height and width devided in half. y has to be flipped as a
            // negative because glut considers the top left corner to be
            // 0,0, while our program considers the bottom right to be 0,0
            y = -(y - WINDOW_HEIGHT/2);
            x = x - WINDOW_WIDTH/2;

            // after the mouse input was modified, it alters a varibale in
            // mandlebrot.cpp
            fractal.mouse_xOff += x;
            fractal.mouse_yOff += y;
        }
    }
    else if( button == GLUT_RIGHT_BUTTON ){
        if( state == GLUT_DOWN ) {
            // if the user right-clicks, sets position back to center
            fractal.mouse_xOff = 0;
            fractal.mouse_yOff = 0;
            fractal.xOff = 0;
            fractal.yOff = 0; 
        }
    }
}

// the following function sends the inputs from the mouse to GLUT
void Graphics::mouseWrapper( int button, int state, int x, int y ) {
    instance->mouse( button, state, x, y);
}

// keyboard handler code ------------------------------------------------------

void Graphics::keyboard( unsigned char key, int x, int y ) { 
    if( key == 27  || key == 'q' ) {
        cout << "Application terminated:" << endl;
        cout << "  frames: " << frames << endl;
        exit( 0 );
    }
    
    // this function zooms in up to three decimal values and resets after 0.001
    if( key == '+' ) {
        if(fractal.scale >= 0.2 ){
            fractal.scale -= 0.1;
            cout << "scale: " << fractal.scale << endl;
        }
        else if(fractal.scale < 0.2 && fractal.scale >= 0.02) {
            fractal.scale -= 0.01;
            cout << "scale: " << fractal.scale << endl;
        }
        else if(fractal.scale < 0.02 && fractal.scale > 0.002){
            fractal.scale -= 0.001;
            cout << "scale: " << fractal.scale << endl;
        }
        else if(fractal.scale <= 0.002) {
            fractal.scale = 0.75;
            cout << "scale: " << fractal.scale << endl;
        }
    }

    // this function zooms out, reseting after 3.0
    if( key == '-' ) {
        if(fractal.scale <= 0.02) {
            fractal.scale += 0.001;
            cout << "scale: " << fractal.scale << endl;
        }
        else if(fractal.scale > 0.02 && fractal.scale <= 0.2) {
            fractal.scale += 0.01;
            cout << "scale : " << fractal.scale << endl;
        }
        else if(fractal.scale > 0.2 && fractal.scale <= 3.0) {
            fractal.scale += 0.1;
            cout << "scale: " << fractal.scale << endl;
        }
        else if(fractal.scale >= 3.0) {
            fractal.scale = 0.75;
            cout << "scale: " << fractal.scale << endl;
        }
    }

}

void Graphics::keyboardWrapper( unsigned char key, int x, int y ) {
    instance->keyboard( key, x, y);
}

// special keyboard handler ---------------------------------------------------

void Graphics::specialKeyboard( int key, int x, int y ) {
    cout << "special key = " << key << endl;

    // the following functions alter the x & y off-sets by incriments of 1
    // in relation to the arrow key
    if( key == GLUT_KEY_UP )
        fractal.yOff += 1;
    if( key == GLUT_KEY_DOWN )
        fractal.yOff -= 1;
    if( key == GLUT_KEY_LEFT )
        fractal.xOff -= 1;
    if( key == GLUT_KEY_RIGHT ) 
        fractal.xOff += 1; 
}

void Graphics::specialKeyboardWrapper( int key, int x, int y ) {
    instance-> specialKeyboard( key, x, y );
}

