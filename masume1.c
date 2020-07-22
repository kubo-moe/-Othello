#include<iostream>
#include<string>

void nyuryoku(int tate,int yoko);							//関数宣言

void masume(int tate, int yoko){
	int i = 0;									//ループカウンタ
	int j = 0;									//ループカウンタ
	int flag = 0;									//フラグ
	int num = 0;

	std::string s1 = "〇";								//〇を変数に代入
	std::string s2 = "●";								//●を変数に代入

	std::cout << "・リバーシを開始します。" << std::endl;
	std::cout << "・あなたは黒石(○)です。" << std::endl;
	std::cout << std::endl;


	do{
		std::cout << "  1 2 3 4" << std::endl;					//列を表示
		for(i = 1; i <= tate; i++){						//縦に四つ表示するまでループ
			std::cout << i;							//行を表示
			for(j = 1; j <= yoko; j++){					//横に四つ表示するまでループ
				if((i == 2 && j == 2) || (i == 3 && j == 3)){		//2行2列の時と3行3列の時
					std::cout << "○" ;				//初期配置の白を二回表示
				}else if((i == 2 && j == 3) || (i == 3 && j == 2)){	//2行3列の時と3行2列の時
					std::cout << "●" ;				//初期位置の黒を二回表示
				}else{
					std::cout << "　" ;				//それ以外は空白
				}
			}
			std::cout << std::endl;						//4つ表示したら改行
		}
		nyuryoku(tate, yoko);

	/* ここでプログラムが終了している(do文が動作してない) */

		if (flag > 0){
			std::cout << "もう一度操作しますか？ Yes…1 / No…0：";
			std::cin >> num;
			if(num == 0){
				break;
			}
		}
		flag++;
	}while(num == 1);

}
