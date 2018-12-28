#include "Groupe.h"

Groupe::Groupe(const int & c) : FormeGeo("Groupe", c), nbForme(0) {}

Groupe::Groupe(const Groupe &g) : FormeGeo(g.getDesig(), g.getCouleur()), nbForme(0) {
	std::vector<FormeGeo*>::const_iterator it = g.getVector().begin();
	for (it; it < g.getVector().end(); it++)
		*this = *this + **it;
}

Groupe::~Groupe() {
	formes.clear();
}

Groupe& Groupe::operator+(const FormeGeo &f) {
	// Le fait de cloner la forme fait qu'une même forme n'appartient pas à plusieurs groupes
	FormeGeo * tmp = f.clone();
	tmp->setCouleur(getCouleur());
	formes.push_back(tmp);
	nbForme++;
	return *this;
}

const FormeGeo & Groupe::operator[](const int &i) const {
	return *formes.at(i);
}

const std::vector<FormeGeo*>& Groupe::getVector() const {
	return formes;
}

void Groupe::translation(const Vecteur2D &v) {
	std::vector<FormeGeo*>::iterator it = formes.begin();
	for (it; it < formes.end(); it++)
		(*it)->translation(v);
}

const int Groupe::getNbSommet() const {
	int nbSommet = 0;
	std::vector<FormeGeo*>::const_iterator it = formes.begin();
	for (it; it < formes.end(); it++)
		nbSommet += (*it)->getNbSommet();
	return nbSommet;
}

const std::string Groupe::getInfos() const {
	std::ostringstream oss;
	oss << FormeGeo::getInfos();
	oss << "Nombres de formes : " << std::endl << nbForme << std::endl;
	std::vector<FormeGeo*>::const_iterator it = formes.begin();
	int i = 1;
	for (it; it < formes.end(); it++, i++)
		oss << std:: endl << "Forme numéro : " << i << std::endl << (*it)->getInfos();
	return oss.str();
}

FormeGeo * Groupe::clone() const {
	return new Groupe(*this);
}
