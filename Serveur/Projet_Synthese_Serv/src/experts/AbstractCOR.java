package experts;

import java.util.ArrayList;

public abstract class AbstractCOR {
	
	protected ArrayList<String> formesConstruites;

    public AbstractCOR next;

    public AbstractCOR(AbstractCOR next){
		formesConstruites = new ArrayList<String>();
    	this.next = next;
    }

    public AbstractCOR() {
		formesConstruites = new ArrayList<String>();
        this.next = null;
    }

    public boolean peutConstruire(String forme) {
		return formesConstruites.contains(forme);
    }
    public abstract boolean construit(/*World world, int x, int y*/);


    public boolean generer(String forme/*World world, int elementType, int x, int y*/){
        if(peutConstruire(forme))
            return construit();

        if(next == null)
            return false;

        return next.generer(forme);
    }

}
