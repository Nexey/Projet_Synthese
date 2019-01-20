package experts;

import java.util.ArrayList;

import dessin.Formes;

//import dessin.CadreDessin;

public abstract class AbstractCOR {
	
	protected int listeX[];
	protected int listeY[];
	protected ArrayList<String> formesConstruitesCOR;
	protected Formes formes;
	//protected CadreDessin cadre;
    public AbstractCOR next;
	String titre, couleur;
	int nbSommets;
    
    protected final int X = 0, Y = 1;
    
    private void initCOR() {
		formesConstruitesCOR = new ArrayList<String>();
		formes = new Formes();
		//this.cadre = new CadreDessin();
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
    
    protected void initTitreCouleur(ArrayList<String> formeStr) {
    	// Mets en place le titre ainsi que la couleur de la forme géographique en récupérant la toute première forme
    	// Attention à ne l'appeler qu'une fois par expert au plus
    	String tmp = formeStr.get(0);
		// Première lettre du titre en majuscule
		titre = tmp.substring(0, 1).toUpperCase() + tmp.substring(1);
		formes.setTitre(titre);
		
		couleur = formeStr.get(1);
		formes.setCouleur(couleur);
    }
    
    protected void initForme(ArrayList<String> formeStr) {
    	// Mets en place les infos de la n-ième forme géographique, peut être appelé plusieurs fois dans un même expert
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
    }
    
    public abstract Formes construit(ArrayList<ArrayList<String>> listeFormes);
    
    public Formes generer(ArrayList<ArrayList<String>> listeFormes){
        if(peutConstruire(listeFormes.get(0).get(0)))
            return construit(listeFormes);

        if(next == null)
            return null;

        return next.generer(listeFormes);
    }
}
