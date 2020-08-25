#include <iostream>

void result(int tate, int yoko, int (&s)[8][8]) {
  int kuroishi = 0;
  int shiroishi = 0;
  int i = 0;  //ループカウンタ
  int j = 0;  //ループカウンタ

  for (i = 0; i < tate; i++) {    //縦に8つ表示するまでループ
    for (j = 0; j < yoko; j++) {  //横に8つ表示するまでループ
      if (s[i][j] == 1) {         //配列内に1があれば
        kuroishi++;
      } else if (s[i][j] == 2) {  //配列内に2があれば
        shiroishi++;
      }
    }
  }
  std::cout << "あなたの石の数は" << kuroishi << "個です。" << std::endl;
  std::cout << "あいての石の数は" << shiroishi << "個です。" << std::endl;

  if (kuroishi > shiroishi) {
    std::cout << kuroishi - shiroishi << "個差であいての勝ちです。"
              << std::endl;
  } else if (shiroishi > kuroishi) {
    std::cout << shiroishi - kuroishi << "個差であなたの勝ちです。"
              << std::endl;
  } else {
    std::cout << "引き分けです。" << std::endl;
  }
  return;
}