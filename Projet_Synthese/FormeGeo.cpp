#include "FormeGeo.h"

int FormeGeo::nbFormeGeos = 0;

const std::string FormeGeo::tabCouleurs[6] = { "BLACK", "BLUE", "RED", "GREEN", "YELLOW", "CYAN" };

const std::string FormeGeo::generateDesig(const std::string &s) {
	FormeGeo::nbFormeGeos++;
	std::stringstream ss;
	ss << s << "_" << FormeGeo::nbFormeGeos;
	return ss.str();
}

FormeGeo::FormeGeo(const std::string& d, const int& c) : couleur(c) {
	desig = generateDesig(d);
}

FormeGeo::FormeGeo(const FormeGeo &f) : desig(f.getDesig()), couleur(f.getCouleur()) {
	std::string temp = f.getDesig();
	temp = temp.substr(0, temp.size() - 1);
	desig = generateDesig(temp);
}

FormeGeo::~FormeGeo() {}

inline const std::string& FormeGeo::getDesig() const {
	return desig;
}

const std::string FormeGeo::getInfos() const {
	std::ostringstream oss;
	oss << "ID : " << desig << ", COULEUR : " << FormeGeo::tabCouleurs[couleur] << ", NB_SOMMETS : " << getNbSommet();
	return oss.str();
}

const int FormeGeo::getCouleur() const {
	return couleur;
}

void FormeGeo::setCouleur(const int& c) {
	couleur = c;
}

std::ostream & operator<<(std::ostream &o, const FormeGeo &f) {
	o << "[" << f.getInfos() << "]" << std::endl;
	return o;
}