package experts;

import java.util.ArrayList;

import dessin.CadreDessin;

public abstract class AbstractCOR {
	
	protected ArrayList<String> formesConstruites;
	protected CadreDessin cadre;
    public AbstractCOR next;

    public AbstractCOR(AbstractCOR next){
		formesConstruites = new ArrayList<String>();
		this.cadre = new CadreDessin();
    	this.next = next;
    }

    public AbstractCOR() {
		formesConstruites = new ArrayList<String>();
		this.cadre = new CadreDessin();
        this.next = null;
    }

    public boolean peutConstruire(String forme) {
		return formesConstruites.contains(forme);
    }
    public abstract boolean construit(ArrayList<String> forme);


    public boolean generer(ArrayList<String> forme){
        if(peutConstruire(forme.get(0)))
            return construit(forme);

        if(next == null)
            return false;

        return next.generer(forme);
    }

}
