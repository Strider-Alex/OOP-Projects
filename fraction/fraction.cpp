#include "fraction.h"
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;
void simplify(int&x, int&y) {
	for (int i = 2;i <= x && i <= y;i++) {
		while (x%i == 0 && y%i == 0) {
			x /= i;
			y /= i;
		}
	}
}

Fraction::Fraction()
	:numerator(0),denominator(1){}

Fraction::Fraction(int numerator,int denominator)
	:numerator(numerator),denominator(denominator){}

Fraction::Fraction(const Fraction& ref)
	:numerator(ref.numerator),denominator(ref.denominator){}

string Fraction::toString() {
	string str;
	stringstream ss;
	ss << numerator << "/" << denominator;
	ss >> str;
	return str;
}

Fraction::operator double() const {
	return double(numerator) / double(denominator);
}

const Fraction Fraction::operator+(const Fraction& r) const {
	int newNtor = numerator*r.denominator + denominator*r.numerator;
	int newDtor = denominator*r.denominator;
	simplify(newNtor, newDtor);
	Fraction newFra(newNtor, newDtor);
	return newFra;
}
const Fraction Fraction::operator-(const Fraction& r) const {
	int newNtor = numerator*r.denominator - denominator*r.numerator;
	int newDtor = denominator*r.denominator;
	simplify(newNtor, newDtor);
	Fraction newFra(newNtor, newDtor);
	return newFra;
}
const Fraction Fraction::operator*(const Fraction& r) const {
	int newNtor = numerator*r.numerator;
	int newDtor = denominator*r.denominator;
	simplify(newNtor, newDtor);
	Fraction newFra(newNtor, newDtor);
	return newFra;
}
const Fraction Fraction::operator/(const Fraction& r) const {
	int newNtor = numerator*r.denominator;
	int newDtor = denominator*r.numerator;
	simplify(newNtor, newDtor);
	Fraction newFra(newNtor, newDtor);
	return newFra;
}

bool Fraction::operator==(const Fraction& r) const {
	return double(*this) == double(r);
}
bool Fraction::operator!=(const Fraction& r) const {
	return !(*this == r);
}
bool Fraction::operator<(const Fraction& r) const {
	return double(*this) < double(r);
}
bool Fraction::operator>(const Fraction& r) const {
	return r < *this;
}
bool Fraction::operator<=(const Fraction& r) const {
	return !(r < *this);
}
bool Fraction::operator>=(const Fraction& r) const {
	return !(*this < r);
}

istream& operator>>(istream& is, Fraction& obj){
	is >> obj.numerator;
	is.get();
	is >> obj.denominator;
	simplify(obj.numerator, obj.denominator);
	return is;
}
ostream& operator<<(ostream& os, const Fraction& obj) {
	os << obj.numerator << "/" << obj.denominator;
	return os;
}


