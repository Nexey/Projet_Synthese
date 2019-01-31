#pragma once
#include "ChargementFichier.h"
class ChargementFichierTexte :
	public ChargementFichier {
public:
	ChargementFichierTexte(GestionnaireChargement * suivant = NULL);
	virtual ~ChargementFichierTexte();

	std::vector<FormeGeo*> construit(const std::string & chemin);
};

