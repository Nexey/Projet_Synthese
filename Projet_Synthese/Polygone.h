#pragma once
#include "FormeGeoSimple.h"
#include <vector>

class Vecteur2D;

class Polygone :
	public FormeGeoSimple {
	Polygone() = delete;
	std::vector<const Vecteur2D*> points;
	int nbPoint;
public:
	Polygone(const std::string& n, const int& c);
	Polygone(const Polygone&);
	virtual ~Polygone();

	Polygone& operator+(const Vecteur2D&);
	Polygone& operator+=(const Vecteur2D&);

	const Vecteur2D& operator[] (const int) const;

	const int getNbSommet() const;

	virtual const std::string getInfos() const;
	FormeGeo * clone() const;
};