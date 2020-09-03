#include "header.h"
void decision(int a, int b, int myturn, int opponent, int space, int counter,
              int (&s)[8][8]) {
  int up = 0, spare = 0, side = 0, reserve = 0;
  counter = 0;
  int i = 0, k = 0, ii = 0;
  do {
    if (counter == 0) {
      up = 0, spare = 1, side = -1, reserve = 0, ii = 1;  //下の判定
    } else if (counter == 1) {
      up = -2, spare = -1, side = -1, reserve = 0, ii = 1;  //上の判定
    } else if (counter == 2) {
      up = -1, side = 0, spare = 0, reserve = 1, ii = 1;  //右の判定
    } else if (counter == 3) {
      up = -1, side = -2, spare = 0, reserve = -1, ii = 1;  //左の判定
    }
    if (s[a + up][b + side] == opponent) {  //入力値の上下左右が敵の石なら
      for (i = ii; i < 8; i++)              //ループカウンタ
      {
        if (up == -2) {  //上判定の時
          if (s[a + spare - i][b - 1] ==
              myturn) {  // iマス隣が敵石且つその隣が自石なら
            s[a + up][b - 1] = myturn;   //自石(判定)を置く
            for (k = 1; k <= i; k++) {   //ループカウンタ
              s[a - k][b - 1] = myturn;  //自石(判定)を置く
            }
          }
        } else if (up == 0) {  //下判定の時
          if (s[a + i][b - 1] == myturn) {  // iマス隣が敵石且つその隣が自石なら
            s[a][b - 1] = myturn;        //自石(判定)を置く
            for (k = 1; k <= i; k++) {   //ループカウンタ
              s[a + k][b - 1] = myturn;  //自石(判定)を置く
            }
          }
        } else if (up == -1 && side == 0) {  //右判定の時
          if (s[a - 1][b + i] == myturn) {  // iマス右が敵石且つその隣が自石なら
            s[a - 1][b] = myturn;        //自石(判定)を置く
            for (k = 1; k <= i; k++) {   //ループカウンタ
              s[a - 1][b + k] = myturn;  //自石(判定)を置く
            }
          }
        } else if (up == -1 && side == -2) {  //左判定の時
          if (s[a - 1][b - i] ==
              myturn) {  // iマス左隣が敵石且つその隣が自石なら
            for (k = 1; k <= i; k++) {   //ループカウンタ
              s[a - 1][b - k] = myturn;  //自石(判定)を置く
            }
          }
        }
      }
    }
    counter++;
  } while (counter <= 4);
  diagonal(a, b, myturn, opponent, space, counter, s);  //斜め判定用関数に移動
}