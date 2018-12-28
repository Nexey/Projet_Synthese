#pragma once
#include "FormeGeo.h"

class FormeGeoSimple :
	public FormeGeo {
	FormeGeoSimple() = delete;
public:
	FormeGeoSimple(const std::string& n, const int& c);
	FormeGeoSimple(const FormeGeoSimple&);
	virtual ~FormeGeoSimple();
};

