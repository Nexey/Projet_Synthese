#pragma once
#include "FormeGeo.h"

class FormeGeoSimple :
	public FormeGeo {
	int couleur;
	FormeGeoSimple() = delete;
public:
	FormeGeoSimple(const std::string& n, const int& c, const Vecteur2D& p);
	FormeGeoSimple(const FormeGeoSimple&);
	virtual ~FormeGeoSimple();

	inline const int getCouleur() const;
	virtual const std::string getInfos() const;
	virtual FormeGeo * clone() const = 0;

};

