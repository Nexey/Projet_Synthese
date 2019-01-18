package serveur;

import java.io.IOException;
import java.net.ServerSocket;

import serveur.dessin.Connexion;

public class Serveur {
	
	static void testPorts() {
		// M�thode permettant de sniffer tous les ports et dire ceux qui sont occup�s
		for(int port = 1; port <= 65535; port++){
			try {
				ServerSocket sSocket = new ServerSocket(port);
				sSocket.close();
			} catch (IOException e) {
				System.err.println("Le port " + port + " est d�j� utilis� ! ");
			}
		}
	}

	public static void main(String[] args) {
        Connexion c = new Connexion();
        c.run();
	}
}