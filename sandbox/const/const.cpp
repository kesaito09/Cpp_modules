#include <iostream>
using namespace std;




int main(void)
{
	int num1= 42;
	int num1= 42;
	//[*] の左にconstがある->ポインタがconstになる
	const int *a = &num1;
	int const *b = &num1;

	// [*]の右にconstがある->ポインタ変数がconstになる
	int *const c = &num1;

	//[*]の左と右にconstがある->ポインタもポインタ変数もconstになる
	int const * const d = &num1;

	
	
	
	
}


