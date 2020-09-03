#include "header.h"
typedef enum {
  Up,     //上方向
  Down,   //下方向
  Left,   //左方向
  Right,  //右方向
} direction;
void decision(int a, int b, int myturn, int opponent, int space, int counter,
              int (&s)[8][8]) {
  int up = 0, side = 0;
  counter = 0;
  int i = 0, k = 0;
  do {
    if (counter == 0) {
      up = 0, side = -1;  //下の判定
    } else if (counter == 1) {
      up = -2, side = -1;  //上の判定
    } else if (counter == 2) {
      up = -1, side = 0;  //右の判定
    } else if (counter == 3) {
      up = -1, side = -2;  //左の判定
    }
    for (i = 1; i < 6; i++)  //ループカウンタ
    {
      if (up == -2) {  //上判定の時
        if (s[a + up][b + side] == opponent &&
            s[a - i][b - 1] == myturn) {  // iマス隣が敵石且つその隣が自石なら
          for (k = 1; k <= i; k++) {   //ループカウンタ
            s[a - k][b - 1] = myturn;  //自石(判定)を置く
          }
        }
      } else if (up == 0) {  //下判定の時
        if (s[a + up][b + side] == opponent &&
            s[a + i][b - 1] == myturn) {  // iマス隣が敵石且つその隣が自石なら
          s[a][b - 1] = myturn;        //自石(判定)を置く
          for (k = 1; k <= i; k++) {   //ループカウンタ
            s[a + k][b - 1] = myturn;  //自石(判定)を置く
          }
        }
      } else if (up == -1 && side == 0) {  //右判定の時
        if (s[a + up][b + side] == opponent &&
            s[a - 1][b + i] == myturn) {  // iマス右が自石且つその隣が空白なら
          s[a - 1][b] = myturn;        //自石(判定)を置く
          for (k = 1; k <= i; k++) {   //ループカウンタ
            s[a - 1][b + k] = myturn;  //自石(判定)を置く
          }
        }
      } else if (up == -1 && side == -2) {  //左判定の時
        if (s[a + up][b + side] == opponent &&
            s[a - 1][b - i] == myturn) {  // iマス左隣が敵石且つその隣が自石なら
          for (k = 1; k <= i; k++) {   //ループカウンタ
            s[a - 1][b - k] = myturn;  //自石(判定)を置く
          }
        }
      }
    }
    counter++;
  } while (counter <= 4);
  diagonal(a, b, myturn, opponent, space, counter, s);  //斜め判定用関数に移動
}