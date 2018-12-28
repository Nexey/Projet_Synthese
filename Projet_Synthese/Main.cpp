#include "Triangle.h"
#include "Segment.h"
#include "Polygone.h"

int main() {
	FormeGeo *pt = new Triangle("Triangle", FormeGeo::BLACK, Vecteur2D(0, 0), Vecteur2D(0, 4), Vecteur2D(4, 0));
	std::cout << *pt << std::endl;
	std::cout << *pt->clone() << std::endl;

	Polygone p("Polygone", FormeGeo::GREEN);
	p = p + Vecteur2D(5, 6) + Vecteur2D(7, 8) + Vecteur2D(0, 5) + Vecteur2D(0, 4) + Vecteur2D(1, 8);
	std::cout << p << std::endl;
	std::cout << *p.clone() << std::endl;

	FormeGeo *tmp = pt;
	delete tmp;

	pt = new Segment("Segment", FormeGeo::CYAN, Vecteur2D(5, 5), Vecteur2D(0, 0));

	std::cout << *pt << std::endl;
	delete pt;

	system("pause");
	exit(0);
}