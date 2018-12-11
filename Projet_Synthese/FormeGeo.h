#include <string>
#include <iostream>
#include <sstream>
#include "Vecteur2D.h"

#pragma once
class FormeGeo {
	std::string nom;
	FormeGeo() = delete;
public:
	Vecteur2D pos;
	FormeGeo(const std::string&, const Vecteur2D&);
	FormeGeo(const FormeGeo&);
	virtual ~FormeGeo();

	const static int
		BLACK = 1,
		BLUE = 2,
		RED = 3,
		GREEN = 4,
		YELLOW = 5,
		CYAN = 6;

//	const Vecteur2D& getPos() const;
	inline const std::string getNom() const;

	virtual const std::string getInfos() const;
	virtual FormeGeo * clone() const = 0;

	friend std::ostream& operator<<(std::ostream&, const FormeGeo&);
};