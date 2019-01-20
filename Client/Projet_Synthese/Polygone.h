#pragma once
#include "FormeGeoSimple.h"
#include <vector>

class Polygone :
	public FormeGeoSimple {
	Polygone() = delete;
	std::vector<Vecteur2D> points;
public:
	Polygone(const int& c);
	Polygone(const int& c, const std::vector<Vecteur2D>);
	Polygone(const std::string& n, const int& c);
	Polygone(const Polygone&);
	virtual ~Polygone();

	virtual void addPoint(const Vecteur2D&);
	Polygone& operator+(const Vecteur2D&);
	Polygone& operator+=(const Vecteur2D&);

	Vecteur2D& operator[] (const int);

	const std::vector<Vecteur2D>& getVector() const;

	const int getNbSommet() const;

	void translation(const Vecteur2D&);
	void zoom(const Vecteur2D& o, const double& k);
	void rotation(const Vecteur2D& c, const double& a);
	virtual const double aire() const;

	virtual const std::string getInfos() const;
	FormeGeo* accepter(IVisiteur *v);
	FormeGeo * clone() const;
};