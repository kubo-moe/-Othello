#include<iostream>

int kuro(int a, int b, int tate, int yoko){

    char s[8][8] = {0};
    int i = 0;
    int j = 0;

    s[3][3] = 1;											//石の有無の判別用
	s[4][4] = 1;										    //石の有無の判別用
	s[3][4] = 2;    										//石の有無の判別用
	s[4][3] = 2;	    									//石の有無の判別用
    int flag = 0;
    int num = 1;

    do{
        if(flag >= 2){
            num += 1;
            std::cout << num << "回目" << std::endl;        //回数表示
            std::cout << "・あなたの番です。白石(●)" << std::endl;
            std::cout << "置きたい行(縦)を入力してください：";
	        std::cin >> a;
            std::cout << "置きたい列(横)を入力してください：";
	        std::cin >> b;
        }

        //配列の要素に白黒の判別をつける
        if(s[a-1][b-1] == 0){
            s[a-1][b-1] = 1;
            if(s[a][b-1] == 2){
                s[a][b-1] = 1;
            }else if(s[a-2][b-1] == 2){
                s[a-2][b-1] = 1;
            }else if(s[a-1][b] == 2){
                s[a-1][b] = 1;
            }else if (s[a-1][b-2] == 2){
                s[a-1][b-2] = 1;
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

    std::cout << "相手の番です相手は黒石です(○)" << std::endl;
    std::cout << "置きたい行(縦)を入力してください：";
	std::cin >> a;
	std::cout << "置きたい列(横)を入力してください：";
	std::cin >> b;

            //配列の要素に白黒の判別をつける
        if(s[a-1][b-1] == 0){
            s[a-1][b-1] = 2;
            if(s[a][b-1] == 1){
                s[a][b-1] = 2;
            }else if(s[a-2][b-1] == 1){
                s[a-2][b-1] = 2;
            }else if(s[a-1][b] == 1){
                s[a-1][b] = 2;
            }else if (s[a-1][b-2] == 1){
                s[a-1][b-2] = 2;
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

    flag++;

    //フラグ立てる場所


    }while(flag != 10);

    
}