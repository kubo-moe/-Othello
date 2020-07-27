#include<iostream>
int nyuryoku(int& a, int& b){

	std::cout << "置きたい行(縦)を入力してください：";
	std::cin >> a;
	std::cout << "置きたい列(横)を入力してください：";
	std::cin >> b;

	return a, b;
}
