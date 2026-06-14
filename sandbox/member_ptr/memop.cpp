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

	mem_ptr obj1 = mem_ptr();
	obj1.age = 42;
	obj1.weight = 4242;
	cout << obj1.*pa << endl; //メンバー変数へのポインタが指すオフセットの値を取得してる
	cout << obj1.age << endl;
	pa = &mem_ptr::weight; //paのoffsetをweightにする
	cout << obj1.*pa << endl;
	
	return 0;
}

/*
		[.*]という演算子は
		[left] [.*] [right]という構文
		leftはインスタンスでrightはメンバのオフセット
		インスタンスのメンバのオフセットを指定してメンバ変数にアクセスするという構文
 
*/