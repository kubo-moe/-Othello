void initialization(int (&s)[8][8]);
void board(int s[8][8]);
void input(int &a, int &b, int (&s)[8][8]);
void reversi(int &a, int &b, int (&s)[8][8]);
void updown(int a, int b, int white, int black, int sk, int counter,
            int (&s)[8][8]);
int diagonal(int a, int b, int white, int black, int sk, int counter,
             int (&s)[8][8]);
void result(int (&s)[8][8]);
