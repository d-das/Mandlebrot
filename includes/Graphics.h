// Graphics.h - Base Graphics class - subclass for application
#pragma once

// this is a GLUT library
#include "glut_graphics.h"
#include "Timer.h"
#include "Mandlebrot.h"

// graphics library tools

class Graphics {
    protected:
        static Graphics * instance;
        static int frames;
        Timer timer;
        double elapsed_time;
        Mandlebrot fractal;
    public:
        // window constants
        const static int WINDOW_WIDTH = 600;    // initial window width
        const static int WINDOW_HEIGHT = 400;   // intiial window height
        const static int WINDOW_X = 50;         // initial window x position
        const static int WINDOW_Y = 50;         // initial window y position    

        const static int FPS = 60;              // desired frame rate
        const static double FRAME_MSEC;         // calculated from FPS

        // mouse coordinates to feed to Mandlebrot
        int mouse_x;
        int mouse_y;


    public:
        // default constructor
        Graphics();

        // start graphics application
        void start( void );

        // initialize GLUT
        void glut_init( int argc, char * argv[] );

        // helper routines
        void setInstance();
        void animate();
        void display();
        void keyboard( unsigned char key, int x, int y );
        void specialKeyboard( int key, int x, int y );
        void mouse( int button, int state, int x, int y );

        // static callback methods for GLUT
        static void displayWrapper();
        static void keyboardWrapper( unsigned char key, int x, int y);
        static void specialKeyboardWrapper( int key, int x, int y );
        static void mouseWrapper( int button, int state, int x, int y );
        static void animateWrapper();
};

