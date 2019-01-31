#pragma once
#include "GestionnaireCreation.h"
#include "Vecteur2D.h"

class CreationCOR :
	public GestionnaireCreation {
	GestionnaireCreation * suivant;
protected:
	std::string designation;
	std::vector<Vecteur2D> coordonnees;
	int idCouleur;
public:
	CreationCOR(const std::string & designation, GestionnaireCreation * suivant = NULL);
	virtual ~CreationCOR();

	virtual FormeGeo * construit(const std::vector<std::string> & forme) = 0;

	void initCouleur(const std::vector<std::string>& forme);
	void initCoords(const std::vector<std::string>& forme);
	bool peutGerer(const std::string & designation);
	FormeGeo * gerer(const std::vector<std::string> & forme);
};

