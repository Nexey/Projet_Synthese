package serveur;

import java.io.IOException;
import java.net.ServerSocket;

import serveur.dessin.Connexion;

public class Serveur {
	
	static void testPorts() {
		for(int port = 1; port <= 65535; port++){
			try {
				ServerSocket sSocket = new ServerSocket(port);
				sSocket.close();
			} catch (IOException e) {
				System.err.println("Le port " + port + " est déjà utilisé ! ");
			}
		}
	}

	public static void main(String[] args) {
		//testPorts();
        Connexion c = new Connexion();
	}
}