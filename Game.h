#ifndef _GAME_H_
#define _GAME_H_

#include "bool.h"
#include "Timer.h"
#include "Bms.h"


#define LANE 8


enum State {
    G_INIT = 0,
    G_TITLE,
    G_SELECT_INIT,
    G_SELECT,
    G_MAIN_INIT,
    G_MAIN,
    G_END,
	G_RESULT_INIT,
    G_RESULT,
};


typedef struct{
    Timer tm;
    Bms bms;

    enum State state;
    float scrMulti;
    long long int startTime;
    long long int globalFreq;
    int bmsNum[16+2+2+16];      //36 16(note:描画)+2(bpm)+2(予備(ここまでで+20になる))+16(note:判定)

    int onKey[LANE];
    int flashIndex[LANE];
    int flashCount[LANE][3];
    int backKeyCount[LANE];
	int score;

	//select
	float x0, y0,scale;
	float x1, y1,xr1,yr1;
	float x2, y2, xr2, yr2;
	float x3,y3, xr3, yr3;
	int selectFlag;

	//result
	float resultRankFlag;
	int rank;
	int resultScoreBegin;
	int digitResult[7];
	int i;
	int digitResultFixed[7];
} Game;


void Game_ctor(Game* this);
bool Game_run(Game* this);

bool Game_init(Game* this);	//soundとかやる？
bool Game_flash(Game* this);

bool Game_gameInit(Game* this);
int Game_gameRun(Game* this, bool demo);

//State追加したらこっちも
bool Game_title(Game* this);
bool Game_selectInit(Game* this);
int Game_select(Game* this);
bool Game_resultInit(Game* this);
bool Game_result(Game* this);


#endif