#include<iostream>
#define kuro 1;
#define shiro 2;


void masume(int tate, int yoko){
	int i = 0;													//ループカウンタ
	int j = 0;													//ループカウンタ
	char s[4][4];
	std::cout << "・リバーシを開始します。" << std::endl;
	std::cout << "・あなたは黒石(○)です。" << std::endl;
	std::cout << std::endl;

	std::cout << "  1 2 3 4" << std::endl;						//列を表示
     for(i = 0; i < tate; i++){                                 //縦に四つ表示するまでループ
    	std::cout << i + 1;                                     //行を表示
        for(j = 0; j < yoko; j++){                              //横に四つ表示するまでループ
			if(s[i][j] == 1){
				std::cout << " ●";
			}else if(s[i][j] == 2){
				std::cout << " ○";
			}else{
				std::cout << "  ";
			}
        }
            std::cout << std::endl;                                         //4つ表示したら改行
    }

}
