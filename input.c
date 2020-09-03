#include <iostream>

#include "header.h"

void output(int (&s)[8][8]) {
  int blackstone = 0;
  int whitestone = 0;
  int i = 0;  //ループカウンタ
  int j = 0;  //ループカウンタ

  for (i = 0; i < 8; i++) {    //縦に8つ表示するまでループ
    for (j = 0; j < 8; j++) {  //横に8つ表示するまでループ
      if (s[i][j] == 1) {      //配列内に1があれば
        blackstone++;
      } else if (s[i][j] == 2) {  //配列内に2があれば
        whitestone++;
      }
    }
  }
  std::cout << "あなたの石の数は" << blackstone << "個です。" << std::endl;
  std::cout << "あいての石の数は" << whitestone << "個です。" << std::endl;

  if (blackstone > whitestone) {
    std::cout << blackstone - whitestone << "個差であいての勝ちです。"
              << std::endl;
  } else if (whitestone > blackstone) {
    std::cout << whitestone - blackstone << "個差であなたの勝ちです。"
              << std::endl;
  } else {
    std::cout << "引き分けです。" << std::endl;
  }
}
void input(int &a, int &b, int (&s)[8][8]) {
  int counter = 0, num = 1;
  const char *character[30][30];  //日本語の文字列の格納用
  const char *stone[30][30];      //持石の文字列の格納用
  do {
    if (counter == 0) {
      character[30][30] = "あなた";
      stone[30][30] = "白石(●)";
    } else {
      character[30][30] = "相手";
      stone[30][30] = "黒石(○)";
    }
    std::cout << std::endl;
    std::cout << num << "回目" << std::endl;  //回数表示
    std::cout << "・" << character[30][30] << "の番です。" << stone[30][30]
              << std::endl;  //テキストを表示;
    std::cout << "・終了するときは9を入力してください。" << std::endl;
    do {
      std::cout << "・置きたい行(縦)を入力してください：";
      std::cin >> a;
      if (a == 9) {
        return;
      } else if (a == 0) {
        break;
      }
      if (a > 8 || a < 1) {
        std::cout << "・1~8の数字で入力して下さい。" << std::endl;
      }
    } while (a > 8 || a < 1);
    do {
      std::cout << "・置きたい列(横)を入力してください：";
      std::cin >> b;

      if (b > 8 || b < 1) {
        std::cout << "・1~8の数字で入力して下さい。" << std::endl;
      }
    } while (b > 8 || b < 1);
    std::cout << std::endl;
    reversi(a, b, s);  //判定処理関数へ移動
    if (counter == 0) {
      counter = 1;
    } else {
      counter = 0;
    }
    num++;

  } while (num != 80);
}
