int diagonal(int a, int b, int w, int black, int sk, int counter,
             int (&s)[8][8]) {
  int up = 0, side = 0, ctrl = 0, adjust = 0;
  counter = 0;
  int i = 0, j = 0, k = 0, ii = 0, jj = 0, kk = 0;
  do {
    if (counter == 0) {
      up = -2, side = 0, ctrl = -1, adjust = 1, ii = 3, jj = 1, kk = 3;
    } else if (counter == 1) {
      up = 0, side = -2, ctrl = 1, adjust = -1, ii = 3, jj = 1, kk = 3;
    } else if (counter == 2) {
      up = 0, side = 0, ctrl = 1, adjust = 1, ii = 1, jj = 1, kk = 1;
    } else if (counter == 3) {
      up = -2, side = -2, ctrl = -1, adjust = -1, ii = 3, jj = 3, kk = 3;
    }
    if (s[a + up][b + side] == black) {  //入力値の斜め右上が黒なら
      j = jj;                            //列用のカウンタ
      for (i = ii; i < 8; i++) {         //ループカウンタ
        if (s[a + up][b + side] == w &&
            s[a + up + ctrl][b + side + adjust] ==
                sk) {  //右上が黒且つその右上が空白なら
          break;       //ループを抜ける
        }
        if (s[a + up][b + side] == black &&
            s[a + up + ctrl][b + side + adjust] ==
                w) {                //右上が黒且つその右上が白なら
          s[a + up][b + side] = w;  //白石(判定)を置く
          break;                    //ループを抜ける
        }
        if (up == -2 && side == 0) {
          if (s[a - i][b + j] == black &&
              s[a - i + ctrl][b + j + adjust] ==
                  sk) {  // iマス右上が黒且つその右上が空白なら
            break;
          }
          if (s[a - i][b + j] == black &&
              s[a - i + ctrl][b + j + adjust] ==
                  w) {  // iマス右上が黒且つその右上が白なら
            j = jj;     // jをインクリメント
            s[a + up][b] = w;            //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - k][b + j] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = 1;
            break;  //ループを抜ける
          }
        } else if (up == 0 && side == -2) {
          if (s[a + j][b - i] == black &&
              s[a + j + ctrl][b - i + adjust] ==
                  sk) {  // iマス左下が黒且つ更に斜め左下が空白なら
            break;
          }
          if (s[a + j][b - i] == black &&
              s[a + j + ctrl][b - i + adjust] ==
                  w) {  // iマス左下が黒且つ更に斜め左下が白なら
            j = jj;     //行用のカウンタ
            s[a][b + side] = w;          //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + j][b - k] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = 1;
            break;
          }
        } else if (up == 0 && side == 0) {
          if (s[a + i][b + j] == black &&
              s[a + i + ctrl][b + j + ctrl] ==
                  sk) {  // iマス右下が黒且つその右下が空白なら
            break;
          }
          if (s[a + i][b + j] == black &&
              s[a + i + ctrl][b + j + ctrl] ==
                  w) {  // iマス右下が黒且つその右下が白なら
            j = jj;     //列用のカウンタ
            s[a + up][b + up] = w;       //白石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + k][b + j] = w;       //白石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = jj;
            break;  //ループを抜ける
          }
        } else if (up == -2 && side == -2) {
          if (s[a - i][b - j] == black &&
              s[a - i + ctrl][b - j + ctrl] ==
                  sk) {  // iマス左上が黒且つその左上が空白なら
            break;
          }
          if (s[a - i][b - j] == black &&
              s[a - i + ctrl][b - j + ctrl] ==
                  w) {  // iマス左上が黒且つその左上が白なら
            j = jj;     //列用のカウンタ
            s[a + up][b + up] = w;       //白石(判定)を置く
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
