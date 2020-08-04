#include<iostream>

void kuro(int a, int b, int tate, int yoko){

    char s[8][8] = {0};                                                         //判定格納用
    int i = 0;                                                                  //ループカウンタ
    int j = 0;                                                                  //ループカウンタ
    int k = 0;                                                                  //ループカウンタ

    s[3][3] = 1;											                    //石の有無の判別用
	s[4][4] = 1;										                        //石の有無の判別用
	s[3][4] = 2;    										                    //石の有無の判別用
	s[4][3] = 2;	    									                    //石の有無の判別用
    int flag = 0;                                                               //判定用フラグ
    int num = 1;                                                                //回数表示用

    do{
        if(flag >= 2){                                                          //フラグが2以上の時
            num += 1;                                                           //回数をインクリメント
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
        if(s[a-1][b-1] == 0){                                                   //入力値のマスが空白なら
            s[a-1][b-1] = 1;                                                    //白石(判定)を置く
        }

        //縦横の相手の石の判定
        //下の処理
        if(s[a][b-1] == 2){                                                     //入力値の下マスが黒なら
            for(i = 1; i <= 8; i++){                                            //ループカウンタ
                if(s[a][b-1] == 2 && s[a+1][b-1] == 0){                         //下が黒且つその下が空白の時
                    break;                                                      //ループを抜ける
                }
                if(s[a][b-1] == 2 && s[a+1][b-1] == 1){                         //下が黒且つその下が白なら
                    s[a][b-1] = 1;                                              //白石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a+i][b-1] == 2 && s[a+i+1][b-1] == 1){                     //iマス下が黒且つその下が白なら
                    for(k = 1; k <= i; k++){                                    //ループカウンタ
                        s[a][b-1] = 1;                                          //白石(判定)を置く
                        s[a+k][b-1] = 1;                                        //白石(判定)を置く
                    }
                    break;                                                      //ループを抜ける
                }
            }
        }
        //上の処理
        if(s[a-2][b-1] == 2){                                                   //入力値の上が黒なら
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a-2][b-1] == 2 && s[a-3][b-1] == 0){                       //上が黒且つその上が空白なら
                    break;                                                      //ループを抜ける
                }
                if(s[a-2][b-1] == 2 && s[a-3][b-1] == 1){                       //上が黒且つその上が白なら
                    s[a-2][b-1] = 1;                                            //白石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a-i][b-1] == 2 && s[a-i-1][b-1] == 1){                     //iマス上が黒且つその上が白なら
                    for(k = 1; k <= i; k++){                                    //ループカウンタ
                        s[a-2][b-1] = 1;                                        //白石(判定)を置く
                        s[a-k][b-1] = 1;                                        //白石(判定)を置く
                    }
                    break;                                                      //ループを抜ける
                }
            }
        }
        //右隣の処理
        if(s[a-1][b] == 2){                                                     //入力値の右隣が黒なら
            for(i = 1; i <= 8; i++){                                            //ループカウンタ
                if(s[a-1][b] == 2 && s[a-1][b+1] == 0){                         //右が黒且つその右が空白なら
                    break;                                                      //ループを抜ける
                }
                if(s[a-1][b] == 2 && s[a-1][b+1] == 1){                         //右が黒且つその右が白なら
                    s[a-1][b] = 1;                                              //白石(判定)を置く
                    break;                                                      //ループを抜ける
                }                                                               
                if(s[a-1][b+i] == 2 && s[a-1][b+i+1] == 1){                     //iマス右が黒且つその右が白なら
                    for(k = 1; k <= i; k++){                                    //ループカウンタ
                        s[a-1][b] = 1;                                          //白石(判定)を置く
                        s[a-1][b+k] = 1;                                        //白石(判定)を置く  
                    }
                    break;                                                      //ループを抜ける
                }
            }
        }
        //左隣の処理
        if(s[a-1][b-2] == 2){                                                   //入力値の左隣が黒なら
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a-1][b-2] == 2 && s[a-1][b-3] == 0){                       //左が黒且つその左が空白なら
                    break;                                                      //ループを抜ける
                }
                if(s[a-1][b-2] == 2 && s[a-1][b-3] == 1){                       //左が黒且つその左が白なら
                    s[a-1][b-2] = 1;                                            //白石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a-1][b-i] == 2 && s[a-1][b-i-1] == 1){                     //さらにその左隣が黒なら
                    for(k = 1; k <= i; k++){                                    //ループカウンタ
                        s[a-1][b-2] = 1;                                        //白石(判定)を置く
                        s[a-1][b-k] = 1;                                        //白石(判定)を置く
                    }
                    break;                                                      //ループを抜ける
                }
            }
        }
        //斜めの相手の石の判定
        //左下の判定
        if(s[a][b-2] == 2){                                                     //入力値の斜め左下が黒なら
            j = 1;                                                              //行用のカウンタ
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a][b-2] == 2 && s[a+1][b-3] == 1){                         //左下が黒且つその左下が白なら
                    s[a][b-2] = 1;                                              //白石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a+j][b-i] == 2 && s[a+j+1][b-i-1] == 1){                   //iマス左下が黒且つ更に斜め左下が白なら
                    j = 1;                                                      //行用のカウンタ
                    for(k = 3; k <= i; k++){                                    //ループカウンタ
                        s[a][b-2] = 1;                                          //白石(判定)を置く
                        s[a+j][b-k] = 1;                                        //白石(判定)を置く
                        j++;                                                    //jをインクリメント
                    }
                    break;                                                      //ループを抜ける
                }
                j++;                                                            //jをインクリメント
            }
        }
        //右上の判定
        if(s[a-2][b] == 2){                                                     //入力値の斜め右上が黒なら
            j = 1;                                                              //列用のカウンタ
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a-2][b] == 2 && s[a-3][b+1] == 1){                         //右上が黒且つその右上が白なら
                    s[a-2][b] = 1;                                              //白石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a-i][b+j] == 2 && s[a-i-1][b+j+1] == 1){                   //iマス右上が黒且つその右上が白なら
                    j = 1;                                                      //jをインクリメント
                    for(k = 3; k <= i; k++){                                    //ループカウンタ
                        s[a-2][b] = 1;                                          //白石(判定)を置く
                        s[a-k][b+j] = 1;                                        //白石(判定)を置く
                        j++;                                                    //jをインクリメント
                    }
                    break;                                                      //ループを抜ける
                }
                j++;                                                            //jをインクリメント
            }
        }
        //左上の判定
        if(s[a-2][b-2] == 2){                                                   //入力値の斜め左上が黒なら
            j = 3;                                                              //列用のカウンタ           
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a-2][b-2] == 2 && s[a-3][b-3] == 1){                       //左上が黒且つその左上が白なら
                    s[a-2][b-2] = 1;                                            //白石(判定)を置く
                    break;                                                      //ループカウンタ
                }
                if(s[a-i][b-j] == 2 && s[a-i-1][b-j-1] == 1){                   //iマス左上が黒且つその左上が白なら
                    j = 3;                                                      //列用のカウンタ
                    for(k = 3; k <= i; k++){                                    //ループカウンタ
                        s[a-2][b-2] = 1;                                        //白石(判定)を置く
                        s[a-k][b-j] = 1;                                        //白石(判定)を置く
                        j++;                                                    //jをインクリメント
                    }
                    break;                                                      //ループを抜ける
                }     
                j++;                                                            //jをインクリメント             
            }
        }
        //右下の判定
        if(s[a][b] == 2){                                                       //入力値の斜め右下が黒なら
            j = 1;                                                              //列用のカウンタ
            for(i = 1; i <= 8; i++){                                            //ループカウンタ     
                if(s[a][b] == 2 && s[a+1][b+1] == 1){                           //右下が黒且つその右上が白なら
                    s[a][b] = 1;                                                //白石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a+i][b+j] == 2 && s[a+i+1][b+j+1] == 1){                   //iマス右下が黒且つその右下が白なら
                    j = 1;                                                      //列用のカウンタ
                    for(k = 1; k <= i; k++){                                    //ループカウンタ
                        s[a][b] = 1;                                            //白石(判定)を置く
                        s[a+k][b+j] = 1;                                        //白石(判定)を置く
                        j++;                                                    //jをインクリメント
                    }
                    break;                                                      //ループを抜ける
                }
                j++;                                                            //jをインクリメント
            }
        }

        //盤面表示
        std::cout << "  1 2 3 4 5 6 7 8" << std::endl;			                //列を表示
        for(i = 0; i < tate; i++){                                              //縦に8つ表示するまでループ
            std::cout << i + 1;                                                 //行を表示
            for(j = 0; j < yoko; j++){                                          //横に8つ表示するまでループ
			    if(s[i][j] == 1){								                //配列内に1があれば
				    std::cout << " ●";							                //黒石を表示
			    }else if(s[i][j] == 2){							                //配列内に2があれば
				    std::cout << " ○";							                //白石を表示
			    }else{											                //それ以外は
				    std::cout << "  ";							                //空白を表示
			    }
            }
                std::cout << std::endl;                                         //4つ表示したら改行
        }
        std::cout << std::endl;                                                 //インデント用改行
        flag++;

        i = 0;                                                                  //ループカウンタを初期化
        j = 0;                                                                  //ループカウンタを初期化

        std::cout << "相手の番です相手は黒石です(○)" << std::endl;               //テキストを表示
        do{
            std::cout << "置きたい行(縦)を入力してください：";                   //テキストを表示
	        std::cin >> a;                                                     //数値の入力
            if(a > 8 || a < 1){                                                //指定外の数値が入力されたら
			    std::cout << "1~8の数字で入力して下さい。" <<std::endl;         //テキストを表示
		    }
	    }while(a > 8 || a < 1);                                                //指定範囲外の数値が入力されたらループ

        do{
	        std::cout << "置きたい列(横)を入力してください：";                  //テキストを表示
	        std::cin >> b;                                                     //数値の入力
            if(a > 8 || a < 1){                                                //指定外の数値が入力されたら
			    std::cout << "1~8の数字で入力して下さい。" <<std::endl;         //テキストを表示
		    }
	    }while(a > 8 || a < 1);                                                //指定範囲外の数値が入力されたらループ



        //配列の要素に白黒の判別をつける
        if(s[a-1][b-1] == 0){                                                   //入力値のマスが空白なら
            s[a-1][b-1] = 2;                                                    //黒石(判定)を置く
        }
        //縦横の相手の石の判定
        //下の処理
        if(s[a][b-1] == 1){                                                     //入力値の下マスが白なら
            for(i = 1; i <= 8; i++){                                            //ループカウンタ
                if(s[a][b-1] == 1 && s[a+1][b-1] == 0){                         //下が白且つその下が空白の時
                    break;                                                      //ループを抜ける
                }
                if(s[a][b-1] == 1 && s[a+1][b-1] == 2){                         //下が白且つその下が黒なら
                    s[a][b-1] = 2;                                              //黒石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a+i][b-1] == 1 && s[a+i+1][b-1] == 2){                     //iマス下が白且つその下が黒なら
                    for(k = 1; k <= i; k++){                                    //ループを抜ける
                        s[a][b-1] = 2;                                          //黒石(判定)を置く
                        s[a+k][b-1] = 2;                                        //黒石(判定)を置く
                    }
                    break;                                                      //ループを抜ける
                }
            }
        }
        //上の処理
        if(s[a-2][b-1] == 1){                                                   //入力値の上が白なら
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a-2][b-1] == 1 && s[a-3][b-1] == 0){                       //上が白且つその上が空白なら
                    break;                                                      //ループを抜ける
                }
                if(s[a-2][b-1] == 1 && s[a-3][b-1] == 2){                       //上が白且つその上が黒なら
                    s[a-2][b-1] = 2;                                            //黒石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a-i][b-1] == 1 && s[a-i-1][b-1] == 2){                     //さらにその上のマスが白なら
                    for(k = 1; k <= i; k++){                                    //ループカウンタ
                        s[a-2][b-1] = 2;                                        //黒石(判定)を置く
                        s[a-k][b-1] = 2;                                        //黒石(判定)を置く
                    }
                    break;                                                      //ループを抜ける
                }
            }
        }
        //右隣の処理
        if(s[a-1][b] == 1){                                                     //入力値の右隣が白なら
            for(i = 1; i <= 8; i++){                                            //ループカウンタ
                if(s[a-1][b] == 1 && s[a-1][b+1] == 0){                         //右が白且つその右が空白なら
                    break;                                                      //ループを抜ける
                }
                if(s[a-1][b] == 1 && s[a-1][b+1] == 2){                         //右が白且つその右が黒なら
                    s[a-1][b] = 2;                                              //黒石(判定)を置く
                    break;                                                      //ループを抜ける    
                }
                if(s[a-1][b+i] == 1 && s[a-1][b+i+1] == 2){                     //iマス右が白且つその右が黒なら
                    for(k = 1; k <= i; k++){                                    //ループカウンタ
                        s[a-1][b] = 2;                                          //黒石(判定)を置く
                        s[a-1][b+k] = 2;                                        //黒石(判定)を置く
                    }
                    break;                                                      //ループを抜ける
                }
            }
        }
        //左隣の処理
        if(s[a-1][b-2] == 1){                                                   //入力値の左隣が白なら 
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a-1][b-2] == 1 && s[a-1][b-3] == 0){                       //左が白且つその左が空白なら
                    break;                                                      //ループを抜ける
                }
                if(s[a-1][b-2] == 1 && s[a-1][b-3] == 2){                       //左が白且つその左が黒なら
                    s[a-1][b-2] = 2;                                            //黒石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a-1][b-i] == 1 && s[a-1][b-i-1] == 2){                     //iマス左が白且つその左が黒なら
                    for(k = 1; k <= i; k++){                                    //ループカウンタ
                        s[a-1][b-2] = 2;                                        //黒石(判定)を置く
                        s[a-1][b-k] = 2;                                        //黒石(判定)を置く
                    }
                    break;                                                      //ループを抜ける
                }
            }
        }       
        //斜めの相手の石の判定
        //左下の判定
        if(s[a][b-2] == 1){                                                     //入力値の斜め左下が白なら
            j = 1;                                                              //行用のカウンタ
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a][b-2] == 1 && s[a+1][b-3] == 2){                         //左下が白且つその左下が黒なら
                    s[a][b-2] = 2;                                              //黒石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a+j][b-i] == 1 && s[a+j+1][b-i-1] == 2){                   //iマス左下が白且つ更に斜め左下が黒なら
                    j = 1;                                                      //行用のカウンタ
                    for(k = 3; k <= i; k++){                                    //ループカウンタ
                        s[a][b-2] = 2;                                          //黒石(判定)を置く
                        s[a+j][b-k] = 2;                                        //黒石(判定)を置く
                        j++;                                                    //jをインクリメント
                    }
                    break;                                                      //ループを抜ける
                }
                j++;                                                            //jをインクリメント
            }
        }
        //右上の判定
        if(s[a-2][b] == 1){                                                     //入力値の斜め右上が白なら
            j = 1;                                                              //列用のカウンタ
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a-2][b] == 1 && s[a-3][b+1] == 2){                         //右上が白且つその右上が黒なら
                    s[a-2][b] = 2;                                              //黒石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a-i][b+j] == 1 && s[a-i-1][b+j+1] == 2){                   //iマス右上が白且つその右上が黒なら
                    j = 1;                                                      //列用のカウンタ
                    for(k = 3; k <= i; k++){                                    //ループカウンタ
                        s[a-2][b] = 2;                                          //黒石(判定)を置く
                        s[a-k][b+j] = 2;                                        //黒石(判定)を置く
                        j++;                                                    //jをインクリメント
                    }
                    break;                                                      //ループを抜ける
                }
                j++;                                                            //jをインクリメント
            }
        }
        //左上の判定
        if(s[a-2][b-2] == 1){                                                   //入力値の斜め左上が白なら
            j = 3;                                                              //列用のカウンタ
            for(i = 3; i <= 8; i++){                                            //ループカウンタ
                if(s[a-2][b-2] == 1 && s[a-3][b-3] == 2){                       //左上が白且つその左上が黒なら
                    s[a-2][b-2] = 2;                                            //黒石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a-i][b-j] == 1 && s[a-i-1][b-j-1] == 2){                   //iマス左上が白且つその左上が黒なら
                    j = 3;                                                      //列用のカウンタ
                    for(k = 3; k <= i; k++){                                    //ループカウンタ
                        s[a-2][b-2] = 2;                                        //黒石(判定)を置く
                        s[a-k][b-j] = 2;                                        //黒石(判定)を置く
                        j++;                                                    //jをインクリメント
                    }
                    break;                                                      //ループを抜ける                   
                }
                j++;                                                            //jをインクリメント
            }
        }
 
        //右下の判定
        if(s[a][b] == 1){                                                       //入力値の斜め右下が白なら
            j = 1;                                                              //列用のカウンタ
            for(i = 1; i <= 8; i++){                                            //ループカウンタ
                if(s[a][b] == 1 && s[a+1][b+1] == 2){                           //右下が白且つその右上が黒なら
                    s[a][b] = 2;                                                //黒石(判定)を置く
                    break;                                                      //ループを抜ける
                }
                if(s[a+i][b+j] == 1 && s[a+i+1][b+j+1] == 2){                   //更に斜め右下が白なら
                    j = 1;                                                      //列用のカウンタ
                    for(k = 1; k <= i; k++){                                    //ループカウンタ
                        s[a][b] = 2;                                            //黒石(判定)を置く
                        s[a+k][b+j] = 2;                                        //黒石(判定)を置く
                        j++;                                                    //jをインクリメント
                    }
                    break;                                                      //ループを抜ける
                }
                j++;                                                            //jをインクリメント
            }
        }


        //盤面表示
        std::cout << "  1 2 3 4 5 6 7 8" << std::endl;			                //列を表示
        for(i = 0; i < tate; i++){                                              //縦に8つ表示するまでループ
            std::cout << i + 1;                                                 //行を表示
            for(j = 0; j < yoko; j++){                                          //横に8つ表示するまでループ
			    if(s[i][j] == 1){								                //配列内に1があれば
				    std::cout << " ●";							                //黒石を表示
			    }else if(s[i][j] == 2){							                //配列内に2があれば
				    std::cout << " ○";							                //白石を表示
			    }else{											                //それ以外は
				    std::cout << "  ";							                //空白を表示
			    }
            }
                std::cout << std::endl;                                         //4つ表示したら改行
        }
        std::cout << std::endl;                                                 //インデント用改行

        i = 0;                                                                  //ループカウンタを初期化
        j = 0;                                                                  //ループカウンタを初期化

        //フラグ立てる場所
        flag++;

    }while(flag != 60);


}