package experts;

public class CercleCOR extends AbstractCOR {
	
	public CercleCOR() {
		super();
		formesConstruites.add("cercle");
	}
	
	public CercleCOR(AbstractCOR next) {
		super(next);
		formesConstruites.add("cercle");
	}
	
	@Override
	public boolean construit() {
		// TODO Auto-generated method stub
		return true;
	}

}
