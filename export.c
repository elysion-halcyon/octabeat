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
	{     860474,          0,  482,  197,  482,  3,     102752, NULL },		/* AG_CG_SELECT2 */
	{     873318,          0,  482,  197,  482,  0,     379816, NULL },		/* AG_CG_SELECT1 */
	{     920795,          0,  601, 1600,  601,  0,    3846400, NULL },		/* AG_CG_HELVETICA_ASCII */
	{    1401595,          0,  601, 1600,  601,  0,    3846400, NULL },		/* AG_CG_HELVETICA_ASCIIWHITE */
	{    1882395,          0,  600,  400,  600,  0,     960000, NULL },		/* AG_CG_MUSICDETAIL */
	{    2002395,          0,  600,  400,  600,  0,     960000, NULL },		/* AG_CG_MUSICDETAIL2 */
	{    2122395,          0,  577,  115,  577,  3,     115872, NULL },		/* AG_CG_BLUEBAR */
	{    2136879,          0,  577,  115,  577,  3,     114360, NULL },		/* AG_CG_SPINKBAR */
	{    2151174,          0,  577,  115,  577,  0,     265420, NULL },		/* AG_CG_PURPLEBAR */
	{    2184352,          0,  800, 1250,  800,  0,    4000000, NULL },		/* AG_CG_FRAME */
	{    2684352,          0,  100,  100,  100,  0,      40000, NULL },		/* AG_CG_STAR */
	{    2689352,          0,  400,  400,  400,  0,     640000, NULL },		/* AG_CG_STARRED */
	{    2769352,          0,  697,  522,  697,  0,    1455336, NULL },		/* AG_CG_OCTABEAT */
	{    2951269,          0,  700,  525,  700,  0,    1470000, NULL },		/* AG_CG_OCTABEATCHAR */
	{    3135019,          0,  300,  300,  300,  3,       2680, NULL },		/* AG_CG_LEFTTRIANGLE */
	{    3135354,          0,  577,  160,  577,  3,     134128, NULL },		/* AG_CG_HIGHSCOREBAR */
	{    3152120,          0,  300,  300,  300,  3,       2872, NULL },		/* AG_CG_RIGHTTRIANGLE */
	{    3152479,          0,  700,  525,  700,  0,    1470000, NULL },		/* AG_CG_OCTABEATCHARWHITE */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_KONPO */
	   3336249,   3338793,   3341317,   3343845,   3346365,   3348933,   3351493,   3354061,
	   3356617,   3359145,   3361697,   3364189,   3366709,   3369201,   3371701,   3374225,
	   3376761,   3379289,   3381821,   3384357,   3386901,   3389421,   3391941,   3394445,
	   3396945,   3399425,   3401929,   3404453,   3406977,   3409493,   3412032,   3414560,
	   3417120,   3419684,   3422220,   3424720,   3427216,   3429728,   3432220,   3434748,
	   3437256,   3439760,   3442292,   3444776,   3447268,   3449768,   3452268,   3454748,
	   3457248,   3459756,   3462276,   3464816,   3467356,   3469880,   3472392,   3474920,
	   3477476,   3480024,   3482568,   3485088,   3487615,   3490147,   3492675,   3495203,
	   3497715,   3500275,   3502835,   3505399,   3507959,   3510487,   3513039,   3515547,
	   3518071,   3520559,   3523059,   3525583,   3528111,   3530639,   3533171,   3535691,
	   3538231,   3540755,   3543279,   3545791,   3548287,   3550767,   3553263,   3555791,
	   3558315,   3560843,   3563390,   3565922,   3568494,   3571042,   3573574,   3576070,
	   3578554,   3581078,   3583578,   3586090,   3588610,   3591114,   3593642,   3596134,
	   3598630,   3601134,   3603626,   3606110,   3608614,   3611126,   3613642,   3616178,
	   3618722,   3621246,   3623758,   3626286,   3628850,   3631402,   3633946,   3636462,
	   3638985,   3641521,   3644053,   3646573,   3649089,   3651649,   3654213,   3656777,
	   3659329,   3661857,   3664405,   3666913,   3669433,   3671925,   3674425,   3676949,
	   3679485,   3682005,   3684545,   3687073,   3689613,   3692133,   3694661,   3697173,
	   3699661,   3702145,   3704637,   3707157,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{    3336229,  720,  480,   7672,    148, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_KONPO */
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
