#include "Segment.h"

Segment::Segment(const int & c, const Vecteur2D& p1, const Vecteur2D& p2) : Polygone("Segment", c) {
	addPoint(p1);
	addPoint(p2);
}

Segment::Segment(const Segment &s) : Polygone(s.getDesig(), s.getCouleur()) {}

Segment::~Segment() {}

FormeGeo * Segment::clone() const {
	return new Segment(*this);
}
