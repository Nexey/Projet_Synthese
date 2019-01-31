#pragma once
#include "FormeGeo.h"
#include <vector>
class GestionnaireCreation {
public:
	virtual FormeGeo * gerer(const std::vector<std::string> & forme) = 0;
};