package experts;

import java.awt.Shape;
import java.util.ArrayList;

import dessin.CadreDessin;

public abstract class AbstractCOR {
	
	protected int listeX[];
	protected int listeY[];
	protected ArrayList<String> formesConstruites;
	protected CadreDessin cadre;
    public AbstractCOR next;
	String titre, couleur;
	int nbSommets;
	Shape forme;
    
    protected final int X = 0, Y = 1;

    public AbstractCOR(AbstractCOR next){
		formesConstruites = new ArrayList<String>();
		this.cadre = new CadreDessin();
    	this.next = next;
    }

    public AbstractCOR() {
		formesConstruites = new ArrayList<String>();
		this.cadre = new CadreDessin();
        this.next = null;
    }

    public boolean peutConstruire(String forme) {
		return formesConstruites.contains(forme);
    }
    
    protected abstract void initForme(ArrayList<String> formeStr);
    
    public boolean construit(ArrayList<String> formeStr) {
		String tmp = formeStr.get(0);
		// Première lettre du titre en majuscule
		titre = tmp.substring(0, 1).toUpperCase() + tmp.substring(1);
		couleur = formeStr.get(1);
		nbSommets = Integer.parseInt(formeStr.get(2));
		this.listeX = new int[nbSommets];
		this.listeY = new int[nbSommets];
		
		// On enlève tous les espaces inutiles
		String ligneCoords = formeStr.get(3).trim();
		String listeCoords[] = ligneCoords.split("-");
		String coordStr[];
		
		for (int i = 0; i < nbSommets; i++) {
			coordStr = listeCoords[i].replaceAll("[()]", "").split(",");
			this.listeX[i] = (Integer.parseInt(coordStr[this.X]));
			this.listeY[i] = (Integer.parseInt(coordStr[this.Y]));
		}
		
		initForme(formeStr);

		this.cadre.dessiner(forme, titre, couleur);
		return true;
    }
    
    public boolean generer(ArrayList<String> forme){
        if(peutConstruire(forme.get(0)))
            return construit(forme);

        if(next == null)
            return false;

        return next.generer(forme);
    }

}
