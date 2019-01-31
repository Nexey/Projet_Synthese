#include "CreationCercleCOR.h"
#include "Cercle.h"

CreationCercleCOR::CreationCercleCOR(GestionnaireCreation * suivant) : CreationCOR("cercle", suivant) {}

CreationCercleCOR::~CreationCercleCOR() {}

FormeGeo * CreationCercleCOR::construit(const std::vector<std::string>& forme) {
	initCoords(forme);
	initCouleur(forme);

	double rayon = std::stod(forme.at(5));
	return new Cercle(this->idCouleur, rayon, this->coordonnees.at(0));
}
