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
	Polygone(const std::string& n, const int& c);
	Polygone(const Polygone&);
	virtual ~Polygone();

	void addPoint(const Vecteur2D&);
	Polygone& operator+(const Vecteur2D&);
	Polygone& operator+=(const Vecteur2D&);

	Vecteur2D& operator[] (const int);

	const std::vector<Vecteur2D>& getVector() const;

	const int getNbSommet() const;

	void translation(const Vecteur2D&);
	void zoom(const Vecteur2D& o, const double& k);
	void rotation(const Vecteur2D& c, const double& a);
	virtual const std::string getInfos() const;
	FormeGeo * clone() const;
};