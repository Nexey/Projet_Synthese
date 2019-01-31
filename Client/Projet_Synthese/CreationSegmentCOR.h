#pragma once
#include "CreationCOR.h"
class CreationSegmentCOR :
	public CreationCOR {
public:
	CreationSegmentCOR(GestionnaireCreation * suivant = NULL);
	virtual ~CreationSegmentCOR();
	FormeGeo * construit(const std::vector<std::string> & forme);
};

