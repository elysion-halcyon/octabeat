#include "fumen.h"

//譜面をつくるときの注意
//開始は2小節目以降の方がいいかも
//11 12 13 14 15 18 19 16  //ch
// 1  2  3  4  5  6  7 Scr //BME format
//CR UR UC UL CL LL LC LR  //OCTABEAT format [Lower/Upper][Left/Right] (Center)
  //これ間違ってるかも

//行末に\n\をつける、または一行ごとに" ... \n"で囲む
//awk '{print $0 "\\n\\"}' test.bms > _test.txt

//今の仕様での制限
//文字列の最後が改行じゃないと止まらない
//一行1024文字以内


char *fumen[FUMENMAX]={

//////////////////////////////////////////////////////////
//                   Octave EASY                        //
//////////////////////////////////////////////////////////
"\n\
*---------------------- HEADER FIELD\n\
\n\
#PLAYER 1\n\
#GENRE pops\n\
#TITLE Octave\n\
#ARTIST As\n\
#BPM 120\n\
#PLAYLEVEL 1\n\
#RANK 3\n\
#STAGEFILE \n\
\n\
#WAV01 Clap1.mp3\n\
#WAV02 octave.wav\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
*---------------------- MAIN DATA FIELD\n\
\n\
\n\
\n\
\n\
\n\
\n\
#00519:01010101\n\
\n\
#00615:01010101\n\
\n\
#00713:01010101\n\
\n\
#00811:01010101\n\
\n\
#00916:01010101\n\
\n\
#01018:01010101\n\
\n\
#01114:01010101\n\
\n\
#01212:01010101\n\
\n\
#01351:01\n\
\n\
#01451:00000001\n\
\n\
#01558:01\n\
\n\
#01658:00000001\n\
\n\
#01753:01\n\
\n\
#01853:00000001\n\
\n\
#01956:01\n\
\n\
#02056:00000001\n\
\n\
#02119:00010001\n\
\n\
#02219:00010001\n\
\n\
#02318:00010001\n\
#02319:00010001\n\
\n\
#02418:00010001\n\
#02419:00010001\n\
\n\
#02516:00010001\n\
\n\
#02616:00010001\n\
\n\
#02711:00010001\n\
#02716:00010001\n\
\n\
#02811:00010101\n\
#02816:00010101\n\
\n\
#02916:0001\n\
#02919:01\n\
\n\
#03011:01\n\
#03012:0001\n\
\n\
#03113:01\n\
#03114:0001\n\
\n\
#03215:01010101\n\
\n\
#03315:0001\n\
#03318:01\n\
\n\
#03413:0001\n\
#03414:01\n\
\n\
#03511:0001\n\
#03512:01\n\
\n\
#03616:01010101\n\
\n\
#03718:0001\n\
#03719:01\n\
\n\
#03814:0001\n\
#03815:01\n\
\n\
#03912:0001\n\
#03913:01\n\
\n\
#04011:01010101\n\
\n\
#04111:0001\n\
#04116:01\n\
\n\
#04212:01\n\
#04213:0001\n\
\n\
#04314:01\n\
#04315:0001\n\
\n\
#04418:01010101\n\
\n\
#04518:01\n\
#04519:01\n\
\n\
"



,




//////////////////////////////////////////////////////////
//                  Octave NORMAL                       //
//////////////////////////////////////////////////////////
"\n\
*---------------------- HEADER FIELD\n\
\n\
#PLAYER 1\n\
#GENRE pops\n\
#TITLE Octave\n\
#ARTIST As\n\
#BPM 120\n\
#PLAYLEVEL 3\n\
#RANK 2\n\
#STAGEFILE \n\
\n\
#WAV01 Clap1.mp3\n\
#WAV02 octave.wav\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
*---------------------- MAIN DATA FIELD\n\
\n\
\n\
\n\
\n\
\n\
\n\
#00518:000U000U\n\
#00519:01010101\n\
\n\
#00614:000U000U\n\
#00615:01010101\n\
\n\
#00712:000U000U\n\
#00713:01010101\n\
\n\
#00811:01010101\n\
#00816:000U000U\n\
\n\
#00916:01010101\n\
#00919:000U000U\n\
\n\
#01015:000U000U\n\
#01018:01010101\n\
\n\
#01113:000U000U\n\
#01114:01010101\n\
\n\
#01211:000U000U\n\
#01212:01010101\n\
\n\
#01351:01\n\
#01354:01\n\
#01359:01\n\
\n\
#01451:00000001\n\
#01454:00000001\n\
#01459:00000001\n\
\n\
#01553:01\n\
#01556:01\n\
#01558:01\n\
\n\
#01653:00000001\n\
#01656:00000001\n\
#01658:00000001\n\
\n\
#01752:01\n\
#01755:01\n\
#01759:01\n\
\n\
#01852:00000001\n\
#01855:00000001\n\
#01859:00000001\n\
\n\
#01951:01\n\
#01954:01\n\
#01958:01\n\
\n\
#02051:00000001\n\
#02054:00000001\n\
#02058:00000001\n\
\n\
#02115:00010001\n\
#02152:01\n\
\n\
#02215:00010001\n\
#02252:00000001\n\
\n\
#02318:00010001\n\
#02353:01\n\
\n\
#02418:00010001\n\
#02453:00000001\n\
\n\
#02519:00010001\n\
#02554:01\n\
\n\
#02619:00010001\n\
#02654:00000001\n\
\n\
#02716:00010001\n\
#02755:01\n\
\n\
#02816:01010101\n\
#02855:00000001\n\
\n\
#02911:00000001\n\
#02916:0001\n\
#02919:01\n\
\n\
#03012:01\n\
#03013:00010000\n\
#03014:0001\n\
#03015:00000001\n\
\n\
#03118:01\n\
#03119:0001\n\
\n\
#03211:01\n\
#03213:00010000\n\
#03215:0001\n\
#03219:00000001\n\
\n\
#03314:00000001\n\
#03315:0001\n\
#03318:01\n\
\n\
#03411:0001\n\
#03412:00010000\n\
#03413:01\n\
#03416:00000001\n\
\n\
#03518:0001\n\
#03519:01\n\
\n\
#03612:00010000\n\
#03614:01\n\
#03616:0001\n\
#03618:00000001\n\
\n\
#03714:01\n\
#03715:0001\n\
#03718:00000001\n\
\n\
#03811:0001\n\
#03812:00000001\n\
#03816:00010000\n\
#03819:01\n\
\n\
#03913:01\n\
#03914:0001\n\
\n\
#04012:0001\n\
#04014:00000001\n\
#04016:00010000\n\
#04018:01\n\
\n\
#04111:00000001\n\
#04112:0001\n\
#04113:01\n\
\n\
#04215:00000001\n\
#04216:01\n\
#04218:0001\n\
#04219:00010000\n\
\n\
#04313:0001\n\
#04314:01\n\
\n\
#04411:0001\n\
#04413:00000001\n\
#04415:01\n\
#04419:00010000\n\
\n\
#04514:01\n\
#04515:01\n\
#04518:01\n\
\n\
"

,


//////////////////////////////////////////////////////////
//                   Octave HARD                        //
//////////////////////////////////////////////////////////

"\n\
*---------------------- HEADER FIELD\n\
\n\
#PLAYER 1\n\
#GENRE pops\n\
#TITLE Octave\n\
#ARTIST As\n\
#BPM 120\n\
#PLAYLEVEL 6\n\
#RANK 1\n\
#STAGEFILE \n\
\n\
#WAV01 Clap1.mp3\n\
#WAV02 octave.wav\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
*---------------------- MAIN DATA FIELD\n\
\n\
\n\
\n\
\n\
\n\
\n\
#00512:00000000000000000100010000010000\n\
#00515:01010101\n\
#00516:01000100000100000000000000000000\n\
\n\
#00612:00000000000000000100010000010000\n\
#00615:01010101\n\
#00616:01000100000100000000000000000000\n\
\n\
#00711:01010101\n\
#00714:00000000000000000100010000010000\n\
#00718:01000100000100000000000000000000\n\
\n\
#00811:01010101\n\
#00814:00000000000000000100010000010000\n\
#00818:01000100000100000000000000000000\n\
\n\
#00911:01000100000100000000000000000000\n\
#00913:00000000000000000100010000010000\n\
#00918:01010101\n\
\n\
#01011:01000100000100000000000000000000\n\
#01013:00000000000000000100010000010000\n\
#01018:01010101\n\
\n\
#01112:01010101\n\
#01115:00000000000000000100010000010000\n\
#01119:01000100000100000000000000000000\n\
\n\
#01212:01010101\n\
#01215:00000000000000000100010000010000\n\
#01219:01000100000100000000000000000000\n\
\n\
#01351:01\n\
\n\
#01416:0000000000010000\n\
#01419:00000001\n\
#01451:0001\n\
#01458:0000000000000001\n\
\n\
\n\
#01611:0001\n\
#01612:0000000000010000\n\
#01613:00000001\n\
#01653:0000000000000001\n\
#01658:00010000\n\
\n\
#01714:00010000\n\
#01753:0001000000000000\n\
#01759:0000000100000000\n\
\n\
#01811:00000001\n\
#01812:0000000000010000\n\
#01813:0001\n\
#01814:0000000100000000\n\
#01815:00010000\n\
#01818:0001000000000000\n\
#01856:0000000000000001\n\
#01859:01\n\
\n\
\n\
#02056:00000001\n\
\n\
#02153:01\n\
\n\
#02214:0000000000010000\n\
#02215:00000001\n\
#02253:0001\n\
#02258:0000000000000001\n\
\n\
#02314:0001000000000000\n\
#02355:00010000\n\
#02358:01\n\
\n\
#02416:00000001\n\
#02418:0001\n\
#02419:0000000000010000\n\
#02455:00010000\n\
#02456:0000000000000001\n\
\n\
#02512:00000001\n\
#02513:0000000000010000\n\
#02514:0001\n\
#02515:0000000100000000\n\
#02552:0000000000000001\n\
#02556:00010000\n\
\n\
#02613:0001000000000000\n\
#02614:00010000\n\
#02615:0000000100000000\n\
#02618:0001\n\
#02619:00000001\n\
#02652:01\n\
#02659:0000000000000001\n\
\n\
#02712:00000000000000000000000001000101\n\
#02715:00000001\n\
#02755:0000000000000001\n\
#02759:0000000000010000\n\
\n\
#02812:00010101010001010001010100000000\n\
#02852:00000000000000000000000001000001\n\
#02855:00000001\n\
\n\
#02911:00000001\n\
#02916:0001\n\
#02953:0100000100000000\n\
\n\
#03012:01\n\
#03013:00010000\n\
#03014:0001\n\
#03015:00000001\n\
\n\
#03116:0000000000000001\n\
#03158:0100000100000000\n\
#03159:0000000001000001\n\
\n\
#03211:01\n\
#03212:0001000000000000\n\
#03213:00010000\n\
#03214:0000000100000000\n\
#03215:0001\n\
#03219:00000001\n\
\n\
#03314:00000001\n\
#03315:0001\n\
#03358:0100000100000000\n\
\n\
#03411:0001\n\
#03412:00010000\n\
#03413:01\n\
#03416:00000001\n\
\n\
#03515:0000000000000001\n\
#03558:00000101\n\
#03559:0100000100000000\n\
\n\
#03611:0000000100000000\n\
#03612:00010000\n\
#03613:0001000000000000\n\
#03614:01\n\
#03616:0001\n\
#03618:00000001\n\
\n\
#03715:0001\n\
#03718:00000001\n\
#03754:0100000100000000\n\
\n\
#03811:0001\n\
#03812:00000001\n\
#03816:00010000\n\
#03819:01\n\
\n\
#03915:0000000000000001\n\
#03953:0100000100000000\n\
#03954:00000101\n\
\n\
#04011:0000000100000000\n\
#04012:0001\n\
#04014:00000001\n\
#04016:00010000\n\
#04018:01\n\
#04019:0001000000000000\n\
\n\
#04111:00000001\n\
#04112:0001\n\
#04153:0100000100000000\n\
\n\
#04215:00000001\n\
#04216:01\n\
#04218:0001\n\
#04219:00010000\n\
\n\
#04311:00000000000000000000000000000001\n\
#04312:0000000000000001\n\
#04353:00000101\n\
#04354:0100000100000000\n\
\n\
#04411:0000000000000001\n\
#04412:00000001\n\
#04413:0000000000010000\n\
#04414:0001\n\
#04415:0000000100000000\n\
#04416:01\n\
#04418:00010000\n\
#04419:0001000000000000\n\
\n\
#04512:01\n\
#04513:01\n\
#04514:01\n\
#04515:01\n\
#04516:01\n\
#04518:01\n\
\n\
"




,






//////////////////////////////////////////////////////////
//                   Double HeLiX EASY                  //
//////////////////////////////////////////////////////////
"\n\
*---------------------- HEADER FIELD\n\
\n\
#PLAYER 1\n\
#GENRE ARTCORE\n\
#TITLE Double HeLiX\n\
#ARTIST As\n\
#BPM 180\n\
#PLAYLEVEL 4\n\
#RANK 3\n\
#STAGEFILE \n\
\n\
#WAV01 Clap1.mp3\n\
\n\
\n\
\n\
#BPM01 170.0001\n\
#BPM02 160.0001\n\
#BPM03 150.0001\n\
#BPM04 130.0001\n\
#BPM05 180.0001\n\
#BPM06 170.0001\n\
#BPM07 160.0001\n\
#BPM08 150.0001\n\
#BPM09 130.0001\n\
#BPM0A 180.0001\n\
\n\
\n\
\n\
\n\
\n\
*---------------------- MAIN DATA FIELD\n\
\n\
\n\
\n\
\n\
#00311:01\n\
#00316:0001\n\
\n\
#00418:0001\n\
#00419:01\n\
\n\
#00514:0001\n\
#00515:01\n\
\n\
#00612:0001\n\
#00613:01\n\
\n\
#00711:01\n\
#00716:0001\n\
\n\
#00818:0001\n\
#00819:01\n\
\n\
#00914:0001\n\
#00915:01\n\
\n\
#01012:0001\n\
#01013:01\n\
\n\
#01112:0001\n\
#01115:01010000\n\
\n\
#01212:0001\n\
#01215:00010000\n\
\n\
#01312:0001\n\
#01315:01010000\n\
\n\
#01412:0001\n\
#01415:00010000\n\
\n\
#01508:01\n\
#01512:0001\n\
#01515:01010000\n\
\n\
#01608:02\n\
#01612:0001\n\
#01615:00010000\n\
\n\
#01708:03\n\
#01712:0001\n\
#01715:01010000\n\
\n\
#01808:04\n\
#01812:0001\n\
#01815:00010000\n\
\n\
#01908:05\n\
\n\
#02053:01\n\
\n\
#02153:00000001\n\
\n\
#02251:01000001\n\
\n\
#02312:0001\n\
#02319:01\n\
\n\
#02414:0100000100000000\n\
#02418:00000001\n\
\n\
#02514:00000101\n\
#02518:0001000000000000\n\
\n\
#02614:01\n\
#02618:0001\n\
\n\
#02712:0001\n\
#02716:01\n\
\n\
#02853:01000001\n\
\n\
#02915:0101\n\
\n\
#03019:0101\n\
\n\
#03111:01\n\
#03151:0001\n\
\n\
#03212:0000000100000000\n\
#03216:01000001\n\
\n\
#03312:0001000000000100\n\
#03316:0001\n\
\n\
#03414:0101\n\
#03451:01\n\
\n\
#03516:0001\n\
#03518:01\n\
\n\
#03612:0001\n\
#03651:01000000000000000000000000000001\n\
\n\
#03713:01\n\
#03714:0001\n\
\n\
#03815:01\n\
#03818:0001\n\
\n\
#03916:0001\n\
#03919:01\n\
\n\
#04011:01\n\
#04012:0001\n\
\n\
#04113:01\n\
#04114:0001\n\
\n\
#04215:01\n\
#04218:0001\n\
\n\
#04316:0001\n\
#04319:01\n\
\n\
#04415:01010000\n\
#04416:0001\n\
\n\
#04515:00010000\n\
#04516:0001\n\
\n\
#04615:01010000\n\
#04616:0001\n\
\n\
#04715:00010000\n\
#04716:0001\n\
\n\
#04808:06\n\
#04815:01010000\n\
#04816:0001\n\
\n\
#04908:07\n\
#04915:00010000\n\
#04916:0001\n\
\n\
#05008:08\n\
#05015:01010000\n\
#05016:0001\n\
\n\
#05108:09\n\
#05115:00010000\n\
#05116:0001\n\
\n\
#05208:05\n\
\n\
#05319:0101\n\
\n\
#05411:01\n\
#05413:0001\n\
\n\
#05515:0100000100010000\n\
#05555:0000000000000001\n\
\n\
#05654:0000000001000001\n\
#05655:0000000100000000\n\
\n\
#05712:0001\n\
#05753:01\n\
\n\
#05816:01\n\
#05818:0001\n\
\n\
#05912:0001\n\
#05914:01\n\
#05953:01\n\
\n\
#06016:01\n\
#06018:0001\n\
\n\
#06119:0101\n\
\n\
#06218:0101\n\
\n\
#06319:0100000100010001\n\
\n\
#06419:0001\n\
\n\
#06551:01\n\
\n\
#06651:0000000000000001\n\
\n\
#06756:01010000\n\
#06759:0000000100000000\n\
\n\
\n\
#06918:01\n\
#06959:01\n\
\n\
"

,






//////////////////////////////////////////////////////////
//                 Double HeLiX NORMAL                  //
//////////////////////////////////////////////////////////
"\n\
*---------------------- HEADER FIELD\n\
\n\
#PLAYER 1\n\
#GENRE ARTCORE\n\
#TITLE Double HeLiX\n\
#ARTIST As\n\
#BPM 180\n\
#PLAYLEVEL 7\n\
#RANK 2\n\
#STAGEFILE \n\
\n\
#WAV01 Clap1.mp3\n\
\n\
\n\
\n\
#BPM01 170.0001\n\
#BPM02 160.0001\n\
#BPM03 150.0001\n\
#BPM04 130.0001\n\
#BPM05 180.0001\n\
#BPM06 170.0001\n\
#BPM07 160.0001\n\
#BPM08 150.0001\n\
#BPM09 130.0001\n\
#BPM0A 180.0001\n\
\n\
\n\
\n\
\n\
\n\
*---------------------- MAIN DATA FIELD\n\
\n\
\n\
\n\
\n\
#00311:01\n\
#00319:0001\n\
\n\
#00413:0001\n\
#00415:01\n\
\n\
#00511:01\n\
#00519:0001\n\
\n\
#00612:0001\n\
#00615:01\n\
\n\
#00711:01\n\
#00719:0001\n\
\n\
#00812:0001\n\
#00814:01\n\
\n\
#00911:01\n\
#00918:0001\n\
\n\
#01012:0001\n\
#01014:01\n\
\n\
#01112:00000101\n\
#01115:01010000\n\
\n\
#01212:00000101\n\
#01215:00010000\n\
\n\
#01312:00000101\n\
#01315:01010000\n\
\n\
#01412:00000101\n\
#01415:00010000\n\
\n\
#01508:01\n\
#01512:00000101\n\
#01515:01010000\n\
\n\
#01608:02\n\
#01612:00000101\n\
#01615:00010000\n\
\n\
#01708:03\n\
#01712:00000101\n\
#01715:01010000\n\
\n\
#01808:04\n\
#01812:00000101\n\
#01815:00010000\n\
\n\
#01908:05\n\
#01911:00000001\n\
#01912:0000000000000001\n\
\n\
#02053:01\n\
\n\
#02111:00000001\n\
#02112:0000000000010000\n\
#02153:0001\n\
#02156:0000000000000001\n\
\n\
#02215:0000000000000001\n\
#02218:00000001\n\
#02219:0000000000010000\n\
#02256:0001\n\
\n\
#02313:0000000000000001\n\
#02314:00010001\n\
#02315:0000000100010000\n\
#02318:0001\n\
\n\
#02412:0100000100000000\n\
#02414:0000000100000100\n\
#02416:01\n\
#02418:00000001\n\
\n\
#02512:00000101\n\
#02514:00000001\n\
#02516:0001000001000000\n\
#02518:0001000000000000\n\
\n\
#02611:01\n\
#02612:00010000\n\
#02613:0000000100000000\n\
#02614:0000000000010000\n\
#02615:00000001\n\
\n\
#02711:0000000000010000\n\
#02712:0000000100000100\n\
#02713:00010000\n\
#02714:0001000000000000\n\
\n\
#02814:0000000000010000\n\
#02815:00000001\n\
#02818:0000000000000001\n\
#02853:0101\n\
\n\
#02914:0000000100000001\n\
#02915:0000010000010000\n\
\n\
#03011:00000001\n\
#03012:0000010000000001\n\
#03013:0001000000000000\n\
\n\
#03113:01010000\n\
#03114:0000000100010000\n\
#03155:00000001\n\
\n\
#03212:01\n\
#03214:00000001\n\
#03216:0100000100000000\n\
#03218:0000000100000100\n\
\n\
#03312:0001000001000000\n\
#03314:0001000000000000\n\
#03316:00000101\n\
#03318:00000001\n\
\n\
#03412:0100010000000001\n\
#03413:0000000100000000\n\
#03455:01\n\
\n\
#03511:01\n\
#03512:0000000000000001\n\
#03513:00000001\n\
#03514:0000000000010000\n\
#03515:0001\n\
#03516:0001000000000000\n\
#03518:0000000100000000\n\
#03519:00010000\n\
\n\
#03612:0001\n\
#03651:01\n\
\n\
#03714:01\n\
#03718:0001\n\
#03751:01\n\
\n\
#03811:01\n\
#03812:0001\n\
\n\
#03914:01\n\
#03919:0001\n\
\n\
#04011:01\n\
#04012:0001\n\
\n\
#04115:01\n\
#04119:0001\n\
\n\
#04211:01\n\
#04213:0001\n\
\n\
#04315:01\n\
#04319:0001\n\
\n\
#04415:01010000\n\
#04416:00000101\n\
\n\
#04515:00010000\n\
#04516:00000101\n\
\n\
#04615:01010000\n\
#04616:00000101\n\
\n\
#04715:00010000\n\
#04716:00000101\n\
\n\
#04808:06\n\
#04815:01010000\n\
#04816:00000101\n\
\n\
#04908:07\n\
#04915:00010000\n\
#04916:00000101\n\
\n\
#05008:08\n\
#05015:01010000\n\
#05016:00000101\n\
\n\
#05108:09\n\
#05115:00010000\n\
#05116:00000101\n\
\n\
#05208:05\n\
#05218:00000001\n\
#05219:0000000000000001\n\
\n\
#05311:0001\n\
#05312:00000001\n\
#05316:01\n\
\n\
#05413:01\n\
#05414:00010000\n\
#05415:0001\n\
#05418:00000001\n\
\n\
#05516:0000000100010000\n\
#05519:01010000\n\
#05551:0000000000000001\n\
\n\
#05651:0000000100000000\n\
#05652:0000000001000001\n\
\n\
#05714:0001000001000001\n\
#05753:01\n\
\n\
#05814:0000010000010000\n\
#05853:0000000000000001\n\
\n\
#05915:01\n\
#05918:0000010000000001\n\
#05919:0001\n\
\n\
#06012:00000001\n\
#06013:0001\n\
#06014:00010000\n\
#06015:01\n\
\n\
#06111:0001010100000000\n\
#06119:0000000000010101\n\
\n\
#06216:0001010100000000\n\
#06218:0000000000010101\n\
\n\
#06313:0000000000000001\n\
#06314:0000000100010000\n\
#06315:01010000\n\
\n\
#06412:0000000000000001\n\
#06413:00000001\n\
#06414:0001000000010000\n\
#06415:00010100\n\
\n\
#06551:01\n\
\n\
#06611:00000000000000000000000000000001\n\
#06612:0000000000000001\n\
#06651:00000001\n\
\n\
#06756:01010000\n\
#06759:0000000100000000\n\
\n\
\n\
#06912:01\n\
#06914:01\n\
#06959:01\n\
\n\
"

,




//////////////////////////////////////////////////////////
//                   Double HeLiX HARD                  //
//////////////////////////////////////////////////////////
"\n\
*---------------------- HEADER FIELD\n\
\n\
#PLAYER 1\n\
#GENRE ARTCORE\n\
#TITLE Double HeLiX\n\
#ARTIST As\n\
#BPM 180\n\
#PLAYLEVEL 9\n\
#RANK 1\n\
#STAGEFILE \n\
\n\
#WAV01 Clap1.mp3\n\
\n\
\n\
\n\
#BPM01 170.0001\n\
#BPM02 160.0001\n\
#BPM03 150.0001\n\
#BPM04 130.0001\n\
#BPM05 180.0001\n\
#BPM06 170.0001\n\
#BPM07 160.0001\n\
#BPM08 150.0001\n\
#BPM09 130.0001\n\
#BPM0A 180.0001\n\
\n\
\n\
\n\
\n\
\n\
*---------------------- MAIN DATA FIELD\n\
\n\
\n\
\n\
\n\
#00311:01\n\
#00313:00000001\n\
#00315:0001\n\
#00319:00010000\n\
\n\
#00411:01\n\
#00413:00000001\n\
#00415:0001\n\
#00419:00010000\n\
\n\
#00511:01\n\
#00512:00000001\n\
#00515:0001\n\
#00519:00010000\n\
\n\
#00611:01\n\
#00612:00000001\n\
#00615:0001\n\
#00619:00010000\n\
\n\
#00711:01\n\
#00712:00000001\n\
#00714:0001\n\
#00719:00010000\n\
\n\
#00811:01\n\
#00812:00000001\n\
#00814:0001\n\
#00819:00010000\n\
\n\
#00911:01\n\
#00912:00000001\n\
#00914:0001\n\
#00918:00010000\n\
\n\
#01011:01\n\
#01012:00000001\n\
#01014:0001\n\
#01018:00010000\n\
\n\
#01112:0001\n\
#01113:01010000\n\
#01114:00010001\n\
\n\
#01212:0001\n\
#01213:00010000\n\
#01214:00010001\n\
\n\
#01312:0001\n\
#01313:01010000\n\
#01314:00010001\n\
\n\
#01412:0001\n\
#01413:00010000\n\
#01414:00010001\n\
\n\
#01508:01\n\
#01512:0001\n\
#01513:01010000\n\
#01514:00010001\n\
\n\
#01608:02\n\
#01612:0001\n\
#01613:00010000\n\
#01614:00010001\n\
\n\
#01708:03\n\
#01712:0001\n\
#01713:01010000\n\
#01714:00010001\n\
\n\
#01808:04\n\
#01812:0001\n\
#01813:00010000\n\
#01814:00010001\n\
\n\
#01908:05\n\
#01911:0000000000000001\n\
#01912:00000000000000000000000000010000\n\
#01913:00000001\n\
#01916:00000000000000000000000000000001\n\
\n\
#02059:01\n\
\n\
#02112:00000000000000000000000000010000\n\
#02113:00000001\n\
#02114:0000000000010000\n\
#02151:0000000000000001\n\
#02159:0001\n\
\n\
#02215:0000000000000001\n\
#02218:00000001\n\
#02219:0000000000010000\n\
#02251:0001\n\
\n\
#02313:0000000000000001\n\
#02314:00010001\n\
#02315:0000000100010000\n\
#02318:0001\n\
\n\
#02412:0100000100000000\n\
#02414:0000000100000100\n\
#02416:01\n\
#02418:00000001\n\
\n\
#02512:00000101\n\
#02514:00000001\n\
#02516:0001000001000000\n\
#02518:0001000000000000\n\
\n\
#02611:01\n\
#02612:00010000\n\
#02613:0000000100000000\n\
#02614:0000000000010000\n\
#02615:00000001\n\
\n\
#02711:0000000000010000\n\
#02712:0000000100000100\n\
#02713:00000000010000000000000000010000\n\
#02714:0001000000000001\n\
#02715:00000000000000000000000000000001\n\
\n\
#02811:0000000000000001\n\
#02816:00000001\n\
#02819:0000000000010000\n\
#02858:0101\n\
\n\
#02914:0000000100000001\n\
#02915:0000010000010000\n\
\n\
#03012:00010000\n\
#03013:0001000000000000\n\
#03014:00000000000000000000000000000001\n\
#03015:0000000000000001\n\
#03018:00000000000000000000000000010000\n\
#03019:00000001\n\
\n\
#03113:01010000\n\
#03114:0000000100010000\n\
#03115:00000001\n\
\n\
#03211:01000001\n\
#03212:0001000000000001\n\
#03213:00010000\n\
#03214:0000000100000000\n\
#03215:0000000100000000\n\
#03216:01000001\n\
#03218:0001\n\
#03219:0000000000010000\n\
\n\
#03311:0001\n\
#03312:0000000000010000\n\
#03313:01000001\n\
#03314:0001000000000100\n\
#03315:0001000000000001\n\
#03316:0001\n\
#03318:00010000\n\
#03319:0000000100000000\n\
\n\
#03411:0000000000000001\n\
#03412:00000000000000000000000000000001\n\
#03418:01010000\n\
#03419:0000000100000000\n\
\n\
#03511:0101\n\
#03512:00000000000000010000000000000001\n\
#03513:0000000100000001\n\
#03514:00000000000100000000000000010000\n\
#03515:00010001\n\
#03516:00010000000000000001000000000000\n\
#03518:00000001000000000000000100000000\n\
#03519:0001000000010000\n\
\n\
#03612:00010000\n\
#03614:0001\n\
#03618:00000001\n\
#03651:01\n\
\n\
#03712:00010000\n\
#03714:0001\n\
#03716:01\n\
#03718:00000001\n\
#03751:01\n\
\n\
#03812:00010000\n\
#03814:0001\n\
#03816:01\n\
#03819:00000001\n\
\n\
#03912:00010000\n\
#03914:0001\n\
#03916:01\n\
#03919:00000001\n\
\n\
#04012:00010000\n\
#04015:0001\n\
#04016:01\n\
#04019:00000001\n\
\n\
#04112:00010000\n\
#04115:0001\n\
#04116:01\n\
#04119:00000001\n\
\n\
#04213:00010000\n\
#04215:0001\n\
#04216:01\n\
#04219:00000001\n\
\n\
#04313:00010000\n\
#04315:0001\n\
#04316:01\n\
#04319:00000001\n\
\n\
#04416:00010001\n\
#04418:0001\n\
#04419:01010000\n\
\n\
#04516:00010001\n\
#04518:0001\n\
#04519:00010000\n\
\n\
#04616:00010001\n\
#04618:0001\n\
#04619:01010000\n\
\n\
#04716:00010001\n\
#04718:0001\n\
#04719:00010000\n\
\n\
#04808:06\n\
#04816:00010001\n\
#04818:0001\n\
#04819:01010000\n\
\n\
#04908:07\n\
#04916:00010001\n\
#04918:0001\n\
#04919:00010000\n\
\n\
#05008:08\n\
#05016:00010001\n\
#05018:0001\n\
#05019:01010000\n\
\n\
#05108:09\n\
#05116:00010001\n\
#05118:0001\n\
#05119:00010000\n\
\n\
#05208:05\n\
#05214:00000001\n\
#05215:00000000000000000000000000010000\n\
#05218:0000000000000001\n\
#05219:00000000000000000000000000000001\n\
\n\
#05311:00000000000000010000000000000000\n\
#05314:0000000000000001\n\
#05315:00000000000000000000000000000001\n\
#05316:0000000100000000\n\
#05318:0000000000010000\n\
#05319:00000000000000000000000100000000\n\
#05356:01000000010000000101000000000000\n\
#05358:00000000000000000000000001010000\n\
\n\
#05411:00000000000000010000000000000000\n\
#05412:0001000001000000\n\
#05413:00000001000000000000010000000000\n\
#05414:00000001\n\
#05415:0000000000000001\n\
#05416:0000000100000000\n\
#05452:00000000010100000000000000000000\n\
#05454:01010000000000000000000000000000\n\
\n\
#05514:01010000\n\
#05515:0000000100000000\n\
#05518:0100010000010000\n\
#05519:0000000100010000\n\
#05555:0000000000000001\n\
\n\
#05654:0000000001000001\n\
#05655:0000000100000000\n\
\n\
#05711:0000010000010000\n\
#05712:0001000001000001\n\
#05716:0000000100000100\n\
#05753:01\n\
\n\
#05811:0100000100000100\n\
#05812:0000010000010000\n\
#05816:00000100000000000100000000010000\n\
#05818:00000000000000000000000000000001\n\
#05819:0000000000000001\n\
#05853:0000000000010000\n\
\n\
#05914:00010000\n\
#05915:0100000100000000\n\
#05918:0000000001000001\n\
#05919:0000000000010000\n\
\n\
#06011:00010000\n\
#06012:00000001000000000000000100000000\n\
#06013:0001000000010100\n\
#06014:00010000000000000001000000010000\n\
#06015:0100000001000001\n\
#06016:00000000000100000000000000000000\n\
#06018:00000000000000010000000000000001\n\
#06019:0000000100000000\n\
\n\
#06111:00000000000000000000010001000101\n\
#06119:01000100010001010000000000000000\n\
\n\
#06212:01000100010001010000000000000000\n\
#06214:00000000000000000000010001000101\n\
\n\
#06312:01\n\
#06313:0001000000000000\n\
#06314:00010000\n\
#06315:01010000\n\
#06316:0000000000010000\n\
#06318:0000000100010001\n\
#06319:0000000100000001\n\
\n\
#06412:0000000000000001\n\
#06413:00010001\n\
#06414:0000000000010000\n\
#06415:0001000001000000\n\
#06418:0001000100000000\n\
\n\
#06512:00000001000000010000000100000001\n\
#06514:0001000100010001\n\
#06516:01010101\n\
#06518:00010000000100000001000000010000\n\
#06551:01\n\
\n\
#06612:00000001000000010000000100000000\n\
#06613:00000000000000000000000000000001\n\
#06614:0001000100010000\n\
#06615:0000000000000001\n\
#06616:01010101\n\
#06618:00010000000100000001000000010000\n\
#06651:00000001\n\
\n\
#06711:0000000000000001\n\
#06712:01010000\n\
#06713:0000000100000000\n\
#06719:00000000000000000000000000000001\n\
#06751:01010000\n\
#06754:0000000100000000\n\
\n\
#06811:0001000100010001\n\
#06813:00010000000100000001000000010000\n\
#06815:01010101\n\
#06819:00000001000000010000000100000001\n\
\n\
#06915:01\n\
#06954:01\n\
\n\
"








};
