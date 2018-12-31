#include "SauvegardeTexte.h"

SauvegardeTexte::SauvegardeTexte() {}


SauvegardeTexte::~SauvegardeTexte() {}

const void SauvegardeTexte::sauvegarde(const FormeGeo *f) const {
	std::cout << *f << std::endl;
}
