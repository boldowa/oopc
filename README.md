# OOP design pattern on C language
This is the sample project about OOP design pattern for C.

This design pattern provides the following features.
- Encapsulate
- Inherit
- Polymorphism ( Override )
- Interface

## Sample files
### src/pack/TestModule.c
Main sample
Test source: tests/pack/TestModuleTest.cpp

### src/pack/TestChild.c
Inherit sample
Test source: tests/pack/TestChildTest.cpp

## Note
This project was created for CppUTest.

---

# C 言語によるOOPデザインパターン
これは、C言語でのOOP(オブジェクト指向プラグラミング)のサンプルプロジェクトです。

このデザインパターンは、以下の機能を提供します。
- カプセル化
- 継承
- ポリモーフィズム ( オーバーライド )
- インターフェイス

## サンプルファイル
### src/pack/TestModule.c
メインのサンプル
テストコード : tests/pack/TestModuleTest.cpp

### src/pack/TestChild.c
継承のサンプル
テストコード : tests/pack/TestChildTest.cpp

## 備考
このプロジェクトはCppUTest向けに作成されています。

## その他
これを書いた人は、C++でプログラムを作成する際に、実行バイナリサイズが大きくなったり、
依存するライブラリ(DLL)が増えたりするのが嫌いで、未だにC言語を使用しています。
そんなものが気にならないのであれば、他のオブジェクト指向に対応したプログラミング言語に
移行したほうがよっぽど賢明であると思います。

これに似たデザインパターンは他にもあるように思いますが、良いサンプルが見つからなかったので、
理解も兼ねて自分で書いてみることにしました。

このデザインパターンのサンプルは、私のようにDLL依存や実行後バイナリサイズを気にする方や、
環境上のやむを得ない理由によりC言語を使わざるを得ないような方には有益であるように思います。

