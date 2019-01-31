#include "ChargementFichier.h"


ChargementFichier::ChargementFichier(const std::string & extension, GestionnaireChargement * suivant) : extension(extension), suivant(suivant) {}

ChargementFichier::~ChargementFichier() {}

bool ChargementFichier::peutGerer(const std::string & chemin) {
	return  chemin.substr(chemin.find_last_of(".") + 1) == extension;
}

std::vector<FormeGeo*> ChargementFichier::gerer(const std::string & chemin) {
	if (peutGerer(chemin))
		return construit(chemin);

	if (suivant != nullptr)
		return suivant->gerer(chemin);

	return std::vector<FormeGeo*>();
}
