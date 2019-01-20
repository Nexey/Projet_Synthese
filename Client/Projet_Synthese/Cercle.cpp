#include "Cercle.h"
#include "IVisiteur.h"

#define M_PI acos(-1)

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

const double Cercle::aire() const {
	return M_PI * std::pow(rayon, 2);
}

const std::string Cercle::getInfos() const {
	std::ostringstream oss;
	oss << Polygone::getInfos();
	oss << getSeparateur() << "RAYON : " << rayon;
	return oss.str();
}

FormeGeo * Cercle::accepter(IVisiteur * v) {
	return v->visite(this);
}

FormeGeo * Cercle::clone() const {
	return new Cercle(*this);
}
