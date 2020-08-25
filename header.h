void initialization(int (&s)[8][8]);
void board(int s[8][8]);
void input(int &a, int &b);
void reversi(int &a, int b, int (&s)[8][8], int &flag, int &num);
void result(int tate, int yoko, int (&s)[8][8]);
void updown(int a, int b, int white, int black, int sk, int counter,
            int (&s)[8][8]);
int diagonal(int a, int b, int white, int black, int sk, int counter,
             int (&s)[8][8]);
