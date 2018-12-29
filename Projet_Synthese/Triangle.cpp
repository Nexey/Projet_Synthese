#include "Triangle.h"

Triangle::Triangle(const int& c, const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3) : Polygone("Triangle", c) {
	addPoint(p1);
	addPoint(p2);
	addPoint(p3);
}

Triangle::Triangle(const Triangle &t)
	: Polygone(*this) {}

Triangle::~Triangle() {}

FormeGeo * Triangle::clone() const {
	return new Triangle(*this);
}