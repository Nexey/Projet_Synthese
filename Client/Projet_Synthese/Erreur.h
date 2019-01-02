#pragma once
/**
classe Erreur
*/
using namespace std;

#include <string>
#include <iostream>

class Erreur {
public:
	const static int LONGUEURMESSAGE = 500;
	char message[1 + LONGUEURMESSAGE];
	Erreur();
	Erreur(const char * messageErreur);

	virtual ~Erreur();
	operator string() const;
};

ostream & operator << (ostream & os, const Erreur & erreur);