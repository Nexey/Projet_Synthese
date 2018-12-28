#include "Polygone.h"

Polygone::Polygone(const std::string & n, const int & c) : FormeGeoSimple(n, c), nbPoint(0) {
}

Polygone::Polygone(const Polygone &p) : FormeGeoSimple(p.getNom(), p.getCouleur()), nbPoint(p.getNbSommet()) {}

Polygone::~Polygone() {
}

const Polygone & Polygone::operator+(const Vecteur2D &v) {
	points.push_back(v);
	nbPoint++;
	return *this;
}

const Polygone & Polygone::operator+=(const Vecteur2D &v) {
	return *this + v;
}

const Vecteur2D & Polygone::operator[](const int i) const {
	return points.at(i);
}

const int Polygone::getNbSommet() const {
	return nbPoint;
}

const std::string Polygone::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeoSimple::getInfos();
	oss << "Points : " << std::endl;
	std::vector<const Vecteur2D>::const_iterator it = points.begin();
	for (it; it < points.end(); it++)
		oss << *it << std::endl;
	return oss.str();
}

FormeGeo * Polygone::clone() const {
	return new Polygone(getNom(), getCouleur());
}
