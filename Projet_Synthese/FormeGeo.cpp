#include "FormeGeo.h"

const std::string FormeGeo::tabCouleurs[6] = { "BLACK", "BLUE", "RED", "GREEN", "YELLOW", "CYAN" };

FormeGeo::FormeGeo(const std::string& d, const int& c) : desig(d), couleur(c) {}

FormeGeo::FormeGeo(const FormeGeo &f) : desig(f.getDesig()), couleur(f.getCouleur()) {}

FormeGeo::~FormeGeo() {}

inline const std::string& FormeGeo::getDesig() const {
	return desig;
}

const std::string FormeGeo::getInfos() const {
	std::ostringstream oss;
	oss << "Désignation : " << std::endl << desig << std::endl;
	oss << "Couleur : " << std::endl << FormeGeo::tabCouleurs[couleur] << std::endl;
	oss << "Nombre de sommets : " << std::endl << getNbSommet() << std::endl;
	oss << "Fin" << std::endl;
	return oss.str();
}

const int FormeGeo::getCouleur() const {
	return couleur;
}

void FormeGeo::setCouleur(const int& c) {
	couleur = c;
}

std::ostream & operator<<(std::ostream &o, const FormeGeo &f) {
	o << f.getInfos();
	return o;
}