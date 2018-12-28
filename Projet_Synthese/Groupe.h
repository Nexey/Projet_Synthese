#pragma once
#include "FormeGeo.h"
#include "Vecteur2D.h"
#include <vector>

class Groupe :
	public FormeGeo {
	Groupe() = delete;

	std::vector<const FormeGeo*> formes;
	int nbForme;
public:
	Groupe(const int& c);
	Groupe(const Groupe&);
	virtual ~Groupe();

	Groupe& operator+(const FormeGeo&);
	const FormeGeo& operator[] (const int&) const;
	const std::vector<const FormeGeo*>& getVector() const;

	const int getNbSommet() const;
	virtual const std::string getInfos() const;

	FormeGeo * clone() const;
};

