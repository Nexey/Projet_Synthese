package experts;

import java.awt.Polygon;
import java.util.ArrayList;

public class PolygoneCOR extends AbstractCOR {
	
	public PolygoneCOR() {
		super();
		formesConstruites.add("segment");
		formesConstruites.add("triangle");
		formesConstruites.add("polygone");
	}
	
	public PolygoneCOR(AbstractCOR next) {
		super(next);
		formesConstruites.add("segment");
		formesConstruites.add("triangle");
		formesConstruites.add("polygone");
	}

	@Override
	protected void initForme(ArrayList<String> formeStr) {
		forme = new Polygon(this.listeX, this.listeY, nbSommets);
	}
	
	/*
	@Override
	public boolean construit(ArrayList<String> forme) {
		/*
		String titre, couleur;
		int nbSommets;
		
		String tmp = forme.get(0);
		// Première lettre du titre en majuscule
		titre = tmp.substring(0, 1).toUpperCase() + tmp.substring(1);
		couleur = forme.get(1);
		nbSommets = Integer.parseInt(forme.get(2));
		this.listeX = new int[nbSommets];
		this.listeY = new int[nbSommets];
		
		// On enlève tous les espaces inutiles
		String ligneCoords = forme.get(3).trim();
		String listeCoords[] = ligneCoords.split("-");
		String coordStr[];
		
		for (int i = 0; i < nbSommets; i++) {
			coordStr = listeCoords[i].replaceAll("[()]", "").split(",");
			this.listeX[i] = (Integer.parseInt(coordStr[this.X]));
			this.listeY[i] = (Integer.parseInt(coordStr[this.Y]));
		}
		*//*
		Shape polygon = new Polygon(this.listeX, this.listeY, nbSommets);
		
		this.cadre.dessiner(polygon, titre, couleur);
		return true;
	}*/

}
