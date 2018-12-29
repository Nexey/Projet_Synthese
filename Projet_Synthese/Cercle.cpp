#include "Cercle.h"

Cercle::Cercle(const int& c, const double& r, const Vecteur2D& p) : Polygone("Cercle", c), rayon(r) {
	addPoint(p);
}

Cercle::Cercle(const Cercle &c) : Polygone(c.getDesig(), c.getCouleur()), rayon(c.getRayon()) {}

Cercle::~Cercle() {}

inline const double Cercle::getRayon() const {
	return rayon;
}

const std::string Cercle::getInfos() const {
	std::ostringstream oss;
	oss << Polygone::getInfos();
	oss << "Rayon : " << std::endl << rayon << std::endl;
	return oss.str();
}

FormeGeo * Cercle::clone() const {
	return new Cercle(*this);
}
