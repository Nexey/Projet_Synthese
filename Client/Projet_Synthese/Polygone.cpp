#include "Polygone.h"
#include "IVisiteur.h"

Polygone::Polygone(const int & c) : FormeGeoSimple("Polygone", c) {}

Polygone::Polygone(const int & c, const std::vector<Vecteur2D> points) : FormeGeoSimple("Polygone", c) {
	std::vector<Vecteur2D>::const_iterator it = points.begin();
	for (it; it < points.end(); it++)
		addPoint(*it);
}

Polygone::Polygone(const std::string& n, const int & c) : FormeGeoSimple(n, c) {}

Polygone::Polygone(const Polygone &p) : FormeGeoSimple(p.getDesig(), p.getCouleur()) {
	std::vector<Vecteur2D>::const_iterator it = p.getVector().begin();
	for (it; it < p.getVector().end(); it++)
		addPoint(*it);
}

Polygone::~Polygone() {
	points.clear();
}

void Polygone::addPoint(const Vecteur2D &v) {
	points.push_back(Vecteur2D(v));
}

Polygone & Polygone::operator+(const Vecteur2D &v) {
	addPoint(v);
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
	return points.size();
}

void Polygone::translation(const Vecteur2D &v) {
	std::vector<Vecteur2D>::iterator it = points.begin();
	for (it; it < points.end(); it++)
		it->translation(v);
}

void Polygone::zoom(const Vecteur2D & o, const double & k) {
	std::vector<Vecteur2D>::iterator it = points.begin();
	for (it; it < points.end(); it++)
		it->zoom(o, k);
}

void Polygone::rotation(const Vecteur2D & c, const double & a) {
	std::vector<Vecteur2D>::iterator it = points.begin();
	for (it; it < points.end(); it++)
		it->rotation(c, a);
}

const std::string Polygone::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeo::getInfos();
	oss << getSeparateur() << "SOMMETS : ";
	std::vector<Vecteur2D>::const_iterator it = points.begin();
	for (it; it < points.end(); it++) {
		oss << *it;
		if (it + 1 != points.end())
			oss << ", ";
	}
	return oss.str();
}

FormeGeo * Polygone::accepter(IVisiteur * v) {
	return v->visite(this);
}

FormeGeo * Polygone::clone() const {
	return new Polygone(*this);
}