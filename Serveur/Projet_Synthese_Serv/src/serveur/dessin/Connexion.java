package serveur.dessin;

import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Connexion {
	private ServerSocket serveur = null;
	private Socket client = null;
	private InetAddress adresseLocale = null;
	
	public Connexion() {
		try {
			adresseLocale = InetAddress.getLocalHost();
			int portServeur = 10000;
			// On accepte que 10 clients au plus
			serveur = new ServerSocket(portServeur, 10, adresseLocale);
			
			System.out.println("Serveur démarré : " + serveur);
			
			int noClient = 1;
			while(true) {
				client = serveur.accept();
				System.out.println("Connexion réussie avec le client numéro " + noClient);
				noClient++;
				Receveur receveur = new Receveur(client, noClient);
				receveur.start();
			}
		} catch(Exception e) {
			System.out.println(e.getMessage());
		}
	}
}