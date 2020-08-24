#include <iostream>
//関数宣言
int syokika(int (&s)[8][8]);
void masume(int tate, int yoko, int s[8][8], int &flag);
int nyuryoku(int &a, int &b);
int shiro(int &a, int b, int tate, int yoko, int (&s)[8][8], int &flag, int &num);
void kekka(int tate, int yoko, int (&s)[8][8]);

int main(void)
{
	int tate = 8, yoko = 8; //縦と横のマス目用
	int a = 0, b = 0;		//行列の入力用
	int s[8][8];			//オセロの石の格納用
	int flag = 0;			//判定用フラグ
	int num = 1;			//回数表示用

	syokika(s);							   //配列の要素を初期化
	masume(tate, yoko, s, flag);		   //盤面の表示
	nyuryoku(a, b);						   //値の入力
	shiro(a, b, tate, yoko, s, flag, num); //相手の石を反転する
	kekka(tate, yoko, s);				   //結果を表示する
	return 0;
}
