#include<iostream>

int nyuryoku(int& x, int& y){
	std::cout << "置きたい行(縦)を入力してください：";
	std::cin >> x;
	std::cout << "置きたい列(横)を入力してください：";
	std::cin >> y;
	return x, y;
}
