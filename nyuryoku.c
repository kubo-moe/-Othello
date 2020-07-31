#include<iostream>

int nyuryoku(int& a, int& b){


	do{
		std::cout << "置きたい行(縦)を入力してください：";
		std::cin >> a;

		if(a > 8 || a < 1){
			std::cout << "1~8の数字で入力して下さい。" <<std::endl;
		}
	}while(a > 8 || a < 1);

	do{
		std::cout << "置きたい列(横)を入力してください：";
		std::cin >> b;

		if(b > 8 || b < 1){
			std::cout << "1~8の数字で入力して下さい。" <<std::endl;
		}
	}while(b > 8 || b < 1);

	return a, b;
}
