#include "SauvegardeTexte.h"
#include <fstream>

SauvegardeTexte::SauvegardeTexte() {}


SauvegardeTexte::~SauvegardeTexte() {}

const void SauvegardeTexte::sauvegarde(const FormeGeo *f) const {
	std::fstream output;
	output.open(("formes.txt"), std::fstream::app);
	output << *f << std::endl;
	output.close();
}
