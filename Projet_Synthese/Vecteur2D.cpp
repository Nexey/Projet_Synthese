#include "Vecteur2D.h"

Vecteur2D::Vecteur2D(const double & x, const double & y) : x(x), y(y) {}



Vecteur2D::~Vecteur2D() {
}

const Vecteur2D Vecteur2D::creeVecteur2D(const double & x, const double & y) {
	return Vecteur2D(x, y);
}

inline const Vecteur2D Vecteur2D::operator+(const Vecteur2D & u) const {
	return Vecteur2D(x + u.x, y + u.y);
}

inline const Vecteur2D Vecteur2D::operator*(const double & a) const {
	return Vecteur2D(x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator^(const Vecteur2D & u) const {
	return Vecteur2D(x*u.x - y * u.y, x*u.y + y * u.x);
}

inline const Vecteur2D Vecteur2D::operator-() const {
	return Vecteur2D(-x, -y);
}

inline double Vecteur2D::operator*(const Vecteur2D & u) const {
	return x * u.x + y * u.y;
}

inline const Vecteur2D Vecteur2D::swap() const {
	return Vecteur2D(y, x);
}

inline bool Vecteur2D::operator==(const Vecteur2D & u) const {
	return x == u.x && y == u.y;	
}

inline const Vecteur2D & Vecteur2D::operator+=(const Vecteur2D & u) {
	x += u.x;
	y += u.y;
	return *this;
}

inline const Vecteur2D & Vecteur2D::operator*=(const double & a) {
	x *= a;
	y *= a;
	return *this;
}

Vecteur2D::operator std::string() const {
	std::ostringstream os;
	os << "( " << x << ", " << y << ")";
	return os.str();
}

inline std::ostream & operator<<(std::ostream & os, const Vecteur2D & u) {
	os << (std::string)u;
	return os;
}