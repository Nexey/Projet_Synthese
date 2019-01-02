#include "Cercle.h"
#include "IVisiteur.h"

Cercle::Cercle(const int& c, const double& r, const Vecteur2D& p) : Polygone("Cercle", c), rayon(r) {
	addPoint(p);
}

Cercle::Cercle(const Cercle &c) : Polygone(c.getDesig(), c.getCouleur()), rayon(c.getRayon()) {
	std::vector<Vecteur2D>::const_iterator it = c.getVector().begin();
	for (it; it < c.getVector().end(); it++)
		addPoint(*it);
}

Cercle::~Cercle() {}

void Cercle::addPoint(const Vecteur2D &v) {
	if (getNbSommet() >= 1) std::cout << "Impossible d'ajouter de nouveaux sommets !";
	else Polygone::addPoint(v);
}

inline const double Cercle::getRayon() const {
	return rayon;
}

const std::string Cercle::getInfos() const {
	std::ostringstream oss;
	oss << Polygone::getInfos();
	oss << "Rayon : " << std::endl << rayon << std::endl;
	oss << "Fin" << std::endl;
	return oss.str();
}

FormeGeo * Cercle::accepter(IVisiteur * v) {
	return v->visite(this);
}

FormeGeo * Cercle::clone() const {
	return new Cercle(*this);
}
