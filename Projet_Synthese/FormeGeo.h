#include <string>
#include <iostream>
#include <sstream>
#include "Vecteur2D.h"

class IVisiteur;

#pragma once
class FormeGeo {
	std::string desig;
	int couleur;
	FormeGeo() = delete;
public:
	FormeGeo(const std::string& d, const int& c);
	FormeGeo(const FormeGeo&);
	virtual ~FormeGeo();

	const static int
		BLACK = 0,
		BLUE = 1,
		RED = 2,
		GREEN = 3,
		YELLOW = 4,
		CYAN = 5;

	static const std::string tabCouleurs[6];

	inline const std::string& getDesig() const;

	virtual const std::string getInfos() const;
	virtual FormeGeo * clone() const = 0;

	const int getCouleur() const;
	void setCouleur(const int&);

	virtual void translation(const Vecteur2D& v) = 0;
	virtual void zoom(const Vecteur2D& o, const double& k) = 0;
	virtual void rotation(const Vecteur2D& o, const double& a) = 0;

	virtual const int getNbSommet() const = 0;

	virtual FormeGeo* accepter(IVisiteur *v) = 0;

	friend std::ostream& operator<<(std::ostream&, const FormeGeo&);
};