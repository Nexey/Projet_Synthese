package dessin;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics2D;
import java.awt.GraphicsConfiguration;
import java.awt.Shape;
import java.awt.image.BufferStrategy;
import java.util.HashMap;
import java.util.Map;

import javax.swing.JFrame;

public class CadreDessin extends Canvas {
	private static final long serialVersionUID = 1L;
	
	Map<String, Color> tabCouleurs;

	public CadreDessin() {
		super();
        this.setPreferredSize(new Dimension(512, 512));
        tabCouleurs = new HashMap<String, Color>();
        tabCouleurs.put("black", Color.BLACK);
        tabCouleurs.put("blue", Color.BLUE);
        tabCouleurs.put("red", Color.RED);
        tabCouleurs.put("green", Color.GREEN);
        tabCouleurs.put("yellow", Color.YELLOW);
        tabCouleurs.put("cyan", Color.CYAN);
	}
	
	public CadreDessin(GraphicsConfiguration config) {
		super(config);
		this.setPreferredSize(new Dimension(512, 512));
	}
	
	public void dessiner(Shape forme, String titre, String couleur) {
		System.setProperty("sun.awt.noerasebackground", "true");
		try {
			JFrame f = new JFrame();
	        f.setTitle(titre);
	        f.setSize(512, 512);
	        
	        //f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	        
	        f.setIgnoreRepaint(true);	// désactive l'appel automatique de la fct paint(...) par repaint()
	        
		    int numBuffers = 1;
	        f.createBufferStrategy(numBuffers);  // crée une stratégie de tampon d'image à 1 tampon vidéo
		    Thread.sleep(150);     
		    
	        f.setVisible(true);
	        
	        CadreDessin canvas = new CadreDessin();
	        canvas.setIgnoreRepaint(true);
	        f.add(canvas);
	        
	        canvas.createBufferStrategy(numBuffers);
	        canvas.setVisible(true);
	        Thread.sleep(150);
	        
			BufferStrategy strategie = canvas.getBufferStrategy();
		    Graphics2D graphics = (Graphics2D) strategie.getDrawGraphics();
		    
		    Color coul = this.tabCouleurs.get(couleur);
		    graphics.setColor(coul);
		    graphics.draw(forme);
		    strategie.show();
		    
		    graphics.dispose();
	        
		} catch (InterruptedException e) {}
	}
	
	/*
	public static void main(String[] args) {
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		/*
		try {
		    Frame f1AR;
		    f1AR = new Frame(" Frame tout simple en Active Rendering");
		    f1AR.setBounds(30, 60, 400, 400);       // coordonnées en dur : très maladroit
		    
		    f1AR.setVisible(true);              // rend le frame visible sur l'écran
		    f1AR.setIgnoreRepaint(true);        // désactive l'appel automatique de la fct paint(...) par repaint()
		    
		    
		    int numBuffers = 2;
		    f1AR.createBufferStrategy(numBuffers);  // crée une stratégie de tampon d'image à 1 tampon vidéo
		    Thread.sleep(150);                       // au moins 150 ms !!!! pour laisser au système le temps de créer le buffer d'image
		    
			BufferStrategy strategie = f1AR.getBufferStrategy();
		    Graphics graphics = strategie.getDrawGraphics();        
		    // le graphics sert à dessiner sur le tampon
		    
		    
		    graphics.drawLine(30, 30, 100, 100);    // dessine sur le tampon vidéo. coordonnées en dur : très maladroit
		    graphics.drawLine(30, 100, 100, 30);    // dessine sur le tampon vidéo
		        
		    strategie.show();       // place le tampon sur l'écran : la technique utilisée dépend du type de stratégie utilisé : blitting, pointeur vidéo, etc.
		    
		    graphics.dispose();
	    } catch (InterruptedException e) {}*/
}
