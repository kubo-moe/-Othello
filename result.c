#include <iostream>

void result(int (&s)[8][8]) {
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
  return;
}