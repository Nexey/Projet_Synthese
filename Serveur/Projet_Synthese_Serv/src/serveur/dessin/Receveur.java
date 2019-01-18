package serveur.dessin;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.ArrayList;

import experts.*;

public class Receveur extends Thread {
	private Socket client;
	private BufferedReader in;
	AbstractCOR expert;

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
		
	}
	
	private void expert(String requete) {
		// Opérations sur la requête :
		
		// On dégage toutes les accolades et tous les espaces
		String tmp = requete.replaceAll("[{}\t ]", "");
		
		// On stocke à des cellules différentes les différentes données
		String categories[] = tmp.split(";");
		
		// Les sous catégories sont du style : "ID : CERCLE"
		String sousCategories[];
		
		// L'arraylist suivant contiendra la forme finale, duh
		ArrayList<String> formeFinale = new ArrayList<String>();
		
		for(String var : categories) {
			// Opération sur la variable : je mets tout en minuscule
			var = var.toLowerCase();
			
			// Je récupère les deux différentes catégories dans le tableau de sous-catégories
			sousCategories = var.split(":");
			
			// Je récupère seulement la deuxième partie, celle qui m'intéresse
			formeFinale.add(sousCategories[1]);
		}
		
		// DEBUG
		// System.out.println(formeFinale);
		
		// DEBUG
		if (expert.generer(formeFinale.get(0))) System.out.println("La forme peut être générée");
		else System.out.println("Ntm");
		
		
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
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
}