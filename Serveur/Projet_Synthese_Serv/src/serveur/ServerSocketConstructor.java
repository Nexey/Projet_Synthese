package serveur;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class ServerSocketConstructor {
	
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
		
		InetAddress adresseLocale = null ;
		try {
			adresseLocale = InetAddress.getLocalHost();
			System.out.println("L'adresse locale est : " + adresseLocale ); 
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
		
		ServerSocket socketServeur = null;
		Socket socketDuServeur;
		PrintWriter out;
		
		try {
			socketServeur = new ServerSocket(10000, 5, adresseLocale);
			socketDuServeur = socketServeur.accept();
			out = new PrintWriter(socketDuServeur.getOutputStream());
			System.out.println(out);
			out.flush();
			
			socketDuServeur.close();
			socketServeur.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}