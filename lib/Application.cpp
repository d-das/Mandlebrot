// Application.cpp - application implementation
#include <iostream>
#include <cstring>
using namespace std;

#include "Application.h"
#include "about.h"
#include "commands.h"

#include "Graphics.h"

// default constructor
Application::Application(){
    this->prog_name = name;
    this->prog_version = version;
}

// main application runner
void Application::run( int argc, char * argv[] ) {
    // say hello
    cout << default_message( 
                this->prog_name, 
                this->prog_version, 
                argc, argv ) << endl;
    // option processing here
    if(argc > 1) {
        if(strncmp(argv[1],"-h", 2) == 0) 
            help();
    } 

    // start the real application
    Graphics app;
    app.glut_init( argc, argv );    // start the graphics engine
    app.start();                    // and degin generating images
}

