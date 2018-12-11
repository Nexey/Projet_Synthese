#include "Cercle.h"

Cercle::Cercle(const std::string& n, const int& c, const double& r, const Vecteur2D& p) : FormeGeoSimple(n, c, p), rayon(r) {}

Cercle::Cercle(const Cercle &c) : FormeGeoSimple(c.getNom(), c.getCouleur(), c.pos), rayon(c.getRayon()) {
}

Cercle::~Cercle() {
}

inline const double Cercle::getRayon() const {
	return rayon;
}

const std::string Cercle::getInfos() const {
	return std::string();
}

FormeGeo * Cercle::clone() const {
	return new Cercle(getNom(), getCouleur(), rayon, Vecteur2D(this->pos));
}
