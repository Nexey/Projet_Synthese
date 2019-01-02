package serveur.dessin;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Receveur extends Thread {
	private BufferedReader in;
	int noClient;
	
	public Receveur(Socket client, int noClient) throws IOException {
		in = new BufferedReader(new InputStreamReader(client.getInputStream()));
		this.noClient = noClient;
	}
	
	private void expert(String requete) {
		System.out.println("Forme " + requete + " reçue");
	}
	public void run() {
		String ligne;
		String requete = "";
		try {
			//while(!this.isInterrupted()) {
				//String requete = in.readLine();
				while ((ligne = in.readLine()) != null)
					requete += ligne;
				expert(requete);
			//}
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
}