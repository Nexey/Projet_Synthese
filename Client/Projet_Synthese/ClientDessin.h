#pragma once
/*
 * ClientDessin.h
 *
 *  Created on: 26 ao�t 2014
 *      Author: Dominique
 */

#include <string>
#include <string.h>
#include "MaWinsock.h"

class ClientDessin {
	SOCKET sock;  // informations concernant le socket � cr�er : famille d'adresses accept�es, mode connect� ou non, protocole 
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

public:
	ClientDessin(const std::string & adresseServeurDessin, const int portServeurDessin);
	~ClientDessin();

	void dessinerForme(const std::string& req) const;
};