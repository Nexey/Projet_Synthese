/**
* Vecteurs2D.h
*
*  Created on: 1 juil. 2011
*      Author: Valérie
*/
#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <float.h>

class Vecteur2D {
public:
	double x, y;

	inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

	static const Vecteur2D creeVecteur2D(const double & x, const double & y) { return Vecteur2D(x, y); }

	//inline Vecteur2D(const char * s);
	inline const Vecteur2D operator + (const Vecteur2D & u) const;
	inline const Vecteur2D operator * (const double & a) const;
	
	inline const Vecteur2D operator ^ (const Vecteur2D & u) const;
	inline const Vecteur2D operator - () const;
	
	inline double operator * (const Vecteur2D & u) const;

	//static double produitScalaire (const Vecteur2D & u1, const Vecteur2D & u2) {return u1*u2;}

	const Vecteur2D rotationDirecteQuartDeTour() const { return Vecteur2D(-y, x); }

	inline const Vecteur2D swap() const { return Vecteur2D(y, x); }

	static inline double det(const Vecteur2D & u1, const Vecteur2D & u2);

	inline bool operator == (const Vecteur2D & u) const { return x == u.x && y == u.y; }

	inline const Vecteur2D & operator +=(const Vecteur2D & u);
	inline const Vecteur2D & operator *=(const double & a);

	template <class T>
	void arrondit(T & xArrondi, T & yArrondi) const { xArrondi = (T)x; yArrondi = (T)y; }

	operator std::string() const { std::ostringstream os; os << "( " << x << ", " << y << ")"; return os.str(); }

	inline static double normeSup(const Vecteur2D& u) { return fmax(abs(u.x), abs(u.y)); }


	//------------------ Vecteur2D ----------------------------------
};

inline std::ostream & operator << (std::ostream & os, const Vecteur2D & u) { os << (std::string)u; return os; }

inline const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u * a; }

inline double normeSup(const Vecteur2D& u) { return Vecteur2D::normeSup(u); }

//----------------------------- implémentation des fonctions inline ----------------------------------

inline  Vecteur2D::
Vecteur2D(const double & x, const double & y) : x(x), y(y) {}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const {
	return Vecteur2D(x + u.x, y + u.y);
}

inline const Vecteur2D Vecteur2D::operator * (const double & a) const {
	return Vecteur2D(x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator ^ (const Vecteur2D & u) const {
	return Vecteur2D(x*u.x - y * u.y, x*u.y + y * u.x);
}

inline const Vecteur2D Vecteur2D::operator - () const {
	return Vecteur2D(-x, -y);
}

inline double Vecteur2D::operator * (const Vecteur2D & u) const {
	return x * u.x + y * u.y;
}

/*static*/ inline double Vecteur2D::det(const Vecteur2D & u1, const Vecteur2D & u2) { return u1.x * u2.y - u1.y * u2.x; }

inline const Vecteur2D & Vecteur2D::operator +=(const Vecteur2D & u) {
	x += u.x;
	y += u.y;
	return *this;
}

inline const Vecteur2D & Vecteur2D::operator *=(const double & a) {
	x *= a;
	y *= a;
	return *this;
}