#pragma once
#include "IVisiteur.h"
class VisiteurSauvegarde :
	public IVisiteur {
public:
	VisiteurSauvegarde();
	virtual ~VisiteurSauvegarde();

	virtual const void sauvegarde(const FormeGeo*) const = 0;

	FormeGeo* visite(Cercle*);
	FormeGeo* visite(Segment*);
	FormeGeo* visite(Triangle*);
	FormeGeo* visite(Polygone*);
	FormeGeo* visite(Groupe*);
};

