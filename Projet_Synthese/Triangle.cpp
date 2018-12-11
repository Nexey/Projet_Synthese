#include "Triangle.h"

Triangle::Triangle(const std::string& n, const int& c, const Vecteur2D& p) : FormeGeoSimple(n, c, p) {}

Triangle::Triangle(const Triangle &t) : FormeGeoSimple(t.getNom(), t.getCouleur(), t.pos) {}

Triangle::~Triangle() {
}

const std::string Triangle::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeoSimple::getInfos();
	oss << "Sommets : " << nbSommets << std::endl;
	return oss.str();
}


FormeGeo * Triangle::clone() const {
	return new Triangle(getNom(), getCouleur(), Vecteur2D(this->pos));
}
