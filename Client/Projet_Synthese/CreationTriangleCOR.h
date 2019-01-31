#pragma once
#include "CreationCOR.h"
class CreationTriangleCOR :
	public CreationCOR {
public:
	CreationTriangleCOR(GestionnaireCreation * suivant = NULL);
	virtual ~CreationTriangleCOR();
	FormeGeo * construit(const std::vector<std::string> & forme);
};

