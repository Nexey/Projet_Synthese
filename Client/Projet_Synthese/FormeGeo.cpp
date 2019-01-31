#include "FormeGeo.h"

int FormeGeo::nbFormeGeos = 0;

std::map<int, std::string> FormeGeo::mapCouleurs = {
	{FormeGeo::BLACK, "BLACK"}, {FormeGeo::BLUE, "BLUE"}, {FormeGeo::RED, "RED"},
	{FormeGeo::GREEN, "GREEN"}, {FormeGeo::YELLOW, "YELLOW"}, {FormeGeo::CYAN, "CYAN"}
};

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
	oss << "ID : " << desig << getSeparateur() << "COULEUR : " << FormeGeo::mapCouleurs.at(couleur) << getSeparateur() << "NB_SOMMETS : " << getNbSommet();
	return oss.str();
}

FormeGeo::operator std::string() const {
	std::stringstream ss;
	ss << "{ " << getInfos() << " }";
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