#pragma once
#include <vector>
#include "FormeGeo.h"

class GestionnaireChargement {
public:
	virtual std::vector<FormeGeo*> gerer(const std::string & chemin) = 0;
};