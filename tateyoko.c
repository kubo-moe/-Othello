//#include "header.h"
int uesita(int a, int b, int w, int black, int sk, int counter,
           int (&s)[8][8]) {
  int us = 0, nus = 0, mu = 0, nyk = 0, yk = 0;
  int i = 0, k = 0;
  int ii = 0, kk = 0;
  do {
    if (counter == 0) {
      us = 0, nus = 1, mu = -1, nyk = 0, ii = 1, kk = 1;
    } else if (counter == 1) {
      us = -2, nus = -1, mu = -1, nyk = 0, ii = 3, kk = 3;
    } else if (counter == 2) {
      us = -1, mu = 0, nus = 0, ii = 1, kk = 1, nyk = 1, yk = 1;
    } else if (counter == 3) {
      us = -1, mu = -2, nus = 0, ii = 3, kk = 3, nyk = -1, yk = -1;
    }
    if (s[a + us][b + mu] == black) {  //入力値の下マスが黒なら
      for (i = ii; i < 8; i++)         //ループカウンタ
      {
        if (s[a + us][b + mu] == black &&
            s[a + us + nus][b + mu + nyk] == sk) {  //下が黒且つその下が空白の時
          break;                                    //ループを抜ける
        }
        if (s[a + us][b + mu] == black &&
            s[a + us + nus][b + mu + nyk] == w) {  //下が黒且つその下が白なら
          s[a + us][b + mu] = w;                   //白石(判定)を置く
          break;                                   //ループを抜ける
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
        } else if (us == 0) {
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
        } else if (us == -1 && mu == 0) {
          if (s[a - 1][b + i] == black &&
              s[a - 1][b + i + nyk] == sk) {  // iマス右が黒且つその右が空白なら
            break;
          }
          if (s[a - 1][b + i] == black &&
              s[a - 1][b + i + nyk] == w) {  // iマス右が黒且つその右が白なら
            s[a - 1][b] = w;                 //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - 1][b + k] = w;       //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        } else if (us == -1 && mu == -2) {
          if (s[a - 1][b - i] == black &&
              s[a - 1][b - i + nyk] == sk) {  //さらにその左隣が空白なら
            break;
          }
          if (s[a - 1][b - i] == black &&
              s[a - 1][b - i + nyk] == w) {  //さらにその左隣が黒なら
            s[a - 1][b + mu] = w;            //白石(判定)を置く
            for (k = kk; k <= i; k++) {      //ループカウンタ
              s[a - 1][b - k] = w;           //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        }
      }
    }
    counter++;
  } while (counter <= 4);
  // yoko(a, b, w, black, sk, counter, s);
  return s[8][8];
}