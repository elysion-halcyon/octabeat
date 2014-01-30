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
	{    2814282,          0,  300,  300,  300,  3,       2680, NULL },		/* AG_CG_LEFTTRIANGLE */
	{    2814617,          0,  577,  160,  577,  3,     134128, NULL },		/* AG_CG_HIGHSCOREBAR */
	{    2831383,          0,  300,  300,  300,  3,       2872, NULL },		/* AG_CG_RIGHTTRIANGLE */
	{    3205195,          0,  700,  525,  700,  3,      26136, NULL },		/* AG_CG_OCTABEATCHAR */
	{    3208462,          0,  700,  525,  700,  3,     193976, NULL },		/* AG_CG_OCTABEATCHARWHITE */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_KONPO */
	   2831762,   2834306,   2836830,   2839358,   2841878,   2844446,   2847006,   2849574,
	   2852130,   2854658,   2857210,   2859702,   2862222,   2864714,   2867214,   2869738,
	   2872274,   2874802,   2877334,   2879870,   2882414,   2884934,   2887454,   2889958,
	   2892458,   2894938,   2897442,   2899966,   2902490,   2905006,   2907545,   2910073,
	   2912633,   2915197,   2917733,   2920233,   2922729,   2925241,   2927733,   2930261,
	   2932769,   2935273,   2937805,   2940289,   2942781,   2945281,   2947781,   2950261,
	   2952761,   2955269,   2957789,   2960329,   2962869,   2965393,   2967905,   2970433,
	   2972989,   2975537,   2978081,   2980601,   2983128,   2985660,   2988188,   2990716,
	   2993228,   2995788,   2998348,   3000912,   3003472,   3006000,   3008552,   3011060,
	   3013584,   3016072,   3018572,   3021096,   3023624,   3026152,   3028684,   3031204,
	   3033744,   3036268,   3038792,   3041304,   3043800,   3046280,   3048776,   3051304,
	   3053828,   3056356,   3058903,   3061435,   3064007,   3066555,   3069087,   3071583,
	   3074067,   3076591,   3079091,   3081603,   3084123,   3086627,   3089155,   3091647,
	   3094143,   3096647,   3099139,   3101623,   3104127,   3106639,   3109155,   3111691,
	   3114235,   3116759,   3119271,   3121799,   3124363,   3126915,   3129459,   3131975,
	   3134498,   3137034,   3139566,   3142086,   3144602,   3147162,   3149726,   3152290,
	   3154842,   3157370,   3159918,   3162426,   3164946,   3167438,   3169938,   3172462,
	   3174998,   3177518,   3180058,   3182586,   3185126,   3187646,   3190174,   3192686,
	   3195174,   3197658,   3200150,   3202670,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{    2831742,  720,  480,   7672,    148, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_KONPO */
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
