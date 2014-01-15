//ag
#include <amlib.h>
#include <agdraw.h>
#include <agetool.h>
#include <agtransfer.h>
#include <vdpreg.h>
#include <agesndmgr.h>  //音

#include "bool.h"
#include "pad.h"        //パッド
#include "Game.h"
#include "Bms.h"        //デバッグ用なので完成したらいらないかも
#include "fumen.h"
#include "export.h"

#define PI (3.14159265358979f)

AGESoundManagerData SndMgr;

//Gameクラス(もどき)
//git test
// コンストラクタ
void Game_ctor(Game* this){
    //各要素の初期化
    Timer_ctor(&this->tm);
    Bms_ctor(&this->bms);

    this->state = G_INIT;
    this->scrMulti = 1.0f;
    this->startTime = 0;
    this->globalFreq = 0;
    memset(this->bmsNum, 0, sizeof(this->bmsNum));

    memset(this->onKey, 0, sizeof(this->onKey));
    memset(this->flashIndex, 0, sizeof(this->flashIndex));
    memset(this->flashCount, 0, sizeof(this->flashCount));
    memset(this->backKeyCount, 0, sizeof(this->backKeyCount));

    return;
}


// 初期化＆ゲーム形成 // いらない？
bool Game_init(Game* this){
    return TRUE;
}


// ロード済みデータの開放 // この環境だとメモリいじると止まったりするのでやらないほうがいい？
bool Game_flash(Game* this){
    //bms.Clear();
    return TRUE;
}

SNDHANDLE handle;
// ゲームメインルーチン
bool Game_run(Game* this){
    bool loop = TRUE;


    //おまじない //どこかで一回やればいい
    agpDisableCpuInterrupts();     //割り込みを禁止する
    aglInitialize();               //ライブラリを初期化する
    agpEnableCpuInterrupts();      //割り込みを許可する

//サウンドおまじない
ageSndMgrInit(&SndMgr, AGE_SOUND_ROM_OFFSET);
{ int i; for(i=0; i<AG_SND_MAX_MASTERVOLUME; ++i)ageSndMgrSetMasterVolume(i,255); }
ageSndMgrSetChannelVolume(0,128);
ageSndMgrSetChannelVolume(1,128);
handle = ageSndMgrAlloc(AS_SND_M64, 0, 1, AGE_SNDMGR_PANMODE_LR12, 0);
ageSndMgrSetVolume(handle, 192);
ageSndMgrSetPan(handle, 128);


    if(this->state==G_INIT) _dprintf("\nG_INIT\n");

    while(loop){
        int tmpState = this->state;
ageSndMgrRun();//終わったOneShotを自動でReleaseしてくれる
        switch(this->state){
        case G_INIT:
            if(Game_init(this))
{
if(ageSndMgrIsPlay) ageSndMgrStop(handle);
ageSndMgrRelease(handle);
handle = ageSndMgrAlloc(AS_SND_M64, 0, 1, AGE_SNDMGR_PANMODE_LR12, 0);
ageSndMgrPlay(handle);
                this->state = G_TITLE;
}            else
                this->state = G_END;
            break;
        case G_TITLE:
            if(Game_title(this))
                this->state = G_SELECT_INIT;
            else
                ;
            break;
        case G_SELECT_INIT:
            if(Game_selectInit(this))
{
if(ageSndMgrIsPlay) ageSndMgrStop(handle);
ageSndMgrRelease(handle);
handle = ageSndMgrAlloc(AS_SND_CLAP1, 0, 1, AGE_SNDMGR_PANMODE_LR12, 0);
ageSndMgrPlay(handle);
                this->state = G_SELECT;
}            else
                this->state = G_END;
            break;
        case G_SELECT:
            switch(Game_select(this)){
            case 1:
                this->state = G_MAIN_INIT;
                break;
            case -1:
                this->state = G_INIT;
                break;
            default:
                break;
            }
            break;
        case G_MAIN_INIT:
            if(Game_gameInit(this))
{
if(ageSndMgrIsPlay) ageSndMgrStop(handle);
                this->state = G_MAIN;
}            else
                this->state = G_END;
            break;
        case G_MAIN:
            if(Game_gameRun(this,FALSE))
                this->state = G_RESULT; //正常終了
            else
                ;
            break;
		case G_RESULT_INIT:
            if(Game_resultInit(this))
{
if(ageSndMgrIsPlay) ageSndMgrStop(handle);
                this->state = G_RESULT;
}          
        case G_RESULT:
            if(Game_result(this))
                this->state = G_SELECT_INIT;
            else
                ;
            break;
        case G_END:
            //Game_flash(&this);
            loop = FALSE;
            break;
        default:
            _dprintf("!!DEFAULT!!\n");
            return FALSE;
            break;
        }

        //デバッグ用
        if(tmpState!=this->state){
            switch(this->state){
            case G_INIT:
                _dprintf("G_INIT\n");
                break;
            case G_TITLE:
                _dprintf("G_TITLE\n");
                break;
            case G_SELECT_INIT:
                _dprintf("G_SELECT_INIT\n");
                break;
            case G_SELECT:
                _dprintf("G_SELECT\n");
                break;
            case G_MAIN_INIT:
                _dprintf("G_MAIN_INIT\n");
                break;
            case G_MAIN:
                _dprintf("G_MAIN\n");
                break;
            case G_RESULT:
if(ageSndMgrIsPlay) ageSndMgrStop(handle);
ageSndMgrRelease(handle);
handle = ageSndMgrAlloc(AS_SND_CLAP2, 0, 1, AGE_SNDMGR_PANMODE_LR12, 0);
ageSndMgrPlay(handle);
                _dprintf("G_RESULT\n");
                break;
            case G_END:
                _dprintf("G_END\n");
                break;
            }
        }
    }
    return TRUE;
}


// メインゲーム初期化
bool Game_gameInit(Game* this){
    //テクスチャや音のロード　//いらない？

    if(!Bms_load(&this->bms, fumen[1]))
        return FALSE;

    //初期化
    this->scrMulti = 1.0f;
    memset(this->bmsNum, 0, sizeof(this->bmsNum));
    memset(this->onKey, 0, sizeof(this->onKey));
    memset(this->flashIndex, 0, sizeof(this->flashIndex));
    memset(this->flashCount, 0, sizeof(this->flashCount));
    memset(this->backKeyCount, 0, sizeof(this->backKeyCount));
	this->score=0;
    this->globalFreq = 199986000;
    this->startTime = AG4REG.SYSMNTR;
    Timer_start(&(this->tm), 60);
/////////////////////////////////////////////////////////////////////////////////
//デバッグ用
/*    _dprintf("\n\n[Header]\n");
    _dprintf("player:%d  ", this->bms.header.player);
    _dprintf("title:%s  ", this->bms.header.title);
    _dprintf("genre:%s  ", this->bms.header.genre);
    _dprintf("artist:%s  ", this->bms.header.artist);
    _dprintf("BPM:%f  ", this->bms.header.bpm);
    _dprintf("playLevel:%d  ", this->bms.header.playLevel);
    _dprintf("rank:%d  ", this->bms.header.rank);
    _dprintf("endBar:%d  ", this->bms.header.endBar);
    _dprintf("maxCount:%d  ", this->bms.header.maxCount);
    _dprintf("bpmIndex:");{int i;for(i=0;i<BMSMAXBUFFER;i++)_dprintf("%d,",this->bms.header.bpmIndex[i]);}

    _dprintf("\n\n[Data]\n");
    {int i,j;for(i=0;i<BMSMAXBUFFER;i++){
        for(j=0;j<DATAMAX;j++){
            //if(this->bms.data[i][j].flag!=0 && this->bms.data[i][j].timing!=0 && this->bms.data[i][j].data!=0 && this->bms.data[i][j].fdata!=0)
            if(this->bms.data[i][j].flag==TRUE){
                //_dprintf("[%d][%d](%d,%d,%d,%f) ",i,j,f,t,d,fd);  //_dprintfのバグか仕様かで、d,fdが0になる？
                _dprintf("[%3d]",i);
                _dprintf("[%3d]",j);
                _dprintf("(%d,",this->bms.data[i][j].flag);
                _dprintf("%8lld,",this->bms.data[i][j].timing);
                _dprintf("%4d,",this->bms.data[i][j].data);
                _dprintf("%4f)\n",this->bms.data[i][j].fdata);
                //_dprintf("[%d,%d],",i,j);
            }
    }}}

    _dprintf("\n\n[DataNum]");
    {int i;for(i=0;i<BMSMAXBUFFER;i++)_dprintf("%d,",this->bms.dataNum[i]);}

    _dprintf("\n\n[Bar]");
    {int i;for(i=0;i<BARMAX;i++)if(this->bms.bar[i].flag==TRUE)
        _dprintf("[%d](%d,%lld,%d)",i,this->bms.bar[i].flag,this->bms.bar[i].timing,this->bms.bar[i].data);}
    _dprintf(" barNum:%d",this->bms.barNum);

    _dprintf("\n\n[BarMagni]");
    {int i;for(i=0;i<BARMAX;i++)if(this->bms.barMagni[i].index!=0 && this->bms.barMagni[i].magnitude!=0)_dprintf("[%d](%d,%.3f)",i,this->bms.barMagni[i].index,this->bms.barMagni[i].magnitude);}
    _dprintf(" barMagniNum:%d",this->bms.barMagniNum);
*/
//    _dprintf(" <%d>", sizeof(this->bms.data[0]));
/////////////////////////////////////////////////////////////////////////////////
    return TRUE;
}


// ゲーム実行ループ
int Game_gameRun(Game* this, bool demo){
    const int index[LANE] = {0,1,2,3,4,7,8,5};
    //const int obj_kind[LANE] = {0,1,0,1,0,1,0,1};
    //const int obj_angle[LANE] = {0,45,90,135,180,225,270,315};
    int i, j, k, l, nowCount,w,h,digit[3];

    l = Timer_run(&this->tm);
    for(k=0; k<l; k++){
        for(j=0; j<LANE; j++)
            for(i=0; i<3; i++)
                if(this->flashCount[j][i]>0)
                    this->flashCount[j][i] -= 2;

        for(i=0; i<LANE; i++)
            if(this->backKeyCount[i]>0)
                this->backKeyCount[i] -= 2;

        //scroll幅変更//ボタン的に無理？
    }

    nowCount = Bms_getCountFromTime(&this->bms, (double)this->tm.count/this->tm.fps);

    if(this->bms.header.maxCount + BMSDATA_RESOLUTION <= nowCount)
        return 1;
   
    //曲の再生//突貫
if(!ageSndMgrIsPlay(handle) && nowCount > BMSDATA_RESOLUTION){
ageSndMgrRelease(handle);
handle = ageSndMgrAlloc(AS_SND_M4, 0, 1, AGE_SNDMGR_PANMODE_LR12, 0);
ageSndMgrPlay(handle);
}

    //判定とか
    if(demo){
        for(j=0; j<LANE; j++){
            int ind = index[j]+11;
            for(i=this->bmsNum[ind+20]; i<this->bms.dataNum[ind]; i++){
                LPBMSDATA bf = &this->bms.data[ind][i];
                if(nowCount < bf->timing)
                    break;
                if(bf->flag){
                    if(nowCount >= bf->timing){
                        bf->flag = FALSE;
                        this->bmsNum[ind+20] = i+1;
                        ageSndMgrPlayOneshot(AS_SND_CLAP1, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
                        //this->flashCount[j][this->flashIndex[j]] = 45;
                        //this->flashIndex[j]++;
                        //if(this->flashIndex[j]>2)
                        //    this->flashIndex[j] = 0;
                        this->backKeyCount[j] = 30;
                    }
                }
            }
        }
    } else {
        u8 keyNum[LANE] = {PAD_RIGHT,PAD_A,PAD_DOWN,PAD_B,PAD_LEFT,PAD_X,PAD_UP,PAD_Y};
        PadRun();
        for(j=0; j<LANE; j++){
            int ind = index[j]+11;
            if(PadLvl()&keyNum[j]){
                this->backKeyCount[j] = 30;
                if(PadTrg()&keyNum[j]){
                    for(i=this->bmsNum[j+11+20]; i<this->bms.dataNum[ind]; i++){
                        LPBMSDATA bm = &this->bms.data[ind][i];
                        if(bm->flag){
                            if((nowCount-625)<bm->timing && bm->timing<(nowCount+625)){
                                bm->flag = FALSE;
                                this->bmsNum[j+11+20] = i+1;
                                ageSndMgrPlayOneshot(AS_SND_CLAP1, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
                                //this->flashCount[j][this->flashIndex[j]] = 45;
                                //this->flashIndex[j]++;
                                //if(this->flashIndex[j]>2)
                                //    this->flashIndex[j] = 0;
                                break;
                            }
                        }
                    }
                }
            }

            for(i=this->bmsNum[j+11+20]; i<this->bms.dataNum[ind]; i++){
                LPBMSDATA bm = &this->bms.data[ind][i];
                if(bm->flag){
                    if(bm->timing < nowCount-625){
                        //POOR処理

                        bm->flag = FALSE;
                        this->bmsNum[j+11+20] = i+1;
                        break;
                    }
                }
            }
        }
    }

    {
        //描画開始
        u32 DrawBuffer[4096*10];
        AGDrawBuffer DBuf;
        AGPolyC *pLane, *pLight, *pLine;

        float x0 = (FB_WIDTH/2)<<2, y0 = (FB_HEIGHT/2)<<2;
        float m=0.9, scale = 4*m*FB_HEIGHT/2, lw=0.003, ow=0.02, n=0.75; //lw:line　width

        agDrawBufferInit(&DBuf, DrawBuffer);
        agDrawSETDAVR(&DBuf, 0, 0, aglGetDrawFrame(), 0, 0);
        agDrawSETDAVF(&DBuf, 0, 0, FB_WIDTH << 2, FB_HEIGHT << 2);
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);

        //背景
        agDrawSETFCOLOR(&DBuf, ARGB(0, 0, 0, 0));
        agDrawRECTANGLE(&DBuf, 0, 0, FB_WIDTH << 2, FB_HEIGHT << 2);

        //レーン
        pLane = agDrawTRIANGLE_C(&DBuf, LANE+2-1, 0, 0, 1, 1);
        pLane->x = x0;
        pLane->y = y0;
        pLane++;
        pLane->x = x0 + scale/m * cosf(2*PI*(-1)/16);
        pLane->y = y0 + scale/m * sinf(2*PI*(-1)/16);
        pLane++;
        for(i=0; i<LANE; i++){
            pLane->x = x0 + scale/m * cosf(2*PI*(2*i+1)/16);
            pLane->y = y0 + scale/m * sinf(2*PI*(2*i+1)/16);
            //単色
            //if(i%2==0)pLane->argb = ARGB(0,200,20,20);
            //else pLane->argb = ARGB(0, 20,20,200);
            //リズムで変わる
            if(i%2==0)pLane->argb = ARGB(0, 135+(nowCount%2400)/20,20,20);
            else pLane->argb = ARGB(0, 20,20,135+(nowCount%2400)/20);
            pLane++;
        }

        //レーン光
agDrawSETDBMODE(&DBuf, 0xff , AG_BLEND_NORMAL , 0, 1);
        pLight = agDrawTRIANGLE_C(&DBuf, LANE+2-1, 0, 0, 1, 1);

        pLight->x = x0;
        pLight->y = y0;
        pLight++;
        pLight->x = x0 + scale/m * cosf(2*PI*(-1)/16);
        pLight->y = y0 + scale/m * sinf(2*PI*(-1)/16);
        pLight++;
        for(i=0; i<LANE; i++){
            pLight->x = x0 + scale/m * cosf(2*PI*(2*i+1)/16);
            pLight->y = y0 + scale/m * sinf(2*PI*(2*i+1)/16);
            pLight->argb = ARGB(this->backKeyCount[i] *6, 200,200,200);
            pLight++;
        }

        //判定線
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
        pLine = agDrawTRIANGLE_C(&DBuf, (LANE+1)*2-1, 0, 0, 1, 0);
        for(i=0; i<LANE+1; i++){
            pLine->x = x0 + scale * (1-lw) * cosf(2*PI*(2*i+1)/16);
            pLine->y = y0 + scale * (1-lw) * sinf(2*PI*(2*i+1)/16);
            pLine->argb = ARGB(0,50,50,50);
            pLine++;
            pLine->x = x0 + scale * (1+lw) * cosf(2*PI*(2*i+1)/16);
            pLine->y = y0 + scale * (1+lw) * sinf(2*PI*(2*i+1)/16);
            pLine->argb = ARGB(0,50,50,50);
            pLine++;
        }


        //小節線
        for(i=this->bmsNum[0];i<this->bms.barNum;i++){
            float r = (this->scrMulti*n*(this->bms.bar[i].timing - nowCount)/BMSDATA_RESOLUTION);
            r=1-r;
            if(r<0) break;//内すぎ
            r = r*r;
            if(r > 1/m) this->bmsNum[0] = i+1;//外すぎ
            else {
                AGPolyC *pBar;
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
                pBar = agDrawTRIANGLE_C(&DBuf, (LANE+1)*2-1, 0, 0, 1, 0);
                for(i=0; i<LANE+1; i++){
                    pBar->x = x0 + scale * (r-lw) * cosf(2*PI*(2*i+1)/16);
                    pBar->y = y0 + scale * (r-lw) * sinf(2*PI*(2*i+1)/16);
                    pBar->argb = ARGB(0,200,200,100);
                    pBar++;
                    pBar->x = x0 + scale * (r+lw) * cosf(2*PI*(2*i+1)/16);
                    pBar->y = y0 + scale * (r+lw) * sinf(2*PI*(2*i+1)/16);
                    pBar->argb = ARGB(0,200,200,100);
                    pBar++;
                }
            }
        }

        //オブジェ
        for(j=0; j<LANE;j++){
            int ind = index[j]+11, size = this->bms.dataNum[ind];
            for(i=this->bmsNum[ind]; i<size; i++){
                float r = (this->scrMulti*n*(this->bms.data[ind][i].timing - nowCount)/BMSDATA_RESOLUTION);
                r=1-r;
                if(r<0) break;//内すぎ
                r = r*r;
                if(r > 1/m) this->bmsNum[ind] = i+1;//外すぎ
                else if(this->bms.data[ind][i].flag){
                    AGPolyC *pObj;
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
                    pObj = agDrawTRIANGLE_C(&DBuf, 4-1, 0, 0, 1, 0);
                    for(k=0; k<2; k++){
                        pObj->x = x0 + scale * (r-ow) * cosf(2*PI*(2*(j+k)-1)/16);
                        pObj->y = y0 + scale * (r-ow) * sinf(2*PI*(2*(j+k)-1)/16);
                        pObj->argb = ARGB(0,255,255,255);
                        pObj++;
                        pObj->x = x0 + scale * (r+ow) * cosf(2*PI*(2*(j+k)-1)/16);
                        pObj->y = y0 + scale * (r+ow) * sinf(2*PI*(2*(j+k)-1)/16);
                        pObj->argb = ARGB(0,255,255,255);
                        pObj++;
                    }
                }
            }
        }

        //フラッシュ
        ///////////スコアとか
		//_dprintf("score=%d",score);
		this->score=6543210;
		
		digit[6]=this->score/1000000;
		digit[5]=this->score/100000-digit[6]*10;
		digit[4]=this->score/10000-(digit[6]*100+digit[5]*10);
		digit[3]=this->score/1000-(digit[6]*1000+digit[5]*100+digit[4]*10);
		digit[2]=this->score/100-(digit[6]*10000+digit[5]*1000+digit[4]*100+digit[3]*10);
		digit[1]=this->score/10-(digit[6]*100000+digit[5]*10000+digit[4]*1000+digit[3]*100+digit[2]*10);
		digit[0]=this->score-(digit[6]*1000000+digit[5]*100000+digit[4]*10000+digit[3]*1000+digit[2]*100+digit[1]*10);
		
		for(i=0;i<7;i++){
			agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
			ageTransferAAC( &DBuf, 2+digit[i] , 0, &w, &h );
			agDrawSPRITE( &DBuf, 1 ,3900-250*i, 100,4100-250*i,  300);
		}

        //描画終了
        agDrawEODL(&DBuf);
        agTransferDrawDMA(&DBuf);
        aglWaitVSync();
        aglSwap();
    }

//_dprintf("%d %d\n", this->tm.count, nowCount);
    return 0;
}



bool Game_title(Game* this){
    u32 DrawBuffer[4096*10];
    AGDrawBuffer DBuf;

    float x0 = (FB_WIDTH/2)<<2, y0 = (FB_HEIGHT/2)<<2, scale = (FB_HEIGHT/2)<<2;
	int w,h;
    agDrawBufferInit(&DBuf, DrawBuffer);
    agDrawSETDAVR(&DBuf, 0, 0, aglGetDrawFrame(), 0, 0);
    agDrawSETDAVF(&DBuf, 0, 0, FB_WIDTH << 2, FB_HEIGHT << 2);
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);

    //背景
	agPictureSetBlendMode( &DBuf , 0 , 255 , 0 , 0 , 2 , 1 );
	ageTransferAAC( &DBuf, AG_CG_OCTABEATTITLE , 0, &w, &h );
	agDrawSPRITE( &DBuf, 1 ,0, 0, FB_WIDTH << 2, FB_HEIGHT<<2);
    
	//描画終了
    agDrawEODL(&DBuf);
    agTransferDrawDMA(&DBuf);
    aglWaitVSync();
    aglSwap();

    PadRun();
    if(PadTrg()&PAD_A)
        return TRUE;

    return FALSE;
}


//セレクトのためにヘッダ情報読み込む
bool Game_selectInit(Game* this){
	this->x0 = (FB_WIDTH/2)<<2;
	this->y0 = (FB_HEIGHT/2)<<2;
	this->scale = (FB_HEIGHT/2)<<2;
	this->x1=this->x0-this->scale/2, this->y1=this->y0-this->scale/2,this->xr1=this->x0+this->scale/2,this->yr1=this->y0-this->scale/4;
	this->x2=this->x0-this->scale/2, this->y2=this->y0, this->xr2=this->x0+this->scale/2, this->yr2=this->y0+this->scale/4;
	this->x3= this->x0-this->scale/2,this->y3=this->y0+this->scale/2, this->xr3=this->x0+this->scale/2, this->yr3=this->y0+3*this->scale/4;
	this->selectFlag=0;
    return TRUE;
}


int Game_select(Game* this){
    u32 DrawBuffer[4096*10];
    AGDrawBuffer DBuf;
	int w,h;
    agDrawBufferInit(&DBuf, DrawBuffer);
    agDrawSETDAVR(&DBuf, 0, 0, aglGetDrawFrame(), 0, 0);
    agDrawSETDAVF(&DBuf, 0, 0, FB_WIDTH << 2, FB_HEIGHT << 2);
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);

    //背景
    agDrawSETFCOLOR(&DBuf, ARGB(0, 0, 0, 0));
    agDrawRECTANGLE(&DBuf, 0, 0, FB_WIDTH << 2, FB_HEIGHT << 2);
	
	agPictureSetBlendMode( &DBuf , 0 , 255 , 0 , 0 , 2 , 1 );
	ageTransferAAC( &DBuf,AG_CG_SELECTBACKGROUND , 0, &w, &h );
	agDrawSPRITE( &DBuf, 1 ,0, 0, FB_WIDTH << 2, FB_HEIGHT<<2);
    //セレクトのつもり
   agDrawSETFCOLOR(&DBuf, ARGB(0, 255, 255, 0));
    agDrawRECTANGLE(&DBuf, this->x1,this->y1, this->xr1, this->yr1);
	agDrawRECTANGLE(&DBuf, this->x2, this->y2, this->xr2, this->yr2);
	agDrawRECTANGLE(&DBuf, this->x3, this->y3, this->xr3, this->yr3);
	_dprintf("selectFlag=%d",this->selectFlag);

	 if(PadTrg()&PAD_DOWN){
			if(this->selectFlag%3==0){
				this->x1=this->x0-this->scale;
				this->xr1=this->x0;
				this->x3=this->x0-this->scale/2;
				this->xr3=this->x0+this->scale/2;
			}else if(this->selectFlag%3==1){
				this->x1=this->x0-this->scale/2;
				this->xr1=this->x0+this->scale/2;
				this->x2=this->x0-this->scale;
				this->xr2=this->x0;
			}else if(this->selectFlag%3==2){
				this->x2=this->x0-this->scale/2;
				this->xr2=this->x0+this->scale/2;
				this->x3=this->x0-this->scale;
				this->xr3=this->x0;
			}
			this->selectFlag++;
	}

    //描画終了
    agDrawEODL(&DBuf);
    agTransferDrawDMA(&DBuf);
    aglWaitVSync();
    aglSwap();

    PadRun();
    if(PadTrg()&PAD_A){
        return 1;
    }else if(PadTrg()&PAD_B)
        return -1;

    return 0;
}

//結果画面のためにヘッダ情報読み込む
bool Game_resultInit(Game* this){
	
    return TRUE;
}

bool Game_result(Game* this){
    u32 DrawBuffer[4096*10];
    AGDrawBuffer DBuf;
	int w,h,i=0,sizeResult,resultFlag;
    float x0 = (FB_WIDTH/2)<<2, y0 = (FB_HEIGHT/2)<<2, scale = (FB_HEIGHT/2)<<2;

    agDrawBufferInit(&DBuf, DrawBuffer);
    agDrawSETDAVR(&DBuf, 0, 0, aglGetDrawFrame(), 0, 0);
    agDrawSETDAVF(&DBuf, 0, 0, FB_WIDTH << 2, FB_HEIGHT << 2);
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);

    //背景
    agDrawSETFCOLOR(&DBuf, ARGB(0, 0, 0, 0));
    agDrawRECTANGLE(&DBuf, 0, 0, FB_WIDTH << 2, FB_HEIGHT << 2);

    //リザルト
	for(i=0;i<10;i++){
		if(i==0){
			sizeResult=0;
		}
		sizeResult++;
		if(i==9){
			sizeResult=0;
		}
	}
	agPictureSetBlendMode( &DBuf , 0 , 255 , 0 , 0 , 2 , 1 );
		ageTransferAAC( &DBuf,AG_CG_RANKS , 0, &w, &h );
		agDrawSPRITE( &DBuf, 1 ,1000+50*sizeResult,1000+50*sizeResult, 2000-50*sizeResult, 2000-50*sizeResult);
	
    //描画終了
    agDrawEODL(&DBuf);
    agTransferDrawDMA(&DBuf);
    aglWaitVSync();
    aglSwap();

    PadRun();
    if(PadTrg()&PAD_A)
        return TRUE;

    return FALSE;
}
