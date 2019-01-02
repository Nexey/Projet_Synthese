#include "Groupe.h"
#include "IVisiteur.h"

Groupe::Groupe(const int & c) : FormeGeo("Groupe", c) {}

Groupe::Groupe(const int & c, const std::vector<FormeGeo*> f) : FormeGeo("Groupe", c) {
	std::vector<FormeGeo*>::const_iterator it = f.begin();
	for (it; it < f.end(); it++)
		addForme(**it);
}

Groupe::Groupe(const Groupe &g) : FormeGeo("Groupe", g.getCouleur()) {
	std::vector<FormeGeo*>::const_iterator it = g.getVector().begin();
	for (it; it < g.getVector().end(); it++)
		*this = *this + **it;
}

Groupe::~Groupe() {
	formes.clear();
}

void Groupe::addForme(const FormeGeo &f) {
	// Le fait de cloner la forme fait qu'une même forme n'appartient pas à plusieurs groupes
	FormeGeo * tmp = f.clone();
	tmp->setCouleur(getCouleur());
	formes.push_back(tmp);
}

Groupe& Groupe::operator+(const FormeGeo &f) {
	addForme(f);
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

void Groupe::zoom(const Vecteur2D & o, const double & k) {
	std::vector<FormeGeo*>::iterator it = formes.begin();
	for (it; it < formes.end(); it++)
		(*it)->zoom(o, k);
}

void Groupe::rotation(const Vecteur2D & c, const double & a) {
	std::vector<FormeGeo*>::iterator it = formes.begin();
	for (it; it < formes.end(); it++)
		(*it)->rotation(c, a);
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
	oss << ", NB_FORMES : " << formes.size() << ", ";
	std::vector<FormeGeo*>::const_iterator it = formes.begin();
	int i = 1;
	for (it; it < formes.end(); it++, i++)
		oss << std::endl << "FORME_" << i << " : " << std::endl << **it;
	return oss.str();
}

FormeGeo * Groupe::accepter(IVisiteur * v) {
	return v->visite(this);
}

FormeGeo * Groupe::clone() const {
	return new Groupe(*this);
}
