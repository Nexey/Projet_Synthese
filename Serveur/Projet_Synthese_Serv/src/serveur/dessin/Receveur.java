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
		
	}
	
	private void expert(String requete) {
		// Op�rations sur la requ�te :
		
		// On d�gage toutes les accolades et tous les espaces
		String tmp = requete.replaceAll("[{}\t ]", "");
		
		// On stocke � des cellules diff�rentes les diff�rentes donn�es
		String categories[] = tmp.split(";");
		
		// Les sous cat�gories sont du style : "ID : CERCLE"
		String sousCategories[];
		
		// L'arraylist suivant contiendra la forme finale, duh
		ArrayList<String> formeFinale = new ArrayList<String>();
		
		for(String var : categories) {
			// Op�ration sur la variable : je mets tout en minuscule
			var = var.toLowerCase();
			
			// Je r�cup�re les deux diff�rentes cat�gories dans le tableau de sous-cat�gories
			sousCategories = var.split(":");
			
			// Je r�cup�re seulement la deuxi�me partie, celle qui m'int�resse
			formeFinale.add(sousCategories[1]);
		}
		
		// DEBUG
		// System.out.println(formeFinale);
		
		// DEBUG
		if (expert.generer(formeFinale.get(0))) System.out.println("La forme peut �tre g�n�r�e");
		else System.out.println("Ntm");
		
		
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
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
}