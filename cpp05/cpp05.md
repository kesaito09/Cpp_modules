割当演算子でガードをつける理由（this != &other）

良い例えとして、文字列を自前で管理するクラスを考えます。

class Str {

 private:

  char* buf_;

 public:

  Str(const char* s) { buf_ = strdup(s); }

  ~Str() { free(buf_); }

  Str& operator=(const Str& other) {

    free(buf_);                    // (1) 自分の持っているバッファを先に解放

    buf_ = strdup(other.buf_);     // (2) コピー元を読んで複製

    return *this;

  }

};

self != &other のチェックがない状態で、自己代入 s = s; をすると何が起きるか追ってみます。

this == &other ということは、this->buf_ と other.buf_ は同じメモリ上の同じ変数を指しています（別々のコピーではなく、文字通り同一のメンバ変数です）。

free(buf_); → s の持っていたバッファを解放。この時点で buf_（＝other.buf_ でもある）はまだ古いアドレスの値を保持したまま（解放しただけで、ポインタ変数自体はまだ書き換わっていない = ダングリングポインタ）。

strdup(other.buf_); → other.buf_ を読む。しかし other.buf_ は this->buf_ と同一の変数なので、さっき free した直後のダングリングポインタを読むことになる。→ use-after-free（解放済みメモリの読み取り）で未定義動作。実際にはクラッシュしたり、壊れたデータが複製されたりします。

ポイントは「解放」と「ポインタの上書き」の間に、もう一度 other 側からデータを読みに行くステップがあることです。this == &other のときは other 側もすでに壊れているので、そこを読みに行った瞬間に事故ります。

Bureaucrat の場合は grade_ が単なる int で、こういう「解放してから読みに行く」ステップが存在しないので、このタイプの事故は起きません。だから実害はほぼない、という話でした。