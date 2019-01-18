package experts;

import java.awt.Shape;
import java.util.ArrayList;

import dessin.CadreDessin;

public abstract class AbstractCOR {
	
	protected int listeX[];
	protected int listeY[];
	protected ArrayList<String> formesConstruitesCOR;
	protected ArrayList<Shape> formes;
	protected CadreDessin cadre;
    public AbstractCOR next;
	String titre, couleur;
	int nbSommets;
    
    protected final int X = 0, Y = 1;
    
    private void initCOR() {
		formesConstruitesCOR = new ArrayList<String>();
		formes = new ArrayList<Shape>();
		this.cadre = new CadreDessin();
    }

    public AbstractCOR(AbstractCOR next) {
    	initCOR();
    	this.next = next;
    }
    
    public AbstractCOR() {
    	initCOR();
        this.next = null;
    }

    public boolean peutConstruire(String forme) {
		return formesConstruitesCOR.contains(forme);
    }
    
    protected abstract void initFormes(ArrayList<ArrayList<String>> listeFormes);
    
    public abstract boolean construit(ArrayList<ArrayList<String>> listeFormes); /*{
		String tmp = formeStr.get(0);
		// Première lettre du titre en majuscule
		titre = tmp.substring(0, 1).toUpperCase() + tmp.substring(1);
		couleur = formeStr.get(1);
		nbSommets = Integer.parseInt(formeStr.get(2));
		this.listeX = new int[nbSommets];
		this.listeY = new int[nbSommets];
		
		initFormes(formeStr);

		this.cadre.dessiner(formes, titre, couleur);
		return true;
    }*/
    
    public boolean generer(ArrayList<ArrayList<String>> listeFormes){
        if(peutConstruire(listeFormes.get(0).get(0)))
            return construit(listeFormes);

        if(next == null)
            return false;

        return next.generer(listeFormes);
    }

}
