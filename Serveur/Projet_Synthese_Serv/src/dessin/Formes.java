package dessin;

import java.awt.Shape;
import java.util.ArrayList;

public class Formes {
	String titre, couleur;
	ArrayList<Shape> listeFormes;
	
	public Formes() {
		this.titre = "";
		this.couleur = "";
		this.listeFormes = new ArrayList<Shape>();
	}
	
	public String getTitre() {
		return titre;
	}

	public void setTitre(String titre) {
		this.titre = titre;
	}

	public String getCouleur() {
		return couleur;
	}

	public void setCouleur(String couleur) {
		this.couleur = couleur;
	}

	public ArrayList<Shape> getListeFormes() {
		return listeFormes;
	}
	
	public void add(Shape s) {
		listeFormes.add(s);
	}
}
