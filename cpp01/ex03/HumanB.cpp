#include <string>
#include <iostream>
#include "HumanB.hpp"
#include <typeinfo>

void	HumanB::attack(void)
{
	if (!weapon)
		return ;
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

// int main()
// {
// 	Weapon weapon("sord");
// 	HumanB human2("human B");
// 	human2.set_Weapon(weapon);
// 	human2.attack();
// 	weapon.setType("staff");
// 	human2.attack();
// }
