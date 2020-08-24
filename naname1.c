int migiue(int a, int b, int w, int black, int sk, int counter,
           int (&s)[8][8]) {
  int mu = 0, hs = 0, ma = 0, ha = 0, mb = 0;
  int i = 0, j = 0, k = 0;
  int ii = 0, kk = 0;
  counter = 0;
  do {
    if (counter == 0) {
      mu = -2;
      hs = 0;
      ma = -1;
      mb = 1;
      ii = 3;
      kk = 3;
    } else {
      mu = 0;
      hs = -2;
      ma = 1;
      mb = -1;
      ii = 3;
      kk = 3;
    }
    if (s[a + mu][b + hs] == black) {  //入力値の斜め右上が黒なら
      j = 1;                           //列用のカウンタ
      for (i = ii; i < 8; i++) {       //ループカウンタ
        if (s[a + mu][b + hs] == w &&
            s[a + mu + ma][b + hs + mb] ==
                sk) {  //右上が黒且つその右上が空白なら
          break;       //ループを抜ける
        }
        if (s[a + mu][b + hs] == black &&
            s[a + mu + ma][b + hs + mb] == w) {  //右上が黒且つその右上が白なら
          s[a + mu][b + hs] = w;                 //白石(判定)を置く
          break;                                 //ループを抜ける
        }
        if (mu == -2) {
          if (s[a - i][b + j] == black &&
              s[a - i + ma][b + j + mb] ==
                  sk) {  // iマス右上が黒且つその右上が空白なら
            break;
          }
          if (s[a - i][b + j] == black &&
              s[a - i + ma][b + j + mb] ==
                  w) {  // iマス右上が黒且つその右上が白なら
            j = 1;      // jをインクリメント
            s[a + mu][b] = w;            //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - k][b + j] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = 1;
            break;  //ループを抜ける
          }
        } else {
          if (s[a + j][b - i] == black &&
              s[a + j + ma][b - i + mb] ==
                  sk) {  // iマス左下が黒且つ更に斜め左下が空白なら
            break;
          }
          if (s[a + j][b - i] == black &&
              s[a + j + ma][b - i + mb] ==
                  w) {  // iマス左下が黒且つ更に斜め左下が白なら
            j = 1;      //行用のカウンタ
            s[a][b + hs] = w;            //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + j][b - k] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = 1;
            break;
          }
        }
        j++;  // jをインクリメント
      }
    }
    counter++;
  } while (counter <= 2);
  return s[8][8];
}
