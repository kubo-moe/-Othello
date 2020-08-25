#include "header.h"
void updown(int a, int b, int white, int black, int sk, int counter,
            int (&s)[8][8]) {
  int tate = 0, nus = 0, yoko = 0, nyk = 0, yk = 0;
  int i = 0, k = 0;
  int ii = 0, kk = 0;
  do {
    if (counter == 0) {
      tate = 0, nus = 1, yoko = -1, nyk = 0, ii = 1, kk = 1;
    } else if (counter == 1) {
      tate = -2, nus = -1, yoko = -1, nyk = 0, ii = 3, kk = 3;
    } else if (counter == 2) {
      tate = -1, yoko = 0, nus = 0, ii = 1, kk = 1, nyk = 1, yk = 1;
    } else if (counter == 3) {
      tate = -1, yoko = -2, nus = 0, ii = 3, kk = 3, nyk = -1, yk = -1;
    }
    if (s[a + tate][b + yoko] == black) {  //入力値の下マスが黒なら
      for (i = ii; i < 8; i++)             //ループカウンタ
      {
        if (s[a + tate][b + yoko] == black &&
            s[a + tate + nus][b + yoko + nyk] ==
                sk) {  //下が黒且つその下が空白の時
          break;       //ループを抜ける
        }
        if (s[a + tate][b + yoko] == black &&
            s[a + tate + nus][b + yoko + nyk] ==
                white) {                  //下が黒且つその下が白なら
          s[a + tate][b + yoko] = white;  //白石(判定)を置く
          break;                          //ループを抜ける
        }
        if (tate == -2) {
          if (s[a - i][b - 1] == black &&
              s[a + nus - i][b - 1] == sk) {  // iマス下が黒且つその下が空白なら
            break;
          }
          if (s[a - i][b - 1] == black &&
              s[a + nus - i][b - 1] ==
                  white) {  // iマス下が黒且つその下が白なら
            s[a + tate][b - 1] = white;  //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - k][b - 1] = white;   //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        } else if (tate == 0) {
          if (s[a + tate + i][b - 1] == black &&
              s[a + nus + i][b - 1] == sk) {  // iマス下が黒且つその下が空白なら
            break;
          }
          if (s[a + i][b - 1] == black &&
              s[a + nus + i][b - 1] ==
                  white) {        // iマス下が黒且つその下が白なら
            s[a][b - 1] = white;  //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + k][b - 1] = white;   //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        } else if (tate == -1 && yoko == 0) {
          if (s[a - 1][b + i] == black &&
              s[a - 1][b + i + nyk] == sk) {  // iマス右が黒且つその右が空白なら
            break;
          }
          if (s[a - 1][b + i] == black &&
              s[a - 1][b + i + nyk] ==
                  white) {        // iマス右が黒且つその右が白なら
            s[a - 1][b] = white;  //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - 1][b + k] = white;   //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        } else if (tate == -1 && yoko == -2) {
          if (s[a - 1][b - i] == black &&
              s[a - 1][b - i + nyk] == sk) {  //さらにその左隣が空白なら
            break;
          }
          if (s[a - 1][b - i] == black &&
              s[a - 1][b - i + nyk] == white) {  //さらにその左隣が黒なら
            s[a - 1][b + yoko] = white;          //白石(判定)を置く
            for (k = kk; k <= i; k++) {          //ループカウンタ
              s[a - 1][b - k] = white;           //白石(判定)を置く
            }
            break;  //ループを抜ける
          }
        }
      }
    }
    counter++;
  } while (counter <= 4);
  diagonal(a, b, white, black, sk, counter, s);
}