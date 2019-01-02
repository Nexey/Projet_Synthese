#pragma once
#include "IVisiteur.h"
class VisiteurDessin :
	public IVisiteur {
public:
	VisiteurDessin();
	virtual ~VisiteurDessin();

	FormeGeo* visite(Cercle*);
	FormeGeo* visite(Segment*);
	FormeGeo* visite(Triangle*);
	FormeGeo* visite(Polygone*);
	FormeGeo* visite(Groupe*);
};

