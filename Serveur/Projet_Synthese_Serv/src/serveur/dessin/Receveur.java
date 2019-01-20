package serveur.dessin;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.ArrayList;

import dessin.CadreDessin;
import experts.*;

public class Receveur extends Thread {
	private Socket client;
	private BufferedReader in;
	AbstractCOR expert;
	CadreDessin cadre;

	public Receveur(Socket client) throws IOException {
		// On récupère le client ainsi que son Buffer
		this.client = client;
		in = new BufferedReader(new InputStreamReader(this.client.getInputStream()));
		
		// Initialisation de la chaîne de responsabilités
		expert = 
				new CercleCOR(
						new PolygoneCOR(
								new GroupeCOR()
								)
						);
		cadre = new CadreDessin();
	}
	
	private void expert(String requete) {
		// Opérations sur la requête :
		
		// On dégage toutes les accolades et tous les espaces
		String tmp = requete.replaceAll("[{}\\[\\] \t]", "");
		tmp = tmp.trim();
		
		// On stocke à des cellules différentes les différentes données
		String categories[] = tmp.split(";");
		
		// Les sous catégories sont du style : "ID : CERCLE"
		String sousCategories[];

		// L'arraylist suivant contiendra une seule forme
		ArrayList<String> forme = new ArrayList<String>();
		
		// L'arraylist suivant contiendra les forme finales, duh
		ArrayList<ArrayList<String>> listeFormes = new ArrayList<ArrayList<String>>();
		
		String sousCategStr;
		for (int i = 0; i < categories.length; i++) {
			sousCategStr = categories[i].toLowerCase();
			sousCategories = sousCategStr.split(":");
			
			if (sousCategories[0].equals("id"))
				if (forme.size() > 0) {
					listeFormes.add(new ArrayList<String>(forme));
					forme.clear();
				}
			
			forme.add(sousCategories[1]);
		}
		listeFormes.add(new ArrayList<String>(forme));
		forme.clear();
		
		
		cadre.dessiner(expert.generer(listeFormes));
	}
	
	public void run() {
		// La requête contiendra la chaîne de caractères renvoyée par le client
		String requete = "";
		
		// Ce caractère sert de buffer à concaténer au String. Ou alors c'est le String qui sert
		// de Buffer auquel on concatène le caractère. C'est l'idée générale
		char read = ' ';
		try {
			while (!this.isInterrupted()) {
				// On cast le buffer en char, car on reçoit des Bytes en int
				read = (char)in.read();
				
				// Je concatène le caractère à mon String
				requete += read;
				
				// Si j'atteins le caractère de fin, je passe aux experts la chaîne finie
				if (read == '}') {
					expert(requete);
					
					// Je réinitialise la ligne de requête et je peux ré-écouter
					requete = "";
				}
			}
		} catch (Exception e) {}
	}
}