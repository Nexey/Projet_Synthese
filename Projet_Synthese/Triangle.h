#pragma once
#include "FormeGeoSimple.h"

class Triangle :
	public FormeGeoSimple {
	Triangle() = delete;
	Vecteur2D p1, p2, p3;
public:
	Triangle(const int& c, const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3);
	Triangle(const Triangle&);
	virtual ~Triangle();

	const Vecteur2D& getP1() const;
	const Vecteur2D& getP2() const;
	const Vecteur2D& getP3() const;

	const int getNbSommet() const;

	void translation(const Vecteur2D&);
	virtual const std::string getInfos() const;
	FormeGeo * clone() const;
};

