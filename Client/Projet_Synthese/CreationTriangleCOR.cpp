#include "CreationTriangleCOR.h"
#include "Triangle.h"

CreationTriangleCOR::CreationTriangleCOR(GestionnaireCreation * suivant) : CreationCOR("triangle", suivant) {}

CreationTriangleCOR::~CreationTriangleCOR() {}

FormeGeo * CreationTriangleCOR::construit(const std::vector<std::string>& forme) {
	initCoords(forme);
	initCouleur(forme);
	return new Triangle(this->idCouleur, this->coordonnees.at(0), this->coordonnees.at(1), this->coordonnees.at(2));
}
