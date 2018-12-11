#include "Triangle.h"
#include "Vecteur2D.h"

int main() {

	Triangle t("test", FormeGeo::BLACK, new Vecteur2D(0, 0));

	std::cout << t;

	system("pause");
	exit(0);
}