#include<iostream>
#include<stdio.h>

void syokika();
void return1(int a, int b, int tate, int yoko){
    char s[4][4] = {0};
    int i = 0;
    int j = 0;

    syokika();

    	std::cout << "  1 2 3 4" << std::endl;						//列を表示
     for(i = 0; i < tate; i++){                                 //縦に四つ表示するまでループ
    	std::cout << i + 1;                                     //行を表示
        for(j = 0; j < yoko; j++){                              //横に四つ表示するまでループ
           // printf("%d ", s[i][j]);

			if(s[i][j] == 1){									//配列内に1があれば
				std::cout << " ●";								//黒石を表示
			}else if(s[i][j] == 2){								//配列内に2があれば
				std::cout << " ○";								//白石を表示
			}else if(s[i][j] == 0){										//それ以外は
				std::cout << "  ";								//空白を表示
			}
        }
            std::cout << std::endl;                              //4つ表示したら改行
    }








}