#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

class Vecteur2D {
public:
	double x, y;
	Vecteur2D(const double & x = 0, const double & y = 0);
	virtual ~Vecteur2D();

	static const Vecteur2D creeVecteur2D(const double & x, const double & y);
	inline const Vecteur2D operator + (const Vecteur2D & u) const;
	inline const Vecteur2D operator * (const double & a) const;

	inline const Vecteur2D operator ^ (const Vecteur2D & u) const;
	inline const Vecteur2D operator - () const;

	inline double operator * (const Vecteur2D & u) const;
	inline const Vecteur2D swap() const;
	inline bool operator == (const Vecteur2D & u) const;

	inline const Vecteur2D & operator +=(const Vecteur2D & u);
	inline const Vecteur2D & operator *=(const double & a);

	operator std::string() const;

	friend inline std::ostream & operator << (std::ostream & os, const Vecteur2D & u);
};

