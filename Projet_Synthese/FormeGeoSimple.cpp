#include "FormeGeoSimple.h"

FormeGeoSimple::FormeGeoSimple(const std::string& n, const int& c) : FormeGeo(n), couleur(c) {}

FormeGeoSimple::FormeGeoSimple(const FormeGeoSimple &f) : FormeGeo(f.getNom()), couleur(f.getCouleur()) {}

FormeGeoSimple::~FormeGeoSimple() {}

inline const int& FormeGeoSimple::getCouleur() const {
	return couleur;
}

const std::string FormeGeoSimple::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeo::getInfos();
	oss << "Couleur : " << std::endl << couleur << std::endl;
	return oss.str();
}