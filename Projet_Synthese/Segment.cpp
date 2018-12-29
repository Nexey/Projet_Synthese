#include "Segment.h"

Segment::Segment(const int & c, const Vecteur2D& p1, const Vecteur2D& p2) : Polygone("Segment", c) {
	addPoint(p1);
	addPoint(p2);
}

Segment::Segment(const Segment &s) : Polygone(s.getDesig(), s.getCouleur()) {
	std::vector<Vecteur2D>::const_iterator it = s.getVector().begin();
	for (it; it < s.getVector().end(); it++)
		addPoint(*it);
}

Segment::~Segment() {}

FormeGeo * Segment::clone() const {
	return new Segment(*this);
}
