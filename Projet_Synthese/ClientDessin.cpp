/*
 * ClientDessin.cpp
 *
 *  Created on: 26 août 2014
 *      Author: Dominique
 */
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <string.h>
#include <string>
#include <sstream>
#include "Erreur.h"
#include "MaWinsock.h"
#include "ClientDessin.h"

using namespace std;

/**
 * crée un client TCP/IP vers un serveur de dessin
 *
 * protocole : Chaque requête est codée sous forme d'une seule String se terminant par le caractère fin de ligne.
 * Sur la ligne, 2 paramètres consécutifs sont séparés par ", ".
 *
 * */

ClientDessin::ClientDessin(const string & adresseServeurDessin, const int portServeurDessin) {
	MaWinsock::getInstance();	// initialisation de la DLL : effectuée une seule fois

	//---------------------- création socket -------------------------------------------------

	int r;

	int familleAdresses = AF_INET;         // IPv4
	int typeSocket = SOCK_STREAM;           // mode connecté TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
											// pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

	sock = socket(familleAdresses, typeSocket, protocole);

	if (sock == INVALID_SOCKET) {
		ostringstream oss;
		oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
		throw Erreur(oss.str().c_str());
	}

	cout << "socket de dessin créé" << endl;

	//------------------------------ création du représentant du serveur ----------------------------------------

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(adresseServeurDessin.c_str());   // inet_addr() convertit de l'ASCII en entier
	sockaddr.sin_port = htons((short)portServeurDessin);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

	//-------------- connexion du client au serveur ---------------------------------------

	r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
																	// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
	
	if (r == SOCKET_ERROR)
		throw Erreur("La connexion au serveur de dessin a échoué");

	cout << "connexion au serveur de dessin réussie" << endl;
}

ClientDessin::~ClientDessin() {
	int r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
														// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

	if (r == SOCKET_ERROR)
		std::cerr << "la coupure de connexion a échoué";

	r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
	if (r) std::cerr << "La fermeture du socket a échoué";

	cout << "arrêt normal du client" << endl;
}

void ClientDessin::dessin(const string & req) {
	int r = send(sock, req.c_str(), req.length(), 0);             //------------------ envoi de la requête au serveur -------------------------------

	if (r == SOCKET_ERROR)
		throw Erreur("échec de l'envoi de la requête");

	cout << "requête envoyée" << endl;
}