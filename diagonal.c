int diagonal(int a, int b, int myturn, int opponent, int space, int counter,
             int (&s)[8][8]) {
  int up = 0, side = 0, ctrl = 0, adjust = 0;
  counter = 0;
  int i = 0, j = 0, k = 0, ii = 0, jj = 0, kk = 0;
  do {
    if (counter == 0) {
      up = -2, side = 0, ctrl = -1, adjust = 1, ii = 3, jj = 1,
      kk = 3;  //右上の判定
    } else if (counter == 1) {
      up = 0, side = -2, ctrl = 1, adjust = -1, ii = 3, jj = 1,
      kk = 3;  //左下の判定
    } else if (counter == 2) {
      up = 0, side = 0, ctrl = 1, adjust = 1, ii = 1, jj = 1,
      kk = 1;  //右下の判定
    } else if (counter == 3) {
      up = -2, side = -2, ctrl = -1, adjust = -1, ii = 3, jj = 3,
      kk = 3;  //左上の判定
    }
    if (s[a + up][b + side] == opponent) {  //入力値の斜め隣が敵石なら
      j = jj;                               //列用のカウンタ
      for (i = ii; i < 8; i++) {            //ループカウンタ
        if (s[a + up][b + side] == myturn &&
            s[a + up + ctrl][b + side + adjust] ==
                space) {  //隣が敵石且つその隣が空白なら
          break;          //ループを抜ける
        }
        if (s[a + up][b + side] == opponent &&
            s[a + up + ctrl][b + side + adjust] ==
                myturn) {  //入力値の斜め隣が敵石且つその斜め隣が自石なら
          s[a + up][b + side] = myturn;  //自石(判定)を置く
          break;                         //ループを抜ける
        }
        if (up == -2 && side == 0) {
          if (s[a - i][b + j] == opponent &&
              s[a - i + ctrl][b + j + adjust] ==
                  space) {  // iマス斜め隣が敵石且つその斜め隣が空白なら
            break;
          }
          if (s[a - i][b + j] == opponent &&
              s[a - i + ctrl][b + j + adjust] ==
                  myturn) {  // iマス斜め隣が敵石且つその斜め隣が自石なら
            j = jj;                      // jをインクリメント
            s[a + up][b] = myturn;       //自石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - k][b + j] = myturn;  //自石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = 1;
            break;  //ループを抜ける
          }
        } else if (up == 0 && side == -2) {
          if (s[a + j][b - i] == opponent &&
              s[a + j + ctrl][b - i + adjust] ==
                  space) {  // iマス斜め隣が敵石且つ更に斜め隣が空白なら
            break;  //ループを抜ける
          }
          if (s[a + j][b - i] == opponent &&
              s[a + j + ctrl][b - i + adjust] ==
                  myturn) {  // iマス斜め隣が敵石且つ更に斜め隣が自石なら
            j = jj;                      //行用のカウンタ
            s[a][b + side] = myturn;     //自石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + j][b - k] = myturn;  //自石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = 1;
            break;
          }
        } else if (up == 0 && side == 0) {
          if (s[a + i][b + j] == opponent &&
              s[a + i + ctrl][b + j + ctrl] ==
                  space) {  // iマス斜め隣が敵石且つその斜め隣が空白なら
            break;
          }
          if (s[a + i][b + j] == opponent &&
              s[a + i + ctrl][b + j + ctrl] ==
                  myturn) {  // iマス斜め隣が敵石且つその斜め隣が自石なら
            j = jj;                      //列用のカウンタ
            s[a + up][b + up] = myturn;  //自石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a + k][b + j] = myturn;  //自石(判定)を置く
              j++;                       // jをインクリメント
            }
            j = jj;
            break;  //ループを抜ける
          }
        } else if (up == -2 && side == -2) {
          if (s[a - i][b - j] == opponent &&
              s[a - i + ctrl][b - j + ctrl] ==
                  space) {  // iマス斜め隣が敵石且つその斜め隣が空白なら
            break;
          }
          if (s[a - i][b - j] == opponent &&
              s[a - i + ctrl][b - j + ctrl] ==
                  myturn) {  // iマス斜め隣が敵石且つその斜め隣が白なら
            j = jj;                      //列用のカウンタ
            s[a + up][b + up] = myturn;  //自石(判定)を置く
            for (k = kk; k <= i; k++) {  //ループカウンタ
              s[a - k][b - j] = myturn;  //自石(判定)を置く
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
