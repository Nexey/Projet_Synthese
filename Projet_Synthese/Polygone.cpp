#include "Polygone.h"

Polygone::Polygone(const int & c) : FormeGeoSimple("Polygone", c), nbPoint(0) {}

Polygone::Polygone(const Polygone &p) : FormeGeoSimple(p.getDesig(), p.getCouleur()), nbPoint(0) {
	std::vector<Vecteur2D>::const_iterator it = p.getVector().begin();
	for (it; it < p.getVector().end(); it++)
		*this = *this + *it;
}

Polygone::~Polygone() {
	points.clear();
}

Polygone & Polygone::operator+(const Vecteur2D &v) {
	points.push_back(Vecteur2D(v));
	nbPoint++;
	return *this;
}

Polygone & Polygone::operator+=(const Vecteur2D &v) {
	return *this + v;
}

Vecteur2D & Polygone::operator[](const int i) {
	return points.at(i);
}

const std::vector<Vecteur2D>& Polygone::getVector() const {
	return points;
}

const int Polygone::getNbSommet() const {
	return nbPoint;
}

void Polygone::translation(const Vecteur2D &v) {
	std::vector<Vecteur2D>::iterator it = points.begin();
	for (it; it < points.end(); it++)
		*it += v;
}

const std::string Polygone::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeo::getInfos();
	oss << "Points : " << std::endl;
	std::vector<Vecteur2D>::const_iterator it = points.begin();
	for (it; it < points.end(); it++)
		oss << *it << std::endl;
	return oss.str();
}

FormeGeo * Polygone::clone() const {
	return new Polygone(*this);
}