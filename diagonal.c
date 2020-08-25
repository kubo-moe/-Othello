int diagonal(int a, int b, int w, int black, int sk, int counter,
             int (&s)[8][8]) {
  int tate = 0, hs = 0, ma = 0, ha = 0, mb = 0;
  counter = 0;
  int i = 0, j = 0, k = 0, ii = 0, jj = 0, kk = 0;
  do {
    if (counter == 0) {
      tate = -2, hs = 0, ma = -1, mb = 1, ii = 3, jj = 1, kk = 3;
    } else if (counter == 1) {
      tate = 0, hs = -2, ma = 1, mb = -1, ii = 3, jj = 1, kk = 3;
    } else if (counter == 2) {
      tate = 0, hs = 0, ma = 1, mb = 1, ii = 1, jj = 1, kk = 1;
    } else if (counter == 3) {
      tate = -2, hs = -2, ma = -1, mb = -1, ii = 3, jj = 3, kk = 3;
    }
    if (s[a + tate][b + hs] == black) {  //入力値の斜め右上が黒なら
      j = jj;                            //列用のカウンタ
      for (i = ii; i < 8; i++) {         //ループカウンタ
        if (s[a + tate][b + hs] == w &&
            s[a + tate + ma][b + hs + mb] ==
                sk) {  //右上が黒且つその右上が空白なら
          break;       //ループを抜ける
        }
        if (s[a + tate][b + hs] == black &&
            s[a + tate + ma][b + hs + mb] ==
                w) {                //右上が黒且つその右上が白なら
          s[a + tate][b + hs] = w;  //白石(判定)を置く
          break;                    //ループを抜ける
        }
        if (tate == -2 && hs == 0) {
          if (s[a - i][b + j] == black &&
              s[a - i + ma][b + j + mb] ==
                  sk) {  // iマス右上が黒且つその右上が空白なら
            break;
          }
          if (s[a - i][b + j] == black &&
              s[a - i + ma][b + j + mb] ==
                  w) {  // iマス右上が黒且つその右上が白なら
            j = jj;     // jをインクリメント
            s[a + tate][b] = w;          //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - k][b + j] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = 1;
            break;  //ループを抜ける
          }
        } else if (tate == 0 && hs == -2) {
          if (s[a + j][b - i] == black &&
              s[a + j + ma][b - i + mb] ==
                  sk) {  // iマス左下が黒且つ更に斜め左下が空白なら
            break;
          }
          if (s[a + j][b - i] == black &&
              s[a + j + ma][b - i + mb] ==
                  w) {  // iマス左下が黒且つ更に斜め左下が白なら
            j = jj;     //行用のカウンタ
            s[a][b + hs] = w;            //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + j][b - k] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = 1;
            break;
          }
        } else if (tate == 0 && hs == 0) {
          if (s[a + i][b + j] == black &&
              s[a + i + ma][b + j + ma] ==
                  sk) {  // iマス右下が黒且つその右下が空白なら
            break;
          }
          if (s[a + i][b + j] == black &&
              s[a + i + ma][b + j + ma] ==
                  w) {  // iマス右下が黒且つその右下が白なら
            j = jj;     //列用のカウンタ
            s[a + tate][b + tate] = w;   //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + k][b + j] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = jj;
            break;  //ループを抜ける
          }
        } else if (tate == -2 && hs == -2) {
          if (s[a - i][b - j] == black &&
              s[a - i + ma][b - j + ma] ==
                  sk) {  // iマス左上が黒且つその左上が空白なら
            break;
          }
          if (s[a - i][b - j] == black &&
              s[a - i + ma][b - j + ma] ==
                  w) {  // iマス左上が黒且つその左上が白なら
            j = jj;     //列用のカウンタ
            s[a + tate][b + tate] = w;   //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - k][b - j] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = jj;
            break;  //ループを抜ける
          }
        }
        j++;  // jをインクリメント
      }
    }
    counter++;
  } while (counter <= 4);
  return s[8][8];
}
