#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // 同じ「ss >> 変数」という書き方で、型に応じて変換が変わる
    // stringstream s1("42");    int    i; s1 >> i;
    // stringstream s2("3.14");  double d; s2 >> d;
    // stringstream s3("99999"); long   l; s3 >> l;
    // stringstream s4("A");     char   c; s4 >> c;

	stringstream	stream;
	int				i;
	stream = "hello";
	stream >> i;
	cout << i;
    // cout << "int:    " << i << endl;
    // cout << "double: " << d << endl;
    // cout << "long:   " << l << endl;
    // cout << "char:   " << c << endl;
	cout << "**ストリームの本質は「入出力」ではなく「テキストと型付きデータの相互変換」**";
    cout << "\n→ Cなら atoi/atof/atol… と別関数が必要だった" << endl;
    return 0;
}