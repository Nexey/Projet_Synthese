#include <string>
#include <iostream>
#include <sstream>

#pragma once
class FormeGeo {
	std::string nom;
	int couleur;
	FormeGeo() = delete;
public:
	FormeGeo(const std::string& n, const int& c);
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

	inline const std::string& getNom() const;

	virtual const std::string getInfos() const;
	virtual FormeGeo * clone() const = 0;

	inline const int& getCouleur() const;

	virtual const int getNbSommet() const = 0;

	friend std::ostream& operator<<(std::ostream&, const FormeGeo&);
};