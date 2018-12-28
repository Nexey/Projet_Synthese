#include "Cercle.h"

Cercle::Cercle(const int& c, const double& r, const Vecteur2D& p) : FormeGeoSimple("Cercle", c), rayon(r), p(p) {}

Cercle::Cercle(const Cercle &c) : FormeGeoSimple(c.getDesig(), c.getCouleur()), rayon(c.getRayon()), p(c.getP()) {}

Cercle::~Cercle() {
}

const Vecteur2D & Cercle::getP() const {
	return p;
}

const int Cercle::getNbSommet() const {
	return 1;
}

void Cercle::translation(const Vecteur2D &v) {
	p += v;
}

inline const double Cercle::getRayon() const {
	return rayon;
}

const std::string Cercle::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeo::getInfos();
	oss << "Rayon : " << std::endl << rayon << std::endl;
	oss << "Centre : " << std::endl << p << std::endl;
	return oss.str();
}

FormeGeo * Cercle::clone() const {
	return new Cercle(*this);
}
