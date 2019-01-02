#include "VisiteurDessin.h"

VisiteurDessin::VisiteurDessin() {}

VisiteurDessin::~VisiteurDessin() {}

FormeGeo * VisiteurDessin::visite(Cercle *c) {
	return nullptr;
}

FormeGeo * VisiteurDessin::visite(Segment *s) {
	return nullptr;
}

FormeGeo * VisiteurDessin::visite(Triangle *t) {
	return nullptr;
}

FormeGeo * VisiteurDessin::visite(Polygone *p) {
	return nullptr;
}

FormeGeo * VisiteurDessin::visite(Groupe *g) {
	return nullptr;
}
