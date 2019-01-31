#pragma once
#include "GestionnaireChargement.h"
class ChargementFichier :
	public GestionnaireChargement {
	std::string extension;
	GestionnaireChargement * suivant;
public:
	ChargementFichier(const std::string & extension, GestionnaireChargement * suivant = NULL);
	virtual ~ChargementFichier();

	virtual std::vector<FormeGeo*> construit(const std::string & chemin) = 0;

	bool peutGerer(const std::string & chemin);
	std::vector<FormeGeo*> gerer(const std::string & chemin);
};