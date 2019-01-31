#include "CreationSegmentCOR.h"
#include "Segment.h"

CreationSegmentCOR::CreationSegmentCOR(GestionnaireCreation * suivant) : CreationCOR("segment", suivant) {}

CreationSegmentCOR::~CreationSegmentCOR() {}

FormeGeo * CreationSegmentCOR::construit(const std::vector<std::string>& forme) {
	this->initCoords(forme);
	initCouleur(forme);
	return new Segment(this->idCouleur, this->coordonnees.at(0), this->coordonnees.at(1));
}
