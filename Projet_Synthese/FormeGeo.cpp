#include "FormeGeo.h"
#include "Vecteur2D.h"

FormeGeo::FormeGeo(const std::string& n) : nom(n) {}

FormeGeo::FormeGeo(const FormeGeo &f) : nom(f.getNom()) {}

FormeGeo::~FormeGeo() {}

inline const std::string& FormeGeo::getNom() const {
	return nom;
}

const std::string FormeGeo::getInfos() const {
	std::ostringstream oss;
	oss << "Nom : " << std::endl << nom << std::endl;
	return oss.str();
}

std::ostream & operator<<(std::ostream &o, const FormeGeo &f) {
	o << f.getInfos();
	return o;
}
