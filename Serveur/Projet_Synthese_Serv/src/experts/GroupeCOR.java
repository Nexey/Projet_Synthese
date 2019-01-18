package experts;

import java.util.ArrayList;

public class GroupeCOR extends AbstractCOR {
	
	public GroupeCOR() {
		super();
		formesConstruites.add("groupe");
	}
	
	public GroupeCOR(AbstractCOR next) {
		super(next);
		formesConstruites.add("groupe");
	}

	@Override
	public boolean construit(ArrayList<String> forme) {
		// TODO Auto-generated method stub
		return true;
	}

}
