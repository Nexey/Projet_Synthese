#include <string>
#include <iostream>
#include <sstream>

#pragma once
class FormeGeo {
	std::string nom;
	FormeGeo() = delete;
public:
	FormeGeo(const std::string&);
	FormeGeo(const FormeGeo&);
	virtual ~FormeGeo();

	const static int
		BLACK = 1,
		BLUE = 2,
		RED = 3,
		GREEN = 4,
		YELLOW = 5,
		CYAN = 6;

	inline const std::string& getNom() const;

	virtual const std::string getInfos() const;
	virtual FormeGeo * clone() const = 0;

	virtual const int getNbSommet() const = 0;

	friend std::ostream& operator<<(std::ostream&, const FormeGeo&);
};