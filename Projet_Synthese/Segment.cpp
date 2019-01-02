#include "Segment.h"
#include "IVisiteur.h"

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

void Segment::addPoint(const Vecteur2D &v) {
	if (getNbSommet() >= 2) std::cout << "Impossible d'ajouter de nouveaux sommets !";
	else Polygone::addPoint(v);
}

FormeGeo * Segment::accepter(IVisiteur * v) {
	return v->visite(this);
}

const std::string Segment::getInfos() const {
	std::ostringstream oss;
	oss << Polygone::getInfos();
	oss << "Fin" << std::endl;
	return oss.str();
}

FormeGeo * Segment::clone() const {
	return new Segment(*this);
}
