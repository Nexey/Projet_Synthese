#pragma once
#include "Polygone.h"

class Cercle :
	public Polygone {
	Cercle() = delete;
	double rayon;

public:
	Cercle(const int& c, const double& r, const Vecteur2D& p);
	Cercle(const Cercle&);
	virtual ~Cercle();

	void addPoint(const Vecteur2D&);

	inline const double getRayon() const;
	virtual const std::string getInfos() const;
	FormeGeo* accepter(IVisiteur *v);
	FormeGeo * clone() const;
};