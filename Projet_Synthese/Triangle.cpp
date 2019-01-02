#include "Triangle.h"
#include "IVisiteur.h"

Triangle::Triangle(const int& c, const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3) : Polygone("Triangle", c) {
	addPoint(p1);
	addPoint(p2);
	addPoint(p3);
}

Triangle::Triangle(const Triangle &t) : Polygone(t.getDesig(), t.getCouleur()) {
	std::vector<Vecteur2D>::const_iterator it = t.getVector().begin();
	for (it; it < t.getVector().end(); it++)
		addPoint(*it);
}

Triangle::~Triangle() {}

void Triangle::addPoint(const Vecteur2D &v) {
	if (getNbSommet() >= 3) std::cout << "Impossible d'ajouter de nouveaux sommets !";
	else Polygone::addPoint(v);
}

FormeGeo * Triangle::accepter(IVisiteur * v) {
	return v->visite(this);
}

const std::string Triangle::getInfos() const {
	std::ostringstream oss;
	oss << Polygone::getInfos();
	oss << "Fin" << std::endl;
	return oss.str();
}

FormeGeo * Triangle::clone() const {
	return new Triangle(*this);
}