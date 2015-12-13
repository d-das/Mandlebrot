// Application.h - Main application class 
#include <string>
using namespace std;

class Application {
    public:
        string prog_name;
        string prog_version;

        Application();
        void run( int argc, char * argv[] );
};

