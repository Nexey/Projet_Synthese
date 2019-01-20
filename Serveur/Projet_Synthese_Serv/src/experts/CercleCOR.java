package experts;

import java.awt.geom.Ellipse2D;
import java.util.ArrayList;

import dessin.Formes;

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
	public Formes construit(ArrayList<ArrayList<String>> listeFormes) {
		ArrayList<String> formeStr = listeFormes.get(0);
		
		initTitreCouleur(formeStr);
		initForme(formeStr);
		
		double rayon = Double.parseDouble(formeStr.get(5));
		formes.add(new Ellipse2D.Double(listeX[0], listeY[0], rayon*2, rayon*2));
		return formes;
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
