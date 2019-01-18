package experts;

public class PolygoneCOR extends AbstractCOR {
	
	public PolygoneCOR() {
		super();
		formesConstruites.add("segment");
		formesConstruites.add("triangle");
		formesConstruites.add("polygone");
	}
	
	public PolygoneCOR(AbstractCOR next) {
		super(next);
		formesConstruites.add("segment");
		formesConstruites.add("triangle");
		formesConstruites.add("polygone");
	}

	@Override
	public boolean construit() {
		// TODO Auto-generated method stub
		return true;
	}

}
