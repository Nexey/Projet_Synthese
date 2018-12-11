#include "Triangle.h"
#include "Vecteur2D.h"

int main() {
	FormeGeo *pt = new Triangle("test", FormeGeo::BLACK, new Vecteur2D(0, 0));
	Triangle t("oui", FormeGeo::BLUE, new Vecteur2D(1, 5));
	std::cout << *pt << std::endl;

	std::cout << t << std::endl;

	std::cout << *pt->clone() << std::endl;

	std::cout << *t.clone() << std::endl;
	system("pause");
	exit(0);
}