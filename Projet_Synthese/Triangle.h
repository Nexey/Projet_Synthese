#pragma once
#include "Polygone.h"

class Triangle :
	public Polygone {
	Triangle() = delete;

	Triangle& operator+(const Vecteur2D&) = delete;
	Triangle& operator+=(const Vecteur2D&) = delete;
public:
	Triangle(const int& c, const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3);
	Triangle(const Triangle&);
	virtual ~Triangle();

	void addPoint(const Vecteur2D&);

	FormeGeo* accepter(IVisiteur *v);
	const std::string getInfos() const;
	FormeGeo * clone() const;
};

