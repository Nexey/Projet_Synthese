#include "Triangle.h"
#include "Segment.h"
#include "Vecteur2D.h"

int main() {
	FormeGeo *pt = new Triangle("Triangle", FormeGeo::BLACK, Vecteur2D(0, 0), Vecteur2D(0, 4), Vecteur2D(4, 0));
	Triangle t("Triangle", FormeGeo::BLUE, Vecteur2D(1, 5), Vecteur2D(3, 6), Vecteur2D(5, 8));
	std::cout << *pt << std::endl;

	//std::cout << t << std::endl;

	//std::cout << *pt->clone() << std::endl;

	FormeGeo *tmp = pt;
	delete tmp;

	pt = new Segment("Segment", FormeGeo::CYAN, Vecteur2D(5, 5), Vecteur2D(0, 0));

	std::cout << *pt << std::endl;

	delete pt;

	//std::cout << *t.clone() << std::endl;
	system("pause");
	exit(0);
}