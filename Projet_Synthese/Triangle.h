#pragma once
#include "FormeGeoSimple.h"
class Triangle :
	public FormeGeoSimple {
	Triangle() = delete;
	const int nbSommets = 3;
public:
	Triangle(const std::string& n, const int& c, const Vecteur2D& p);
	Triangle(const Triangle&);
	virtual ~Triangle();


	virtual const std::string getInfos() const;
	virtual FormeGeo * clone() const;
};

