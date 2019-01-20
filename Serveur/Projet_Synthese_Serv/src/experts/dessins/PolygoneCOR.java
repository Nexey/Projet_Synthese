package experts.dessins;

import java.awt.Polygon;
import java.util.ArrayList;

import dessin.Formes;

public class PolygoneCOR extends FormeCOR {
	
	public PolygoneCOR() {
		super();
		formesConstruitesCOR.add("segment");
		formesConstruitesCOR.add("triangle");
		formesConstruitesCOR.add("polygone");
	}
	
	public PolygoneCOR(FormeCOR next) {
		super(next);
		formesConstruitesCOR.add("segment");
		formesConstruitesCOR.add("triangle");
		formesConstruitesCOR.add("polygone");
	}
	
	@Override
	public Formes construit(ArrayList<ArrayList<String>> listeFormes) {
		ArrayList<String> formeStr = listeFormes.get(0);
		
		initTitreCouleur(formeStr);
		initForme(formeStr);
		
		formes.add(new Polygon(this.listeX, this.listeY, nbSommets));
		return formes;
	}
}
