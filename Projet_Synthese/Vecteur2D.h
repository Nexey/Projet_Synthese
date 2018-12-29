#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

class Vecteur2D {
public:
	double x, y;
	Vecteur2D(const double & x = 0, const double & y = 0);
	Vecteur2D(const Vecteur2D&);
	virtual ~Vecteur2D();

	static const Vecteur2D creeVecteur2D(const double & x, const double & y);
	const Vecteur2D operator + (const Vecteur2D & u) const;
	const Vecteur2D operator * (const double & a) const;

	const Vecteur2D operator ^ (const Vecteur2D & u) const;
	const Vecteur2D operator - () const;

	double operator * (const Vecteur2D & u) const;
	const Vecteur2D swap() const;
	bool operator == (const Vecteur2D & u) const;

	const Vecteur2D & operator +=(const Vecteur2D & u);
	const Vecteur2D & operator *=(const double & a);

	Vecteur2D& translation(const Vecteur2D&);
	Vecteur2D& zoom(const Vecteur2D&, const double&);
	Vecteur2D& rotation(const Vecteur2D&, const double&);

	operator std::string() const;

	friend std::ostream & operator << (std::ostream & os, const Vecteur2D & u);
};

