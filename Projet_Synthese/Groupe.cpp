#include "Groupe.h"
#include "IVisiteur.h"

Groupe::Groupe(const int & c) : FormeGeo("Groupe", c) {}

Groupe::Groupe(const Groupe &g) : FormeGeo(g.getDesig(), g.getCouleur()) {
	std::vector<FormeGeo*>::const_iterator it = g.getVector().begin();
	for (it; it < g.getVector().end(); it++)
		*this = *this + **it;
}

Groupe::~Groupe() {
	formes.clear();
}

Groupe& Groupe::operator+(const FormeGeo &f) {
	// Le fait de cloner la forme fait qu'une m�me forme n'appartient pas � plusieurs groupes
	FormeGeo * tmp = f.clone();
	tmp->setCouleur(getCouleur());
	formes.push_back(tmp);
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
	oss << "Nombres de formes : " << std::endl << formes.size() << std::endl;
	std::vector<FormeGeo*>::const_iterator it = formes.begin();
	int i = 1;
	for (it; it < formes.end(); it++, i++)
		oss << std:: endl << "Forme num�ro : " << i << std::endl << (*it)->getInfos();
	return oss.str();
}

FormeGeo * Groupe::accepter(IVisiteur * v) {
	return v->visite(this);
}

FormeGeo * Groupe::clone() const {
	return new Groupe(*this);
}
