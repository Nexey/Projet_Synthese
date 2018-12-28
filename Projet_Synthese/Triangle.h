#pragma once
#include "FormeGeoSimple.h"
#include "Vecteur2D.h"
class Triangle :
	public FormeGeoSimple {
	Triangle() = delete;
	const int nbSommets = 3;
	Vecteur2D p1, p2, p3;
public:
	Triangle(const std::string& n, const int& c, const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3);
	Triangle(const Triangle&);
	virtual ~Triangle();

	const Vecteur2D& getP1() const;
	const Vecteur2D& getP2() const;
	const Vecteur2D& getP3() const;

	virtual const std::string getInfos() const;
	FormeGeo * clone() const;
};

