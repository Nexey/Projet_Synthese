#include "FormeGeo.h"

int FormeGeo::nbFormeGeos = 0;

const std::string FormeGeo::tabCouleurs[6] = { "BLACK", "BLUE", "RED", "GREEN", "YELLOW", "CYAN" };

FormeGeo::FormeGeo(const std::string& d, const int& c, const std::string & s) : desig(d), separateur(s), couleur(c) {}

FormeGeo::FormeGeo(const FormeGeo &f) : desig(f.getDesig()), couleur(f.getCouleur()) {}

FormeGeo::~FormeGeo() {}

inline const std::string& FormeGeo::getDesig() const {
	return desig;
}

inline const std::string & FormeGeo::getSeparateur() const {
	return separateur;
}

const std::string FormeGeo::getInfos() const {
	std::ostringstream oss;
	oss << "ID : " << desig << getSeparateur() << "COULEUR : " << FormeGeo::tabCouleurs[couleur] << getSeparateur() << "NB_SOMMETS : " << getNbSommet();
	return oss.str();
}

FormeGeo::operator std::string() const {
	std::stringstream ss;
	ss << "{\t" << getInfos() << "\t}";
	return ss.str();
}

const int FormeGeo::getCouleur() const {
	return couleur;
}

void FormeGeo::setCouleur(const int& c) {
	couleur = c;
}

std::ostream & operator<<(std::ostream &o, const FormeGeo &f) {
	o << (std::string)f;
	return o;
}