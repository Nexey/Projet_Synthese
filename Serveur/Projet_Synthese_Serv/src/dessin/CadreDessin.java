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
        tabCouleurs = new HashMap<String, Color>();
        tabCouleurs.put("black", Color.BLACK);
        tabCouleurs.put("blue", Color.BLUE);
        tabCouleurs.put("red", Color.RED);
        tabCouleurs.put("green", Color.GREEN);
        tabCouleurs.put("yellow", Color.YELLOW);
        tabCouleurs.put("cyan", Color.CYAN);
	}
	
	public void dessiner(Formes formes) {
		System.setProperty("sun.awt.noerasebackground", "true");
		try {
			JFrame f = new JFrame();
	        f.setTitle(formes.getTitre());
	        f.setSize(512, 512);
	        
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
		    
		    Color coul = this.tabCouleurs.get(formes.getCouleur());
		    graphics.setColor(coul);
		    
		    for (Shape forme : formes.getListeFormes())
		    	graphics.draw(forme);
		    strategie.show();
		    
		    graphics.dispose();
	        
		} catch (InterruptedException e) {}
	}
}
