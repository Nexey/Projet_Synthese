#pragma once
#include "VisiteurSauvegarde.h"
class SauvegardeTexte :
	public VisiteurSauvegarde {
public:
	SauvegardeTexte();
	virtual ~SauvegardeTexte();

	const void sauvegarde(const FormeGeo*) const;
};