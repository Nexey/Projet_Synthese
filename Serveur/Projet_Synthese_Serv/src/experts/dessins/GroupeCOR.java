package experts.dessins;

import java.util.ArrayList;

import dessin.Formes;

public class GroupeCOR extends FormeCOR {
	
	public GroupeCOR() {
		super();
		formesConstruitesCOR.add("groupe");
	}
	
	public GroupeCOR(FormeCOR next) {
		super(next);
		formesConstruitesCOR.add("groupe");
	}

	@Override
	public Formes construit(ArrayList<ArrayList<String>> listeFormes) {
		// listeFormes.get(0) est l'arrayList du Groupe
		ArrayList<String> formeStr = listeFormes.get(0);
		
		FormeCOR expert;

		expert = 
				new CercleCOR(
						new PolygoneCOR(
								new GroupeCOR()
								)
						);
		ArrayList<ArrayList<String>> formesTmp = new ArrayList<ArrayList<String>>();
		for (int i = 1; i < listeFormes.size(); i++) {
			formesTmp.add(listeFormes.get(i));
			formes.getListeFormes().addAll(expert.generer(formesTmp).getListeFormes());
			formesTmp.clear();
		}
		
		initTitreCouleur(formeStr);
		return formes;
	}
}
