#pragma once
#include "CreationCOR.h"
class CreationCercleCOR :
	public CreationCOR {
public:
	CreationCercleCOR(GestionnaireCreation * suivant = NULL);
	virtual ~CreationCercleCOR();
	FormeGeo * construit(const std::vector<std::string> & forme);
};