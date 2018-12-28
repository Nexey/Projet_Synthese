#pragma once
#include "FormeGeoSimple.h"

class Segment :
	public FormeGeoSimple {
	Segment() = delete;
	Vecteur2D p1, p2;
public:
	Segment(const int& c, const Vecteur2D& p1, const Vecteur2D& p2);
	Segment(const Segment&);
	virtual ~Segment();

	const Vecteur2D& getP1() const;
	const Vecteur2D& getP2() const;

	const int getNbSommet() const;

	void translation(const Vecteur2D&);
	virtual const std::string getInfos() const;
	FormeGeo * clone() const;
};

