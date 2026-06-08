#include <iostream>
#include <string>
#include <cctype>


int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		std::string s = av[i];
		for (int j = 0; j < (int)s.size(); j++)
			s[j] = std::toupper(s[j]);
		std::cout << s;
	}
	std:: cout << std::endl;
	return 0;
}

/*

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *


*/

// int main(void)
// {
// 	std::string s;

// 	std::cin >> s;
// 	std::cout << s;
// 	return (0);
// }
