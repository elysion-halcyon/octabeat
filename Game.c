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
SNDHANDLE handle;

//Gameクラス(もどき)

// コンストラクタ
void Game_ctor(Game* this){
    //各要素の初期化
    Timer_ctor(&this->tm);
    Bms_ctor(&this->bms);

    memset(this->selectInfo, 0, sizeof(this->selectInfo));

    this->option.scrMulti = 1.0f;
    this->option.shift=0;
    this->option.random=0;
    this->option.appearance=0;
    this->option.boost=0;
    this->option.gauge=0;
    this->option.optionSelectFlag=0;

    this->state = G_INIT;
    this->scrMulti = 1.0f;
    this->startTime = 0;
    this->globalFreq = 0;
    memset(this->bmsNum, 0, sizeof(this->bmsNum));

    memset(this->onKey, 0, sizeof(this->onKey));
    memset(this->flashIndex, 0, sizeof(this->flashIndex));
    memset(this->flashCount, 0, sizeof(this->flashCount));
    memset(this->backKeyCount, 0, sizeof(this->backKeyCount));

    memset(this->judge, 0, sizeof(this->judge));
    memset(this->judgeCount, 0, sizeof(this->judgeCount));
    memset(this->judgeSum, 0, sizeof(this->judgeSum));
    this->score = 0;
    this->score_prev = 0;
    this->total = 0;
    this->combo = 0;
    this->comboMax = 0;
    this->gauge = 0;

    this->selectFlag = 0;

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
            if(Game_init(this)){
                if(ageSndMgrIsPlay) ageSndMgrStop(handle);
                ageSndMgrRelease(handle);
                handle = ageSndMgrAlloc(AS_SND_TITLE, 0, 1, AGE_SNDMGR_PANMODE_LR12, 0);
                ageSndMgrPlay(handle);
                this->state = G_TITLE;
            } else
                this->state = G_END;
            break;
        case G_TITLE:
            if(Game_title(this))
                this->state = G_SELECT_INIT;
            else
                ;
            break;
        case G_SELECT_INIT:
            if(Game_selectInit(this)){
                if(ageSndMgrIsPlay) ageSndMgrStop(handle);
                ageSndMgrRelease(handle);
                handle = ageSndMgrAlloc(AS_SND_TITLE, 0, 1, AGE_SNDMGR_PANMODE_LR12, 0);
                ageSndMgrPlay(handle);
                this->state = G_SELECT;
            } else
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
            case -2:
                this->state = G_OPTION;
                break;
            default:
                break;
            }
            break;
        case G_OPTION:
            if(Game_option(this)){
                this->state = G_SELECT;
            }
            break;
        case G_MAIN_INIT:
            if(Game_gameInit(this)){
                if(ageSndMgrIsPlay) ageSndMgrStop(handle);
                this->state = G_MAIN;
            } else
                this->state = G_END;
            break;
        case G_MAIN:
            if(Game_gameRun(this,FALSE))
                this->state = G_RESULT_INIT; //正常終了
            else
                ;
            break;
		case G_RESULT_INIT:
            if(Game_resultInit(this)){
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

        //デバッグ用//と思ったけどサウンド用に使うかも
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
            case G_OPTION:
                _dprintf("G_OPTION\n");
                break;
            case G_MAIN_INIT:
                _dprintf("G_MAIN_INIT\n");
                break;
            case G_MAIN:
                _dprintf("G_MAIN\n");
                break;
			 case G_RESULT_INIT:
                _dprintf("G_RESULT_INIT\n");
                break;
            case G_RESULT:
                if(ageSndMgrIsPlay) ageSndMgrStop(handle);
                ageSndMgrRelease(handle);
                handle = ageSndMgrAlloc(AS_SND_RESULT, 0, 1, AGE_SNDMGR_PANMODE_LR12, 0);
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

    Bms_clear(&this->bms);
    if(!Bms_load(&this->bms, fumen[this->selectFlag]))
        return FALSE;

    //初期化
    this->scrMulti = 1.0f;
    memset(this->bmsNum, 0, sizeof(this->bmsNum));
    memset(this->onKey, 0, sizeof(this->onKey));
    memset(this->flashIndex, 0, sizeof(this->flashIndex));
    memset(this->flashCount, 0, sizeof(this->flashCount));
    memset(this->backKeyCount, 0, sizeof(this->backKeyCount));
    memset(this->judge, 0, sizeof(this->judge));
    memset(this->judgeCount, 0, sizeof(this->judgeCount));
    memset(this->judgeSum, 0, sizeof(this->judgeSum));
	this->score=0.5;   //四捨五入のため+0.5
    this->score_prev = this->score;
    {
        int i;
        this->total = 0;
        for(i=0;i<9;i++)
            if(i!=6){
                this->total += this->bms.dataNum[11+i];
                this->total += this->bms.dataNum[51+i]/2;
            }
    }
    this->combo = 0;
    this->comboMax = 0;
    this->gauge = 0.2;

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

    int i, j, k, l, nowCount, w, h;

    //フレームごとにしたい処理
    l = Timer_run(&this->tm);
    for(k=0; k<l; k++){
        //フラッシュエフェクトの減衰
        for(j=0; j<LANE; j++)
            for(i=0; i<3; i++)
                if(this->flashCount[j][i]>0)
                    this->flashCount[j][i] -= 2;
        for(i=0; i<LANE; i++)
            if(this->backKeyCount[i]>0)
                this->backKeyCount[i] -= 2;

        //scroll幅変更//ボタン的に無理？
    }

    //現在のBMSカウントを取得
    nowCount = Bms_getCountFromTime(&this->bms, (double)this->tm.count/this->tm.fps);

    //譜面の最後+1小節まで来たら終了(曲の最後までにした方がいい？)
    if(this->bms.header.maxCount + BMSDATA_RESOLUTION <= nowCount)
    //if(!ageSndMgrIsPlay(handle) && this->bms.header.maxCount+BMSDATA_RESOLUTION <= nowCount)
        return 1;
   
    //曲の再生//突貫
if(!ageSndMgrIsPlay(handle) && nowCount > BMSDATA_RESOLUTION){
ageSndMgrRelease(handle);
handle = ageSndMgrAlloc(AS_SND_OCTAVE, 0, 0, AGE_SNDMGR_PANMODE_LR12, 0);
ageSndMgrPlay(handle);
}

    //判定とか
    if(demo){
        for(j=0; j<LANE; j++){
            int ind = index[j]+11, indLong = index[j]+51;
            for(i=this->bmsNum[ind+20]; i<this->bms.dataNum[ind]; i++){
                LPBMSDATA bf = &this->bms.data[ind][i];
                if(nowCount < bf->timing)
                    break;
                if(bf->flag){
                    //PERFECT判定時と同じ処理をする
                    if(nowCount >= bf->timing){
                        float score_add = 1000000.0/this->total, gauge_add = 2.0/this->total;
                        bf->flag = FALSE;
                        this->bmsNum[ind+20] = i+1;
                        ageSndMgrPlayOneshot(AS_SND_CLAP1, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
                        //this->flashCount[j][this->flashIndex[j]] = 45;
                        //this->flashIndex[j]++;
                        //if(this->flashIndex[j]>2)
                        //    this->flashIndex[j] = 0;
                        this->backKeyCount[j] = 30;

                        this->judge[j] = J_PERFECT;
                        this->judgeCount[j] = JCMAX;
                        this->judgeSum[this->judge[j]]++;
                        this->score += score_add;
                        this->gauge += gauge_add;
                        if(this->gauge > 1.0) this->gauge = 1.0;
                        else if(this->gauge < 0.0) this->gauge = 0.0;
                        this->combo++;
                        if(this->combo > this->comboMax) this->comboMax = this->combo;
                    }
                }
            }
            //ロングノート
            for(i=this->bmsNum[indLong+20]; i<this->bms.dataNum[indLong]; i++){
                LPBMSDATA bf = &this->bms.data[indLong][i];
                if(nowCount < bf->timing)
                    break;
                if(bf->flag){
                    //PERFECT判定時と同じ処理をする
                    if(nowCount >= bf->timing){
                        if(i%2==0){
                            bf->flag = FALSE;
                            this->bmsNum[indLong+20] = i+1;
                            ageSndMgrPlayOneshot(AS_SND_CLAP1, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
                            //this->flashCount[j][this->flashIndex[j]] = 45;
                            //this->flashIndex[j]++;
                            //if(this->flashIndex[j]>2)
                            //    this->flashIndex[j] = 0;
                            this->backKeyCount[j] = 30;
                        }else{
                            float score_add = 1000000.0/this->total, gauge_add = 2.0/this->total;
                            bf->flag = FALSE;
                            this->bmsNum[indLong+20] = i+1;
                            ageSndMgrPlayOneshot(AS_SND_CLAP1, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
                            //ロング用の光？

                            this->judgeCount[j] = JCMAX;
                            this->judgeSum[this->judge[j]]++;
                            this->score += score_add;
                            this->gauge += gauge_add;
                            if(this->gauge > 1.0) this->gauge = 1.0;
                            else if(this->gauge < 0.0) this->gauge = 0.0;
                            this->combo++;
                            if(this->combo > this->comboMax) this->comboMax = this->combo;
                        }
                    }
                }
            }
            //if(this->bmsNum[indLong+20] %2 ==1) this->backKeyCount[j] = 30; //次が終なら押下中なので光らせる
        }
    //手動演奏
    } else {
        u8 keyNum[LANE] = {PAD_RIGHT,PAD_A,PAD_DOWN,PAD_B,PAD_LEFT,PAD_X,PAD_UP,PAD_Y};
        PadRun();
        for(j=0; j<LANE; j++){
            int ind = index[j]+11, indLong = index[j]+51;
            if(PadLvl()&keyNum[j]){
                //this->backKeyCount[j] = 30;
                if(PadTrg()&keyNum[j]){
                    bool normalNoteProcessed = FALSE;
                    this->backKeyCount[j] = 30;
                    //普通処理
                    for(i=this->bmsNum[j+11+20]; i<this->bms.dataNum[ind]; i++){
                        LPBMSDATA bm = &this->bms.data[ind][i];
                        if(bm->flag){
                            if((nowCount-625)<bm->timing && bm->timing<(nowCount+625)){
                                float score_add = 1000000.0/this->total, gauge_add = 2.0/this->total;
                                bm->flag = FALSE;
                                this->bmsNum[j+11+20] = i+1;
                                ageSndMgrPlayOneshot(AS_SND_CLAP1, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
                                //this->flashCount[j][this->flashIndex[j]] = 45;
                                //this->flashIndex[j]++;
                                //if(this->flashIndex[j]>2)
                                //    this->flashIndex[j] = 0;

                                if      (nowCount+500 < bm->timing) this->judge[j] = J_BAD;
                                else if (nowCount+300 < bm->timing) this->judge[j] = J_GOOD;
                                else if (nowCount+100 < bm->timing) this->judge[j] = J_GREAT;
                                else if (nowCount-100 < bm->timing) this->judge[j] = J_PERFECT;
                                else if (nowCount-300 < bm->timing) this->judge[j] = J_GREAT;
                                else if (nowCount-500 < bm->timing) this->judge[j] = J_GOOD;
                                else                                this->judge[j] = J_BAD;
                                this->judgeCount[j] = JCMAX;
                                this->judgeSum[this->judge[j]]++;

                                switch(this->judge[j]){
                                case J_PERFECT:
                                    score_add *= 1.0;
                                    gauge_add *= 1.0;
                                    this->combo++;
                                    _dprintf("PERFECT ");
                                    break;
                                case J_GREAT:
                                    score_add *= 0.5;
                                    gauge_add *= 1.0;
                                    this->combo++;
                                    _dprintf("GREAT   ");
                                    break;
                                case J_GOOD:
                                    score_add *= 0.1;
                                    gauge_add *= 0.5;
                                    this->combo++;
                                    _dprintf("GOOD    ");
                                    break;
                                case J_BAD:
                                    score_add *= 0.0;
                                    gauge_add *= -1.0;
                                    this->combo = 0;
                                    _dprintf("BAD     ");
                                    break;
                                }
                                this->score += score_add;
                                this->gauge += gauge_add;
                                if(this->gauge > 1.0) this->gauge = 1.0;
                                else if(this->gauge < 0.0) this->gauge = 0.0;
                                _dprintf("SCORE:%d(+%d) GAUGE:%d%%(+%d%%) COMBO:%d\n", (int)this->score, (int)score_add, (int)(this->gauge*100), (int)(gauge_add*100), this->combo);
                                if(this->combo > this->comboMax) this->comboMax = this->combo;

                                normalNoteProcessed = TRUE;
                                break;
                            }
                        }
                    }

                    //ロング始点処理
                    if(!normalNoteProcessed){
                        for(i=this->bmsNum[j+51+20]; i<this->bms.dataNum[indLong]; i++){
                            LPBMSDATA bm = &this->bms.data[indLong][i];
                            if(bm->flag){
                                //始
                                if(i%2==0){
                                    if((nowCount-625)<bm->timing && bm->timing<(nowCount+625)){
                                        bm->flag = FALSE;
                                        this->bmsNum[j+51+20] = i+1;
                                        ageSndMgrPlayOneshot(AS_SND_CLAP1, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
                                        //this->flashCount[j][this->flashIndex[j]] = 45;
                                        //this->flashIndex[j]++;
                                        //if(this->flashIndex[j]>2)
                                        //    this->flashIndex[j] = 0;

                                        if      (nowCount+500 < bm->timing) this->judge[j] = J_POOR;//BADでなくPOORに
                                        else if (nowCount+300 < bm->timing) this->judge[j] = J_GOOD;
                                        else if (nowCount+100 < bm->timing) this->judge[j] = J_GREAT;
                                        else if (nowCount-100 < bm->timing) this->judge[j] = J_PERFECT;
                                        else if (nowCount-300 < bm->timing) this->judge[j] = J_GREAT;
                                        else if (nowCount-500 < bm->timing) this->judge[j] = J_GOOD;
                                        else                                this->judge[j] = J_POOR;

                                        if(this->judge[j] == J_POOR){
                                            float score_add = 1000000.0/this->total, gauge_add = 2.0/this->total;
                                            this->judgeCount[j] = JCMAX;
                                            this->judgeSum[this->judge[j]]++;
                                            this->bms.data[indLong][i+1].flag = FALSE; // 終も消す
                                            this->bmsNum[j+51+20]++;

                                            score_add *= 0.0;
                                            gauge_add *= -2.0;
                                            this->combo = 0;
                                            this->score += score_add;
                                            this->gauge += gauge_add;
                                            if(this->gauge > 1.0) this->gauge = 1.0;
                                            else if(this->gauge < 0.0) this->gauge = 0.0;
                                            _dprintf(" POOR*   SCORE:%d(+0) GAUGE:%d%%(%d%%) COMBO:%d\n", (int)this->score, (int)(this->gauge*100), (int)(gauge_add*100), this->combo);
                                            break;
                                        }
                                
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }

                //ロング終端処理
                for(i=this->bmsNum[j+51+20]; i<this->bms.dataNum[indLong]; i++){
                    LPBMSDATA bm = &this->bms.data[indLong][i];
                    if(bm->flag){
                        //終
                        if(i%2==1) {
                            if(nowCount >= bm->timing){
                                float score_add = 1000000.0/this->total, gauge_add = 2.0/this->total;
                                bm->flag = FALSE;
                                this->bmsNum[j+51+20] = i+1;
                                ageSndMgrPlayOneshot(AS_SND_CLAP1, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
                                //this->flashCount[j][this->flashIndex[j]] = 45;
                                //this->flashIndex[j]++;
                                //if(this->flashIndex[j]>2)
                                //    this->flashIndex[j] = 0;

                                this->judgeCount[j] = JCMAX;
                                this->judgeSum[this->judge[j]]++;

                                switch(this->judge[j]){
                                case J_PERFECT:
                                    score_add *= 1.0;
                                    gauge_add *= 1.0;
                                    this->combo++;
                                    _dprintf(" PERFECT ");
                                    break;
                                case J_GREAT:
                                    score_add *= 0.5;
                                    gauge_add *= 1.0;
                                    this->combo++;
                                    _dprintf(" GREAT   ");
                                    break;
                                case J_GOOD:
                                    score_add *= 0.1;
                                    gauge_add *= 0.5;
                                    this->combo++;
                                    _dprintf(" GOOD    ");
                                    break;
                                }
                                this->score += score_add;
                                this->gauge += gauge_add;
                                if(this->gauge > 1.0) this->gauge = 1.0;
                                else if(this->gauge < 0.0) this->gauge = 0.0;
                                _dprintf("SCORE:%d(+%d) GAUGE:%d%%(+%d%%) COMBO:%d\n", (int)this->score, (int)score_add, (int)(this->gauge*100), (int)(gauge_add*100), this->combo);
                                if(this->combo > this->comboMax) this->comboMax = this->combo;

                                break;
                            }
                        }
                    }
                }

            //ロング中途POOR
            } else {
                if(this->bmsNum[j+51+20]%2==1 && this->bms.data[indLong][this->bmsNum[j+51+20]].flag==TRUE){
                    float gauge_add = 2.0/this->total;
                    gauge_add *= -2.0;
                    this->combo = 0;
                    this->gauge += gauge_add;
                    if(this->gauge > 1.0) this->gauge = 1.0;
                    else if(this->gauge < 0.0) this->gauge = 0.0;
                    _dprintf(" POOR**  SCORE:%d(+0) GAUGE:%d%%(%d%%) COMBO:%d\n", (int)this->score, (int)(this->gauge*100), (int)(gauge_add*100), this->combo);
                    this->judge[j] = J_POOR;
                    this->judgeCount[j] = JCMAX;
                    this->judgeSum[this->judge[j]]++;
                    this->bms.data[indLong][this->bmsNum[j+51+20]].flag = FALSE;
                    this->bmsNum[j+51+20]++;
                    break;
                }
            }

            //普通空POOR
            for(i=this->bmsNum[j+11+20]; i<this->bms.dataNum[ind]; i++){
                LPBMSDATA bm = &this->bms.data[ind][i];
                if(bm->flag){
                    if(bm->timing < nowCount-625){
                        //POOR処理
                        float gauge_add = 2.0/this->total;
                        gauge_add *= -2.0;
                        this->combo = 0;
                        this->gauge += gauge_add;
                        if(this->gauge > 1.0) this->gauge = 1.0;
                        else if(this->gauge < 0.0) this->gauge = 0.0;
                        _dprintf("POOR    SCORE:%d(+0) GAUGE:%d%%(%d%%) COMBO:%d\n", (int)this->score, (int)(this->gauge*100), (int)(gauge_add*100), this->combo);
                        this->judge[j] = J_POOR;
                        this->judgeCount[j] = JCMAX;
                        this->judgeSum[this->judge[j]]++;
                        bm->flag = FALSE;
                        this->bmsNum[j+11+20] = i+1;
                        break;
                    }
                }
            }

            //ロング空POOR
            for(i=this->bmsNum[j+51+20]; i<this->bms.dataNum[indLong]; i++){
                LPBMSDATA bm = &this->bms.data[indLong][i];
                if(bm->flag){
                    if(i%2==0){
                        if(bm->timing < nowCount-625){
                            //POOR処理
                            float gauge_add = 2.0/this->total;
                            gauge_add *= -2.0;
                            this->combo = 0;
                            this->gauge += gauge_add;
                            if(this->gauge > 1.0) this->gauge = 1.0;
                            else if(this->gauge < 0.0) this->gauge = 0.0;
                            _dprintf(" POOR*** SCORE:%d(+0) GAUGE:%d%%(%d%%) COMBO:%d\n", (int)this->score, (int)(this->gauge*100), (int)(gauge_add*100), this->combo);
                            this->judge[j] = J_POOR;
                            this->judgeCount[j] = JCMAX;
                            this->judgeSum[this->judge[j]]++;
                            bm->flag = FALSE;
                            this->bms.data[indLong][i+1].flag = FALSE;
                            this->bmsNum[j+51+20] = i+2;
                            break;
                        }
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
        float m=0.9, scale = 4*m*FB_HEIGHT/2, lineWidth=0.002, objeWidth=0.015, n=0.7;

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
            if(i%2==0)pLane->argb = ARGB(0, 105+(nowCount%2400)/20,20,20);
            else pLane->argb = ARGB(0, 20,20,105+(nowCount%2400)/20);
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
            pLight->argb = ARGB(this->backKeyCount[i]*6, 200,200,200);
            pLight++;
        }

        //判定線
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
        pLine = agDrawTRIANGLE_C(&DBuf, (LANE+1)*2-1, 0, 0, 1, 0);
        for(i=0; i<LANE+1; i++){
            pLine->x = x0 + scale * (1-lineWidth) * cosf(2*PI*(2*i+1)/16);
            pLine->y = y0 + scale * (1-lineWidth) * sinf(2*PI*(2*i+1)/16);
            pLine->argb = ARGB(0,50,50,50);
            pLine++;
            pLine->x = x0 + scale * (1+lineWidth) * cosf(2*PI*(2*i+1)/16);
            pLine->y = y0 + scale * (1+lineWidth) * sinf(2*PI*(2*i+1)/16);
            pLine->argb = ARGB(0,50,50,50);
            pLine++;
        }

        //小節線
        for(i=this->bmsNum[0];i<this->bms.barNum;i++){
            float r1, r2, r = (this->option.scrMulti*n*(this->bms.bar[i].timing - nowCount)/BMSDATA_RESOLUTION);
            r=1-r;
            if(r<0) break;//内すぎ
            r1 = (1-cosf((r-lineWidth)*PI/2))*(r-lineWidth);
            r2 = (1-cosf((r+lineWidth)*PI/2))*(r+lineWidth);
            if(r1 > 1/m) this->bmsNum[0] = i+1;//外すぎ
            else{
                AGPolyC *pBar;
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
                pBar = agDrawTRIANGLE_C(&DBuf, (LANE+1)*2-1, 0, 0, 1, 0);
                for(j=0; j<LANE+1; j++){
                    pBar->x = x0 + scale * r1 * cosf(2*PI*(2*j+1)/16);
                    pBar->y = y0 + scale * r1 * sinf(2*PI*(2*j+1)/16);
                    pBar->argb = ARGB(0,200,200,100);
                    pBar++;
                    pBar->x = x0 + scale * r2 * cosf(2*PI*(2*j+1)/16);
                    pBar->y = y0 + scale * r2 * sinf(2*PI*(2*j+1)/16);
                    pBar->argb = ARGB(0,200,200,100);
                    pBar++;
                }
            }
        }


        //ロング
        for(j=0; j<LANE;j++){
            int ind = index[j]+51, size = this->bms.dataNum[ind];
            for(i=this->bmsNum[ind]; i<size; i+=2){
                float r1 = (this->option.scrMulti*n*(this->bms.data[ind][i].timing - nowCount)/BMSDATA_RESOLUTION);
                r1=1-r1;
                if(r1<0) break;//始が内すぎたら次
                else {
                    float r2 = (this->option.scrMulti*n*(this->bms.data[ind][i+1].timing - nowCount)/BMSDATA_RESOLUTION);
                    r2=1-r2;
                    if(r2<0) r2 = 0; //終が内すぎたら内ギリギリに
                    r1 = (1-cosf((r1)*PI/2))*(r1);
                    r2 = (1-cosf((r2)*PI/2))*(r2);
                    if(r2 > 1/m) this->bmsNum[ind] = i+2;//終が外すぎたら次
                    else {
                        AGPolyC *pLong;
                        u32 color = ARGB(200,150,100,0);
                        if(this->bms.data[ind][i].flag==FALSE && this->bms.data[ind][i+1].flag==TRUE)
                            color=ARGB(150+rand()%100,200,170,0);
                        if(r1 > 1/m) r1=1/m;//始が外すぎたら外ギリギリに
agDrawSETDBMODE(&DBuf, 0xff , AG_BLEND_NORMAL , 0, 1);
                        pLong = agDrawTRIANGLE_C(&DBuf, 4-1, 0, 0, 1, 0);
                        for(k=0; k<2; k++){
                            pLong->x = x0 + scale * (r2) * cosf(2*PI*(2*(j+k)-1)/16);
                            pLong->y = y0 + scale * (r2) * sinf(2*PI*(2*(j+k)-1)/16);
                            pLong->argb = color;
                            pLong++;
                            pLong->x = x0 + scale * (r1) * cosf(2*PI*(2*(j+k)-1)/16);
                            pLong->y = y0 + scale * (r1) * sinf(2*PI*(2*(j+k)-1)/16);
                            pLong->argb = color;
                            pLong++;
                        }
                    }
                }
            }
        }

        //ロングの頭
        for(j=0; j<LANE;j++){
            int ind = index[j]+51, size = this->bms.dataNum[ind];
            for(i=this->bmsNum[ind]; i<size; i++){
                if(i%2==0){
                    float r = (this->option.scrMulti*n*(this->bms.data[ind][i].timing - nowCount)/BMSDATA_RESOLUTION);
                    r=1-r;
                    if(r<0) break;//内すぎ
                    if(this->bms.data[ind][i].flag){//外すぎたら上の処理ではじかれてる
                        AGPolyC *pObj;
                        float r1 = (1-cosf((r-objeWidth)*PI/2))*(r-objeWidth);
                        float r2 = (1-cosf((r+objeWidth)*PI/2))*(r+objeWidth);
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
                        pObj = agDrawTRIANGLE_C(&DBuf, 4-1, 0, 0, 1, 0);
                        for(k=0; k<2; k++){
                            pObj->x = x0 + scale * r1 * cosf(2*PI*(2*(j+k)-1)/16);
                            pObj->y = y0 + scale * r1 * sinf(2*PI*(2*(j+k)-1)/16);
                            pObj->argb = ARGB(0,255,210,0);
                            pObj++;
                            pObj->x = x0 + scale * r2 * cosf(2*PI*(2*(j+k)-1)/16);
                            pObj->y = y0 + scale * r2 * sinf(2*PI*(2*(j+k)-1)/16);
                            pObj->argb = ARGB(0,255,210,0);
                            pObj++;
                        }
                    }
                }
            }
        }


        //オブジェ
        for(j=0; j<LANE;j++){
            int ind = index[j]+11, size = this->bms.dataNum[ind];
            for(i=this->bmsNum[ind]; i<size; i++){
                float r = (this->option.scrMulti*n*(this->bms.data[ind][i].timing - nowCount)/BMSDATA_RESOLUTION);
                r=1-r;
                if(r<0) break;//内すぎ
                if(r > 1/m) this->bmsNum[ind] = i+1;//外すぎ
                else if(this->bms.data[ind][i].flag){
                    AGPolyC *pObj;
                    float r1 = (1-cosf((r-objeWidth)*PI/2))*(r-objeWidth);
                    float r2 = (1-cosf((r+objeWidth)*PI/2))*(r+objeWidth);
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
                    pObj = agDrawTRIANGLE_C(&DBuf, 4-1, 0, 0, 1, 0);
                    for(k=0; k<2; k++){
                        pObj->x = x0 + scale * r1 * cosf(2*PI*(2*(j+k)-1)/16);
                        pObj->y = y0 + scale * r1 * sinf(2*PI*(2*(j+k)-1)/16);
                        pObj->argb = ARGB(0,255,255,255);
                        pObj++;
                        pObj->x = x0 + scale * r2 * cosf(2*PI*(2*(j+k)-1)/16);
                        pObj->y = y0 + scale * r2 * sinf(2*PI*(2*(j+k)-1)/16);
                        pObj->argb = ARGB(0,255,255,255);
                        pObj++;
                    }
                }
            }
        }

        //フラッシュ

        //判定
        for(j=0; j<LANE;j++){
            if(this->judgeCount[j]>0 && this->judgeCount[j]%6 > 1){
                u32 a,r,g,b;
                AGPolyC *pJudge;
                a=r=g=b=0;
                switch(this->judge[j]){
                case J_PERFECT:
                    r=g=b=255;
                    break;
                case J_GREAT:
                    r=g=255;
                    break;
                case J_GOOD:
                    r=255;
                    g=100;
                    break;
                case J_BAD:
                    g=b=100;
                    break;
                case J_POOR:
                    r=b=150;
                    break;
                }
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
                pJudge = agDrawTRIANGLE_C(&DBuf, 4-1, 0, 0, 1, 0);
                for(k=0; k<2; k++){
                    pJudge->x = x0 + scale * (1/m) * cosf(2*PI*(2*(j+k)-1)/16);
                    pJudge->y = y0 + scale * (1/m) * sinf(2*PI*(2*(j+k)-1)/16);
                    pJudge->argb = ARGB(a,r,g,b);
                    pJudge++;
                    pJudge->x = x0 + scale * (1/m+0.1) * cosf(2*PI*(2*(j+k)-1)/16);
                    pJudge->y = y0 + scale * (1/m+0.1) * sinf(2*PI*(2*(j+k)-1)/16);
                    pJudge->argb = ARGB(a,r,g,b);
                    pJudge++;
                }
            }
            if(this->judgeCount[j]>0) this->judgeCount[j]--;
        }


        //コンボ
        {
            int x_0, y_0, digit = 0, combo = this->combo;
            while((int)(combo/powf(10,digit))>0) digit++;
            x_0 = x0+(digit-2)*200/2;
            y_0 = y0-200/2;
            for(i=0;i<digit;i++,combo/=10){
                agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
                ageTransferAAC( &DBuf, AG_CG_NUMBER0+combo%10 , 0, &w, &h );
                agDrawSPRITE( &DBuf, 1 ,x_0-200*i,y_0, x_0-200*i+200,y_0+200);
            }        
        }

        //スコア
        if(this->score - this->score_prev < 50) this->score_prev = this->score;
        else this->score_prev += (this->score - this->score_prev)/4;
        {
            int score = this->score_prev;
            for(i=0;i<7;i++,score/=10){
                agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
                ageTransferAAC( &DBuf, AG_CG_NUMBER0+score%10 , 0, &w, &h );
                agDrawSPRITE( &DBuf, 1 ,3900-200*i,100, 4100-200*i,300);
            }
        }

        //ゲージ(縦)
agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
        {
            int x_0 = (FB_WIDTH-50)<<2, y_0 = (3*FB_HEIGHT/4)<<2, w = 80, h = (FB_HEIGHT/2)<<2;
            agDrawSETFCOLOR(&DBuf, ARGB(0, 0, 50, 0));
            agDrawRECTANGLE(&DBuf, x_0, y_0-h, x_0+w, y_0);
            agDrawSETFCOLOR(&DBuf, ARGB(0, 0, 200, 0));
            agDrawRECTANGLE(&DBuf, x_0, y_0-h*this->gauge, x_0+w, y_0);
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
    int i, j, bpm, bpmMin, bpmMax;
    for(i=0;i<MUSICMAX;i++){
        Bms_clear(&this->bms);
        if(!Bms_load(&this->bms, fumen[i]))
            return FALSE;
        this->selectInfo[i].header = this->bms.header;

        bpm = this->selectInfo[i].header.bpm;
        bpmMin = bpmMax = bpm;
        for(j=0;j<BMSMAXBUFFER;j++){
            bpm = this->selectInfo[i].header.bpmIndex[j].bpm;
            if(bpm != 0){
                if(bpm < bpmMin) bpmMin = bpm;
                if(bpm > bpmMax) bpmMax = bpm;
            }
        }
        this->selectInfo[i].bpmMin = bpmMin;
        this->selectInfo[i].bpmMax = bpmMax;
    }

    if(this->score > this->selectInfo[this->selectFlag].highscore)
        this->selectInfo[this->selectFlag].highscore = this->score;

    return TRUE;
}


int Game_select(Game* this){
    int i, x0, y0, scale, width, height;
    int x[MUSICMAX], y[MUSICMAX];
    int selectFlag_DEBUG = this->selectFlag;

    PadRun();
    if(PadTrg()&PAD_A){
        return 1;
    }else if(PadTrg()&PAD_B){
        return -1;
    }else if(PadTrg()&PAD_X){
        return -2;
    }else if(PadTrg()&PAD_DOWN){
        this->selectFlag++;
        if(this->selectFlag >= MUSICMAX) this->selectFlag -= MUSICMAX;
    }else if(PadTrg()&PAD_UP){
        this->selectFlag--;
        if(this->selectFlag < 0) this->selectFlag += MUSICMAX;
    }

    if(this->selectFlag != selectFlag_DEBUG){
        _dprintf("selectFlag=%d\n",this->selectFlag);
        _dprintf("player:%d  ", this->selectInfo[this->selectFlag].header.player);
        _dprintf("title:%s  ", this->selectInfo[this->selectFlag].header.title);
        _dprintf("genre:%s  ", this->selectInfo[this->selectFlag].header.genre);
        _dprintf("artist:%s   ", this->selectInfo[this->selectFlag].header.artist);
        _dprintf("BPM:%f  ", this->selectInfo[this->selectFlag].header.bpm);
        _dprintf("playLevel:%d  ", this->selectInfo[this->selectFlag].header.playLevel);
        _dprintf("rank:%d  ", this->selectInfo[this->selectFlag].header.rank);
        _dprintf("endBar:%d  ", this->selectInfo[this->selectFlag].header.endBar);
        _dprintf("maxCount:%d  ", this->selectInfo[this->selectFlag].header.maxCount);
        _dprintf("bpm:%d", this->selectInfo[this->selectFlag].bpmMax);
        if(this->selectInfo[this->selectFlag].bpmMin != this->selectInfo[this->selectFlag].bpmMax)
            _dprintf("-%d", this->selectInfo[this->selectFlag].bpmMin);
        _dprintf("  high score:%d  ", this->selectInfo[this->selectFlag].highscore);
        _dprintf("\n");
    }


    x0 = (FB_WIDTH/2)<<2;
    y0 = (FB_HEIGHT/2)<<2;
    scale = (FB_HEIGHT/2)<<2;
    width = scale-380;
    height = scale/4;

    for(i=0;i<MUSICMAX;i++){
        x[i] = x0;
        y[i] = x0 + (i-2) * height * 2;
    }
    x[this->selectFlag] -= width/2;

    {
    u32 DrawBuffer[4096*10];
    AGDrawBuffer DBuf;
    int w, h;

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

    for(i=0;i<MUSICMAX;i++){
		agPictureSetBlendMode( &DBuf , 0 , 255 , 0 , 0 , 2 , 1 );
	ageTransferAAC( &DBuf,AG_CG_SELECT+i , 0, &w, &h );
	agDrawSPRITE( &DBuf, 1 ,x[i],y[i], x[i]+width, y[i]+height);
	}

    //描画終了
    agDrawEODL(&DBuf);
    agTransferDrawDMA(&DBuf);
    aglWaitVSync();
    aglSwap();
    }


    return 0;
}

//結果画面のためにヘッダ情報読み込む
bool Game_resultInit(Game* this){
	this->resultRankFlag=0;
	this->rank=0;
	this->resultScoreBegin=this->score;
	_dprintf("digitResult=%d",this->resultScoreBegin);
	this->digitResult[6]=this->resultScoreBegin/1000000;
	this->digitResult[5]=this->resultScoreBegin/100000-this->digitResult[6]*10;
	this->digitResult[4]=this->resultScoreBegin/10000-(this->digitResult[6]*100+this->digitResult[5]*10);
	this->digitResult[3]=this->resultScoreBegin/1000-(this->digitResult[6]*1000+this->digitResult[5]*100+this->digitResult[4]*10);
	this->digitResult[2]=this->resultScoreBegin/100-(this->digitResult[6]*10000+this->digitResult[5]*1000+this->digitResult[4]*100+this->digitResult[3]*10);
	this->digitResult[1]=this->resultScoreBegin/10-(this->digitResult[6]*100000+this->digitResult[5]*10000+this->digitResult[4]*1000+this->digitResult[3]*100+this->digitResult[2]*10);
	this->digitResult[0]=this->resultScoreBegin-(this->digitResult[6]*1000000+this->digitResult[5]*100000+this->digitResult[4]*10000+this->digitResult[3]*1000+this->digitResult[2]*100+this->digitResult[1]*10);
	this->i=0;
	for( this->i=0;this->i<7;this->i++){
		this->digitResultFixed[this->i]=this->digitResult[this->i];
	}
	this->soundFlag=0;
    return TRUE;
}

bool Game_result(Game* this){
    u32 DrawBuffer[4096*10];
    AGDrawBuffer DBuf;
	int w,h,i=0,centerX=2050,s,digitNum[5],judgeSumResult[5],judgeDigit[5];
    int perfect=this->judgeSum[0];
	float x0 = (FB_WIDTH/2)<<2, y0 = (FB_HEIGHT/2)<<2, scale = (FB_HEIGHT/2)<<2;

    agDrawBufferInit(&DBuf, DrawBuffer);
    agDrawSETDAVR(&DBuf, 0, 0, aglGetDrawFrame(), 0, 0);
    agDrawSETDAVF(&DBuf, 0, 0, FB_WIDTH << 2, FB_HEIGHT << 2);
	agDrawSETDBMODE(&DBuf, 0xff , 0 , 0, 0);
	
	


    //背景
	agPictureSetBlendMode( &DBuf , 0 , 255 , 0 , 0 , 2 , 1 );
	ageTransferAAC( &DBuf,AG_CG_SELECTBACKGROUND , 0, &w, &h );
	agDrawSPRITE( &DBuf, 1 ,0, 0, FB_WIDTH << 2, FB_HEIGHT<<2);
	
	//白フィルター
	agDrawSETFCOLOR( &DBuf, ARGB( 80, 255, 255, 255 ) );	
	agDrawSETDBMODE( &DBuf, 0xff, 0, 0, 1 );
	agDrawSPRITE( &DBuf,0,0, 0, FB_WIDTH << 2, FB_HEIGHT << 2);

	agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2, 1 );
	ageTransferAAC( &DBuf, AG_CG_PERFECT , 0, &w, &h );			//描画
	agDrawSPRITE( &DBuf, 1 ,centerX-1700,600, centerX-1000,  1300);
	
    agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	ageTransferAAC( &DBuf, AG_CG_GREAT, 0, &w, &h );			//描画
	agDrawSPRITE( &DBuf, 1 ,centerX-1050,300, centerX-350,  1000);

	  agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	ageTransferAAC( &DBuf, AG_CG_GOOD , 0, &w, &h );			//描画
	agDrawSPRITE( &DBuf, 1 ,centerX-350,200, centerX+350,  900);

	agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	ageTransferAAC( &DBuf, AG_CG_POOR , 0, &w, &h );			//描画
	agDrawSPRITE( &DBuf, 1 ,centerX+1000,600, centerX+1700,  1300);
	
    agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	ageTransferAAC( &DBuf, AG_CG_BAD, 0, &w, &h );			//描画
	agDrawSPRITE( &DBuf, 1 ,centerX+350,300, centerX+1050,  1000);
	
	for(i=0;i<5;i++){
		digitNum[i]=this->judgeSum[i];
		judgeSumResult[i]=this->judgeSum[i];
	}
	
	for(i=0;i<5;i++){
		for(judgeDigit[i]=0;digitNum[i]!=0;judgeDigit[i]++){
			digitNum[i]/=10;
		}
	}
	 //コンボ
     /*   {
            int x_0, y_0, digit = 0, combo = this->combo;
            while((int)(combo/powf(10,digit))>0) digit++;
            x_0 = x0+(digit-2)*200/2;
            y_0 = y0-200/2;
            for(i=0;i<digit;i++,combo/=10){
                agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
                ageTransferAAC( &DBuf, AG_CG_NUMBER0+combo%10 , 0, &w, &h );
                agDrawSPRITE( &DBuf, 1 ,x_0-200*i,y_0, x_0-200*i+200,y_0+200);
            }        
        }
		*/
	//PERFECT表示	
	{
		int x_0, y_0;
		if(judgeDigit[0]==0){
			judgeDigit[0]=1;
		}
		x_0 = centerX-1350+(judgeDigit[0]-2)*200/2;
        y_0 = 900-200/2;
		for(i=0;i<judgeDigit[0];i++,judgeSumResult[0]/=10){
			_dprintf("perfect%d\n",judgeSumResult[0]%10);
		    agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
		    ageTransferAAC( &DBuf, AG_CG_NUMBER0+judgeSumResult[0]%10 , 0, &w, &h );
		    agDrawSPRITE( &DBuf, 1,x_0-200*i,y_0, x_0-200*i+200,y_0+200);
		}
	}
	//GREAT表示
	{
		int x_1, y_1;
		if(judgeDigit[1]==0){
			judgeDigit[1]=1;
		}
		x_1 = centerX-700+(judgeDigit[1]-2)*200/2;
        y_1 = 600-200/2;
		for(i=0;i<judgeDigit[1];i++,judgeSumResult[1]/=10){
			_dprintf("great%d\n",judgeSumResult[1]%10);
		    agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
		    ageTransferAAC( &DBuf, AG_CG_NUMBER0+judgeSumResult[1]%10 , 0, &w, &h );
			agDrawSPRITE( &DBuf, 1,x_1-200*i,y_1, x_1-200*i+200,y_1+200);
		}
	}
	//Good表示
	{
		int x_2, y_2;
		if(judgeDigit[2]==0){
			judgeDigit[2]=1;
		}
		x_2 = centerX+(judgeDigit[2]-2)*200/2;
        y_2 = 500-200/2;
		
		for(i=0;i<judgeDigit[2];i++,judgeSumResult[2]/=10){
			_dprintf("good%d\n",judgeSumResult[2]%10);
		    agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
			ageTransferAAC( &DBuf, AG_CG_NUMBER0+judgeSumResult[2]%10 , 0, &w, &h );
		    agDrawSPRITE( &DBuf, 1,x_2-200*i,y_2, x_2-200*i+200,y_2+200);
	    }
	}
	//BAD表示
	{
		int x_3, y_3;
			if(judgeDigit[3]==0){
			judgeDigit[3]=1;
		}
		x_3 = centerX+700+(judgeDigit[3]-2)*200/2;
        y_3 = 600-200/2;
	
		for(i=0;i<judgeDigit[3];i++,judgeSumResult[3]/=10){
			_dprintf("bad%d\n",judgeSumResult[3]%10);
		   agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
		  ageTransferAAC( &DBuf, AG_CG_NUMBER0+judgeSumResult[3]%10 , 0, &w, &h );
		  agDrawSPRITE( &DBuf, 1,x_3-200*i,y_3, x_3-200*i+200,y_3+200);
		 }
		
	}
	//POOR表示
	{
		int x_4, y_4;
		x_4 = centerX+1350+(judgeDigit[4]-2)*200/2;
        y_4 = 900-200/2;
		if(judgeDigit[4]==0){
			judgeDigit[4]=1;
		}
		for(i=0;i<judgeDigit[4];i++,judgeSumResult[4]/=10){
			_dprintf("poor%d\n",judgeSumResult[4]%10);
			agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
		    ageTransferAAC( &DBuf, AG_CG_NUMBER0+judgeSumResult[4]%10 , 0, &w, &h );
		    agDrawSPRITE( &DBuf, 1,x_4-200*i,y_4, x_4-200*i+200,y_4+200);
		}
	}
	
	//リザルトスコア
	this->digitResult[0]++;
	this->digitResult[1]++;
	this->digitResult[2]++;
	this->digitResult[3]++;
	this->digitResult[4]++;
	this->digitResult[5]++;
	this->digitResult[6]++;


	for(i=0;i<7;i++){
		agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
		ageTransferAAC( &DBuf, 2+this->digitResult[i]%10 , 0, &w, &h );			//描画
		agDrawSPRITE( &DBuf, 1 ,centerX+375-150*i, 1400,centerX+575-150*i,  1600);
	}

	if(this->digitResult[0]%10==this->resultScoreBegin-(this->digitResultFixed[6]*1000000+this->digitResultFixed[5]*100000+this->digitResultFixed[4]*10000+this->digitResultFixed[3]*1000+this->digitResultFixed[2]*100+this->digitResultFixed[1]*10)){
		this->digitResult[0]--;
	
	}
	if(this->digitResult[1]%10==this->resultScoreBegin/10-(this->digitResultFixed[6]*100000+this->digitResultFixed[5]*10000+this->digitResultFixed[4]*1000+this->digitResultFixed[3]*100+this->digitResultFixed[2]*10)){
		this->digitResult[1]--;
	
	}
	if(this->digitResult[2]%10==this->resultScoreBegin/100-(this->digitResultFixed[6]*10000+this->digitResultFixed[5]*1000+this->digitResultFixed[4]*100+this->digitResultFixed[3]*10)){
		this->digitResult[2]--;
	
	}
	if(this->digitResult[3]%10==this->resultScoreBegin/1000-(this->digitResultFixed[6]*1000+this->digitResultFixed[5]*100+this->digitResultFixed[4]*10)){
		this->digitResult[3]--;
	
	}
	if(this->digitResult[4]%10==this->resultScoreBegin/10000-(this->digitResultFixed[6]*100+this->digitResultFixed[5]*10)){
		this->digitResult[4]--;
	
	}
	if(this->digitResult[5]%10==this->resultScoreBegin/100000-(this->digitResultFixed[6]*10)){
		this->digitResult[5]--;
	
	}
	if(this->digitResult[6]%10==this->resultScoreBegin/1000000){
		this->digitResult[6]--;

	 //リザルトランク
		if(this->score>900000){
			this->rank=18;
		}else if(this->score<=900000 && this->score>800000){
			this->rank=12;
		}else if(this->score<=800000 && this->score>700000){
			this->rank=13;
		}else if(this->score<=700000 && this->score>600000){
			this->rank=14;
		}else if(this->score<=600000 && this->score>500000){
			this->rank=15;
		}else if(this->score<=500000 && this->score>400000){
			this->rank=16;
		}else if(this->score<=400000){
			this->rank=17;
		}

		agPictureSetBlendMode( &DBuf , 0 , 255 , 0 , 0 , 2 , 1 );
		ageTransferAAC( &DBuf,this->rank , 0, &w, &h );
		agDrawSPRITE( &DBuf, 1 ,1500+50*this->resultRankFlag,1450+50*this->resultRankFlag, 2600-50*this->resultRankFlag, 2550-50*this->resultRankFlag);
	
		this->resultRankFlag+=0.3;
	
		if(this->resultRankFlag>5){
			this->resultRankFlag=5;
			this->soundFlag++;
		}
	}
	//ランクのボイス
	if(this->soundFlag==1){
		if(this->rank==18){
			ageSndMgrPlayOneshot(AS_SND_30_S, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
		}else if(this->rank==12){
			ageSndMgrPlayOneshot(AS_SND_31_A, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
		}else if(this->rank==13){
			ageSndMgrPlayOneshot(AS_SND_32_B, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
		}else if(this->rank==14){
			ageSndMgrPlayOneshot(AS_SND_33_C, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
		}else if(this->rank==15){
			ageSndMgrPlayOneshot(AS_SND_34_D, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
		}else if(this->rank==16){
			ageSndMgrPlayOneshot(AS_SND_35_E, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
		}else if(this->rank==17){
			ageSndMgrPlayOneshot(AS_SND_36_F, 0, 255, AGE_SNDMGR_PANMODE_LR12, 128, 0);
		}
	}
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


bool Game_option(Game* this){
    int i,j,item[6],iMAX = 6;
    item[0] = (this->option.scrMulti+0.05)*10;
    item[1] = this->option.shift;
    item[2] = this->option.random;
    item[3] = this->option.appearance;
    item[4] = this->option.boost;
    item[5] = this->option.gauge;

    PadRun();
    if(PadTrg()&(PAD_A|PAD_B|PAD_X|PAD_Y)){
        return TRUE;
    }else if(PadTrg()&PAD_UP){
        this->option.optionSelectFlag--;
        if(this->option.optionSelectFlag < 0) this->option.optionSelectFlag += iMAX;
    }else if(PadTrg()&PAD_DOWN){
        this->option.optionSelectFlag++;
        if(this->option.optionSelectFlag >= iMAX) this->option.optionSelectFlag -= iMAX;
    }else if(PadTrg()&PAD_RIGHT){
        item[this->option.optionSelectFlag]++;
    }else if(PadTrg()&PAD_LEFT){
        if(this->option.optionSelectFlag!=0 && item[this->option.optionSelectFlag]>0)
            item[this->option.optionSelectFlag]--;
        else if(item[this->option.optionSelectFlag]>1)
            item[this->option.optionSelectFlag]--;
    }

    this->option.scrMulti = item[0]/10.0;
    this->option.shift = item[1];
    this->option.random = item[2];
    this->option.appearance = item[3];
    this->option.boost = item[4];
    this->option.gauge = item[5];


    {
    u32 DrawBuffer[4096*10];
    AGDrawBuffer DBuf;
    int w, h;

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

    //各種
    agPictureSetBlendMode( &DBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
    for(i=0;i<iMAX;i++){
        for(j=0;j<7;j++,item[i]/=10){
                ageTransferAAC( &DBuf, AG_CG_NUMBER0+item[i]%10 , 0, &w, &h );
                agDrawSPRITE( &DBuf, 1 ,3000-200*j,100+300*i, 3200-200*j,300+300*i);
                if(i==this->option.optionSelectFlag) agDrawRECTANGLE(&DBuf, 500, 100+300*i, 700, 300+300*i);
        }
    }

    strDraw(&DBuf, "scroll", 200, 500, 100, 100, 50);

    //描画終了
    agDrawEODL(&DBuf);
    agTransferDrawDMA(&DBuf);
    aglWaitVSync();
    aglSwap();
    }

    return FALSE;
}


//範囲外の文字を入れるとバグるかも
bool charDraw(AGDrawBuffer *DBuf, char c, int x, int y, int w, int h){
    ageTransferAAC( DBuf, AG_CG_HELVETICA_ASCII, 0, NULL, NULL );
agDrawSPRITE_UV( DBuf,
    (x)<<2, (y)<<2, ((c/16-2)*4096/6), ((c%16)*4096/16), //x0,y0,u0,v0
    (x+w)<<2, (y+h)<<2, ((c/16-1)*4096/6), ((c%16+1)*4096/16)); //x1,y1,u1,v1
    //4096 = 2^12 = <<12 //AG4の固定小数点数の仕様
}

bool strDraw(AGDrawBuffer *DBuf, char *s, int x, int y, int w, int h, int track){
    int i;
    for(i=0; i<strlen(s);i++)
        charDraw(DBuf, s[i], x+(w-track)*i, y, w, h);
}
