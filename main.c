#include<iostream>

void syokika();							//関数宣言
void masume(int tate, int yoko);		
int nyuryoku(int& a, int& b);
int kuro(int a, int b, int tate, int yoko);
int shiro(int a, int b, int tate, int yoko, char s);


int main(void){
	int tate = 8;						//縦のマス目用
	int yoko = 8;						//横のマス目用
	int a = 0;							//行の入力用
	int b = 0;							//列の入力用
	int c = 0;
	int d = 0;
	char s[8][8] = {0};
	syokika();
	masume(tate, yoko);					//盤面の表示
	nyuryoku(a, b);						//値の入力
	kuro(a, b, tate, yoko);				//石をひっくり返す
	nyuryoku(a, b);						//値の入力
	shiro(a, b, tate, yoko, s[8][8]);	//石をひっくり返す
	return 0;
}


