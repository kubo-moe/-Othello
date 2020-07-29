#include<iostream>

void syokika();							//関数宣言
void masume(int tate, int yoko);		
int nyuryoku(int& a, int& b);
void kuro(int a, int b, int tate, int yoko);
//char shiro(int a, int b, int tate, int yoko, char *sp);


int main(void){
	int tate = 8;						//縦のマス目用
	int yoko = 8;						//横のマス目用
	int a = 0;							//行の入力用
	int b = 0;							//列の入力用

	//char s[8][8] = {0};
	//char *sp[8];

	//sp[8] = &s[8][8];

	syokika();
	masume(tate, yoko);					//盤面の表示
	nyuryoku(a, b);						//値の入力
	kuro(a, b, tate, yoko);				//石をひっくり返す
	//nyuryoku(a, b);						//値の入力
	//shiro(a, b, tate, yoko, sp[8]);	//石をひっくり返す
	return 0;
}


