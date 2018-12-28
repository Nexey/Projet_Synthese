#include "FormeGeoSimple.h"

FormeGeoSimple::FormeGeoSimple(const std::string& n, const int& c) : FormeGeo(n, c) {}

FormeGeoSimple::FormeGeoSimple(const FormeGeoSimple &f) : FormeGeo(f.getDesig(), f.getCouleur()) {}

FormeGeoSimple::~FormeGeoSimple() {}

const std::string FormeGeoSimple::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeo::getInfos();
	return oss.str();
}