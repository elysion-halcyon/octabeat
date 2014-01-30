#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0,  399,  298,  399,  3,     293888, NULL },		/* AG_CG_OCTABEATTITLE */
	{      36736,          0,  400,  300,  400,  3,     304888, NULL },		/* AG_CG_SELECTBACKGROUND */
	{      74847,          0,  154,  154,  154,  3,      21184, NULL },		/* AG_CG_NUMBER0 */
	{      77495,          0,  154,  154,  154,  3,      13712, NULL },		/* AG_CG_NUMBER1 */
	{      79209,          0,  154,  154,  154,  3,      22984, NULL },		/* AG_CG_NUMBER2 */
	{      82082,          0,  154,  154,  154,  3,      22832, NULL },		/* AG_CG_NUMBER3 */
	{      84936,          0,  154,  154,  154,  3,      18640, NULL },		/* AG_CG_NUMBER4 */
	{      87266,          0,  154,  154,  154,  3,      23480, NULL },		/* AG_CG_NUMBER5 */
	{      90201,          0,  154,  154,  154,  3,      23280, NULL },		/* AG_CG_NUMBER6 */
	{      93111,          0,  154,  154,  154,  3,      19088, NULL },		/* AG_CG_NUMBER7 */
	{      95497,          0,  154,  154,  154,  3,      23480, NULL },		/* AG_CG_NUMBER8 */
	{      98432,          0,  154,  154,  154,  3,      23560, NULL },		/* AG_CG_NUMBER9 */
	{     101377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_RANKA */
	{     146377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_RANKB */
	{     191377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_RANKC */
	{     236377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_RANKD */
	{     281377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_RANKE */
	{     326377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_RANKF */
	{     371377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_RANKS */
	{     416377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_BAD */
	{     461377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_GOOD */
	{     506377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_GREAT */
	{     551377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_PERFECT */
	{     596377,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_POOR */
	{     641377,          0,  482,  197,  482,  0,     379816, NULL },		/* AG_CG_SELECT */
	{     688854,          0,  482,  197,  482,  0,     379816, NULL },		/* AG_CG_SELECT1 */
	{     736331,          0,  482,  197,  482,  0,     379816, NULL },		/* AG_CG_SELECT2 */
	{     783808,          0,  601, 1600,  601,  0,    3846400, NULL },		/* AG_CG_HELVETICA_ASCII */
	{    1264608,          0,  601, 1600,  601,  0,    3846400, NULL },		/* AG_CG_HELVETICA_ASCIIWHITE */
	{    1745408,          0,  600,  400,  600,  0,     960000, NULL },		/* AG_CG_MUSICDETAIL */
	{    1865408,          0,  600,  400,  600,  0,     960000, NULL },		/* AG_CG_MUSICDETAIL2 */
	{    1985408,          0,  577,  115,  577,  3,     115872, NULL },		/* AG_CG_BLUEBAR */
	{    1999892,          0,  577,  115,  577,  3,     114360, NULL },		/* AG_CG_SPINKBAR */
	{    2014187,          0,  577,  115,  577,  0,     265420, NULL },		/* AG_CG_PURPLEBAR */
	{    2047365,          0,  800, 1250,  800,  0,    4000000, NULL },		/* AG_CG_FRAME */
	{    2547365,          0,  100,  100,  100,  0,      40000, NULL },		/* AG_CG_STAR */
	{    2552365,          0,  400,  400,  400,  0,     640000, NULL },		/* AG_CG_STARRED */
	{    2632365,          0,  697,  522,  697,  0,    1455336, NULL },		/* AG_CG_OCTABEAT */
	{    2814282,          0,  700,  525,  700,  0,    1470000, NULL },		/* AG_CG_OCTABEATCHAR */
	{    2998032,          0,  300,  300,  300,  3,       2680, NULL },		/* AG_CG_LEFTTRIANGLE */
	{    2998367,          0,  577,  160,  577,  3,     134128, NULL },		/* AG_CG_HIGHSCOREBAR */
	{    3015133,          0,  300,  300,  300,  3,       2872, NULL },		/* AG_CG_RIGHTTRIANGLE */
	{    3015492,          0,  700,  525,  700,  0,    1470000, NULL },		/* AG_CG_OCTABEATCHARWHITE */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_KONPO */
	   3199262,   3201806,   3204330,   3206858,   3209378,   3211946,   3214506,   3217074,
	   3219630,   3222158,   3224710,   3227202,   3229722,   3232214,   3234714,   3237238,
	   3239774,   3242302,   3244834,   3247370,   3249914,   3252434,   3254954,   3257458,
	   3259958,   3262438,   3264942,   3267466,   3269990,   3272506,   3275045,   3277573,
	   3280133,   3282697,   3285233,   3287733,   3290229,   3292741,   3295233,   3297761,
	   3300269,   3302773,   3305305,   3307789,   3310281,   3312781,   3315281,   3317761,
	   3320261,   3322769,   3325289,   3327829,   3330369,   3332893,   3335405,   3337933,
	   3340489,   3343037,   3345581,   3348101,   3350628,   3353160,   3355688,   3358216,
	   3360728,   3363288,   3365848,   3368412,   3370972,   3373500,   3376052,   3378560,
	   3381084,   3383572,   3386072,   3388596,   3391124,   3393652,   3396184,   3398704,
	   3401244,   3403768,   3406292,   3408804,   3411300,   3413780,   3416276,   3418804,
	   3421328,   3423856,   3426403,   3428935,   3431507,   3434055,   3436587,   3439083,
	   3441567,   3444091,   3446591,   3449103,   3451623,   3454127,   3456655,   3459147,
	   3461643,   3464147,   3466639,   3469123,   3471627,   3474139,   3476655,   3479191,
	   3481735,   3484259,   3486771,   3489299,   3491863,   3494415,   3496959,   3499475,
	   3501998,   3504534,   3507066,   3509586,   3512102,   3514662,   3517226,   3519790,
	   3522342,   3524870,   3527418,   3529926,   3532446,   3534938,   3537438,   3539962,
	   3542498,   3545018,   3547558,   3550086,   3552626,   3555146,   3557674,   3560186,
	   3562674,   3565158,   3567650,   3570170,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{    3199242,  720,  480,   7672,    148, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_KONPO */
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
