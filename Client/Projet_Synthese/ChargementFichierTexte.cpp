#include "ChargementFichierTexte.h"
#include "CreationCercleCOR.h"
#include "CreationTriangleCOR.h"
#include "CreationSegmentCOR.h"
#include "CreationPolygoneCOR.h"
#include "CreationGroupeCOR.h"
#include <algorithm>
#include <fstream>

ChargementFichierTexte::ChargementFichierTexte(GestionnaireChargement * suivant) : ChargementFichier("txt", suivant) {}

ChargementFichierTexte::~ChargementFichierTexte() {}

std::vector<FormeGeo*> ChargementFichierTexte::construit(const std::string & chemin) {
	std::vector<FormeGeo*> * formes = new std::vector<FormeGeo*>();

	std::ifstream input;
	input.open(chemin, std::ifstream::in);
	std::string formesStr(
		(std::istreambuf_iterator<char>(input)),
		(std::istreambuf_iterator<char>()));
	// Toutes les formes sont maintenant chargées dans un seul string
	// Il faut stocker chaque forme dans un vector<string> et créer les experts capables de les créer
	std::vector<std::string> vectorUneFormeStr;

	// On arrive à l'explosion du string en différentes catégories

	// Une forme est stockée sur une ligne
	std::string ligne;

	// Une ligne possède plusieurs catégories
	std::string categorie;

	// Ce stream va permettre de récupérer les formes lignes par ligne
	std::stringstream streamToutesFormesStr(formesStr);

	// Mise en place des experts
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

	while (std::getline(streamToutesFormesStr, ligne)) {
		// J'efface tous les caractères superflus et je mets tout en minuscule
		ligne.erase(std::remove_if(ligne.begin(), ligne.end(), [](char chr) { return chr == ' ' || chr == '}' || chr == '{' || chr == '[' || chr == ']'; }), ligne.end());
		std::transform(ligne.begin(), ligne.end(), ligne.begin(), ::tolower);

		if (ligne != "") {
			// Ce stream va récupérer les différentes catégories et les ajouter au vector<string>
			std::stringstream streamUneFormeStr(ligne);
			while (std::getline(streamUneFormeStr, categorie, ';'))
				// J'ai donc récupéré une catégorie, je dois maintenant récupérer la partie droite, celle qui m'intéresse
				vectorUneFormeStr.push_back(categorie.substr(categorie.find(':') +1));
			formes->push_back(expertCreation->gerer(vectorUneFormeStr));
			vectorUneFormeStr.clear();
		}
	}

	return *formes;
}
