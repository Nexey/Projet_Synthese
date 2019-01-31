#include "Menu.h"
#include <fstream>
#include "ChargementFichierTexte.h"

Menu::Menu() {
	visiSauvegarde = new SauvegardeTexte();
	visiDessin = new VisiteurDessin();
}

Menu::~Menu() {
	formes.clear();
}

void Menu::chargerFormes(const std::string & chemin) {
	GestionnaireChargement * expertChargement = new ChargementFichierTexte;
	this->formes = expertChargement->gerer(chemin);
	std::vector<FormeGeo*>::const_iterator it = this->formes.begin();
	for (it; it < this->formes.end(); it++)
		this->sauvegarder(*it);
}

const void Menu::show() {
	int choix;
	std::cout << "S�lectionnez la forme � cr�er" << std::endl;
	std::cout << Menu::CERCLE << ")\tCercle" << std::endl << Menu::SEGMENT << ")\tSegment" << std::endl << Menu::TRIANGLE << ")\tTriangle" << std::endl
		<< Menu::POLYGONE << ")\tPolygone" << std::endl << Menu::GROUPE << ")\tGroupe" << std::endl << "6)\tDessiner les formes sauvegard�es"
		<< std::endl << "0)\tQuitter" << std::endl;
	do {
		inputVar(choix);
	} while (choix < 0 || choix > 6);

	switch (choix) {
	case 0:
		break;
	case 6:
		Menu::dessiner();
		break;
	default:
		formes.push_back(inputForme(choix));
		sauvegarder(formes.back());
		break;
	}

	if (choix != 0) show();
}

template<class T>
const void Menu::inputVar(T& var) const {
	std::cin >> var;
}

const int Menu::inputCouleur() const {
	int couleur;
	std::cout << "S�lectionnez la couleur : " << std::endl;
	for (int i = FormeGeo::BLACK; i <= FormeGeo::CYAN; i++)
		std::cout << i << ") " << FormeGeo::mapCouleurs.at(i) << std::endl;
	do {
		inputVar(couleur);
	} while (couleur < FormeGeo::BLACK || couleur > FormeGeo::CYAN);
	// Couleur pr�te
	return couleur;
}

FormeGeo * Menu::inputForme(int choix, int couleur) const {
	std::vector<Vecteur2D> points;
	if (couleur == -1)
		couleur = inputCouleur();
	
	switch (choix) {
	case Menu::CERCLE:
		points = *inputPoints(1);
		double r;
		std::cout << "Rentrez le rayon du cercle : " << std::endl;
		do {
			inputVar(r);
		} while (r <= 0);
		return new Cercle(couleur, r, points.at(0));
		break;
	case Menu::SEGMENT:
		points = *inputPoints(2);
		return new Segment(couleur, points.at(0), points.at(1));
		break;
	case Menu::TRIANGLE:
		points = *inputPoints(3);
		return new Triangle(couleur, points.at(0), points.at(1), points.at(2));
		break;
	case Menu::POLYGONE:
		points = *inputPoints();
		return new Polygone(couleur, points);
		break;
	case Menu::GROUPE:
		std::cout << "Combien de formes voulez-vous rentrer ?" << std::endl;
		int nbFormes;
		do {
			inputVar(nbFormes);
		} while (nbFormes < 1);

		return new Groupe(couleur, *inputGroupe(nbFormes, couleur));
		break;
	default:
		return NULL;
		break;
	}
}

const std::vector<Vecteur2D>* Menu::inputPoints(int nbPoints) const {
	int x, y;
	if (nbPoints == 0) {
		std::cout << "Combien de points voulez-vous rentrer ?" << std::endl;
		do {
			inputVar(nbPoints);
		} while (nbPoints <= 0);
	}

	std::vector<Vecteur2D> * points = new std::vector<Vecteur2D>();
	for (int i = 0; i < nbPoints; i++) {
		std::cout << "Point num�ro " << i + 1 << std::endl;
		std::cout << "Entrez X : " << std::endl;
		inputVar(x);
		std::cout << "Entrez Y : " << std::endl;
		inputVar(y);
		points->push_back(Vecteur2D(x, y));
	}

	return points;
}

const std::vector<FormeGeo*> * Menu::inputGroupe(const int nbFormes, const int couleur) const {
	std::vector<FormeGeo*> * f = new std::vector<FormeGeo*>();
	int choix;
	for (int i = 0; i < nbFormes; i++) {
		std::cout << "S�lectionnez la " << i + 1 << "�me forme � ajouter au groupe" << std::endl;
		std::cout << Menu::CERCLE << ")\tCercle" << std::endl << Menu::SEGMENT << ")\tSegment" << std::endl << Menu::TRIANGLE << ")\tTriangle" << std::endl
			<< Menu::POLYGONE << ")\tPolygone" << std::endl << Menu::GROUPE << ")\tGroupe" << std::endl;
		do {
			inputVar(choix);
		} while (choix < 0 || choix > 5);
		f->push_back(inputForme(choix, couleur));
	}
	return f;
}

const void Menu::sauvegarder(FormeGeo * forme) const {
	forme->accepter(visiSauvegarde);
}

const void Menu::dessiner() {
	if (formes.size() != 0) {
		int i = 1;
		int choix;
		std::cout << "S�lectionnez la forme � dessiner" << std::endl;
		std::vector<FormeGeo*>::const_iterator it = formes.begin();
		for (it, i; it < formes.end(); i++, it++)
			std::cout << i << ") " << **it << std::endl;
		do {
			inputVar(choix);
		} while (choix < 1 || choix > formes.size());
		try {
			(formes.at(choix - 1))->accepter(visiDessin);
		}
		catch (Erreur e) {
			std::cerr << e.message << std::endl;
		}
	}
}

Menu::operator std::string() const {
	std::stringstream ss;
	std::vector<FormeGeo*>::const_iterator it = formes.begin();
	for (it; it < formes.end(); it++)
		ss << **it << std::endl;
	return ss.str();
}