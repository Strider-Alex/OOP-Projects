#ifndef _FRACTION_H_
#define _FRACTION_H_
#include<string>
using namespace std;
class Fraction {
public:
	Fraction();
	Fraction(int numerator, int denomiator);
	Fraction(const Fraction& ref);
	string toString();
	operator double() const;
	const Fraction operator+(const Fraction& r) const;
	const Fraction operator-(const Fraction& r) const;
	const Fraction operator*(const Fraction& r) const;
	const Fraction operator/(const Fraction& r) const;
	bool operator==(const Fraction& r) const;
	bool operator!=(const Fraction& r) const;
	bool operator<(const Fraction& r) const;
	bool operator>(const Fraction& r) const;
	bool operator<=(const Fraction& r) const;
	bool operator>=(const Fraction& r) const;
	friend istream& operator>>(istream& is, Fraction& obj);
	friend ostream& operator<<(ostream& os, const Fraction& obj);
private:
	int numerator;
	int denominator;
};
#endif
