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
	{    3199242,          0,  600, 1600,  600,  0,    3840000, NULL },		/* AG_CG_ASCII_HANDEL */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_KONPO */
	   3679262,   3681806,   3684330,   3686858,   3689378,   3691946,   3694506,   3697074,
	   3699630,   3702158,   3704710,   3707202,   3709722,   3712214,   3714714,   3717238,
	   3719774,   3722302,   3724834,   3727370,   3729914,   3732434,   3734954,   3737458,
	   3739958,   3742438,   3744942,   3747466,   3749990,   3752506,   3755045,   3757573,
	   3760133,   3762697,   3765233,   3767733,   3770229,   3772741,   3775233,   3777761,
	   3780269,   3782773,   3785305,   3787789,   3790281,   3792781,   3795281,   3797761,
	   3800261,   3802769,   3805289,   3807829,   3810369,   3812893,   3815405,   3817933,
	   3820489,   3823037,   3825581,   3828101,   3830628,   3833160,   3835688,   3838216,
	   3840728,   3843288,   3845848,   3848412,   3850972,   3853500,   3856052,   3858560,
	   3861084,   3863572,   3866072,   3868596,   3871124,   3873652,   3876184,   3878704,
	   3881244,   3883768,   3886292,   3888804,   3891300,   3893780,   3896276,   3898804,
	   3901328,   3903856,   3906403,   3908935,   3911507,   3914055,   3916587,   3919083,
	   3921567,   3924091,   3926591,   3929103,   3931623,   3934127,   3936655,   3939147,
	   3941643,   3944147,   3946639,   3949123,   3951627,   3954139,   3956655,   3959191,
	   3961735,   3964259,   3966771,   3969299,   3971863,   3974415,   3976959,   3979475,
	   3981998,   3984534,   3987066,   3989586,   3992102,   3994662,   3997226,   3999790,
	   4002342,   4004870,   4007418,   4009926,   4012446,   4014938,   4017438,   4019962,
	   4022498,   4025018,   4027558,   4030086,   4032626,   4035146,   4037674,   4040186,
	   4042674,   4045158,   4047650,   4050170,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{    3679242,  720,  480,   7672,    148, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_KONPO */
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
