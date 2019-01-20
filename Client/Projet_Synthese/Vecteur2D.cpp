#include "Vecteur2D.h"

#define M_PI acos(-1)

Vecteur2D::Vecteur2D(const double & x, const double & y) : x(x), y(y) {}

Vecteur2D::Vecteur2D(const Vecteur2D &v) : x(v.x), y(v.y) {}

Vecteur2D::~Vecteur2D() {}

const Vecteur2D Vecteur2D::creeVecteur2D(const double & x, const double & y) {
	return Vecteur2D(x, y);
}

const Vecteur2D Vecteur2D::operator+(const Vecteur2D & u) const {
	return Vecteur2D(x + u.x, y + u.y);
}

const Vecteur2D Vecteur2D::operator-(const Vecteur2D & u) const {
	return Vecteur2D(x - u.x, y - u.y);
}

const Vecteur2D Vecteur2D::operator*(const double & a) const {
	return Vecteur2D(x*a, y*a);
}

const Vecteur2D Vecteur2D::operator^(const Vecteur2D & u) const {
	return Vecteur2D(x*u.x - y * u.y, x*u.y + y * u.x);
}

const Vecteur2D Vecteur2D::operator-() const {
	return Vecteur2D(-x, -y);
}

double Vecteur2D::operator*(const Vecteur2D & u) const {
	return x * u.x + y * u.y;
}

const Vecteur2D Vecteur2D::swap() const {
	return Vecteur2D(y, x);
}

bool Vecteur2D::operator==(const Vecteur2D & u) const {
	return x == u.x && y == u.y;	
}

const Vecteur2D & Vecteur2D::operator+=(const Vecteur2D & u) {
	x += u.x;
	y += u.y;
	return *this;
}

const Vecteur2D & Vecteur2D::operator*=(const double & a) {
	x *= a;
	y *= a;
	return *this;
}

Vecteur2D & Vecteur2D::translation(const Vecteur2D &v) {
	x += v.x;
	y += v.y;
	return *this;
}

Vecteur2D & Vecteur2D::zoom(const Vecteur2D & o, const double & k) {
	x = (x - o.x) * k + o.x;
	y = (y - o.y) * k + o.y;
	return *this;
}

Vecteur2D & Vecteur2D::rotation(const Vecteur2D & c, const double & a) {
	double angle = a;
	angle *= M_PI / 180;
	double dirP1 = atan2(c.y - y, c.x - x);
	double dirP2 = dirP1 + angle;
	double dist = std::sqrt(std::pow((c.x - x), 2) + (std::pow((c.y - y), 2)));
	x = c.x + dist * cos(dirP2);
	y = c.y + dist * sin(dirP2);
	return *this;
}

Vecteur2D::operator std::string() const {
	std::ostringstream os;
	os << "(" << x << ", " << y << ")";
	return os.str();
}

std::ostream & operator<<(std::ostream & os, const Vecteur2D & u) {
	os << (std::string)u;
	return os;
}
