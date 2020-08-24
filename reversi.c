#include <iostream>

#include "header.h"
int shiro(int &a, int b, int tate, int yoko, int (&s)[8][8], int &flag,
          int &num) {
  int i = 0, j = 0, k = 0;       //ループカウンタ
  int sp = 1, np = 0;            //自分用と相手用の印
  int w = 0, black = 0, sk = 0;  //白・黒・空白の数値格納用
  const char *moji[30][30];      //日本語の文字列の格納用
  const char *ishi[30][30];      //日本語の文字列の格納用
  int counter = 0;
  do {
    if (sp > np) {
      w = 1;      //白石判定用
      black = 2;  //黒石判定用
      moji[30][30] = "あなた";
      ishi[30][30] = "白石(●)";
    } else {
      w = 2;      //黒石判定用
      black = 1;  //白石判定用
      moji[30][30] = "相手";
      ishi[30][30] = "黒石(○)";
    }
    if (flag >= 1) {                            //フラグが2以上の時
      std::cout << num << "回目" << std::endl;  //回数表示
      do {
        std::cout << "・" << moji[30][30] << "の番です。" << ishi[30][30]
                  << std::endl;  //テキストを表示
        std::cout << "・スキップする場合は0を入力してください。" << std::endl;
        std::cout << "・終了するときは9を入力してください。" << std::endl;

        std::cout << "・置きたい行(縦)を入力してください：";  //テキストを表示
        std::cin >> a;                                        //数値の入力
        if (a == 0 || a == 9) {
          break;
        }
        if (a > 8 || a < 1) {  //指定外の数値が入力されたら
          std::cout << "・1~8の数字で入力して下さい。"
                    << std::endl;  //テキストを表示
        }
      } while (a > 8 || a < 1);  //指定範囲外の数値が入力されたらループ

      if (a != 0 && a != 9) {
        do {
          std::cout << "・置きたい列(横)を入力してください：";  //テキストを表示
          std::cin >> b;         //数値の入力
          if (b > 8 || b < 1) {  //指定外の数値が入力されたら
            std::cout << "・1~8の数字で入力して下さい。"
                      << std::endl;  //テキストを表示
          }
        } while (b > 8 || b < 1);  //指定範囲外の数値が入力されたらループ
      }
    }
    if (a != 0 && a != 9) {
      //配列の要素に白黒の判別をつける
      if (s[a - 1][b - 1] == sk) {  //入力値のマスが空白なら
        s[a - 1][b - 1] = w;        //白石(判定)を置く
      }
      uesita(a, b, w, black, sk, counter, s);
      flag++;
      num++;
      masume(tate, yoko, s);   //盤面表示
      std::cout << std::endl;  //インデント用改行
    }
    if (sp > np) {
      sp = 0;
      np = 1;
    } else {
      sp = 1;
      np = 0;
    }
    if (a == 9) {
      return s[8][8], flag, num, a;
    }
  } while (flag != 80);
  return 0;
}