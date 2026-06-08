#include <iostream>
using namespace std;

void swap(int& x, int& y)
{
	int tmp = x;

	x = y;
	y = tmp;
}

int main(void)
{
	int x = 2;
	int y = 4;

	swap(x, y);
	cout << x << y << endl;	
}

// int main(void)
// {		
// 	int a = 10;
// 	int b = a;
// 	int& ref = 	a;

// 	cout << a << b << ref << endl;
// 	cout << &a << endl << &b << endl << &ref << endl;
// }
