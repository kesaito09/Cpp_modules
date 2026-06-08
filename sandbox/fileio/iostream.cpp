#include <iostream>
#include <fstream>
using namespace std;


struct point
{
	int	x;
	int	y;
};

ostream& operator<<(ostream& os, const point& p)
{
	os << p.x << ", " << p.y;
	return os;
}


int main(void)
{
	point	p;
	//ファイルストリームのインスタンス作成とコンストラクタでファイルをopen
	ofstream f("point.txt");

	p.x = 2;
	p.y = 81;

	cout << p;


	f << "fstream!!"<< p << endl;
	f.close();
	return 0;
	
}

