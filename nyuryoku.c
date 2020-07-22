#include<iostream>
#include<string>
void nyuryoku(int tate, int yoko, int i, int j){
	int x = 0;
	int y = 0;
	std::cout << "置きたい行(縦)を入力してください：";
	std::cin >> x;
	std::cout << "置きたい列(横)を入力してください：";
	std::cin >> y;

	std::cout << "  1 2 3 4" << std::endl;

	for(i = 1; i <= tate; i++){                                             //縦に四つ表示するまでループ
		std::cout << i;                                        		//行を表示
	        for(j = 1; j <= yoko; j++){                                     //横に四つ表示するまでループ
			if(i == x && j == y){
				std::cout << "○" ;
			}else if((i == 2 && j == 2) || (i == 3 && j == 3)){     //2行2列の時と3行3列の時
			        std::cout << "○" ;                             //初期配置の白を二回表示
			}else if((i == 2 && j == 3) || (i == 3 && j == 2)){     //2行3列の時と3行2列の時
			        std::cout << "●" ;                             //初期位置の黒を二回表示
		        }else{
			        std::cout << "　" ;                        	//それ以外は空白
		   	}
		}
		std::cout << std::endl;
	}


}
