#ifndef _GAME_H_
#define _GAME_H_

#include "bool.h"
#include "Timer.h"
#include "Bms.h"
#include "fumen.h"
#include <amlib.h>
#include <agdraw.h>

#define PI (3.14159265358979f)

#define LANE 8

#define JCMAX 30
#define OPTIONMAX 7

//Judge Timing
//参考：16分音符ぶん=9600/16=600
#define JT_PF 250
#define JT_GR 450
#define JT_GD 550
#define JT_BD 650
//#define JT_PR

//SCore倍率
#define SC_PF (1.0f)
#define SC_GR (0.7f)
#define SC_GD (0.3f)
#define SC_BD (0.0f)
#define SC_PR (0.0f)

//Gauge Normal倍率
#define GN_PF (1.0f)
#define GN_GR (1.0f)
#define GN_GD (0.5f)
#define GN_BD (-1.0f)
#define GN_PR (-2.0f)

//Gauge Hard倍率
#define GH_PF (0.5f)
#define GH_GR (0.3f)
#define GH_GD (0.1f)
#define GH_BD (-1.0f)
#define GH_PR (-3.0f)


enum State {
    G_INIT = 0,
	G_TITLE_INIT,
    G_TITLE,
    G_SELECT_INIT,
    G_SELECT,
    G_OPTION,
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
    BMSHEADER header;
    int bpmMin;
    int bpmMax;
    int highscore;
} SelectInfo;

//optionSelectFlag以外の要素数をOPTIONMAXに定義
typedef struct{
    float scrMulti;
    int shift;
    bool reverse;
    int random;
    int appearance;
    int gauge;
    bool demo;
    int optionSelectFlag;
} Option;


typedef struct{
    Timer tm;
    Bms bms;

    SelectInfo selectInfo[FUMENMAX];
    Option option;

    enum State state;
    float scrMulti;
    long long int startTime;
    long long int globalFreq;
    int bmsNum[BMSMAXBUFFER];

    int onKey[LANE];
    int flashIndex[LANE];
    int flashCount[LANE][3];
    int backKeyCount[LANE];

    int laneIndex[LANE];
    enum Judge judge[LANE];
    int judgeCount[LANE];
    int judgeSum[5];    //リザルト用に判定の個数を保持
	float score;
    float score_prev;
    int total;
    int combo;
    int comboMax;
    float gauge;
    int voiceFlag;

	//title
	int titleFlag;
	int titleCharFlag;
	int titleCharLimitFlag;

	//select
	int selectFlag;
    int selectTrialCount;
    bool selectTrialFlag;

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
bool Game_titleInit(Game* this);
bool Game_title(Game* this);
bool Game_selectInit(Game* this);
int Game_select(Game* this);
bool Game_resultInit(Game* this);
bool Game_result(Game* this);

bool Game_option(Game* this);

//x,y:左上の座標
//w,h:一文字の大きさ
//track:字間の幅
bool charDraw(AGDrawBuffer *DBuf, char c, int x, int y, int w, int h);
bool strDraw(AGDrawBuffer *DBuf, char *s, int x, int y, int w, int h, int track);

#endif