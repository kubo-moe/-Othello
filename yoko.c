#include "header.h"
int yoko(int a, int b, int w, int black, int sk, int counter, int (&s)[8][8]) {
  int yk = 0, nyk = 0;
  int i = 0, k = 0;
  int ii = 0, kk = 0;
  counter = 0;
  do {
    if (counter == 0) {
      yk = 0;
      nyk = 1;
      ii = 1;
      kk = 1;
    } else {
      yk = -2;
      nyk = -1;
      ii = 3;
      kk = 3;
    }
    if (s[a - 1][b + yk] == black) {  //入力値の右隣が黒なら
      for (i = ii; i < 8; i++) {      //ループカウンタ
        if (s[a - 1][b + yk] == black &&
            s[a - 1][b + yk + nyk] == sk) {  //右が黒且つその右が空白なら
          break;                             //ループを抜ける
        }
        if (s[a - 1][b + yk] == black &&
            s[a - 1][b + yk + nyk] == w) {  //右が黒且つその右が白なら
          s[a - 1][b + yk] = w;             //白石(判定)を置く
          break;                            //ループを抜ける
        }
        if (yk == 0) {
          if (s[a - 1][b + i] == black &&
              s[a - 1][b + i + nyk] == sk) {  // iマス右が黒且つその右が空白なら
            break;
          }
          if (s[a - 1][b + i] == black &&
              s[a - 1][b + i + nyk] == w) {  // iマス右が黒且つその右が白なら
            s[a - 1][b + yk] = w;        //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - 1][b + k] = w;       //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        } else {
          if (s[a - 1][b - i] == black &&
              s[a - 1][b - i + nyk] == sk) {  //さらにその左隣が空白なら
            break;
          }
          if (s[a - 1][b - i] == black &&
              s[a - 1][b - i + nyk] == w) {  //さらにその左隣が黒なら
            s[a - 1][b + yk] = w;            //白石(判定)を置く
            for (k = kk; k <= i; k++) {      //ループカウンタ
              s[a - 1][b - k] = w;           //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        }
      }
    }
    counter++;
  } while (counter <= 2);
  migiue(a, b, w, black, sk, counter, s);
  return s[8][8];
}