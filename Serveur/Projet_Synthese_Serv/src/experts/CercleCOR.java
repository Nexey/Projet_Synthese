package experts;

import java.awt.geom.Ellipse2D;
import java.util.ArrayList;

public class CercleCOR extends AbstractCOR {
	
	public CercleCOR() {
		super();
		formesConstruitesCOR.add("cercle");
	}
	
	public CercleCOR(AbstractCOR next) {
		super(next);
		formesConstruitesCOR.add("cercle");
	}

	@Override
	protected void initFormes(ArrayList<ArrayList<String>> listeFormes) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public boolean construit(ArrayList<ArrayList<String>> listeFormes) {
		// On récupère notre cercle
		ArrayList<String> formeStr = listeFormes.get(0);
		
		String tmp = formeStr.get(0);
		// Première lettre du titre en majuscule
		titre = tmp.substring(0, 1).toUpperCase() + tmp.substring(1);
		couleur = formeStr.get(1);
		nbSommets = Integer.parseInt(formeStr.get(2));
		this.listeX = new int[nbSommets];
		this.listeY = new int[nbSommets];

		String coordStr[] = formeStr.get(3).trim().replaceAll("[()]", "").split(",");
		this.listeX[0] = (Integer.parseInt(coordStr[this.X]));
		this.listeY[0] = (Integer.parseInt(coordStr[this.Y]));
		
		double rayon = Double.parseDouble(formeStr.get(4));
		formes.add(new Ellipse2D.Double(listeX[0], listeY[0], rayon*2, rayon*2));

		this.cadre.dessiner(formes, titre, couleur);
		return true;
	}

	
	/*
	@Override
	protected void initFormes(ArrayList<String> formeStr) {
		// On enlève tous les espaces inutiles
		//String ligneCoords = formeStr.get(3).trim();
		//String listeCoords[] = ligneCoords.split("-");
		String coordStr[];
		
		//coordStr = listeCoords[0].replaceAll("[()]", "").split(",");
		coordStr = formeStr.get(3).trim().replaceAll("[()]", "").split(",");
		this.listeX[0] = (Integer.parseInt(coordStr[this.X]));
		this.listeY[0] = (Integer.parseInt(coordStr[this.Y]));
		
		double rayon = Double.parseDouble(formeStr.get(4));
		formes.add(new Ellipse2D.Double(listeX[0], listeY[0], rayon*2, rayon*2));
	}
	*/
}
