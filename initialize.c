void initialize(int (&s)[8][8]) {
  s[3][3] = 1;  //石の有無の判別用
  s[4][4] = 1;  //石の有無の判別用
  s[3][4] = 2;  //石の有無の判別用
  s[4][3] = 2;  //石の有無の判別用
}