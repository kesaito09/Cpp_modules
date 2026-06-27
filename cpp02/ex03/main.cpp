#include "Point.hpp"
#include <iostream>
bool bsp(Point const a, Point const b, Point const c, Point const point);


int main(void) {
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(3.0f, 5.0f);
	Point inpoint(2.0f, 1.0f);
	Point outpoint1(2.0f, 6.0f);
	Point onp2(3.0f, 5.0f);
	Point onedge(2.5f, 0.0f);
	Point outpoint2(-1.0f, -1.0f);
	Point inpoint2(3.0f, 4.0f);

	std::cout << bsp(a, b, c, inpoint) << "\n";
	std::cout << bsp(a, c, b ,inpoint) << "\n";
	std::cout << bsp(c, a, b ,inpoint) << "\n";
	std::cout << bsp(c, b, a ,inpoint) << "\n";
	std::cout << bsp(a, b, c, outpoint1) << "\n";
	std::cout << bsp(a, b, c, onp2) << "\n";
	std::cout << bsp(a, b, c, onedge) << "\n";
	std::cout << bsp(a, b, c, outpoint2) << "\n";
	std::cout << bsp(a, b, c, inpoint2) << "\n";
}
