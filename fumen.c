//譜面つくったらここに追加する


//譜面をつくるときの注意
//開始は2小節目以降の方がいいかも
//11 12 13 14 15 18 19 16  //ch
// 1  2  3  4  5  6  7 Scr //BME format
//CR UR UC UL CL LL LC LR  //OCTABEAT format [Lower/Upper][Left/Right] (Center)



//譜面データ

//行末に\n\をつける、または一行ごとに" ... \n"で囲む
//awk '{print $0 "\\n\\"}' test.bms > _test.bms

//今の仕様での制限
//文字列の最後が改行じゃないと止まらない
//一行1024文字以内


char *fumen[2]={

"\n\
#TITLE IMAGINE THE FUTURE.\n\
#ARTIST Tsukuba Univ.\n\
#BPM 170\n\
#PLAYLEVEL 11\n\
#RANK 3\n\
#TOTAL 300\n\
#VOLWAV 100\n\
#DIFFICULTY 2 \n\
\n\
*---------------------- MAIN DATA FIELD\n\
\n\
#00111:0000000000000065\n\
\n\
#00201:43\n\
#00201:00\n\
#00201:00\n\
#00201:6K\n\
#00201:00\n\
#00201:00\n\
"
,


"\n\
*---------------------- HEADER FIELD\n\
\n\
#PLAYER 1\n\
#GENRE test genre\n\
#TITLE metronome\n\
#ARTIST test artist\n\
#BPM 120\n\
#PLAYLEVEL 1\n\
#RANK 3\n\
#STAGEFILE \n\
\n\
#WAV01 M4.mp3\n\
\n\
*---------------------- MAIN DATA FIELD\n\
\n\
#00111:01\n\
#00113:00010000\n\
#00115:0001\n\
#00119:00000001\n\
\n\
#00212:0001\n\
#00214:00010000\n\
#00216:00000001\n\
#00218:01\n\
\n\
#00311:000001\n\
\n\
"




};
