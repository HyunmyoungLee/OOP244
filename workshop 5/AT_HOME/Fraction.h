// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict{

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 

		// TODO: declare private member functions
		int Numerator;
		int Denominator;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);

	};
}

#endif
