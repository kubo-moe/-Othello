#include <iostream>

#include "header.h"

int main(void) {
  int s[8][8]{};                //オセロの石の格納用
  initialization(s);            //配列の要素を初期化
  board(s);                     //盤面の表示
  int a = 0;                    //行の入力用
  int b = 0;                    //列の入力用
  input(a, b);                  //値の入力
  int flag = 0;                 //判定用フラグ
  int num = 1;                  //回数表示用
  reversi(a, b, s, flag, num);  //相手の黒石を反転する
  result(8, 8, s);              //結果を表示する
  return 0;
}