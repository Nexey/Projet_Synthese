package experts;

import java.awt.Polygon;
import java.util.ArrayList;

public class GroupeCOR extends AbstractCOR {
	
	public GroupeCOR() {
		super();
		formesConstruitesCOR.add("groupe");
	}
	
	public GroupeCOR(AbstractCOR next) {
		super(next);
		formesConstruitesCOR.add("groupe");
	}

	@Override
	protected void initFormes(ArrayList<ArrayList<String>> listeFormes) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public boolean construit(ArrayList<ArrayList<String>> listeFormes) {
		// TODO Auto-generated method stub
		return false;
	}

	
	/*
	@Override
	protected void initFormes(ArrayList<String> formeStr) {
		// On réassemble le groupe pour le décortiquer comme je veux
		String formesDuGroupe = "";
		for (int i = 4; i < formeStr.size(); i++) {
			formesDuGroupe += formeStr.get(i);
		}
		
		System.out.println(formesDuGroupe);
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
	}
	*/
}
