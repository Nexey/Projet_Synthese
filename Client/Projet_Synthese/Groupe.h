#pragma once
#include "FormeGeo.h"
#include <vector>

class Groupe :
	public FormeGeo {
	Groupe() = delete;

	std::vector<FormeGeo*> formes;
public:
	Groupe(const int& c);
	Groupe(const int& c, const std::vector<FormeGeo*>);
	Groupe(const Groupe&);
	virtual ~Groupe();

	void addForme(const FormeGeo&);
	Groupe& operator+(const FormeGeo&);
	const FormeGeo& operator[] (const int&) const;
	const std::vector<FormeGeo*>& getVector() const;

	void translation(const Vecteur2D&);
	void zoom(const Vecteur2D& o, const double& k);
	void rotation(const Vecteur2D& c, const double& a);
	const int getNbSommet() const;
	virtual const std::string getInfos() const;

	FormeGeo* accepter(IVisiteur *v);
	FormeGeo * clone() const;
};