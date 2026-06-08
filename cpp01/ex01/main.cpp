#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
	int N = 2;

	Zombie* zombies = zombieHorde(N, "batakaha");
	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return 0;
}
