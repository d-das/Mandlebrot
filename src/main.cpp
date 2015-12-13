// main.cpp - program entry point. "main" launches app

#include "Application.h"
#include "about.h"

int main(int argc, char * argv[] ) {
    Application app;                // create the application
    app.run( argc, argv );           // start the app running
    return 0;                       // exit after it finishes
}
