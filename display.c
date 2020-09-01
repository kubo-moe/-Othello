#include <iostream>

void display(int s[8][8]) {
  std::cout << "・リバーシを開始します。" << std::endl;
  std::cout << "・あなたは白石(●)です。" << std::endl;
  std::cout << std::endl;

  std::cout << "  1 2 3 4 5 6 7 8" << std::endl;  //列を表示
  for (int i = 0; i < 8; i++) {    //縦に四つ表示するまでループ
    std::cout << i + 1;            //行を表示
    for (int j = 0; j < 8; j++) {  //横に四つ表示するまでループ
      if (s[i][j] == 1) {          //配列内に1があれば
        std::cout << " ●";         //敵石を表示
      } else if (s[i][j] == 2) {   //配列内に2があれば
        std::cout << " ○";         //白石を表示
      } else {                     //それ以外は
        std::cout << "  ";         //空白を表示
      }
    }
    std::cout << std::endl;  // 4つ表示したら改行
  }
}