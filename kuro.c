#include<iostream>

void kuro(int a, int b, int tate, int yoko){

    char s[8][8] = {0};
    int i = 0;
    int j = 0;
    int k = 0;

    s[3][3] = 1;											//石の有無の判別用
	s[4][4] = 1;										    //石の有無の判別用
	s[3][4] = 2;    										//石の有無の判別用
	s[4][3] = 2;	    									//石の有無の判別用
    int flag = 0;
    int num = 1;

    do{
        if(flag >= 2){
            num += 1;
            std::cout << num << "回目" << std::endl;                            //回数表示
            do{
                std::cout << "・あなたの番です。白石(●)" << std::endl;           //テキストを表示
                std::cout << "置きたい行(縦)を入力してください：";               //テキストを表示
	            std::cin >> a;                                                  //数値の入力
                if(a > 8 || a < 1){                                             //指定外の数値が入力されたら
			        std::cout << "1~8の数字で入力して下さい。" <<std::endl;      //テキストを表示
		        }
	        }while(a > 8 || a < 1);                                             //指定範囲外の数値が入力されたらループ

            do{
                std::cout << "置きたい列(横)を入力してください：";                //テキストを表示
	            std::cin >> b;                                                  //数値の入力
                if(b > 8 || b < 1){                                             //指定外の数値が入力されたら
			        std::cout << "1~8の数字で入力して下さい。" <<std::endl;      //テキストを表示
		        }
	        }while(b > 8 || b < 1);                                             //指定範囲外の数値が入力されたらループ

        }

        //配列の要素に白黒の判別をつける
        if(s[a-1][b-1] == 0){                               //入力値のマスが空白なら
            s[a-1][b-1] = 1;                                //白石(判定)を置く
        }
        //縦横の相手の石の判定
            //下の処理
            if(s[a][b-1] == 2){                             //入力値の下マスが黒なら
                for(i = 1; i <= 8; i++){                    //ループカウンタ
                    if(s[a][b-1] == 2 && s[a+1][b-1] == 0){
                        break;
                    }
                    if(s[a][b-1] == 2 && s[a+1][b-1] == 1){
                        s[a][b-1] = 1;                      //白石(判定)を置く
                        break;
                    }
                    if(s[a+i][b-1] == 2 && s[a+i+1][b-1] == 1){//さらにその下マスが黒なら
                        for(k = 1; k <= i; k++){
                            s[a][b-1] = 1;                     //白石(判定)を置く
                            s[a+i][b-1] = 1;                   //白石(判定)を置く
                        }
                        break;
                    }
                }
            }
            //上の処理
            if(s[a-2][b-1] == 2){                           //入力値の上が黒なら
                for(i = 3; i <= 8; i++){                    //ループカウンタ
                    if(s[a-2][b-1] == 2 && s[a-3][b-1] == 0){
                        break;
                    }
                    if(s[a-2][b-1] == 2 && s[a-3][b-1] == 1){
                        s[a-2][b-1] = 1;
                        break;
                    }
                    if(s[a-i][b-1] == 2 && s[a-i-1][b-1] == 1){//さらにその上のマスが黒なら
                        for(k = 1; k <= i; k++){
                            s[a-2][b-1] = 1;                   //白石(判定)を置く
                            s[a-i][b-1] = 1;                   //白石(判定)を置く
                        }
                        break;                                 //ループを抜ける
                    }
                }
            }
            //右隣の処理
            if(s[a-1][b] == 2){                             //入力値の右隣が黒なら
                for(i = 1; i <= 8; i++){                    //ループカウンタ
                    if(s[a-1][b] == 2 && s[a-1][b+1] == 0){
                        break;
                    }
                    if(s[a-1][b] == 2 && s[a-1][b+1] == 1){
                        s[a-1][b] = 1;                      //白石(判定)を置く
                        break;
                    }
                    if(s[a-1][b+i] == 2 && s[a-1][b+i+1] == 1){//さらにその右隣のマスが黒なら
                        for(k = 1; k <= i; k++){
                            s[a-1][b] = 1;                      //白石(判定)を置く
                            s[a-1][b+i] = 1;                    //白石(判定)を置く  
                        }
                        break;                                  //ループを抜ける
                    }
                }
            }
            //左隣の処理
            if(s[a-1][b-2] == 2){                               //入力値の左隣が黒なら
                for(i = 3; i <= 8; i++){                        //ループカウンタ
                    if(s[a-1][b-2] == 2 && s[a-2][b-2] == 0){
                        break;
                    }
                    if(s[a-1][b-2] == 2 && s[a-1][b-3] == 1){
                        s[a-1][b-2] = 1;                        //白石(判定)を置く
                        break;
                    }
                    if(s[a-1][b-i] == 2 && s[a-1][b-i-1] == 1){ //さらにその左隣が黒なら
                        for(k = 1; k <= i; k++){
                            s[a-1][b-2] = 1;                    //白石(判定)を置く
                            s[a-1][b-i] = 1;                    //白石(判定)を置く
                        }
                        break;                                  //ループを抜ける
                    }
                }
            }
    //斜めの相手の石の判定
        //左下の判定
        if(s[a][b-2] == 2){                                 //入力値の斜め左下が黒なら
            j = 1;                                          //行用のカウンタ
            for(i = 3; i <= 8; i++){                        //ループカウンタ
                if(s[a][b-2] == 2 && s[a+1][b-3] == 1){
                    s[a][b-2] = 1;                          //白石(判定)を置く
                    break;
                }
                if(s[a+j][b-i] == 2){                       //更に斜め左下が黒なら
                    s[a][b-2] = 1;                          //白石(判定)を置く
                    s[a+j][b-i] = 1;                        //白石(判定)を置く
                    if(s[a+j+1][b-i-1] == 1){               //更に斜め左下が白なら
                        break;                              //ループを抜ける
                    }
                }
                j++;                                        //jをインクリメント
            }
        }
        //右上の判定
        if(s[a-2][b] == 2){                                 //入力値の斜め右上が黒なら
            j = 1;                                          //列用のカウンタ
            for(i = 3; i <= 8; i++){                        //ループカウンタ
                if(s[a-2][b] == 2 && s[a-3][b+1] == 1){
                    s[a-2][b] = 1;                          //白石(判定)を置く
                    break;
                }
                if(s[a-i][b+j] == 2){                       //更に斜め右上が黒なら
                    s[a-2][b] = 1;                          //白石(判定)を置く
                    s[a-i][b+j] == 1;                       //白石(判定)を置く
                    if(s[a-i-1][b+j+1] == 1){               //更に斜め右上が白なら
                        break;                              //ループを抜ける
                    }
                }
                j++;                                        //jをインクリメント
            }
        }
        //左上の判定
        if(s[a-2][b-2] == 2){                               //入力値の斜め左上が黒なら
            j = 3;                                          //列用のカウンタ           
            for(i = 3; i <= 8; i++){                        //ループカウンタ
                if(s[a-2][b-2] == 2 && s[a-3][b-3] == 1){
                    s[a-2][b-2] = 1;                        //白石(判定)を置く
                    break;
                }
                if(s[a-i][b-j] == 2){                       //更に斜め左上が黒なら
                    s[a-2][b-2] = 1;                        //白石(判定)を置く
                    s[a-i][b-j] = 1;                        //白石(判定)を置く
                    if(s[a-i-1][b-j-1] == 1){               //更に斜め左上が白なら
                        break;                              //ループを抜ける
                    }
                }
                j++;                                        //jをインクリメント                    
            }
        }
        //右下の判定
        if(s[a][b] == 2){                                   //入力値の斜め右下が黒なら
            j = 1;                                          //列用のカウンタ
            for(i = 1; i <= 8; i++){                        //ループカウンタ     
                if(s[a][b] == 2 && s[a+1][b+1] == 1){
                    s[a][b] = 1;                            //白石(判定)を置く
                    break;
                }
                if(s[a+i][b+j] == 2){                       //更に斜め右下が黒なら
                    s[a][b] = 1;                            //白石(判定)を置く
                    s[a+i][b+j] = 1;                        //白石(判定)を置く
                    if(s[a+i+1][b+j+1] == 1){               //更に斜め右下が白なら
                        break;                              //ループを抜ける
                    }
                }
                j++;                                    //jをインクリメント
            }
        }
        

    //盤面表示
    std::cout << "  1 2 3 4 5 6 7 8" << std::endl;			//列を表示
    for(i = 0; i < tate; i++){                              //縦に8つ表示するまでループ
        std::cout << i + 1;                                 //行を表示
        for(j = 0; j < yoko; j++){                          //横に8つ表示するまでループ
			if(s[i][j] == 1){								//配列内に1があれば
				std::cout << " ●";							//黒石を表示
			}else if(s[i][j] == 2){							//配列内に2があれば
				std::cout << " ○";							//白石を表示
			}else{											//それ以外は
				std::cout << "  ";							//空白を表示
			}
        }
            std::cout << std::endl;                         //4つ表示したら改行
    }

    std::cout << std::endl;                                 //インデント用改行
    flag++;

    i = 0;                                                  //ループカウンタを初期化
    j = 0;                                                  //ループカウンタを初期化

    std::cout << "相手の番です相手は黒石です(○)" << std::endl;       //テキストを表示
    do{
        std::cout << "置きたい行(縦)を入力してください：";           //テキストを表示
	    std::cin >> a;                                              //数値の入力
        if(a > 8 || a < 1){                                         //指定外の数値が入力されたら
			std::cout << "1~8の数字で入力して下さい。" <<std::endl;  //テキストを表示
		}
	}while(a > 8 || a < 1);                                         //指定範囲外の数値が入力されたらループ

    do{
	    std::cout << "置きたい列(横)を入力してください：";            //テキストを表示
	    std::cin >> b;                                              //数値の入力
        if(a > 8 || a < 1){                                         //指定外の数値が入力されたら
			std::cout << "1~8の数字で入力して下さい。" <<std::endl;  //テキストを表示
		}
	}while(a > 8 || a < 1);                                         //指定範囲外の数値が入力されたらループ



        //配列の要素に白黒の判別をつける
        if(s[a-1][b-1] == 0){                               //入力値のマスが空白なら
            s[a-1][b-1] = 2;                                //黒石(判定)を置く
        }
        //縦横の相手の石の判定
            //下の処理
            if(s[a][b-1] == 1){                             //入力値の下マスが白なら
                for(i = 1; i <= 8; i++){                    //ループカウンタ
                    if(s[a][b-1] == 1 && s[a+1][b-1] == 0){
                        break;
                    }
                    if(s[a][b-1] == 1 && s[a+1][b-1] == 2){
                        s[a][b-1] = 2;                      //黒石(判定)を置く
                        break;
                    }
                    if(s[a+i][b-1] == 1 && s[a+i+1][b-1] == 2){ //さらにその下マスが白なら
                        for(k = 1; k <= i; k++){
                            s[a][b-1] = 2;                      //黒石(判定)を置く
                            s[a+i][b-1] = 2;                    //黒石(判定)を置く
                        }
                        break;                                  //ループを抜ける
                    }
                }
            }
            //上の処理
            if(s[a-2][b-1] == 1){                           //入力値の上が白なら
                for(i = 3; i <= 8; i++){                    //ループカウンタ
                    if(s[a-2][b-1] == 1 && s[a-3][b-1] == 0){
                        break;
                    }
                    if(s[a-2][b-1] == 1 && s[a-3][b-1] == 2){
                        s[a-2][b-1] = 2;                    //黒石(判定)を置く
                        break;
                    }
                    if(s[a-i][b-1] == 1 && s[a-i-1][b-1] == 2){ //さらにその上のマスが白なら
                        for(k = 1; k <= i; k++){
                            s[a-2][b-1] = 2;                    //黒石(判定)を置く
                            s[a-i][b-1] = 2;                    //黒石(判定)を置く
                        }
                        break;                                  //ループを抜ける
                    }
                }
            }
            //右隣の処理
            if(s[a-1][b] == 1){                             //入力値の右隣が白なら
                for(i = 1; i <= 8; i++){                    //ループカウンタ
                    if(s[a-1][b] == 1 && s[a-1][b+1] == 0){
                        break;
                    }
                    if(s[a-1][b] == 1 && s[a-1][b+1] == 2){
                        s[a-1][b] = 2;                      //黒石(判定)を置く
                        break;
                    }
                    if(s[a-1][b+i] == 1 && s[a-1][b+i+1] == 2){ //さらにその右隣のマスが白なら
                        for(k = 1; k <= i; k++){
                            s[a-1][b] = 2;                      //黒石(判定)を置く
                            s[a-1][b+i] = 2;                    //黒石(判定)を置く
                        }
                        break;                                      //ループを抜ける
                    }
                }
            }
            //左隣の処理
            if(s[a-1][b-2] == 1){                           //入力値の左隣が白なら 
                for(i = 3; i <= 8; i++){                    //ループカウンタ
                    if(s[a-1][b-2] == 1 && s[a-1][b-3] == 0){
                        break;
                    }
                    if(s[a-1][b-2] == 1 && s[a-1][b-3] == 2){
                        s[a-1][b-2] = 2;                    //黒石(判定)を置く
                        break;
                    }
                    if(s[a-1][b-i] == 1 && s[a-1][b-i-1] == 2){ //さらにその左隣が白なら
                        for(k = 1; k <= i; k++){
                            s[a-1][b-2] = 2;                    //黒石(判定)を置く
                            s[a-1][b-i] = 2;                    //黒石(判定)を置く
                        }
                        break;                                  //ループを抜ける
                    }
                }
            }       
    //斜めの相手の石の判定
        //左下の判定
        if(s[a][b-2] == 1){                                 //入力値の斜め左下が白なら
            j = 1;                                          //行用のカウンタ
            for(i = 3; i <= 8; i++){                        //ループカウンタ
                if(s[a][b-2] == 1 && s[a+1][b-3] == 2){
                    s[a][b-2] = 2;                          //黒石(判定)を置く
                    break;
                }
                if(s[a+j][b-i] == 1){                       //更に斜め左下が白なら
                    s[a][b-2] = 2;                          //黒石(判定)を置く
                    s[a+j][b-i] = 2;                        //黒石(判定)を置く
                    if(s[a+j+1][b-i-1] == 2){               //更に斜め左下が黒なら
                        break;                              //ループを抜ける
                    }
                }
                j++;                                        //jをインクリメント
            }
        }
        //右上の判定
        if(s[a-2][b] == 1){                                 //入力値の斜め右上が白なら
            j = 1;                                          //列用のカウンタ
            for(i = 3; i <= 8; i++){                        //ループカウンタ
                if(s[a-2][b] == 1 && s[a-3][b+1] == 2){
                    s[a-2][b] = 2;                          //黒石(判定)を置く
                    break;
                }
                if(s[a-i][b+j] == 1){                       //更に斜め右上が白なら
                    s[a-2][b] = 2;                          //黒石(判定)を置く
                    s[a-i][b+j] == 2;                       //黒石(判定)を置く
                    if(s[a-i-1][b+j+1] == 2){               //更に斜め右上が黒なら
                        break;                              //ループを抜ける
                    }
                }
                j++;                                        //jをインクリメント
            }
        }
        //左上の判定
        if(s[a-2][b-2] == 1){                               //入力値の斜め左上が白なら
            j = 3;                                          //列用のカウンタ
            for(i = 3; i <= 8; i++){                        //ループカウンタ
                if(s[a-2][b-2] == 1 && s[a-3][b-3] == 2){
                    s[a-2][b-2] = 2;                        //黒石(判定)を置く
                    break;
                }
                if(s[a-i][b-j] == 1){                       //更に斜め左上が白なら
                    s[a-2][b-2] = 2;                        //黒石(判定)を置く
                    s[a-i][b-j] = 2;                        //黒石(判定)を置く
                    if(s[a-i-1][b-j-1] == 2){               //更に斜め左上が黒なら
                        break;                              //ループを抜ける
                    }                   
                }
                j++;                                        //jをインクリメント
            }
        }
 
        //右下の判定
        if(s[a][b] == 1){                                   //入力値の斜め右下が白なら
            j = 1;                                          //列用のカウンタ
            for(i = 1; i <= 8; i++){                        //ループカウンタ
                if(s[a][b] == 1 && s[a+1][b+1] == 2){
                    s[a][b] = 2;
                    break;                                  //黒石(判定)を置く
                }
                if(s[a+i][b+j] == 1){                       //更に斜め右下が白なら
                    s[a][b] = 2;                            //黒石(判定)を置く
                    s[a+i][b+j] = 2;                        //黒石(判定)を置く
                    if(s[a+i+1][b+j+1] == 2){               //更に斜め右下が黒なら
                        break;                              //ループを抜ける
                    }
                }
                 j++;                                       //jをインクリメント
            }
        }


    //盤面表示
    std::cout << "  1 2 3 4 5 6 7 8" << std::endl;			//列を表示
    for(i = 0; i < tate; i++){                              //縦に8つ表示するまでループ
        std::cout << i + 1;                                 //行を表示
        for(j = 0; j < yoko; j++){                          //横に8つ表示するまでループ
			if(s[i][j] == 1){								//配列内に1があれば
				std::cout << " ●";							//黒石を表示
			}else if(s[i][j] == 2){							//配列内に2があれば
				std::cout << " ○";							//白石を表示
			}else{											//それ以外は
				std::cout << "  ";							//空白を表示
			}
        }
            std::cout << std::endl;                         //4つ表示したら改行
    }

    std::cout << std::endl;                                 //インデント用改行

    i = 0;                                                  //ループカウンタを初期化
    j = 0;                                                  //ループカウンタを初期化

    //フラグ立てる場所
    flag++;

    }while(flag != 60);


}