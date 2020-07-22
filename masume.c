#include<iostream>
#include<string>

void nyuryoku(int tate,int yoko, int i, int j);					//関数宣言

void masume(int tate, int yoko){
	int i = 0;								//ループカウンタ
	int j = 0;								//ループカウンタ

	std::string s1 = "〇";							//〇を変数に代入
	std::string s2 = "●";							//●を変数に代入

	std::cout << "・リバーシを開始します。" << std::endl;
	std::cout << "・あなたは黒石(○)です。" << std::endl;
	std::cout << std::endl;

	std::cout << "  1 2 3 4" << std::endl;					//列を表示

	for(i = 0; i < tate; i++){						//縦に四つ表示するまでループ
		std::cout << i + 1;						//行を表示
		for(j = 0; j < yoko; j++){					//横に四つ表示するまでループ
			if((i == 1 && j == 1) || (i == 2 && j == 2)){		//2行2列の時と3行3列の時
				std::cout << "○" ;				//初期配置の白を二回表示
			}else if((i == 1 && j == 2) || (i == 2 && j == 1)){	//2行3列の時と3行2列の時
				std::cout << "●" ;				//初期位置の黒を二回表示
			}else{
				std::cout << "　" ;				//それ以外は空白
			}
		}
		std::cout << std::endl;						//4つ表示したら改行
	}
	nyuryoku(tate, yoko, i, j);
}
