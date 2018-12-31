#include "VisiteurSauvegarde.h"

VisiteurSauvegarde::VisiteurSauvegarde() {}

VisiteurSauvegarde::~VisiteurSauvegarde() {}

FormeGeo * VisiteurSauvegarde::visite(Cercle *c) {
	sauvegarde(c);
	return nullptr;
}

FormeGeo * VisiteurSauvegarde::visite(Segment *s) {
	sauvegarde(s);
	return nullptr;
}

FormeGeo * VisiteurSauvegarde::visite(Triangle *t) {
	sauvegarde(t);
	return nullptr;
}

FormeGeo * VisiteurSauvegarde::visite(Polygone *p) {
	sauvegarde(p);
	return nullptr;
}

FormeGeo * VisiteurSauvegarde::visite(Groupe *g) {
	sauvegarde(g);
	return nullptr;
}
