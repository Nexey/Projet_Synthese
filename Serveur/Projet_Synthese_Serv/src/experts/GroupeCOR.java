package experts;

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
	public boolean construit() {
		// TODO Auto-generated method stub
		return true;
	}

}
