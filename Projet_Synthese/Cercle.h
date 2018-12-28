#pragma once
#include "FormeGeoSimple.h"

class Cercle :
	public FormeGeoSimple {
	Cercle() = delete;
	double rayon;
	Vecteur2D p;
public:
	Cercle(const int& c, const double& r, const Vecteur2D& p);
	Cercle(const Cercle&);
	virtual ~Cercle();

	const Vecteur2D& getP() const;

	const int getNbSommet() const;

	void translation(const Vecteur2D&v);

	inline const double getRayon() const;
	virtual const std::string getInfos() const;
	FormeGeo * clone() const;
};