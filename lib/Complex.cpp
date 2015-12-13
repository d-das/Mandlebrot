// The skeleton for this program was provided by Prof. Black
// Program completed at 5 in the morning of what was Friday November 5th
// when I first sat down.
// Written by Dawson Weehunt for the Exam Lab 2

#include <iostream>
#include <sstream>
using namespace std;
#include "Complex.h"

// constructors -------------------------------------------
// default constructor
Complex::Complex() {
    r = 0;
    i = 0;
}

// unique constructor
Complex::Complex( double r, double i ) {
    this->r = r;
    this->i = i;
}

// constant constructor 
Complex::Complex( double r ) {
    this->r = r;
    i = 0;
}

// accessors ----------------------------------------------
string Complex::toString( void ) { 
    ostringstream  tmp;
    tmp << r << "+" << i << "i";  
    return tmp.str();
}

// operators ----------------------------------------------
Complex Complex::operator + ( const Complex & rhs ) {

    // initialize output
    Complex temp;

    // add the real parts
    temp.r = r + rhs.r;

    // add the imaginary parts
    temp.i = i + rhs.i;
 
    // return the calculation
    return temp;
}

Complex Complex::operator - ( const Complex & rhs ) {

    // initialize output
    Complex temp; 

    // subtract the real parts
    temp.r = r - rhs.r;

    // subtract the imaginary parts
    temp.i = i - rhs.i;

    // return the calculation
    return temp;
}

Complex Complex::operator * ( const Complex & rhs ) {

    // initialize output
    Complex temp;

    // if multiplying by a constant
    if(rhs.i==0) {

        // multiply the real part by the constant
        temp.r += (r * rhs.r);

        //multipy the imaginary part by the constant
        temp.i += (i * rhs.r);

        //return the calculation
        return temp;
    }

    // if multiplying a constant by a complex number
    else if(i==0) {

        // multiply the constant by the real part
        temp.r += (r * rhs.r);

        // multiply the constant by the imaginary part
        temp.i += (r * rhs.i);

        // return the calculation
        return temp;
    }

    // if multiplying two complex numbers together
    else {

        // add the multiplied real parts with the multiplied imaginary 
        // parts with the inverse symbol
        temp.r += (r * rhs.r) + -(i * rhs.i);

        // add the multiplication of the first real part to the second 
        // imaginary part to the multiplication of the first imaginary
        // part to the second real part
        temp.i += (r * rhs.i) + (i * rhs.r); 

        // return the calculation
        return temp;
    }
}

Complex Complex::operator / ( const Complex & rhs ) {

    // initialize the output
    Complex temp;

    // if dividing by a constant
    if(rhs.i==0) {

        // divide the real part by the constant
        temp.r += r / rhs.r;

        // divide the imaginary part by the constant
        temp.i += i / rhs.r;

        // return the calculation
        return temp;
    }

    // if dividing a constant by a complex number (Bonus credit?!?!)
    else if(i==0) { 

        // divide the mutliplication of the constant and the real part
        // of the complex number by the diviser multiplied by its conjugate
        temp.r += (r * rhs.r) / (rhs.r * rhs.r + rhs.i * rhs.i);

        // divide the multiplication of the negative constant and the imaginary
        // part of the complex number by the diviser multiplied by its conjugate
        temp.i += (-r * rhs.i) / (rhs.r * rhs.r + rhs.i * rhs.i);

        // return the calculation
        return temp;
    }

    // if dividing two complex numbers
    else {

        // divide the sum of the multiplication of the first real part to the
        // second real part and the multiplication of first imaginary part to the 
        // second imaginary part by the divisor multiplied by its conjugate
        temp.r += ((r * rhs.r + i * rhs.i) / (rhs.r * rhs.r + rhs.i * rhs.i));

        // divide the subtraction of the multiplication of the first imaginary part to
        // the second real part and the multiplication of the first real part to the
        // second imaginary part by the divisor multiplied by it's conjugate
        //
        // I really hope I never have to type the proccess of 
        // dividing complex numbers in words again.
        temp.i += ((i * rhs.r - r * rhs.i) / (rhs.r * rhs.r + rhs.i * rhs.i));

        // return the calculation
        return temp;
    }
}

// Determine the magnitude of the complex number
float Complex::magnitude(void) {
    float m = 0;
    float temp =0;
    Complex d;
    Complex a(r, i);
    Complex b(r, -i);
    d = a*b;
    temp = d.r;
    m = sqrt(temp);
    
    return m;
}

ostream & operator << ( ostream & lhs, const Complex & rhs ) {
    lhs << rhs.r << '+' << rhs.i << 'i';
    return lhs;
}

Complex operator + ( double lhs, const Complex & rhs ){
    return rhs;
}

Complex operator + ( Complex & lhs, const double rhs ) {
    Complex temp;
    return temp;
}

