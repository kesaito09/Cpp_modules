
#include "Harl.hpp"

int main(void)
{
	Harl obj1 = Harl();
	Harl obj2 = Harl();

	obj1.complain("DEBUG");
	obj2.complain("WARNING");
	obj2.complain("ERROR");
	obj2.complain("INFO");
}
