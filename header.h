void initialize(int (&s)[8][8]);
void display(int s[8][8]);
void input(int &a, int &b, int (&s)[8][8]);
void reversi(int &a, int &b, int (&s)[8][8]);
void decision(int a, int b, int white, int opponent, int sk, int counter,
              int (&s)[8][8]);
int diagonal(int a, int b, int white, int opponent, int sk, int counter,
             int (&s)[8][8]);
void output(int (&s)[8][8]);
