#include "Polygone.h"
#include "Vecteur2D.h"

Polygone::Polygone(const std::string & n, const int & c) : FormeGeoSimple(n, c), nbPoint(0) {
}

Polygone::Polygone(const Polygone &p) : FormeGeoSimple(p.getNom(), p.getCouleur()), nbPoint(0) {
	std::vector<const Vecteur2D*>::const_iterator it = p.points.begin();
	for (it; it < p.points.end(); it++)
		*this = *this + **it;
}

Polygone::~Polygone() {}

Polygone & Polygone::operator+(const Vecteur2D &v) {
	points.push_back(new Vecteur2D(v));
	nbPoint++;
	return *this;
}

Polygone & Polygone::operator+=(const Vecteur2D &v) {
	return *this + v;
}

const Vecteur2D & Polygone::operator[](const int i) const {
	return *points.at(i);
}

const int Polygone::getNbSommet() const {
	return nbPoint;
}

const std::string Polygone::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeoSimple::getInfos();
	oss << "Points : " << std::endl;
	std::vector<const Vecteur2D*>::const_iterator it = points.begin();
	for (it; it < points.end(); it++)
		oss << **it << std::endl;
	return oss.str();
}

FormeGeo * Polygone::clone() const {
	return new Polygone(*this);
}
