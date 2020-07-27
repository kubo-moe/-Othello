#include<iostream>

void return1(int a, int b, int tate, int yoko){

    char s[4][4] = {0};

    s[1][1] = 1;											//石の有無の判別用
	s[2][2] = 1;										    //石の有無の判別用
	s[1][2] = 2;    										//石の有無の判別用
	s[2][1] = 2;	    									//石の有無の判別用




    if(s[a][b] == 0){
        s[a][b] = 1;
        if(s[a + 1][b] == 2){
            s[a + 1][b] = 1;
        }else if(s[a - 1][b] == 2){
            s[a - 1][b] = 1;
        }else if(s[a][b + 1] == 2){
            s[a][b + 1] = 1;
        }else if (s[a][b - 1] == 2){
            s[a][b - 1] = 1;
        }       
    }

    //盤面表示
    std::cout << "  1 2 3 4" << std::endl;						//列を表示
     for(int i = 0; i < tate; i++){                             //縦に四つ表示するまでループ
    	std::cout << i + 1;                                     //行を表示
        for(int j = 0; j < yoko; j++){                          //横に四つ表示するまでループ
			if(s[i][j] == 1){									//配列内に1があれば
				std::cout << " ●";								//黒石を表示
			}else if(s[i][j] == 2){								//配列内に2があれば
				std::cout << " ○";								//白石を表示
			}else{												//それ以外は
				std::cout << "  ";								//空白を表示
			}
        }
            std::cout << std::endl;                              //4つ表示したら改行
    }








}