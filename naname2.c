int migishita(int a, int b, int w, int black, int sk, int counter,
              int (&s)[8][8]) {
  int mu = 0, hs = 0, ma = 0;
  int i = 0, j = 0, k = 0;
  int ii = 0, jj = 0, kk = 0;
  counter = 0;
  do {
    if (counter == 0) {
      mu = 0, hs = 1;
      ii = 1, jj = 1, kk = 1;
    } else {
      mu = -2, hs = -3, ma = -1;
      ii = 3, jj = 3, kk = 3;
    }
    if (s[a + mu][b + mu] == black) {  //入力値の斜め右下が黒なら
      j = jj;                          //列用のカウンタ
      for (i = ii; i < 8; i++) {       //ループカウンタ
        if (s[a + mu][b + mu] == black &&
            s[a + hs][b + hs] == sk) {  //右下が黒且つその右上が空白なら
          break;
        }
        if (s[a + mu][b + mu] == black &&
            s[a + hs][b + hs] == w) {  //右下が黒且つその右上が白なら
          s[a + mu][b + mu] = w;       //白石(判定)を置く
          break;                       //ループを抜ける
        }
        if (mu == 0) {
          if (s[a + i][b + j] == black &&
              s[a + i + hs][b + j + hs] ==
                  sk) {  // iマス右下が黒且つその右下が空白なら
            break;
          }
          if (s[a + i][b + j] == black &&
              s[a + i + hs][b + j + hs] ==
                  w) {  // iマス右下が黒且つその右下が白なら
            j = 1;      //列用のカウンタ
            s[a + mu][b + mu] = w;       //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + k][b + j] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = 1;
            break;  //ループを抜ける
          } else {
            if (s[a - i][b - j] == black &&
                s[a - i + ma][b - j + ma] ==
                    sk) {  // iマス左上が黒且つその左上が空白なら
              break;
            }
            if (s[a - i][b - j] == black &&
                s[a - i + ma][b - j + ma] ==
                    w) {  // iマス左上が黒且つその左上が白なら
              j = 3;      //列用のカウンタ
              s[a + mu][b + mu] = w;       //白石(判定)を置く
              for (k = kk; k <= i; k++) {  //ループカウンタ
                s[a - k][b - j] = w;       //白石(判定)を置く
                j++;                       // jをインクリメント
              }
              j = 1;
              break;  //ループを抜ける
            }
          }
          j++;  // jをインクリメント
        }
      }
    }
    counter++;
  } while (counter <= 2);
  return s[8][8];
}