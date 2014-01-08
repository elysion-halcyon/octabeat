//NULL=0がstddef.hで定義されている stdio.hとかstdlib.hとか読むと読まれる
#include <agtypes.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include "bool.h"
#include "Bms.h"

void Bms_ctor(Bms* this){
	memset(&this->header, 0, sizeof(this->header));
	memset(this->data, 0, sizeof(this->data));
	memset(this->dataNum, 0, sizeof(this->dataNum));

	this->header.player = 1;
	this->header.bpm = 120;

	memset(this->bar, 0, sizeof(this->bar));
	this->barNum = 0;
	memset(this->barMagni, 0, sizeof(this->barMagni));
	this->barMagniNum = 0;
}

//実質ctorと同じ
bool Bms_clear(Bms* this){
	memset(&this->header, 0, sizeof(this->header));
	memset(this->data, 0, sizeof(this->data));
	memset(this->dataNum, 0, sizeof(this->dataNum));

	this->header.player = 1;
	this->header.bpm = 120;

	memset(this->bar, 0, sizeof(this->bar));
	this->barNum = 0;
	memset(this->barMagni, 0, sizeof(this->barMagni));
	this->barMagniNum = 0;
	return TRUE;
}

bool Bms_restart(Bms* this){
	int i, j;
	for(j=0; j<BMSMAXBUFFER; j++)
		for(i=0; i<this->dataNum[j]; i++)
			this->data[j][i].flag = 1;

	return TRUE;
}

//36進数(0-9A-Z)を10進数に変換
int Bms_atoi3610(char* s){
	int i, j, length=strlen(s), digit=0, result=0;

	for(i=0; i<length; i++){
		if(s[i]>'z') return result;
		else if(s[i]>='a') digit = s[i]-'a'+10;
		else if(s[i]>='A') digit = s[i]-'A'+10;
		else digit = s[i]-'0';

		for(j=i+1; j<length; j++) digit*=36;

		result += digit;
	}

	return result;
}

//丸め誤差バリバリだけどそこまで精度いらない
float Bms_atof(char* s){
	float ret, base;
	//小数点が来るまで読む
	for(ret=0.0; *s!='.'; s++){
		if(*s == '\0')//小数点がないとき
			return ret;

		if(*s>='0' && *s<='9')
			ret = ret*10.0 + (*s-'0');
	}
	s++;//小数点のぶん
	//小数点以下
	for(base=0.1; *s!='\0'; s++,base/=10.0)
		if(*s>='0' && *s <='9')
			ret += base * (*s-'0');
	
	return ret;
}

bool Bms_sort(Bms* this, int ch){
	int i, j;
	if(ch<0 || ch>BMSMAXBUFFER-1) return FALSE;

	for(i=0; i<this->dataNum[ch]-1; i++)
		for(j=i+1; j<this->dataNum[ch]; j++)
			if(this->data[ch][i].timing > this->data[ch][j].timing){
				BMSDATA tmp;
				memcpy(&tmp, &this->data[ch][i], sizeof(BMSDATA));
				memcpy(&this->data[ch][i], &this->data[ch][j], sizeof(BMSDATA));
				memcpy(&this->data[ch][j], &tmp, sizeof(BMSDATA));
			}

	return TRUE;
}

int Bms_getCountFromTime(Bms* this, double sec){
	int i, count=0, count2;
	double t=0, bpm=120, sub;

	if( this->dataNum[BMS_TEMPO]>0 )
		bpm = this->data[BMS_TEMPO][0].fdata;

	if(sec<0) return 0;

	for(i=0;i<this->dataNum[BMS_TEMPO];i++){
		double add = (double)(this->data[BMS_TEMPO][i].timing-count)/(bpm/60)/(BMSDATA_RESOLUTION/4);
		if(t+add>sec) break;//現在時を超えるときは抜ける

		t += add;
		bpm = (double)this->data[BMS_TEMPO][i].fdata;
		count = this->data[BMS_TEMPO][i].timing;
	}

	//抜けたとこからのも足す
	sub = sec-t;
	count2 = sub*(BMSDATA_RESOLUTION/4)*(bpm/60);
	count += count2;
	return count;
}

bool Bms_load(Bms* this, char* f){
	if(!Bms_getHeader(this, f))
		return FALSE;
	if(!Bms_loadBmsData(this, f))
		return FALSE;
	return TRUE;
}

bool Bms_getHeader(Bms* this, char* f){
	int i, p=0; //p:いわゆるfpみたいな使い方する
	char buf[1024];

	Bms_clear(this);

	while(TRUE){
		int com;
		char str[256];

		//終端なら終了
		if(f[p]=='\0') break;

		//bufに1行読む
		memset(buf,0,sizeof(buf));
		for(i=0;f[p+i]!='\n';i++){}		//i:改行までの文字数
		strncpy(buf,f+p,i);				//改行は読まない
		i++;								//改行のぶん
		p += i;

		//コマンド以外ならパス
		if( buf[0]!='#') continue;

		//コマンド(com)とデータ(str)を取得
		com = Bms_getCommand(buf);
		if(com<-1) continue;		//認識できないコマンドならパス
		memset(str,0,sizeof(str));
		if(!Bms_getCommandString(buf,str)) return FALSE;

		//データ格納
		switch(com)
		{
			char s[4];//数字取得用
			memset(s,0,sizeof(s));
		case 0: // PLAYER
			this->header.player = atoi(str);
			break;
		case 1: // GENRE
			strcpy(this->header.genre, str);
			break;
		case 2: // TITLE
			strcpy(this->header.title, str);
			break;
		case 3: // ARTIST
			strcpy(this->header.artist, str);
			break;
		case 4: // BPM
			if( buf[4]==' ' || buf[4]=='\t'){
				this->header.bpm = Bms_atof(str);
				Bms_addData(this, BMS_TEMPO, 0, this->header.bpm);
			} else {
				memcpy(s,buf+4,2);
				this->header.bpmIndex[atoi(s)].bpm = Bms_atof(str);
			}
			break;
		case 6: // PLAYLEVEL
			this->header.playLevel = atoi(str);
			break;
		case 7: // RANK
			this->header.rank = atoi(str);
			break;
		case 5: break;
		case 8: break;
		case 9: break;
		case 10: break;
		case 11: break;
		case 12: break;
		case 13: break;
		case 14: break;
		default: {
				int index, ch;

				memcpy(s,buf+1,3);
				index = atoi(s);

				memset(s,0,sizeof(s));
				memcpy(s,buf+4,2);
				ch = atoi(s);

				if(ch==BMS_STRETCH){
					this->barMagni[this->barMagniNum].index = index;
					this->barMagni[this->barMagniNum].magnitude = Bms_atof(str);
					this->barMagniNum++;					
				}

				if(this->header.endBar < index)
					this->header.endBar = index;
			}
			break;
		}
	}

	{
		int i,j,sum=0,add;
		for(i=0; i<=this->header.endBar+1; i++){
			//小節を追加
			this->bar[this->barNum].flag = TRUE;
			this->bar[this->barNum].timing = sum;//.data は無視
			this->barNum++;

			//maxCountを求めるために足してく
			add = BMSDATA_RESOLUTION;
			for(j=0; j<this->barMagniNum; j++){
				if(this->barMagni[j].index==i){
					add = BMSDATA_RESOLUTION * this->barMagni[j].magnitude;
					break;
				}
			}
			sum += add;
			if(i<=this->header.endBar && this->header.maxCount<sum)
				this->header.maxCount = sum;
		}
	}

	return TRUE;
}

bool Bms_loadBmsData(Bms* this, char* f){
	int i, p=0; //p:いわゆるfpみたいな使い方する
	char buf[1024];

	while(TRUE){
		int com;
		char str[256];

		//終端なら終了
		if(f[p]=='\0') break;

		//bufに1行読む
		memset(buf,0,sizeof(buf));
		for(i=0;f[p+i]!='\n';i++){}		//i:改行までの文字数
		strncpy(buf,f+p,i);				//改行は読まない
		i++;								//改行のぶん
		p += i;

		//コマンド以外ならパス
		if( buf[0]!='#') continue;

		//コマンド(com)とデータ(str)を取得
		com = Bms_getCommand(buf);
		if(com!=-1) continue;		//データ以外ならパス
		memset(str,0,sizeof(str));
		if(!Bms_getCommandString(buf,str)) return FALSE;

		{
			int index, ch, len, startCount, chkline;
			char s[4];
			float nowBarReso;

			memset(s,0,sizeof(s));
			memcpy(s,buf+4,2);
			ch = atoi(s);

			if(ch==BMS_STRETCH) continue;

			memset(s,0,sizeof(s));
			memcpy(s,buf+1,3);
			index = atoi(s);

			if(strlen(str)<1 || strlen(str)%2==1) continue;

			len = strlen(str)/2;
			startCount = 0;
			chkline =0;
			while(chkline<index){
				int add = BMSDATA_RESOLUTION;
				for(i=0; i<this->barMagniNum; i++){
					if(this->barMagni[i].index==chkline){
						add = ((float)BMSDATA_RESOLUTION*this->barMagni[i].magnitude);
						break;
					}
				}
				startCount += add;
				chkline++;
			}

			nowBarReso = (float)BMSDATA_RESOLUTION/(float)len;
			for(i=0; i<this->barMagniNum; i++){
				if(this->barMagni[i].index==chkline){
					nowBarReso = ((float)BMSDATA_RESOLUTION*this->barMagni[i].magnitude)/len;
					break;
				}
			}

			memset(s,0,sizeof(s));
			for(i=0;i<len;i++){
				int hex;
				s[0] = str[i*2];
				s[1] = str[i*2+1];
				hex = Bms_atoi3610(s);
				if(hex>0)
					Bms_addData(this, ch, startCount+nowBarReso*(float)i, hex);
			}
		}
	}

	for(i=0; i<BMSMAXBUFFER; i++)
		Bms_sort(this, i);

	return TRUE;
}

int Bms_getCommand(char* s){
	const char *command[15] = {
		"PLAYER\0",//いらない
		"GENRE\0",
		"TITLE\0",
		"ARTIST\0",
		"BPM\0",
		"MIDIFILE\0",//いらない
		"PLAYLEVEL\0",
		"RANK\0",
		"VOLWAV\0",
		"TOTAL\0",
		"STAGEFILE\0",//いらない
		"WAV\0",//いらない
		"BMP\0",//いらない
		"GUID\0",//いらない
		"MOVIE\0",//いらない
	};
	int i;
	bool obj = TRUE;

	//コマンド(英字)か見る
	for(i=0;i<15;i++)
		if(strncmp(s+1,command[i],strlen(command[i])) == 0)//strnicmp(大小無視)が使えないのでstrncmpで代用
			return i;
	
	//コマンド(数字)か見る
	for(i=0;i<5;i++){
		if(s[i+1]<'0' || s[i+1]>'9'){
			obj = FALSE;
			break;
		}
	}
	if(obj)
		return -1;

	return -2;
}


bool Bms_getCommandString(char* src, char* dst){
	int i=0, j=0;
	while(TRUE){
		//データ部分まで読む
		if(src[i]==' ' || src[i]=='\t' || src[i]==':'){
			i++;
			break;
		}
		//データに行き当たらなかったらFALSE
		if(src[i]=='\n' || src[i]=='\0') return FALSE;

		i++;
	}

	//終端までコピー
	while(TRUE){
		if(src[i]=='\n' || src[i]=='\0')
			break;
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j]='\0';
	return TRUE;
}


bool Bms_addData(Bms* this, int ch, int startPos, float dat){
	if(ch<0 || ch>255) return FALSE;
	if(ch==BMS_STRETCH) return FALSE;
	if(dat==0) return TRUE;
	switch(ch)
	{
	case BMS_BPMINDEX://BMS_BPMINDEX(0x08)に来たらBMS_TEMPO(0x03)に統合 //今のプログラムではやってないっぽい？
		this->data[BMS_TEMPO][this->dataNum[BMS_TEMPO]].flag = TRUE;
		this->data[BMS_TEMPO][this->dataNum[BMS_TEMPO]].timing = startPos;
		this->data[BMS_TEMPO][this->dataNum[BMS_TEMPO]].data = (int) this->header.bpmIndex[(int)(dat+0.5)].bpm;
		this->data[BMS_TEMPO][this->dataNum[BMS_TEMPO]].fdata = (float) this->header.bpmIndex[(int)(dat+0.5)].bpm;
		//datがint,long -> fdataの意味がなくなる のでdatをfloatとしたが、配列添字に使用するとき本当に正しく動くか？//今はパス
		this->dataNum[BMS_TEMPO]++;
		break;
	default:
		this->data[ch][this->dataNum[ch]].flag = TRUE;
		this->data[ch][this->dataNum[ch]].timing = startPos;
		this->data[ch][this->dataNum[ch]].data = (int) dat;
		this->data[ch][this->dataNum[ch]].fdata = (float) dat;
		this->dataNum[ch]++;
		break;
	}
	return TRUE;
}

