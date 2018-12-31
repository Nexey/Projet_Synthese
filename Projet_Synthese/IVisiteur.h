#pragma once

#include "Cercle.h"
#include "Segment.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"

class IVisiteur {
public:
	virtual FormeGeo* visite(Cercle*) = 0;
	virtual FormeGeo* visite(Segment*) = 0;
	virtual FormeGeo* visite(Triangle*) = 0;
	virtual FormeGeo* visite(Polygone*) = 0;
	virtual FormeGeo* visite(Groupe*) = 0;
};