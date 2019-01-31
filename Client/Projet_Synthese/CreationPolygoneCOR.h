#pragma once
#include "CreationCOR.h"
class CreationPolygoneCOR :
	public CreationCOR {
public:
	CreationPolygoneCOR(GestionnaireCreation * suivant = NULL);
	virtual ~CreationPolygoneCOR();
	FormeGeo * construit(const std::vector<std::string> & forme);
};

