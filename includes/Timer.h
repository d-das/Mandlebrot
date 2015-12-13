// Timer.h - basic GLUT timing class
#pragma once
using namespace std;
#include <cstdlib>
#ifdef WIN32
    #include <windows.h>
#else
    #include <sys/time.h>
#endif

class Timer {
    public:
        Timer();
        void start();
        void stop();
        bool running() const;
        double get_elapsed_time();  // milliseconds
    private:
        bool stopped;
#ifdef WIN32
        LARGE_INTEGER start_time;
        LARGE_INTEGER end_time;
        LARGE_INTEGER frequency;
#else
        timeval start_time;
        timeval end_time;
#endif
};
