#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie
{
private:
	std::string name;
public:
	~Zombie();
	void	set(std::string name);
	void	announce(void);
};

#endif
