#ifndef _BMS_H_
#define _BMS_H_


#include "bool.h"


#define BMSDATA_RESOLUTION	9600		//小節分解能
#define BMSMAXBUFFER		(16*16)		//
#define BARMAX				1000
#define DATAMAX				256

// BMSチャンネル定義
#define BMS_BACKMUSIC		0x01		// その位置にきたら、自動的に再生されるWAVを指定します
#define BMS_STRETCH			0x02		// その小節の長さを定義したデータ倍します（１０進数、小数ともに使用可）
#define BMS_TEMPO			0x03		// 再生テンポ（ＢＰＭ / １分間の四分音符数）の途中変更（１６進数）
#define BMS_BACKANIME		0x04		// バックグラウンドアニメーション機能
#define BMS_EXTENEDOBJ		0x05		// 落下してくるオブジェを別のキャラクターナンバーのものにすり替える機能
#define BMS_CHGPOORANI		0x06		// POORを出したときに表示される画像を変更
#define BMS_LAYERANIME		0x07		// Ch.04で指定したBGAの上にかぶせるBMPを指定できます
#define BMS_BPMINDEX		0x08		// BPMのインデックス指定(新)


//小節(bar)線
typedef struct {
	bool flag;
	long long int timing;
	int data;
} BAR, *LPBAR;

//小節倍率
typedef struct {
	int index;
	float magnitude;
} BARMAGNI, *LPBARMAGNI;


//BPM
typedef struct {
	float bpm;
} BPMINDEX, *LPBPMINDEX;


//BMSヘッダ
typedef struct {
	int player;
	char genre[256];//256文字まで
	char title[256];
	char artist[256];
	float bpm;
	int playLevel;
	int rank;
	//int wavVol;
	//int total;
	//char midiFile[MAX_PATH];
	//char stagePic[MAX_PATH];
	//char movie[MAX_PATH];
	//GUID guid;
	int endBar;
	int maxCount;
	BPMINDEX bpmIndex[BMSMAXBUFFER];
} BMSHEADER, *LPBMSHEADER;

//BMSデータ
typedef struct { 
	bool flag;
	long long int timing;
	long data;
	float fdata;	//BPM情報の際はこっちに
} BMSDATA, *LPBMSDATA;


//Bmsクラス本体
typedef struct{
	BMSHEADER header;
	//LPBMSDATA data[BMSMAXBUFFER];
	BMSDATA data[BMSMAXBUFFER][DATAMAX];// //8(NORMAL(11-19))+8(LONG(51-59))+BPM(08(03))+BARMAGNI(02)+STOP?
	int dataNum[BMSMAXBUFFER];

	//LPBAR bar;
	BAR bar[BARMAX];//BMSフォーマット上1000までできるべきだが、256あればだいたい耐える
	int barNum;
	//LPBARMAGNI barMagni;
	BARMAGNI barMagni[BARMAX];//小節数と同数
	int barMagniNum;
} Bms;


void Bms_ctor(Bms* this);
//dtor()
bool Bms_clear(Bms* this);
bool Bms_restart(Bms* this);

//BMSカウント取得
int Bms_getCountFromTime(Bms* this, double sec);
//load関係
bool Bms_load(Bms* this, char* f);
	bool Bms_getHeader(Bms* this, char* f);
	bool Bms_loadBmsData(Bms* this, char* f);
		int Bms_getCommand(char* s);
		bool Bms_getCommandString(char* src, char* dst);
		bool Bms_addData(Bms* this, int ch, int startPos, float dat);

int Bms_atoi3610(char* s);
float Bms_atof(char* s);	//atofが使えないっぽい
bool Bms_sort(Bms* this, int ch);


#endif