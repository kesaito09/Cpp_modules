#include <iostream>
#include <bitset>
#include <cstring>

// float (IEEE 754 単精度) のビットを「実際に見る」プログラム。
//
// 32bit の内訳:
//   [31]      符号 (sign)     1bit
//   [30..23]  指数 (exponent) 8bit   ※ bias 127 のゲタばき
//   [22..0]   仮数 (mantissa) 23bit  ※ 先頭の "1." は省略 (ケチ表現)
//
// 値 = (-1)^sign * 1.mantissa * 2^(exponent - 127)

void show(float f)
{
	// 同じ32bitを「整数として」読み直すための型変換。
	// (float の中身を直接 unsigned で見る = reinterpret)
	unsigned int bits;
	std::memcpy(&bits, &f, sizeof(bits));

	std::bitset<32> b(bits);
	std::string s = b.to_string();

	std::cout << f << "\n  raw  = " << s << "\n";
	std::cout << "  sign = " << s.substr(0, 1)
			  << "  exp = " << s.substr(1, 8)
			  << "  mant = " << s.substr(9, 23) << "\n";

	// 指数を10進で。bias 127 を引くと本当の指数。
	int exp = std::bitset<8>(s.substr(1, 8)).to_ulong();
	std::cout << "  exp(raw)=" << exp
			  << "  exp(real)=" << exp - 127 << "\n\n";
}

int main(void)
{
	std::cout << "=== 基本 ===" << std::endl;
	show(1.0f);    // exp=127(0), mant=0 → 1.0 * 2^0
	show(2.0f);    // exp=128(1)         → 1.0 * 2^1
	show(3.0f);    // exp=128(1)         → 1.0 * 2^1
	show(4.0f);    // exp=128(1)         → 1.0 * 2^1
	show(8.0f);    // exp=128(1)         → 1.0 * 2^1
	show(0.5f);    // exp=126(-1)        → 1.0 * 2^-1
	show(-1.0f);   // sign=1

	std::cout << "=== 課題でおなじみ ===" << std::endl;
	show(42.0f);
	show(42.42f);  // 2進で割り切れない → 仮数が中途半端なビット列

	std::cout << "=== 特殊な値 ===" << std::endl;
	show(0.0f);    // 全部0
	show(0.1f);    // 10進0.1は2進で循環小数 → 丸め誤差の正体

	return 0;
}
