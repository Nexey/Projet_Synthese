#pragma once
#include "FormeGeoSimple.h"
#include <vector>

class Polygone :
	public FormeGeoSimple {
	Polygone() = delete;
	std::vector<Vecteur2D> points;
	int nbPoint;
public:
	Polygone(const int& c);
	Polygone(const Polygone&);
	virtual ~Polygone();

	Polygone& operator+(const Vecteur2D&);
	Polygone& operator+=(const Vecteur2D&);

	Vecteur2D& operator[] (const int);

	const std::vector<Vecteur2D>& getVector() const;

	const int getNbSommet() const;

	void translation(const Vecteur2D&);
	virtual const std::string getInfos() const;
	FormeGeo * clone() const;
};