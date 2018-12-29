#pragma once
#include "Polygone.h"

class Segment :
	public Polygone {
	Segment() = delete;
public:
	Segment(const int& c, const Vecteur2D& p1, const Vecteur2D& p2);
	Segment(const Segment&);
	virtual ~Segment();

	FormeGeo * clone() const;
};

