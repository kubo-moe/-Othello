#include<iostream>
#include<string>
int nyuryoku(int tate, int yoko){
	int x = 0;
	int y = 0;
	std::cout << "置きたい行(縦)を入力してください：";
	std::cin >> x;
	std::cout << "置きたい列(横)を入力してください：";
	std::cin >> y;

	return x, y;
}
