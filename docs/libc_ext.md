## 規格上記載すべき事項

## 標準C言語で提供される拡張機能
`<math.h>`のうち、次のmacroは処理系定義となっており、互換性の問題から本部品集では実装していない。これらの動作は処理系で提供される定義に依存する。
1. 次の定数macro
~~~C
#define HUGE_VAL_FN
#define HUGE_VAL_DN
#define HUGE_VAL_FNX
#define HUGE_VAL_DNX
#define DEC_INFINITY
#define DEC_NAN

typedef _Float16_t;
typedef _Float32_t;
typedef _Float64_t;
typedef _Float128_t;

~~~

## 標準備品集の独自拡張
C言語の標準化委員会で標準化された場合を想定して、いくつか標準部品集に独自の関数を追加した。
これらは、extc配下に収録されている。
### \<extc/stdlib.h\>
- max, min, swap関数
### \<extc/stdio.h\>
構造体書式指定子 `sformat_t`とそれを使った安全な書式付き入力関数
## その他
1. 連結配列、連想配列、循環配列とその操作
2. 集成体を使わずに各OSのAPIなどを使って、次の関数を作る。引数は指示変数ひとつのみである。
- 実行時に配列の長さを求める関数。実装方法は指示を増分しながら次の関数を繰り返し呼べば良い。
- その領域の状態（未確保か、確保済みか）を返す関数。引数は積み上げ、可変領域どちらを指していてもよい。
  - この関数の実装方法に関する道しるべ
   1. Linuxでは、`/proc/self/maps`や`/proc/self/smaps`を解析すれば状態がわかる。
   2. BSDとDarwinではvmmap commandを解析
   3. Windowsでは、winAPIのVirtualQuery()かVirtualQueryEx()関数を使う。
   4. HaikuOSでは、kernel/OS.hのget_area_info(), get_next_area_info()などの関数を使う。
- その領域が積み上げ領域か可変領域のどちらを指しているか求める関数。領域が未確保の場合は、C23以降の附属書Kで規定されている制約ハンドラ関数を呼び出す。実装方法は得る情報が違うだけで、前の関数と同じ。