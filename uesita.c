#include "header.h"
int uesita(int a, int b, int w, int black, int sk, int counter,
           int (&s)[8][8]) {
  int us = 0, nus = 0;
  int i = 0, k = 0;
  int ii = 0, kk = 0;
  do {
    if (counter == 0) {
      us = 0;
      nus = 1;
      ii = 1;
      kk = 1;
    } else {
      us = -2;
      nus = -1;
      ii = 3;
      kk = 3;
    }
    if (s[a + us][b - 1] == black) {  //入力値の下マスが黒なら
      for (i = ii; i < 8; i++)        //ループカウンタ
      {
        if (s[a + us][b - 1] == black &&
            s[a + us + nus][b - 1] == sk) {  //下が黒且つその下が空白の時
          break;                             //ループを抜ける
        }
        if (s[a + us][b - 1] == black &&
            s[a + us + nus][b - 1] == w) {  //下が黒且つその下が白なら
          s[a + us][b - 1] = w;             //白石(判定)を置く
          break;                            //ループを抜ける
        }
        if (us == -2) {
          if (s[a - i][b - 1] == black &&
              s[a + nus - i][b - 1] == sk) {  // iマス下が黒且つその下が空白なら
            break;
          }
          if (s[a - i][b - 1] == black &&
              s[a + nus - i][b - 1] == w) {  // iマス下が黒且つその下が白なら
            s[a + us][b - 1] = w;        //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - k][b - 1] = w;       //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        } else {
          if (s[a + us + i][b - 1] == black &&
              s[a + nus + i][b - 1] == sk) {  // iマス下が黒且つその下が空白なら
            break;
          }
          if (s[a + i][b - 1] == black &&
              s[a + nus + i][b - 1] == w) {  // iマス下が黒且つその下が白なら
            s[a][b - 1] = w;                 //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + k][b - 1] = w;       //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        }
      }
    }
    counter++;
  } while (counter <= 1);
  yoko(a, b, w, black, sk, counter, s);
  return s[8][8];
}