#include "Cercle.h"

Cercle::Cercle(const std::string& n, const int& c, const double& r, const Vecteur2D& p) : FormeGeoSimple(n, c), rayon(r), p(p) {}

Cercle::Cercle(const Cercle &c) : FormeGeoSimple(c.getNom(), c.getCouleur()), rayon(c.getRayon()), p(c.getP()) {}

Cercle::~Cercle() {
}

const Vecteur2D & Cercle::getP() const {
	return p;
}

const int Cercle::getNbSommet() const {
	return 1;
}

inline const double Cercle::getRayon() const {
	return rayon;
}

const std::string Cercle::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeoSimple::getInfos();
	oss << "Rayon : " << std::endl << rayon << std::endl;
	oss << "Centre : " << std::endl << p << std::endl;
	return oss.str();
}

FormeGeo * Cercle::clone() const {
	return new Cercle(*this);
}
