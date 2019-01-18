package experts;

import java.awt.Shape;
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
	public boolean construit(ArrayList<String> forme) {
		String titre, couleur;
		double x, y, rayon;
		titre = forme.get(0);
		couleur = forme.get(1);
		// forme.get(2) est le nombre de sommets, on s'en fiche ici
		
		String coords[] = forme.get(3).replaceAll("[()]", "").split(",");
		
		x = Double.parseDouble(coords[0]);
		y = Double.parseDouble(coords[1]);
		rayon = Double.parseDouble(forme.get(4));

		Shape cercle = new Ellipse2D.Double(x, y, rayon*2, rayon*2);
		
		this.cadre.dessiner(cercle, titre, couleur);
		return true;
	}

}
