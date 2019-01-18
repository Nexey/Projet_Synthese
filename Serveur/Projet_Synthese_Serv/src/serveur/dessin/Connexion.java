package serveur.dessin;

import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Connexion {
	private ServerSocket serveur = null;
	private Socket client = null;
	private String adresseLocale = "127.0.0.16";
	
	public Connexion() {
		try {
			// Initialisation des paramètres du serveur
			int portServeur = 10000;
			int nbClient = 10;
			
			// On accepte que 10 clients au plus
			serveur = new ServerSocket(portServeur, nbClient, InetAddress.getByName(adresseLocale));
			System.out.println("Serveur démarré : " + serveur);
		} catch(Exception e) {
			System.out.println(e.getMessage());
		}
	}
	
	public void run() {
		try {
			// La méthode suivante bloque le programme en attendant notre client
			client = serveur.accept();
			
			// Peut servir pour plus tard, je sais pas
			client.setKeepAlive(true);
			
			System.out.println("Connexion réussie");
			Receveur receveur = new Receveur(client);
			receveur.start();
			
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
}