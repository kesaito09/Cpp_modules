#include <iostream>
#include <bitset>
#include <climits>

// 補数表現を「実際に見る」ための観察用プログラム。
// 同じビット列を「符号あり int」と「符号なし unsigned」の
// 両方の目で見ると、補数表現の正体がわかる。

void show(int x)
{
	// reinterpret: 同じ32bitを符号なしとして読み直す
	unsigned int u = static_cast<unsigned int>(x);

	std::cout << "signed = " << x
			  << "\tunsigned = " << u
			  << "\tbits = " << std::bitset<32>(u)
			  << std::endl;
}

int main(void)
{
	std::cout << "=== 0 のまわり ===" << std::endl;
	show(2);
	show(1);
	show(0);
	show(-1);   // 全bitが1になるはず
	show(-2);

	std::cout << "\n=== 端っこ ===" << std::endl;
	show(INT_MAX);       // 0111...1
	show(INT_MIN);       // 1000...0
	show(INT_MIN + 1);

	std::cout << "\n=== -x は ~x + 1 と同じか? ===" << std::endl;
	int x = 42;
	std::cout << " x   = " << std::bitset<32>(static_cast<unsigned int>(x)) << std::endl;
	std::cout << "~x   = " << std::bitset<32>(static_cast<unsigned int>(~x)) << std::endl;
	std::cout << "~x+1 = " << std::bitset<32>(static_cast<unsigned int>(~x + 1)) << std::endl;
	std::cout << "-x   = " << std::bitset<32>(static_cast<unsigned int>(-x)) << std::endl;

	return 0;
}
