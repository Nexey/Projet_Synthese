#pragma once
#include "CreationCOR.h"
class CreationGroupeCOR :
	public CreationCOR {
public:
	CreationGroupeCOR(GestionnaireCreation * suivant = NULL);
	virtual ~CreationGroupeCOR();
	FormeGeo * construit(const std::vector<std::string> & forme);
};

