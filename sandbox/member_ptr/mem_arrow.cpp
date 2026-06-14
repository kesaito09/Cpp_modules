#include <string>
#include <iostream>
using namespace std;

class mem_ptr
{
public:
	int id; //4
	int age; // offset = 8 
	int height; 
	int weight;
};

int main(void){
	int mem_ptr::*pa = &mem_ptr::age; // paにはoffset　8を入れてる。アドレスではない

	mem_ptr* obj1 = new mem_ptr();
	mem_ptr* obj2 = new mem_ptr();

	obj1->age = 42;
	obj1->weight = 4242;
	obj2->age = 24;
	obj2->weight = 2424;
	cout << obj1->*pa << endl; //メンバー変数へのポインタが指すオフセットの値を取得してる
	cout << obj1->age << endl;
	cout << "[obj2 offset]" << obj2->*pa << endl; // クラスメンバのオフセットだから別インスタンスでも使える
	pa = &mem_ptr::weight; //paのoffsetをweightにする
	cout << obj1->*pa << endl;
	cout << "[obj2 offset]" << obj2->*pa << endl;
	delete obj1;
	delete obj2;
	return 0;
}

/*
	[->*]も演算子の意味としては[.*]と同じだけど、
	構造体のアクセスと同じでポインタの場合は、[->]でオブジェクトの実体にアクセスしてオフセットを適用してるだけ
*/