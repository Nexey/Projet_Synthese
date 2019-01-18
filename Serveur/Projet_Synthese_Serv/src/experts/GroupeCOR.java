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
	protected void initForme(ArrayList<String> formeStr) {
		// TODO Auto-generated method stub
		
	}

}
