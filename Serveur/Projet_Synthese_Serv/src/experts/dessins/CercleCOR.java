package experts.dessins;

import java.awt.geom.Ellipse2D;
import java.util.ArrayList;

import dessin.Formes;

public class CercleCOR extends FormeCOR {
	
	public CercleCOR() {
		super();
		formesConstruitesCOR.add("cercle");
	}
	
	public CercleCOR(FormeCOR next) {
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
}
