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
		// On r�cup�re le client ainsi que son Buffer
		this.client = client;
		in = new BufferedReader(new InputStreamReader(this.client.getInputStream()));
		
		// Initialisation de la cha�ne de responsabilit�s
		expert = 
				new CercleCOR(
						new PolygoneCOR(
								new GroupeCOR()
								)
						);
		cadre = new CadreDessin();
	}
	
	private void expert(String requete) {
		// Op�rations sur la requ�te :
		
		// On d�gage toutes les accolades et tous les espaces
		String tmp = requete.replaceAll("[{}\\[\\] \t]", "");
		tmp = tmp.trim();
		
		// On stocke � des cellules diff�rentes les diff�rentes donn�es
		String categories[] = tmp.split(";");
		
		// Les sous cat�gories sont du style : "ID : CERCLE"
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
		// La requ�te contiendra la cha�ne de caract�res renvoy�e par le client
		String requete = "";
		
		// Ce caract�re sert de buffer � concat�ner au String. Ou alors c'est le String qui sert
		// de Buffer auquel on concat�ne le caract�re. C'est l'id�e g�n�rale
		char read = ' ';
		try {
			while (!this.isInterrupted()) {
				// On cast le buffer en char, car on re�oit des Bytes en int
				read = (char)in.read();
				
				// Je concat�ne le caract�re � mon String
				requete += read;
				
				// Si j'atteins le caract�re de fin, je passe aux experts la cha�ne finie
				if (read == '}') {
					expert(requete);
					
					// Je r�initialise la ligne de requ�te et je peux r�-�couter
					requete = "";
				}
			}
		} catch (Exception e) {}
	}
}