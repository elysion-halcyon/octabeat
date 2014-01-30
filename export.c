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
	{     101377,          0,  713,  713,  713,  3,     573184, NULL },		/* AG_CG_RANKA */
	{     173025,          0,  660,  660,  660,  3,     604520, NULL },		/* AG_CG_RANKB */
	{     248590,          0,  713,  713,  713,  3,     689496, NULL },		/* AG_CG_RANKC */
	{     334777,          0,  660,  660,  660,  3,     620368, NULL },		/* AG_CG_RANKD */
	{     412323,          0,  660,  660,  660,  3,     607344, NULL },		/* AG_CG_RANKE */
	{     488241,          0,  713,  734,  713,  3,     562864, NULL },		/* AG_CG_RANKF */
	{     558599,          0,  660,  660,  660,  3,     504848, NULL },		/* AG_CG_RANKS */
	{     621705,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_PERFECT */
	{     666705,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_GREAT */
	{     711705,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_GOOD */
	{     756705,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_BAD */
	{     801705,          0,  300,  300,  300,  0,     360000, NULL },		/* AG_CG_POOR */
	{     846705,          0,  482,  197,  482,  3,     110152, NULL },		/* AG_CG_SELECT */
	{     860474,          0,  482,  197,  482,  3,     106600, NULL },		/* AG_CG_SELECT1 */
	{     873799,          0,  482,  197,  482,  3,     102752, NULL },		/* AG_CG_SELECT2 */
	{     886643,          0,  601, 1600,  601,  0,    3846400, NULL },		/* AG_CG_HELVETICA_ASCII */
	{    1367443,          0,  601, 1600,  601,  0,    3846400, NULL },		/* AG_CG_HELVETICA_ASCIIWHITE */
	{    1848243,          0,  600,  400,  600,  0,     960000, NULL },		/* AG_CG_MUSICDETAIL */
	{    1968243,          0,  600,  400,  600,  0,     960000, NULL },		/* AG_CG_MUSICDETAIL2 */
	{    2088243,          0,  577,  115,  577,  3,     115872, NULL },		/* AG_CG_BLUEBAR */
	{    2102727,          0,  577,  115,  577,  3,     114360, NULL },		/* AG_CG_SPINKBAR */
	{    2117022,          0,  577,  115,  577,  0,     265420, NULL },		/* AG_CG_PURPLEBAR */
	{    2150200,          0,  800, 1250,  800,  0,    4000000, NULL },		/* AG_CG_FRAME */
	{    2650200,          0,  100,  100,  100,  0,      40000, NULL },		/* AG_CG_STAR */
	{    2655200,          0,  400,  400,  400,  0,     640000, NULL },		/* AG_CG_STARRED */
	{    2735200,          0,  697,  522,  697,  0,    1455336, NULL },		/* AG_CG_OCTABEAT */
	{    2917117,          0,  700,  525,  700,  0,    1470000, NULL },		/* AG_CG_OCTABEATCHAR */
	{    3100867,          0,  300,  300,  300,  3,       2680, NULL },		/* AG_CG_LEFTTRIANGLE */
	{    3101202,          0,  577,  160,  577,  3,     134128, NULL },		/* AG_CG_HIGHSCOREBAR */
	{    3117968,          0,  300,  300,  300,  3,       2872, NULL },		/* AG_CG_RIGHTTRIANGLE */
	{    3118327,          0,  700,  525,  700,  0,    1470000, NULL },		/* AG_CG_OCTABEATCHARWHITE */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_KONPO */
	   3302097,   3304641,   3307165,   3309693,   3312213,   3314781,   3317341,   3319909,
	   3322465,   3324993,   3327545,   3330037,   3332557,   3335049,   3337549,   3340073,
	   3342609,   3345137,   3347669,   3350205,   3352749,   3355269,   3357789,   3360293,
	   3362793,   3365273,   3367777,   3370301,   3372825,   3375341,   3377880,   3380408,
	   3382968,   3385532,   3388068,   3390568,   3393064,   3395576,   3398068,   3400596,
	   3403104,   3405608,   3408140,   3410624,   3413116,   3415616,   3418116,   3420596,
	   3423096,   3425604,   3428124,   3430664,   3433204,   3435728,   3438240,   3440768,
	   3443324,   3445872,   3448416,   3450936,   3453463,   3455995,   3458523,   3461051,
	   3463563,   3466123,   3468683,   3471247,   3473807,   3476335,   3478887,   3481395,
	   3483919,   3486407,   3488907,   3491431,   3493959,   3496487,   3499019,   3501539,
	   3504079,   3506603,   3509127,   3511639,   3514135,   3516615,   3519111,   3521639,
	   3524163,   3526691,   3529238,   3531770,   3534342,   3536890,   3539422,   3541918,
	   3544402,   3546926,   3549426,   3551938,   3554458,   3556962,   3559490,   3561982,
	   3564478,   3566982,   3569474,   3571958,   3574462,   3576974,   3579490,   3582026,
	   3584570,   3587094,   3589606,   3592134,   3594698,   3597250,   3599794,   3602310,
	   3604833,   3607369,   3609901,   3612421,   3614937,   3617497,   3620061,   3622625,
	   3625177,   3627705,   3630253,   3632761,   3635281,   3637773,   3640273,   3642797,
	   3645333,   3647853,   3650393,   3652921,   3655461,   3657981,   3660509,   3663021,
	   3665509,   3667993,   3670485,   3673005,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{    3302077,  720,  480,   7672,    148, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_KONPO */
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
