#include<iostream>

void syokika();							//関数宣言
void masume(int tate, int yoko);		
int nyuryoku(int& a, int& b);
//void return1(int a, int b);

#define kuro 1;
#define shiro 2;
extern char s;

int main(void){
	int tate = 4;						//縦のマス目用
	int yoko = 4;						//横のマス目用
	int a = 0;							//行の入力用
	int b = 0;							//列の入力用
	syokika();
	masume(tate, yoko);					//盤面の表示
	nyuryoku(a, b);						//値の入力
	//return1(a, b);						//石をひっくり返す


	
	return 0;
}

