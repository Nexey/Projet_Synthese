#include "Triangle.h"
#include "Segment.h"
#include "Polygone.h"
#include "Groupe.h"

#include <Windows.h> // Pour les accents dans la console sous Windows
int main() {
	SetConsoleOutputCP(1252); // Pour les accents dans la console sous Windows
	FormeGeo *pt = new Triangle(FormeGeo::BLACK, Vecteur2D(0, 0), Vecteur2D(0, 4), Vecteur2D(4, 0));
	std::cout << *pt << std::endl;
	std::cout << *pt->clone() << std::endl;

	Polygone p(FormeGeo::GREEN);
	p = p + Vecteur2D(5, 6) + Vecteur2D(7, 8) + Vecteur2D(0, 5) + Vecteur2D(0, 4) + Vecteur2D(1, 8);
	std::cout << p << std::endl;
	//std::cout << *p.clone() << std::endl;

	FormeGeo *tmp = pt;
	pt = new Segment(FormeGeo::CYAN, Vecteur2D(5, 5), Vecteur2D(0, 0));
	std::cout << *pt << std::endl;

	Groupe g1(FormeGeo::BLUE);
	g1 = g1 + p + *pt + Triangle(FormeGeo::CYAN, Vecteur2D(0, 0), Vecteur2D(0, 4), Vecteur2D(4, 0));
	std::cout << g1 << std::endl;
	//std::cout << *g1.clone() << std::endl;

	g1.translation(Vecteur2D(1, 1));
	std::cout << g1 << std::endl;
	

	system("pause");
	//delete tmp;
	delete pt;
	exit(0);
}