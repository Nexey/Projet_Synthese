#include "FormeGeo.h"
#include "Vecteur2D.h"

const std::string FormeGeo::tabCouleurs[6] = { "BLACK", "BLUE", "RED", "GREEN", "YELLOW", "CYAN" };

FormeGeo::FormeGeo(const std::string& n, const int& c) : nom(n), couleur(c) {}

FormeGeo::FormeGeo(const FormeGeo &f) : nom(f.getNom()), couleur(f.getCouleur()) {}

FormeGeo::~FormeGeo() {}

inline const std::string& FormeGeo::getNom() const {
	return nom;
}

const std::string FormeGeo::getInfos() const {
	std::ostringstream oss;
	oss << "Nom : " << std::endl << nom << std::endl;
	oss << "Couleur : " << std::endl << FormeGeo::tabCouleurs[couleur] << std::endl;
	return oss.str();
}

inline const int & FormeGeo::getCouleur() const {
	return couleur;
}

std::ostream & operator<<(std::ostream &o, const FormeGeo &f) {
	o << f.getInfos();
	return o;
}
