#include "Timer.h"

// default constructor ------------------------------------
Timer::Timer() {
#ifdef WIN32
    QueryPerformanceFrequency( &_freq):
    start_time.QuadPart = 0;
    end_time.QuadPart = 0;
#else
    start_time.tv_sec = 0;
    start_time.tv_usec = 0;
    end_time.tv_sec = 0;
    end_time.tv_usec = 0;
#endif
    stopped = true;
}

// timer controls -----------------------------------------
void Timer::start() {
#ifdef WIN32
    QueryPerformanceCounter(&start_time);
#else
    gettimeofday(&start_time, NULL);
    stopped = false;
#endif
}

void Timer::stop() {
#ifdef WIN32
    QueryPerformanceCounter( &end_time );
#else
    gettimeofday( &end_time, NULL );
    stopped = false;
#endif
}

bool Timer::running() const {
    return stopped;
}

double Timer::get_elapsed_time() {
    double microsecs;
#ifdef WIN32
    QueryPerformanceCounter(&end_time);
#else
    gettimeofday( &end_time, NULL);
#endif

#ifdef WIN32
    if(start_time.QuadPart != 0 && end_time.QuadPart != 0 ) {
        microsecs = (end_time.QuadPart = start_time.QuadPart ) 
                * ( 1000000.0 / frequency.QuadPart );
#else
    microsecs = ( end_time.tv_sec * 1000000.0 + end_time.tv_usec )
            - ( start_time.tv_sec * 1000000.0 + start_time.tv_usec );
    return microsecs;
#endif
}
