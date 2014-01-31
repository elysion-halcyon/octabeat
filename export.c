#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0,  399,  298,  399,  3,     293888, NULL },		/* AG_CG_OCTABEATTITLE */
	{      36736,          0,  400,  300,  400,  3,     304888, NULL },		/* AG_CG_SELECTBACKGROUND */
	{      74847,          0,  154,  154,  154,  3,       8088, NULL },		/* AG_CG_NUMBER0 */
	{      75858,          0,  154,  154,  154,  3,       8368, NULL },		/* AG_CG_NUMBER1 */
	{      76904,          0,  154,  154,  154,  3,       7744, NULL },		/* AG_CG_NUMBER2 */
	{      77872,          0,  154,  154,  154,  3,       8072, NULL },		/* AG_CG_NUMBER3 */
	{      78881,          0,  154,  154,  154,  3,       7808, NULL },		/* AG_CG_NUMBER4 */
	{      79857,          0,  154,  154,  154,  3,       7768, NULL },		/* AG_CG_NUMBER5 */
	{      80828,          0,  154,  154,  154,  3,       8000, NULL },		/* AG_CG_NUMBER6 */
	{      81828,          0,  154,  154,  154,  3,       8384, NULL },		/* AG_CG_NUMBER7 */
	{      82876,          0,  154,  154,  154,  3,       7760, NULL },		/* AG_CG_NUMBER8 */
	{      83846,          0,  154,  154,  154,  3,       8032, NULL },		/* AG_CG_NUMBER9 */
	{      84850,          0,  300,  300,  300,  3,     130320, NULL },		/* AG_CG_RANKA */
	{     101140,          0,  300,  300,  300,  3,     125648, NULL },		/* AG_CG_RANKB */
	{     116846,          0,  300,  300,  300,  3,     135232, NULL },		/* AG_CG_RANKC */
	{     133750,          0,  300,  300,  300,  3,     157904, NULL },		/* AG_CG_RANKD */
	{     153488,          0,  300,  300,  300,  3,     160800, NULL },		/* AG_CG_RANKE */
	{     173588,          0,  300,  300,  300,  3,     149888, NULL },		/* AG_CG_RANKF */
	{     192324,          0,  300,  300,  300,  3,     128008, NULL },		/* AG_CG_RANKS */
	{     208325,          0,  300,  300,  300,  3,     104960, NULL },		/* AG_CG_BAD */
	{     221445,          0,  300,  300,  300,  3,     101984, NULL },		/* AG_CG_GOOD */
	{     234193,          0,  300,  300,  300,  3,      99632, NULL },		/* AG_CG_GREAT */
	{     246647,          0,  300,  300,  300,  3,      83016, NULL },		/* AG_CG_PERFECT */
	{     257024,          0,  300,  300,  300,  3,     105720, NULL },		/* AG_CG_POOR */
	{     270239,          0,  482,  197,  482,  3,      95960, NULL },		/* AG_CG_SELECT */
	{     282234,          0,  482,  197,  482,  3,      95960, NULL },		/* AG_CG_SELECT1 */
	{     294229,          0,  482,  197,  482,  3,      95960, NULL },		/* AG_CG_SELECT2 */
	{     306224,          0,  601, 1600,  601,  3,      64768, NULL },		/* AG_CG_HELVETICA_ASCII */
	{     314320,          0,  601, 1600,  601,  3,      49544, NULL },		/* AG_CG_HELVETICA_ASCIIWHITE */
	{     320513,          0,  600,  400,  600,  3,     276352, NULL },		/* AG_CG_MUSICDETAIL */
	{     355057,          0,  600,  400,  600,  3,     542992, NULL },		/* AG_CG_MUSICDETAIL2 */
	{     422931,          0,  577,  115,  577,  3,     115872, NULL },		/* AG_CG_BLUEBAR */
	{     437415,          0,  577,  115,  577,  3,     114360, NULL },		/* AG_CG_SPINKBAR */
	{     451710,          0,  577,  115,  577,  3,      52072, NULL },		/* AG_CG_PURPLEBAR */
	{     458219,          0,  800, 1250,  800,  3,     191440, NULL },		/* AG_CG_FRAME */
	{     482149,          0,  100,  100,  100,  3,      31616, NULL },		/* AG_CG_STAR */
	{     486101,          0,  400,  400,  400,  3,     298064, NULL },		/* AG_CG_STARRED */
	{     523359,          0,  697,  522,  697,  3,     854536, NULL },		/* AG_CG_OCTABEAT */
	{     630176,          0,  300,  300,  300,  3,       2680, NULL },		/* AG_CG_LEFTTRIANGLE */
	{     630511,          0,  577,  160,  577,  3,     134128, NULL },		/* AG_CG_HIGHSCOREBAR */
	{     647277,          0,  300,  300,  300,  3,       2872, NULL },		/* AG_CG_RIGHTTRIANGLE */
	{     647636,          0,  600, 1600,  600,  3,     338488, NULL },		/* AG_CG_ASCII_HANDEL */
	{     689947,          0,  700,  525,  700,  3,      26136, NULL },		/* AG_CG_OCTABEATCHAR */
	{     693214,          0,  700,  525,  700,  3,     193976, NULL },		/* AG_CG_OCTABEATCHARWHITE */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_KONPO */
	    717481,    720025,    722549,    725077,    727597,    730165,    732725,    735293,
	    737849,    740377,    742929,    745421,    747941,    750433,    752933,    755457,
	    757993,    760521,    763053,    765589,    768133,    770653,    773173,    775677,
	    778177,    780657,    783161,    785685,    788209,    790725,    793264,    795792,
	    798352,    800916,    803452,    805952,    808448,    810960,    813452,    815980,
	    818488,    820992,    823524,    826008,    828500,    831000,    833500,    835980,
	    838480,    840988,    843508,    846048,    848588,    851112,    853624,    856152,
	    858708,    861256,    863800,    866320,    868847,    871379,    873907,    876435,
	    878947,    881507,    884067,    886631,    889191,    891719,    894271,    896779,
	    899303,    901791,    904291,    906815,    909343,    911871,    914403,    916923,
	    919463,    921987,    924511,    927023,    929519,    931999,    934495,    937023,
	    939547,    942075,    944622,    947154,    949726,    952274,    954806,    957302,
	    959786,    962310,    964810,    967322,    969842,    972346,    974874,    977366,
	    979862,    982366,    984858,    987342,    989846,    992358,    994874,    997410,
	    999954,   1002478,   1004990,   1007518,   1010082,   1012634,   1015178,   1017694,
	   1020217,   1022753,   1025285,   1027805,   1030321,   1032881,   1035445,   1038009,
	   1040561,   1043089,   1045637,   1048145,   1050665,   1053157,   1055657,   1058181,
	   1060717,   1063237,   1065777,   1068305,   1070845,   1073365,   1075893,   1078405,
	   1080893,   1083377,   1085869,   1088389,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_KOMPO */
	   1090934,   1095286,   1099594,   1103914,   1108250,   1112610,   1116934,   1121230,
	   1125526,   1129794,   1134066,   1138302,   1142538,   1146818,   1151098,   1155386,
	   1159706,   1164014,   1168286,   1172550,   1176778,   1181014,   1185258,   1189526,
	   1193822,   1198134,   1202462,   1206810,   1211154,   1215418,   1219669,   1223945,
	   1228225,   1232473,   1236689,   1240925,   1245149,   1249397,   1253621,   1257861,
	   1262121,   1266369,   1270641,   1274917,   1279153,   1283389,   1287657,   1291933,
	   1296189,   1300425,   1304685,   1308925,   1313133,   1317317,   1321565,   1325781,
	   1330005,   1334193,   1338405,   1342569,   1346740,   1350848,   1355020,   1359188,
	   1363372,   1367584,   1371800,   1375992,   1380172,   1384356,   1388520,   1392676,
	   1396892,   1401120,   1405368,   1409632,   1413960,   1418260,   1422528,   1426764,
	   1430992,   1435248,   1439464,   1443704,   1447932,   1452136,   1456344,   1460576,
	   1464804,   1469028,   1473291,   1477563,   1481827,   1486127,   1490403,   1494691,
	   1498991,   1503307,   1507591,   1511855,   1516151,   1520443,   1524695,   1528963,
	   1533275,   1537559,   1541835,   1546087,   1550347,   1554575,   1558819,   1563059,
	   1567331,   1571579,   1575871,   1580155,   1584459,   1588739,   1592991,   1597231,
	   1601438,   1605650,   1609906,   1614218,   1618534,   1622874,   1627250,   1631598,
	   1635910,   1640186,   1644486,   1648778,   1653050,   1657318,   1661574,   1665822,
	   1670066,   1674322,   1678586,   1682862,   1687162,   1691458,   1695802,   1700102,
	   1704394,   1708690,   1713054,   1717382,   1721682,   1725982,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{     717461,  720,  480,   7672,    148, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_KONPO */
	{    1090914, 1024,  768,   7680,    150, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_KOMPO */
};

/***************************************************************/
/*                     Reserve Member Lists                    */
/***************************************************************/
const u32 ageReserve[1] = { 0 }; /* No Reserve Member */

/***************************************************************/
/*                      User Member Lists                      */
/***************************************************************/
const u32 ageUser[1] = { 0 }; /* No User Member */

/***************************************************************/
/*                      Vram Group Lists                       */
/***************************************************************/
const AGEVramGroup ageVG[] = { { 0, NULL } };
const s16 ageVGCnt = 0;

const u8* ageMotCommon[] = { NULL };
const AGEMotion ageMot[] = {
	{ 0, 0, 0, NULL, },
};
/***************************************************************/
/*                   Sound Rom Member Lists                    */
/***************************************************************/
const AGESoundRomMember ageSRM[] = {
	/* Ch, Length */
	{ 2,     8000 },		/* AS_SND_M4 */
	{ 2,    64000 },		/* AS_SND_M64 */
	{ 2,    14222 },		/* AS_SND_TITLE */
	{ 2,     3555 },		/* AS_SND_RESULT */
	{ 2,    96000 },		/* AS_SND_OCTAVE */
	{ 2,    98049 },		/* AS_SND_DOUBLE_HELIX */
	{ 2,      500 },		/* AS_SND_CLAP1 */
	{ 2,      500 },		/* AS_SND_CLAP2 */
	{ 2,      500 },		/* AS_SND_SILENT1 */
	{ 1,      743 },		/* AS_SND_01_OCTABEAT */
	{ 1,     1404 },		/* AS_SND_02_WELCOME_TO_OCTABEAT */
	{ 1,     1199 },		/* AS_SND_03_SELECT_THE_MUSIC */
	{ 1,      573 },		/* AS_SND_04_EASY */
	{ 1,      637 },		/* AS_SND_05_NORMAL */
	{ 1,      486 },		/* AS_SND_06_HARD */
	{ 1,      758 },		/* AS_SND_07_ARE_YOU_READY */
	{ 1,      480 },		/* AS_SND_08_GO */
	{ 1,      915 },		/* AS_SND_09_KEEP_THE_BEATS */
	{ 1,     1414 },		/* AS_SND_10_WHAT_THE_FASCINATING_BEAT */
	{ 1,     1181 },		/* AS_SND_11_FOLLOW_THE_RHYTHM */
	{ 1,     1161 },		/* AS_SND_12_GET_INTO_THE_RHYTHM */
	{ 1,     1112 },		/* AS_SND_13_MAKE_SOME_NOISE */
	{ 1,      840 },		/* AS_SND_14_TURN_IT_UP */
	{ 1,      877 },		/* AS_SND_15_TAKE_IT_EASY */
	{ 1,     1036 },		/* AS_SND_16_NEVER_SAY_NEVER */
	{ 1,      688 },		/* AS_SND_17_PERFECT */
	{ 1,      614 },		/* AS_SND_18_GREAT */
	{ 1,      557 },		/* AS_SND_19_GOOD */
	{ 1,      445 },		/* AS_SND_20_BAD */
	{ 1,      674 },		/* AS_SND_21_POOR */
	{ 1,      725 },		/* AS_SND_22_EXCELLENT */
	{ 1,      987 },		/* AS_SND_23_FULL_COMBO */
	{ 1,      611 },		/* AS_SND_24_CLEARED */
	{ 1,      750 },		/* AS_SND_25_FAILED */
	{ 1,      918 },		/* AS_SND_26_YOU_WIN */
	{ 1,     1115 },		/* AS_SND_27_YOU_LOSE */
	{ 1,      700 },		/* AS_SND_28_RESULT */
	{ 1,      942 },		/* AS_SND_29_YOUR_RANK_IS */
	{ 1,      421 },		/* AS_SND_30_S */
	{ 1,      342 },		/* AS_SND_31_A */
	{ 1,      444 },		/* AS_SND_32_B */
	{ 1,      416 },		/* AS_SND_33_C */
	{ 1,      331 },		/* AS_SND_34_D */
	{ 1,      393 },		/* AS_SND_35_E */
	{ 1,      361 },		/* AS_SND_36_F */
	{ 1,     1205 },		/* AS_SND_37_THANK_YOU_FOR_PLAYING */
};

/***************************************************************/
/*                      Sound Score Lists                      */
/***************************************************************/
const AGESoundScore ageSS[] = { { 0, 0, 0, -1, NULL } };
