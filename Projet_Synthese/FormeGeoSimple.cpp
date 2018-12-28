#include "FormeGeoSimple.h"

FormeGeoSimple::FormeGeoSimple(const std::string& n, const int& c) : FormeGeo(n, c) {}

FormeGeoSimple::FormeGeoSimple(const FormeGeoSimple &f) : FormeGeo(f.getNom(), f.getCouleur()) {}

FormeGeoSimple::~FormeGeoSimple() {}
const std::string FormeGeoSimple::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeo::getInfos();
	oss << "Nombre de sommets : " << std::endl << getNbSommet() << std::endl;
	return oss.str();
}