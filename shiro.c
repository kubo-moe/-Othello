#include<iostream>

int shiro(int a, int b, int tate, int yoko, char s[8][8]){

    //char s[8][8] = {0};
    int i = 0;
    int j = 0;

    s[3][3] = 1;											//石の有無の判別用
	s[4][4] = 1;										    //石の有無の判別用
	s[3][4] = 2;    										//石の有無の判別用
	s[4][3] = 2;	    									//石の有無の判別用
    int flag = 0;

    //do{

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


    //フラグ立てる場所


    //}while(flag == 0);
    //return s[i][j];
}