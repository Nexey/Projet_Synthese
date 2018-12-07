#include "FormeGeo.h"

FormeGeo::FormeGeo(const std::string n, const Vecteur2D p) : nom(n), pos(p) {}

FormeGeo::FormeGeo(const FormeGeo &f) : nom(f.getNom()) {}

FormeGeo::~FormeGeo() {}


inline const Vecteur2D FormeGeo::getPos() const {
	return pos;
}

inline const std::string FormeGeo::getNom() const {
	return nom;
}

const std::string FormeGeo::getInfos() const {
	std::ostringstream oss;
	oss << "Nom : " << nom << std::endl;
	oss << "Position : " << pos << std::endl;
	return oss.str();
}

std::ostream & operator<<(std::ostream &o, const FormeGeo &f) {
	o << f.getInfos();
	return o;
}
