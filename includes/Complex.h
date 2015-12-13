// Complex.h - complex number class
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Complex {
    private:
        double r;       // real part
        double i;       // imaginary part

    public:
        float magnitude();
        Complex();      // default constructor
        Complex( double r, double i );  // normal constructor
        Complex( double r );            // alternate constructor
        
        string toString( void );
        Complex operator + ( const Complex & rhs );
        Complex operator - ( const Complex & rhs );
        Complex operator * ( const Complex & rhs ); 
        Complex operator / ( const Complex & rhs );
        friend ostream & operator << ( ostream & lhs, const Complex & rhs );
        friend Complex operator + ( double lhs, const Complex & rhs );
        friend Complex operator + ( Complex & lhs, const double rhs );
};


