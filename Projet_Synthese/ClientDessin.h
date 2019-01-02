#pragma once
/*
 * ClientDessin.h
 *
 *  Created on: 26 ao�t 2014
 *      Author: Dominique
 */

#include <WinSock2.h>
#include <string>
#include <string.h>

using namespace std;

class ClientDessin {
	SOCKET sock;  // informations concernant le socket � cr�er : famille d'adresses accept�es, mode connect� ou non, protocole 
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

public:
	ClientDessin(const string & adresseServeurDessin, const int portServeurDessin);
	~ClientDessin();

	void dessin(const string& req);
};


