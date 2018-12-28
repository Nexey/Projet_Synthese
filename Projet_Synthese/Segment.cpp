#include "Segment.h"
#include "Vecteur2D.h"

Segment::Segment(const int & c, const Vecteur2D& p1, const Vecteur2D& p2) : FormeGeoSimple("Segment", c), p1(p1), p2(p2) {}

Segment::Segment(const Segment &s) : FormeGeoSimple(s.getDesig(), s.getCouleur()), p1(s.getP1()), p2(s.getP2()) {}

Segment::~Segment() {}

const Vecteur2D & Segment::getP1() const {
	return p1;
}

const Vecteur2D & Segment::getP2() const {
	return p2;
}

const int Segment::getNbSommet() const {
	return 2;
}

const std::string Segment::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeoSimple::getInfos();
	oss << "Points : " << std::endl << p1 << std::endl << p2 << std::endl;
	return oss.str();
}

FormeGeo * Segment::clone() const {
	return new Segment(*this);
}
