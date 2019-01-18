package experts;

import java.awt.Polygon;
import java.util.ArrayList;

public class PolygoneCOR extends AbstractCOR {
	
	public PolygoneCOR() {
		super();
		formesConstruitesCOR.add("segment");
		formesConstruitesCOR.add("triangle");
		formesConstruitesCOR.add("polygone");
	}
	
	public PolygoneCOR(AbstractCOR next) {
		super(next);
		formesConstruitesCOR.add("segment");
		formesConstruitesCOR.add("triangle");
		formesConstruitesCOR.add("polygone");
	}

	@Override
	protected void initFormes(ArrayList<ArrayList<String>> listeFormes) {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public boolean construit(ArrayList<ArrayList<String>> listeFormes) {
		// On récupère notre polygone
		ArrayList<String> formeStr = listeFormes.get(0);
		
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
		
		formes.add(new Polygon(this.listeX, this.listeY, nbSommets));

		this.cadre.dessiner(formes, titre, couleur);
		return true;
	}

	/*
	@Override
	protected void initFormes(ArrayList<String> formeStr) {
		// On enlève tous les espaces inutiles
		String ligneCoords = formeStr.get(3).trim();
		String listeCoords[] = ligneCoords.split("-");
		String coordStr[];
		
		for (int i = 0; i < nbSommets; i++) {
			coordStr = listeCoords[i].replaceAll("[()]", "").split(",");
			this.listeX[i] = (Integer.parseInt(coordStr[this.X]));
			this.listeY[i] = (Integer.parseInt(coordStr[this.Y]));
		}
		
		formes.add(new Polygon(this.listeX, this.listeY, nbSommets));
	}*/
}
