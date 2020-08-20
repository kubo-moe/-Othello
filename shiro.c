#include <iostream>
int kuro(int &a, int b, int tate, int yoko, int (&s)[8][8], int &flag, int &num);

int shiro(int &a, int b, int tate, int yoko, int (&s)[8][8], int &flag, int &num)
{
    int i = 0; //ループカウンタ
    int j = 0; //ループカウンタ
    int k = 0; //ループカウンタ

    if (flag >= 2)
    {                                            //フラグが2以上の時
        num += 1;                                //回数をインクリメント
        std::cout << num << "回目" << std::endl; //回数表示
        do
        {
            std::cout << "・あなたの番です。白石(●)" << std::endl; //テキストを表示
            std::cout << "・スキップする場合は0を入力してください。" << std::endl;
            std::cout << "・終了するときは9を入力してください。" << std::endl;

            std::cout << "・置きたい行(縦)を入力してください："; //テキストを表示
            std::cin >> a;                                       //数値の入力
            if (a == 0 || a == 9)
            {
                break;
            }
            if (a > 8 || a < 1)
            {                                                              //指定外の数値が入力されたら
                std::cout << "・1~8の数字で入力して下さい。" << std::endl; //テキストを表示
            }
        } while (a > 8 || a < 1); //指定範囲外の数値が入力されたらループ

        if (a != 0 && a != 9)
        {
            do
            {
                std::cout << "・置きたい列(横)を入力してください："; //テキストを表示
                std::cin >> b;                                       //数値の入力
                if (b > 8 || b < 1)
                {                                                              //指定外の数値が入力されたら
                    std::cout << "・1~8の数字で入力して下さい。" << std::endl; //テキストを表示
                }
            } while (b > 8 || b < 1); //指定範囲外の数値が入力されたらループ
        }
    }
    if (a != 0 && a != 9)
    {
        //配列の要素に白黒の判別をつける
        if (s[a - 1][b - 1] == 0)
        {                        //入力値のマスが空白なら
            s[a - 1][b - 1] = 1; //白石(判定)を置く
        }

        //縦横の相手の石の判定
        //下の処理
        if (s[a][b - 1] == 2)
        {                           //入力値の下マスが黒なら
            for (i = 1; i < 8; i++) //ループカウンタ
            {
                if (s[a][b - 1] == 2 && s[a + 1][b - 1] == 0)
                {          //下が黒且つその下が空白の時
                    break; //ループを抜ける
                }
                if (s[a][b - 1] == 2 && s[a + 1][b - 1] == 1)
                {                    //下が黒且つその下が白なら
                    s[a][b - 1] = 1; //白石(判定)を置く
                    break;           //ループを抜ける
                }

                if (s[a + i][b - 1] == 2 && s[a + i + 1][b - 1] == 0)
                { //iマス下が黒且つその下が空白なら
                    break;
                }
                if (s[a + i][b - 1] == 2 && s[a + i + 1][b - 1] == 1)
                {                    //iマス下が黒且つその下が白なら
                    s[a][b - 1] = 1; //白石(判定)を置く
                    for (k = 1; k <= i; k++)
                    {                        //ループカウンタ
                        s[a + k][b - 1] = 1; //白石(判定)を置く
                    }
                    break; //ループを抜ける
                }
            }
        }
        //上の処理
        if (s[a - 2][b - 1] == 2)
        { //入力値の上が黒なら
            for (i = 3; i < 8; i++)
            { //ループカウンタ
                if (s[a - 2][b - 1] == 2 && s[a - 3][b - 1] == 0)
                {          //上が黒且つその上が空白なら
                    break; //ループを抜ける
                }
                if (s[a - 2][b - 1] == 2 && s[a - 3][b - 1] == 1)
                {                        //上が黒且つその上が白なら
                    s[a - 2][b - 1] = 1; //白石(判定)を置く
                    break;               //ループを抜ける
                }

                if (s[a - i][b - 1] == 2 && s[a - i - 1][b - 1] == 0)
                { //iマス上が黒且つその上が空白なら
                    break;
                }
                if (s[a - i][b - 1] == 2 && s[a - i - 1][b - 1] == 1)
                {                        //iマス上が黒且つその上が白なら
                    s[a - 2][b - 1] = 1; //白石(判定)を置く
                    for (k = 3; k <= i; k++)
                    {                        //ループカウンタ
                        s[a - k][b - 1] = 1; //白石(判定)を置く
                    }
                    break; //ループを抜ける
                }
            }
        }
        //右隣の処理
        if (s[a - 1][b] == 2)
        { //入力値の右隣が黒なら
            for (i = 1; i < 8; i++)
            { //ループカウンタ
                if (s[a - 1][b] == 2 && s[a - 1][b + 1] == 0)
                {          //右が黒且つその右が空白なら
                    break; //ループを抜ける
                }
                if (s[a - 1][b] == 2 && s[a - 1][b + 1] == 1)
                {                    //右が黒且つその右が白なら
                    s[a - 1][b] = 1; //白石(判定)を置く
                    break;           //ループを抜ける
                }
                if (s[a - 1][b + i] == 2 && s[a - 1][b + i + 1] == 0)
                { //iマス右が黒且つその右が空白なら
                    break;
                }
                if (s[a - 1][b + i] == 2 && s[a - 1][b + i + 1] == 1)
                {                    //iマス右が黒且つその右が白なら
                    s[a - 1][b] = 1; //白石(判定)を置く
                    for (k = 1; k <= i; k++)
                    { //ループカウンタ

                        s[a - 1][b + k] = 1; //白石(判定)を置く
                    }
                    break; //ループを抜ける
                }
            }
        }
        //左隣の処理
        if (s[a - 1][b - 2] == 2)
        { //入力値の左隣が黒なら
            for (i = 3; i < 8; i++)
            { //ループカウンタ
                if (s[a - 1][b - 2] == 2 && s[a - 1][b - 3] == 0)
                {          //左が黒且つその左が空白なら
                    break; //ループを抜ける
                }
                if (s[a - 1][b - 2] == 2 && s[a - 1][b - 3] == 1)
                {                        //左が黒且つその左が白なら
                    s[a - 1][b - 2] = 1; //白石(判定)を置く
                    break;               //ループを抜ける
                }

                if (s[a - 1][b - i] == 2 && s[a - 1][b - i - 1] == 0)
                { //さらにその左隣が空白なら
                    break;
                }
                if (s[a - 1][b - i] == 2 && s[a - 1][b - i - 1] == 1)
                {                        //さらにその左隣が黒なら
                    s[a - 1][b - 2] = 1; //白石(判定)を置く
                    for (k = 3; k <= i; k++)
                    {                        //ループカウンタ
                        s[a - 1][b - k] = 1; //白石(判定)を置く
                    }
                    break; //ループを抜ける
                }
            }
        }
        //斜めの相手の石の判定
        //左下の判定
        if (s[a][b - 2] == 2)
        {          //入力値の斜め左下が黒なら
            j = 1; //行用のカウンタ
            for (i = 3; i < 8; i++)
            { //ループカウンタ
                if (s[a][b - 2] == 2 && s[a + 1][b - 3] == 0)
                {          //左下が黒且つその左下が空白なら
                    break; //ループを抜ける
                }
                if (s[a][b - 2] == 2 && s[a + 1][b - 3] == 1)
                {                    //左下が黒且つその左下が白なら
                    s[a][b - 2] = 1; //白石(判定)を置く
                    break;           //ループを抜ける
                }

                if (s[a + j][b - i] == 2 && s[a + j + 1][b - i - 1] == 0)
                { //iマス左下が黒且つ更に斜め左下が空白なら
                    break;
                }
                if (s[a + j][b - i] == 2 && s[a + j + 1][b - i - 1] == 1)
                {                    //iマス左下が黒且つ更に斜め左下が白なら
                    j = 1;           //行用のカウンタ
                    s[a][b - 2] = 1; //白石(判定)を置く
                    for (k = 3; k <= i; k++)
                    {                        //ループカウンタ
                        s[a + j][b - k] = 1; //白石(判定)を置く
                        j++;                 //jをインクリメント
                    }
                    break; //ループを抜ける
                }
                j++; //jをインクリメント
            }
        }
        //右上の判定
        if (s[a - 2][b] == 2)
        {          //入力値の斜め右上が黒なら
            j = 1; //列用のカウンタ
            for (i = 3; i < 8; i++)
            { //ループカウンタ
                if (s[a - 2][b] == 2 && s[a - 3][b + 1] == 0)
                {          //右上が黒且つその右上が空白なら
                    break; //ループを抜ける
                }
                if (s[a - 2][b] == 2 && s[a - 3][b + 1] == 1)
                {                    //右上が黒且つその右上が白なら
                    s[a - 2][b] = 1; //白石(判定)を置く
                    break;           //ループを抜ける
                }

                if (s[a - i][b + j] == 2 && s[a - i - 1][b + j + 1] == 0)
                { //iマス右上が黒且つその右上が空白なら
                    break;
                }
                if (s[a - i][b + j] == 2 && s[a - i - 1][b + j + 1] == 1)
                {                    //iマス右上が黒且つその右上が白なら
                    j = 1;           //jをインクリメント
                    s[a - 2][b] = 1; //白石(判定)を置く
                    for (k = 3; k <= i; k++)
                    {                        //ループカウンタ
                        s[a - k][b + j] = 1; //白石(判定)を置く
                        j++;                 //jをインクリメント
                    }
                    break; //ループを抜ける
                }
                j++; //jをインクリメント
            }
        }
        //左上の判定
        if (s[a - 2][b - 2] == 2)
        {          //入力値の斜め左上が黒なら
            j = 3; //列用のカウンタ
            for (i = 3; i < 8; i++)
            { //ループカウンタ
                if (s[a - 2][b - 2] == 2 && s[a - 3][b - 3] == 0)
                { //左上が黒且つその左上が空白なら
                    break;
                }
                if (s[a - 2][b - 2] == 2 && s[a - 3][b - 3] == 1)
                {                        //左上が黒且つその左上が白なら
                    s[a - 2][b - 2] = 1; //白石(判定)を置く
                    break;               //ループカウンタ
                }

                if (s[a - i][b - j] == 2 && s[a - i - 1][b - j - 1] == 0)
                { //iマス左上が黒且つその左上が空白なら
                    break;
                }
                if (s[a - i][b - j] == 2 && s[a - i - 1][b - j - 1] == 1)
                { //iマス左上が黒且つその左上が白なら

                    s[a - 2][b - 2] = 1; //白石(判定)を置く
                    for (k = 3; k <= i; k++)
                    {                        //ループカウンタ
                        j = 3;               //列用のカウンタ
                        s[a - k][b - j] = 1; //白石(判定)を置く
                        j++;                 //jをインクリメント
                    }
                    break; //ループを抜ける
                }
                j++; //jをインクリメント
            }
        }
        //右下の判定
        if (s[a][b] == 2)
        {          //入力値の斜め右下が黒なら
            j = 1; //列用のカウンタ
            for (i = 1; i < 8; i++)
            { //ループカウンタ
                if (s[a][b] == 2 && s[a + 1][b + 1] == 0)
                { //右下が黒且つその右上が空白なら
                    break;
                }
                if (s[a][b] == 2 && s[a + 1][b + 1] == 1)
                {                //右下が黒且つその右上が白なら
                    s[a][b] = 1; //白石(判定)を置く
                    break;       //ループを抜ける
                }

                if (s[a + i][b + j] == 2 && s[a + i + 1][b + j + 1] == 0)
                { //iマス右下が黒且つその右下が空白なら
                    break;
                }
                if (s[a + i][b + j] == 2 && s[a + i + 1][b + j + 1] == 1)
                {                //iマス右下が黒且つその右下が白なら
                    j = 1;       //列用のカウンタ
                    s[a][b] = 1; //白石(判定)を置く
                    for (k = 1; k <= i; k++)
                    {                        //ループカウンタ
                        s[a + k][b + j] = 1; //白石(判定)を置く
                        j++;                 //jをインクリメント
                    }
                    break; //ループを抜ける
                }
                j++; //jをインクリメント
            }
        }

        //盤面表示
        std::cout << std::endl;
        std::cout << "  1 2 3 4 5 6 7 8" << std::endl; //列を表示
        for (i = 0; i < tate; i++)
        {                       //縦に8つ表示するまでループ
            std::cout << i + 1; //行を表示
            for (j = 0; j < yoko; j++)
            { //横に8つ表示するまでループ
                if (s[i][j] == 1)
                {                      //配列内に1があれば
                    std::cout << " ●"; //黒石を表示
                }
                else if (s[i][j] == 2)
                {                      //配列内に2があれば
                    std::cout << " ○"; //白石を表示
                }
                else
                {                      //それ以外は
                    std::cout << "  "; //空白を表示
                }
            }
            std::cout << std::endl; //4つ表示したら改行
        }
        std::cout << std::endl; //インデント用改行
        flag++;
        num++;
    }
    if (a == 9)
    {
        return s[8][8], flag, num, a;
    }
    kuro(a, b, tate, yoko, s, flag, num); //相手の白石を石を反転する
    return s[8][8], flag, num, a;
}