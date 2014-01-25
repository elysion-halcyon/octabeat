#ifndef _GAME_H_
#define _GAME_H_

#include "bool.h"
#include "Timer.h"
#include "Bms.h"


#define LANE 8

#define JCMAX 30

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

enum Judge {
    J_PERFECT = 0,
    J_GREAT,
    J_GOOD,
    J_BAD,
    J_POOR,
};


typedef struct{
    Timer tm;
    Bms bms;

    enum State state;
    float scrMulti;
    long long int startTime;
    long long int globalFreq;
    int bmsNum[BMSMAXBUFFER];

    int onKey[LANE];
    int flashIndex[LANE];
    int flashCount[LANE][3];
    int backKeyCount[LANE];

    enum Judge judge[LANE];
    int judgeCount[LANE];
    int judgeSum[5];    //リザルト用に判定の個数を保持
	float score;
    float score_prev;
    int total;
    int combo;
    float gauge;

	int selectFlag;

	//result
	float resultRankFlag;
	int rank;
	int resultScoreBegin;
	int digitResult[7];
	int i;
	int digitResultFixed[7];
	int soundFlag;
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