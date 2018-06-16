// TODO: insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;
// TODO: continue the namespace
namespace sict{
	// TODO: implement the default constructor
	Fraction::Fraction(){
		Numerator = 0;
		Denominator = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int den){
		if(num > 0 && den > 0){
			Numerator = num;
			Denominator = den;
			reduce();
		}else{
			Numerator = 0;
			Denominator = 0;
		}
	}

	// TODO: implement the max query
	int Fraction::max() const{
		return (Numerator > Denominator) ? Numerator : Denominator;
	}


    // TODO: implement the min query
    	int Fraction::min() const{
		return (Numerator < Denominator) ? Numerator : Denominator;
	}

	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce(){
	    int g_c_d = gcd();

	    Numerator = Numerator/g_c_d;
	    Denominator = Denominator/g_c_d;
    }


    // TODO: implement the display query
    void Fraction::display() const{
	    if(!isEmpty() && Denominator != 1){
		    cout << Numerator << "/" << Denominator;
	    }else if(!isEmpty() && Denominator == 1){
		    cout << Numerator;
	    }else if(isEmpty()){
		    cout << "no fraction stored";
	    }
    }
	    

    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const{
	    if(Numerator == 0 && Denominator == 0)
		    return true;
	    else
		    return false;
    }

    // TODO: implement the + operator
    Fraction Fraction::operator+(const Fraction& rhs) const{
	    Fraction COPY;
	    if(!isEmpty() && !rhs.isEmpty()){
		    COPY.Numerator = (Numerator * rhs.Denominator) + (Denominator * rhs.Numerator);
		    COPY.Denominator = Denominator * rhs.Denominator;
		
		    return COPY;
	    }else{
		    COPY.isEmpty();
		    return COPY;
	    }
    }
    Fraction Fraction::operator*(const Fraction& rhs) const{
	    Fraction COPY;
	    if(!isEmpty() && !rhs.isEmpty()){
		    COPY.Numerator = Numerator * rhs.Numerator;
		    COPY.Denominator = Denominator * rhs.Denominator;
		    return COPY;
	    }else{
		    COPY.isEmpty();
		    return COPY;
	    }
    }
    bool Fraction::operator==(const Fraction& rhs) const{
		if(!isEmpty() && !rhs.isEmpty()){
			if(Numerator == rhs.Numerator && Denominator == rhs.Denominator){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
    }
    bool Fraction::operator!=(const Fraction& rhs) const{
	    if(!isEmpty() && !rhs.isEmpty()){
		    if(Numerator != rhs.Numerator && Denominator != rhs.Denominator){
			    return true;
		    }else{
			    return false;
		    }
	    }else{
		    return false;
	    }
    }
    Fraction& Fraction::operator+=(const Fraction& rhs){
	    if(!isEmpty() && !rhs.isEmpty()){
		    *this = *this + rhs;
		    return *this;
	    }else{
		    isEmpty();
		    return *this;
	    }
    }


}
