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
	{     621705,          0,  482,  197,  482,  3,     110152, NULL },		/* AG_CG_SELECT */
	{     635474,          0,  482,  197,  482,  3,     106600, NULL },		/* AG_CG_SELECT1 */
	{     648799,          0,  482,  197,  482,  3,     102752, NULL },		/* AG_CG_SELECT2 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const AGERM3Member ageRM3[] = { { 0, 0, 0, 0, 0, 0, 0, NULL } }; /* No RM3 Member */
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
