#include <iostream>

#include "header.h"
namespace {
int me = 1, you = 0;  //自分用と相手用の印
}
void reversi(int &a, int &b, int (&s)[8][8]) {
  int myturn = 0, opponent = 0, space = 0;  //白・黒・空白の数値格納用
  int counter = 0;                          //カウンター
  if (me > you) {
    myturn = 1;    //自石判定用
    opponent = 2;  //敵石判定用
  } else {
    myturn = 2;    //敵石判定用
    opponent = 1;  //自石判定用
  }
  if (s[a - 1][b - 1] == space) {  //入力値のマスが空白なら
    s[a - 1][b - 1] = myturn;      //持石(判定)を置く
  }
  decision(a, b, myturn, opponent, space, counter,
           s);             //上下左右の判定関数へ移動
  display(s);              //盤面表示
  std::cout << std::endl;  //インデント用改行
  if (me > you) {
    me = 0;  //値を変換する
    you = 1;
  } else {
    me = 1;  //値を変換する
    you = 0;
  }
}