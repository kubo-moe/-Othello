
void syokika(){
	int i = 0;												//ループカウンタ
    char s[4][4] = {0};

	for(i = 0; i < 4*4; i++){									
		s[4][4] = 0;										//配列内を全て0で初期化
	}

	s[1][1] = 1;											//石の有無の判別用
	s[2][2] = 1;										    //石の有無の判別用
	s[1][2] = 2;    										//石の有無の判別用
	s[2][1] = 2;	    									//石の有無の判別用
}
