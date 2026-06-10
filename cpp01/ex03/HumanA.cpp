#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

// int main()
// {
// 	Weapon weapon = Weapon("sord");
// 	HumanA human1("human A", weapon);
// 	human1.attack();
// 	weapon.setType("staff");
// 	human1.attack();
// }