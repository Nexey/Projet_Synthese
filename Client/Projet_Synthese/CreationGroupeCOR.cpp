#include "CreationGroupeCOR.h"
#include "CreationCercleCOR.h"
#include "CreationSegmentCOR.h"
#include "CreationTriangleCOR.h"
#include "CreationPolygoneCOR.h"
#include "Groupe.h"

CreationGroupeCOR::CreationGroupeCOR(GestionnaireCreation * suivant) : CreationCOR("groupe", suivant) {}

CreationGroupeCOR::~CreationGroupeCOR() {}

FormeGeo * CreationGroupeCOR::construit(const std::vector<std::string>& forme) {
	GestionnaireCreation * expertCreation =
		new CreationCercleCOR(
			new CreationSegmentCOR(
				new CreationTriangleCOR(
					new CreationPolygoneCOR(
						new CreationGroupeCOR
					)
				)
			)
		);
	initCouleur(forme);
	std::vector<FormeGeo*> formesDuGroupe;
	int pos = 4;
	std::string desig;
	std::vector<std::string> * sousForme = new std::vector<std::string>(forme.begin() + pos, forme.end());
	for (int i = 0; i < sousForme->size(); i++)
		if (sousForme->at(i) == "cercle" || sousForme->at(i) == "segment" || sousForme->at(i) == "triangle" || sousForme->at(i) == "polygone" || sousForme->at(i) == "groupe")
			formesDuGroupe.push_back(expertCreation->gerer(std::vector<std::string>(sousForme->begin() + i, sousForme->end())));

	return new Groupe(this->idCouleur, formesDuGroupe);
}
