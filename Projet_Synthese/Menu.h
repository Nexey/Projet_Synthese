#pragma once
#include "Cercle.h"
#include "Segment.h"
#include "Triangle.h"
#include "Groupe.h"
#include <memory>
#include "SauvegardeTexte.h"

class Menu {
	//std::vector<std::unique_ptr<Cercle*>> formes;

	IVisiteur *visiSauvegarde;
	std::vector<FormeGeo*> formes;
public:
	const static int
		CERCLE = 1,
		SEGMENT = 2,
		TRIANGLE = 3,
		POLYGONE = 4,
		GROUPE = 5;

	Menu();
	virtual ~Menu();

	const void show();
	template<class T>
	const void inputVar(T&) const;
	const int inputCouleur() const;
	FormeGeo* inputForme(int choix, int couleur = -1) const;

	const std::vector<Vecteur2D>* inputPoints(int nbPoints = 0) const;
	const std::vector<FormeGeo*>* inputGroupe(const int nbFormes, const int couleur) const;

	const void sauvegarder() const;
};

