#include "CreationCOR.h"
#include <algorithm>

CreationCOR::CreationCOR(const std::string & forme, GestionnaireCreation * suivant) : designation(forme), suivant(suivant) {}

CreationCOR::~CreationCOR() {}

void CreationCOR::initCouleur(const std::vector<std::string>& forme) {
	std::string couleur = forme.at(1);
	std::transform(couleur.begin(), couleur.end(), couleur.begin(), ::toupper);

	bool trouve = false;
	std::map<int, std::string>::iterator it = FormeGeo::mapCouleurs.begin();
	while (it != FormeGeo::mapCouleurs.end() && !trouve) {
		if (it->second == couleur) {
			this->idCouleur = it->first;
			trouve = true;
		}
		it++;
	}
}

void CreationCOR::initCoords(const std::vector<std::string>& forme) {
	this->coordonnees.clear();

	std::string coords = forme.at(3);
	std::string ligneCoord;
	std::string vecteurCoord;
	std::vector<double> xy;
	
	std::stringstream streamCoords(coords);
	while (std::getline(streamCoords, ligneCoord, '-')) {
		ligneCoord.erase(std::remove_if(ligneCoord.begin(), ligneCoord.end(), [](char chr) { return chr == '(' || chr == ')'; }), ligneCoord.end());
		std::stringstream streamVecteur2D(ligneCoord);
		while (std::getline(streamVecteur2D, vecteurCoord, ','))
			xy.push_back(std::stod(vecteurCoord));
		this->coordonnees.push_back(Vecteur2D(xy.at(0), xy.at(1)));
		xy.clear();
	}
}

bool CreationCOR::peutGerer(const std::string & desig) {
	return this->designation == desig;
}

FormeGeo * CreationCOR::gerer(const std::vector<std::string> & forme) {
	if (peutGerer(forme.at(0)))
		return construit(forme);

	if (suivant != nullptr)
		return suivant->gerer(forme);

	return nullptr;
}
