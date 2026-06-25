// 前置 ++ / 後置 ++ の挙動を「自分の目で」確認する検証コード
//
//   c++ -Wall -Wextra -Werror -std=c++98 verify.cpp -o verify && ./verify
//
// 確認したいこと:
//   1) 式の戻り値: 前置=増えた後 / 後置=増える前
//   2) for の第3節: 戻り値を捨てる → pre/post で差が出ない
//   3) while の条件 / 添字: 戻り値を使う → pre/post で差が出る
//   4) 自作クラス: 後置は「古い自分のコピー」を作る（コピーが見える）

#include <iostream>

// ---------------------------------------------------------------------------
// 1) 式としての戻り値の違い
// ---------------------------------------------------------------------------
static void expr_value()
{
	std::cout << "=== 1) 式の戻り値 ===" << std::endl;

	int i = 5;
	int a = ++i;  // 前置: i=6, a も 6（増えた後）
	std::cout << "++i: i=" << i << " a=" << a << "  (a は増えた後の値)" << std::endl;

	int j = 5;
	int b = j++;  // 後置: j=6, b は 5（増える前）
	std::cout << "j++: j=" << j << " b=" << b << "  (b は増える前の値)" << std::endl;
	std::cout << std::endl;
}

// ---------------------------------------------------------------------------
// 2) for の第3節: 戻り値を捨てる → 差が出ない
// ---------------------------------------------------------------------------
static void for_clause()
{
	std::cout << "=== 2) for 第3節（戻り値を捨てる）===" << std::endl;

	std::cout << "i++: ";
	for (int i = 0; i < 4; i++)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "++i: ";
	for (int i = 0; i < 4; ++i)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << "→ 同じ系列。初期値の調整も不要" << std::endl << std::endl;
}

// ---------------------------------------------------------------------------
// 3) while の条件 / 添字: 戻り値を使う → 差が出る
// ---------------------------------------------------------------------------
static void condition_and_index()
{
	std::cout << "=== 3) while 条件（戻り値を使う）===" << std::endl;
	const int ac = 3;

	int count_post = 0;
	int i = 1;
	while (i++ < ac)  // 古い i で比較
		count_post++;
	std::cout << "while (i++ < ac): ループ " << count_post << " 回" << std::endl;

	int count_pre = 0;
	int k = 1;
	while (++k < ac)  // 新しい k で比較
		count_pre++;
	std::cout << "while (++k < ac): ループ " << count_pre << " 回" << std::endl;
	std::cout << "→ 回数が違う。前置で揃えたいなら初期値をずらす辻褄合わせが要る" << std::endl;

	std::cout << "--- 添字でも同じ ---" << std::endl;
	const char *s = "ABCD";
	int p = 0;
	std::cout << "s[p++] 1回目: " << s[p++] << "  (古い 0 を使う → 'A')" << std::endl;
	int q = 0;
	std::cout << "s[++q] 1回目: " << s[++q] << "  (新しい 1 を使う → 'B')" << std::endl;
	std::cout << std::endl;
}

// ---------------------------------------------------------------------------
// 4) 自作クラス: 後置のコピーを「見える化」する
//    コピーコンストラクタにログを仕込むと、後置で1回呼ばれるのが分かる
// ---------------------------------------------------------------------------
class Counter
{
	int _value;

public:
	Counter(int v) : _value(v) {}

	// コピーコンストラクタにログ（後置でここが呼ばれるか観察する）
	Counter(const Counter &other) : _value(other._value)
	{
		std::cout << "    [copy ctor 呼ばれた] value=" << _value << std::endl;
	}

	// 前置: ++a  → 参照を返す。コピーなし
	Counter &operator++()
	{
		++this->_value;
		return *this;
	}

	// 後置: a++  → 古い自分をコピーして退避し、それを値で返す
	Counter operator++(int)
	{
		Counter old = *this;  // ← ここでコピーが起きる
		++(*this);            // 前置を呼ぶ（DRY）
		return old;
	}

	int value() const { return _value; }
};

static void class_copy()
{
	std::cout << "=== 4) 自作クラスのコピー観察 ===" << std::endl;

	std::cout << "前置 ++a:" << std::endl;
	Counter a(10);
	++a;  // copy ctor は呼ばれないはず
	std::cout << "  a.value()=" << a.value() << "  (copy ログ無し)" << std::endl;

	std::cout << "後置 b++:" << std::endl;
	Counter b(10);
	b++;  // copy ctor が呼ばれるはず（old の退避）
	std::cout << "  b.value()=" << b.value() << "  (上に copy ログが出たはず)" << std::endl;
}

int main()
{
	expr_value();
	for_clause();
	condition_and_index();
	class_copy();
	return 0;
}
