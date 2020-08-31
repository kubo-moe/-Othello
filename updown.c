#include "header.h"
void updown(int a, int b, int white, int black, int space, int counter,
            int (&s)[8][8]) {
  int up = 0, spare = 0, down = 0, reserve = 0;
  counter = 0;
  int i = 0, k = 0, ii = 0, kk = 0;
  do {
    if (counter == 0) {
      up = 0, spare = 1, down = -1, reserve = 0, ii = 1, kk = 1;
    } else if (counter == 1) {
      up = -2, spare = -1, down = -1, reserve = 0, ii = 3, kk = 3;
    } else if (counter == 2) {
      up = -1, down = 0, spare = 0, ii = 1, kk = 1, reserve = 1;
    } else if (counter == 3) {
      up = -1, down = -2, spare = 0, ii = 3, kk = 3, reserve = -1;
    }
    if (s[a + up][b + down] == black) {  //入力値の下マスが相手石なら
      for (i = ii; i < 8; i++)           //ループカウンタ
      {
        if (s[a + up][b + down] == black &&
            s[a + up + spare][b + down + reserve] ==
                space) {  //下が相手石且つその下が空白の時
          break;          //ループを抜ける
        }
        if (s[a + up][b + down] == black &&
            s[a + up + spare][b + down + reserve] ==
                white) {  //下が相手石且つその下が自石なら
          s[a + up][b + down] = white;  //自石(判定)を置く
          break;                        //ループを抜ける
        }
        if (up == -2) {
          if (s[a - i][b - 1] == black &&
              s[a + spare - i][b - 1] ==
                  space) {  // iマス下が相手石且つその下が空白なら
            break;
          }
          if (s[a - i][b - 1] == black &&
              s[a + spare - i][b - 1] ==
                  white) {  // iマス下が相手石且つその下が自石なら
            s[a + up][b - 1] = white;    //自石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - k][b - 1] = white;   //自石(判定)を置く
            }
            break;  //ループを抜ける
          }
        } else if (up == 0) {
          if (s[a + up + i][b - 1] == black &&
              s[a + spare + i][b - 1] ==
                  space) {  // iマス下が相手石且つその下が空白なら
            break;
          }
          if (s[a + i][b - 1] == black &&
              s[a + spare + i][b - 1] ==
                  white) {  // iマス下が相手石且つその下が自石なら
            s[a][b - 1] = white;         //自石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + k][b - 1] = white;   //自石(判定)を置く
            }
            break;  //ループを抜ける
          }
        } else if (up == -1 && down == 0) {
          if (s[a - 1][b + i] == black &&
              s[a - 1][b + i + reserve] ==
                  space) {  // iマス右が相手石且つその右が空白なら
            break;
          }
          if (s[a - 1][b + i] == black &&
              s[a - 1][b + i + reserve] ==
                  white) {  // iマス右が相手石且つその右が自石なら
            s[a - 1][b] = white;         //自石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - 1][b + k] = white;   //自石(判定)を置く
            }
            break;  //ループを抜ける
          }
        } else if (up == -1 && down == -2) {
          if (s[a - 1][b - i] == black &&
              s[a - 1][b - i + reserve] == space) {  //さらにその左隣が空白なら
            break;
          }
          if (s[a - 1][b - i] == black &&
              s[a - 1][b - i + reserve] ==
                  white) {  // iマス左隣が相手石且つその隣が自石なら
            s[a - 1][b + down] = white;  //自石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - 1][b - k] = white;   //自石(判定)を置く
            }
            break;  //ループを抜ける
          }
        }
      }
    }
    counter++;
  } while (counter <= 4);
  diagonal(a, b, white, black, space, counter, s);
}