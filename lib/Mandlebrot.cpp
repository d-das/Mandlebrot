// Mandlebrot.cpp - fractal generator
#include "Mandlebrot.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Mandlebrot::Mandlebrot() {
    IMAGE_WIDTH = 1;
    IMAGE_HEIGHT = 1;
}

void Mandlebrot::init( int w, int h ) {
    max_iterations = 50;

    // min and max values for coordinates in calculating the fractal
    xMin = -2.5;
    xMax = 2.5;
    yMin = -2.0;
    yMax = 2.0;

    // offset values for translating the image w/ arrow keys
    xOff = 0;
    yOff = 0;

    // offset values for translating the image w/ mouse
    mouse_xOff = 0;
    mouse_yOff = 0;

    // scale for zoom function
    scale = 0.75;

    // screen values and scale for pixel size
    IMAGE_HEIGHT = h;
    IMAGE_WIDTH = w;
    pixelHeight = (yMax - yMin ) / IMAGE_HEIGHT;
    pixelWidth = (xMax - xMin ) / IMAGE_WIDTH;
    bitmap = NULL;
}

void Mandlebrot::update( int dx, int dy, int dn ) {
    // it seems like this function is supposed to update the fractal
    // in relation to x & y offsets and a new number of iterations,
    // but I cant find any function calling on it. Therefore, Im not so 
    // sure of its purpose. Furthermore, when completely commented out,
    // the program runs fine. I think this part is unecessary, but because
    // I didnt write it I'll leave it in.
    xOff = xOff + dx;
    yOff = yOff + dy;
    max_iterations = max_iterations + dn;
    if( max_iterations < 10 ) max_iterations = 10;
    cout << "xOff = " << xOff << " yOff = " << yOff << " iters = " << max_iterations << endl;
}


int Mandlebrot::pixelValue( double x, double y ) {
    // this function calculates the magnitude of any given complex number,
    // and determines whether it should be plotted or not
    double zmag;
    Complex z, c;
    z = Complex( x, y );
    c = Complex( x, y );
    z = z * z + c;
    zmag = z.magnitude();
    int i = 0;
    for( i = 0; i < max_iterations; i++ ) {
        if( zmag > 2.0 ) {
            break;
        }
        z = z * z + c;
        zmag = z.magnitude();
   }
    return i;
}

void Mandlebrot:: initBitmap() {
    // create bitmap buffer for this window size
    if( bitmap )
        free( bitmap );
    bitmap = (unsigned char *) malloc( IMAGE_WIDTH * IMAGE_HEIGHT * 4 );
}

unsigned char * Mandlebrot::generate( void ) {
    double mx, my;
    // generate the image
    initBitmap();

    int offset = 0;
    for( int y = 0; y < IMAGE_HEIGHT; y++ )
        for( int x = 0; x < IMAGE_WIDTH; x++ ) {

            // calculate image coordinate
            mx = xMin + x * pixelWidth + xOff;
            my = yMin + y * pixelHeight + yOff;

            // translate the image in relation to pointer
            mx += mouse_xOff * pixelWidth;
            my += mouse_yOff * pixelHeight;

            // scale image
            mx *= scale;
            my *= scale;  
            

            int fv = pixelValue( mx, my );
            
            // generate color
            int red = 255 * fv / max_iterations;
            if( red > 255) red = 255 - red;

            int green = 255 * fv * 4 / max_iterations;
            if( green > 255) green = 255 - green;
    
            int blue = 255 * fv * 20 / max_iterations;
            if( blue > 255) blue = 255 - blue;
            
            // load into bitmap
            bitmap[offset + 0] = red;
            bitmap[offset + 1] = green;
            bitmap[offset + 2] = blue;
            bitmap[offset + 3] = 255;
            offset = offset + 4;
        }
    return bitmap;
}
