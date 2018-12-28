#include "Triangle.h"

Triangle::Triangle(const std::string& n, const int& c, const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3) : FormeGeoSimple(n, c), p1(p1), p2(p2), p3(p3) {}

Triangle::Triangle(const Triangle &t) : FormeGeoSimple(t.getNom(), t.getCouleur()), p1(t.getP1()), p2(t.getP2()), p3(t.getP3()) {}

Triangle::~Triangle() {
}

const Vecteur2D & Triangle::getP1() const {
	return p1;
}

const Vecteur2D & Triangle::getP2() const {
	return p2;
}

const Vecteur2D & Triangle::getP3() const {
	return p3;
}

const int Triangle::getNbSommet() const {
	return 3;
}

const std::string Triangle::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeoSimple::getInfos();
	oss << "Points : " << std::endl << p1 << std::endl << p2 << std::endl << p3 << std::endl;
	return oss.str();
}


FormeGeo * Triangle::clone() const {
	return new Triangle(getNom(), getCouleur(), p1, p2, p3);
}
