#include "VisiteurDessin.h"

VisiteurDessin::VisiteurDessin() {
	client = new ClientDessin("127.0.0.16", 10000);
}

VisiteurDessin::~VisiteurDessin() {}

FormeGeo * VisiteurDessin::visite(Cercle *c) {
	dessinerForme(c);
	return nullptr;
}

FormeGeo * VisiteurDessin::visite(Segment *s) {
	dessinerForme(s);
	return nullptr;
}

FormeGeo * VisiteurDessin::visite(Triangle *t) {
	dessinerForme(t);
	return nullptr;
}

FormeGeo * VisiteurDessin::visite(Polygone *p) {
	dessinerForme(p);
	return nullptr;
}

FormeGeo * VisiteurDessin::visite(Groupe *g) {
	dessinerForme(g);
	return nullptr;
}

void VisiteurDessin::dessinerForme(FormeGeo *f) const {
	client->dessinerForme(*f);
}