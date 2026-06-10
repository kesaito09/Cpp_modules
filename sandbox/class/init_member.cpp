#include <string>
#include <iostream>
using namespace std;

class init_member
{
private:
	int			num1;
	const int	num2;
	const int&		num2_ref;
	
public:
	init_member(): num1(12), num2(42), num2_ref(num2) {};
	void	check_value();
};


void	init_member::check_value(void)
{
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num2_ref << endl;
}


int main(void)
{
	init_member obj;
	obj.check_value();
}
