package sockets;

import java.io.IOException;
import java.net.ServerSocket;

public class ServerSocketConstructor {

   public static void main(String[] args) {

      for(int port = 1; port <= 65535; port++){
         try {
            ServerSocket sSocket = new ServerSocket(port);
            sSocket.close();
         } catch (IOException e) {
            System.err.println("Le port " + port + " est déjà utilisé ! ");
         }
      }
   }
}