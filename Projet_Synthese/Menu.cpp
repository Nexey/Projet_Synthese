#include "Menu.h"

Menu::Menu() {
	visiSauvegarde = new SauvegardeTexte();
	show();
}

Menu::~Menu() {
	formes.clear();
}

const void Menu::show() {
	int choix;
	std::cout << "Sélectionnez la forme à dessiner" << std::endl;
	std::cout << Menu::CERCLE << ")\tCercle" << std::endl << Menu::SEGMENT << ")\tSegment" << std::endl << Menu::TRIANGLE << ")\tTriangle" << std::endl
		<< Menu::POLYGONE << ")\tPolygone" << std::endl << Menu::GROUPE << ")\tGroupe" << std::endl << "0)\tQuitter" << std::endl;
	do {
		inputVar(choix);
	} while (choix < 0 || choix > 5);
	formes.push_back(inputForme(choix));
}

template<class T>
const void Menu::inputVar(T& var) const {
	std::cin >> var;
}

const int Menu::inputCouleur() const {
	int couleur;
	std::cout << "Sélectionnez la couleur : " << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << i << ") " << FormeGeo::tabCouleurs[i] << std::endl;
	do {
		inputVar(couleur);
	} while (couleur < 0 || couleur > 5);
	// Couleur prête
	return couleur;
}

FormeGeo * Menu::inputForme(const int choix) const {
	std::vector<Vecteur2D> * points = new std::vector<Vecteur2D>();
	int couleur;
	FormeGeo * f;
	switch (choix) {
	case Menu::CERCLE:
		points->assign(*inputPoints(1));
		couleur = inputCouleur();
		double r;
		do {
			inputVar(r);
		} while (r <= 0);
		f = new Cercle(couleur, r, points.at(0));
		break;
	case Menu::SEGMENT:
		points = inputPoints(2);

		break;
	case Menu::TRIANGLE:
		points = inputPoints(3);

		break;
	case Menu::POLYGONE:
		points = inputPoints();

		break;
	case Menu::GROUPE:

		break;
	default:
		f = new Triangle(1, 1, 1, 1);
		break;
	}

	return f;
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
		std::cout << "Point numéro " << i << std::endl;
		std::cout << "Entrez X : " << std::endl;
		inputVar(x);
		std::cout << "Entrez Y : " << std::endl;
		inputVar(y);
		points->push_back(Vecteur2D(x, y));
	}

	return points;
}

const void Menu::sauvegarder() const {
	std::vector<FormeGeo*>::const_iterator it = formes.begin();
	for (it; it < formes.end(); it++)
		(*it)->accepter(visiSauvegarde);
}
