#include "CreationPolygoneCOR.h"
#include "Polygone.h"

CreationPolygoneCOR::CreationPolygoneCOR(GestionnaireCreation * suivant) : CreationCOR("polygone", suivant) {}

CreationPolygoneCOR::~CreationPolygoneCOR() {}

FormeGeo * CreationPolygoneCOR::construit(const std::vector<std::string>& forme) {
	this->initCoords(forme);
	initCouleur(forme);
	return new Polygone(this->idCouleur, this->coordonnees);
}