#include <iostream>

#include "header.h"

int main(void) {
  int s[8][8]{};      //オセロの石の格納用
  initialization(s);  //配列の要素を初期化
  board(s);           //盤面の表示
  int a = 0;          //行の入力用
  int b = 0;          //列の入力用
  input(a, b, s);     //値の入力
  result(s);          //結果を表示する
  return 0;
}