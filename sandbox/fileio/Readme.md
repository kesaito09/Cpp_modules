# ストリームの仕組み

## 演算子オーバーロード

演算子に対して左辺や右辺が特定のデータ型の振る舞いを定義できる

<< >> はビットシフト演算子だが、演算子オーバーロードによって、cout, cin の挙動を定義してる。

<< の場合左辺がostream, cout で右辺が文字列や数値の場合の定義をしているという仕組み。





ostream& endl(ostream& os)   // os は cout の「別名(参照)」

{

    os.put('\n');

    os.flush();

    return os;               // 受け取った cout をそのまま返す

}

ここでostreamを返さないと連続する cout << "hello" << endl;のendlの前にcoutがないと、endlが動かないので、必ずostreamを返す。

ostream& operator<<(ostream& os, const SomeType& value)\
coutもこのように定義されることにより連続するcout << "" << "" << endl;に対応できる。





