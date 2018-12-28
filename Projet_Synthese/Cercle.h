#pragma once
#include "FormeGeoSimple.h"
#include "Vecteur2D.h"

class Cercle :
	public FormeGeoSimple {
	Cercle() = delete;
	double rayon;
	Vecteur2D p;
public:
	Cercle(const std::string& n, const int& c, const double& r, const Vecteur2D& p);
	Cercle(const Cercle&);
	virtual ~Cercle();

	const Vecteur2D& getP() const;

	const int getNbSommet() const;

	inline const double getRayon() const;
	virtual const std::string getInfos() const;
	FormeGeo * clone() const;
};

