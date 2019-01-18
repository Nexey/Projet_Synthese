package experts;

import java.awt.geom.Ellipse2D;
import java.util.ArrayList;

public class CercleCOR extends AbstractCOR {
	
	public CercleCOR() {
		super();
		formesConstruites.add("cercle");
	}
	
	public CercleCOR(AbstractCOR next) {
		super(next);
		formesConstruites.add("cercle");
	}

	@Override
	protected void initForme(ArrayList<String> formeStr) {
		double rayon = Double.parseDouble(formeStr.get(4));

		forme = new Ellipse2D.Double(listeX[0], listeY[0], rayon*2, rayon*2);
	}
	
	/*
	@Override
	public boolean construit(ArrayList<String> forme) {
		super.construit(forme);
		/*
		String titre, couleur;
		double x, y, rayon;
		
		String tmp = forme.get(0);
		// Première lettre du titre en majuscule
		titre = tmp.substring(0, 1).toUpperCase() + tmp.substring(1);
		couleur = forme.get(1);
		// forme.get(2) est le nombre de sommets, on s'en fiche ici
		
		String coords[] = forme.get(3).replaceAll("[()]", "").split(",");
		*/
		/*double rayon = Double.parseDouble(forme.get(4));

		Shape cercle = new Ellipse2D.Double(listeX[0], listeY[0], rayon*2, rayon*2);
		
		this.cadre.dessiner(cercle, titre, couleur);
		return true;
	}*/
	
}
