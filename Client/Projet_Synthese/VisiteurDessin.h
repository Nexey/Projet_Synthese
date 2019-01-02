#pragma once
#include "IVisiteur.h"
#include "ClientDessin.h"

class VisiteurDessin :
	public IVisiteur {
	ClientDessin * client;
public:
	VisiteurDessin();
	virtual ~VisiteurDessin();

	FormeGeo* visite(Cercle*);
	FormeGeo* visite(Segment*);
	FormeGeo* visite(Triangle*);
	FormeGeo* visite(Polygone*);
	FormeGeo* visite(Groupe*);

	void dessinerForme(FormeGeo*) const;
};