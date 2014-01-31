#ifndef __AG_EXPORT__
#define __AG_EXPORT__

#include <agexport.h>
#include <ag3d.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************/
/*                       FrameBuffer                           */
/***************************************************************/
#define AGE_FB_WIDTH	(1024)
#define AGE_FB_HEIGHT	(768)
#define AGE_DISP_WIDTH	(1024)
#define AGE_DISP_HEIGHT	(768)
#define AGE_FB_ADDR0	(7602176)
#define AGE_FB_ADDR1	(6815744)
#define AGE_ZB_ADDR	(6815744)
#define AGE_ZB_DEPTH	(4)
#define AGE_ZMD	(1)
#define AGE_AAC_ADDR	(13631488)
#define AGE_AAC_SIZE	(13631488)
#define AGE_SOUND_ROM_OFFSET	(0x400000)

/***************************************************************/
/*                    Rom Member Symbol                        */
/***************************************************************/
#define AG_CG_OCTABEATTITLE	(0)
#define AG_CG_SELECTBACKGROUND	(1)
#define AG_CG_NUMBER0	(2)
#define AG_CG_NUMBER1	(3)
#define AG_CG_NUMBER2	(4)
#define AG_CG_NUMBER3	(5)
#define AG_CG_NUMBER4	(6)
#define AG_CG_NUMBER5	(7)
#define AG_CG_NUMBER6	(8)
#define AG_CG_NUMBER7	(9)
#define AG_CG_NUMBER8	(10)
#define AG_CG_NUMBER9	(11)
#define AG_CG_RANKA	(12)
#define AG_CG_RANKB	(13)
#define AG_CG_RANKC	(14)
#define AG_CG_RANKD	(15)
#define AG_CG_RANKE	(16)
#define AG_CG_RANKF	(17)
#define AG_CG_RANKS	(18)
#define AG_CG_BAD	(19)
#define AG_CG_GOOD	(20)
#define AG_CG_GREAT	(21)
#define AG_CG_PERFECT	(22)
#define AG_CG_POOR	(23)
#define AG_CG_SELECT	(24)
#define AG_CG_SELECT1	(25)
#define AG_CG_SELECT2	(26)
#define AG_CG_HELVETICA_ASCII	(27)
#define AG_CG_HELVETICA_ASCIIWHITE	(28)
#define AG_CG_MUSICDETAIL	(29)
#define AG_CG_MUSICDETAIL2	(30)
#define AG_CG_BLUEBAR	(31)
#define AG_CG_SPINKBAR	(32)
#define AG_CG_PURPLEBAR	(33)
#define AG_CG_FRAME	(34)
#define AG_CG_STAR	(35)
#define AG_CG_STARRED	(36)
#define AG_CG_OCTABEAT	(37)
#define AG_CG_LEFTTRIANGLE	(38)
#define AG_CG_HIGHSCOREBAR	(39)
#define AG_CG_RIGHTTRIANGLE	(40)
#define AG_CG_ASCII_HANDEL	(41)
#define AG_CG_OCTABEATCHAR	(42)
#define AG_CG_OCTABEATCHARWHITE	(43)

/***************************************************************/
/*                     RM3 Member Symbol                       */
/***************************************************************/
#define AG_RP_KONPO	(0)
#define AG_RP_KOMPO	(1)
#define AG_RP_COMPO	(2)

/***************************************************************/
/*                       Vram Group Symbol                     */
/***************************************************************/

/***************************************************************/
/*                       Sound Member Symbol                   */
/***************************************************************/
#define AS_SND_M4	(0)
#define AS_SND_M64	(1)
#define AS_SND_TITLE	(2)
#define AS_SND_RESULT	(3)
#define AS_SND_OCTAVE	(4)
#define AS_SND_DOUBLE_HELIX	(5)
#define AS_SND_CLAP1	(6)
#define AS_SND_CLAP2	(7)
#define AS_SND_SILENT1	(8)
#define AS_SND_01_OCTABEAT	(9)
#define AS_SND_02_WELCOME_TO_OCTABEAT	(10)
#define AS_SND_03_SELECT_THE_MUSIC	(11)
#define AS_SND_04_EASY	(12)
#define AS_SND_05_NORMAL	(13)
#define AS_SND_06_HARD	(14)
#define AS_SND_07_ARE_YOU_READY	(15)
#define AS_SND_08_GO	(16)
#define AS_SND_09_KEEP_THE_BEATS	(17)
#define AS_SND_10_WHAT_THE_FASCINATING_BEAT	(18)
#define AS_SND_11_FOLLOW_THE_RHYTHM	(19)
#define AS_SND_12_GET_INTO_THE_RHYTHM	(20)
#define AS_SND_13_MAKE_SOME_NOISE	(21)
#define AS_SND_14_TURN_IT_UP	(22)
#define AS_SND_15_TAKE_IT_EASY	(23)
#define AS_SND_16_NEVER_SAY_NEVER	(24)
#define AS_SND_17_PERFECT	(25)
#define AS_SND_18_GREAT	(26)
#define AS_SND_19_GOOD	(27)
#define AS_SND_20_BAD	(28)
#define AS_SND_21_POOR	(29)
#define AS_SND_22_EXCELLENT	(30)
#define AS_SND_23_FULL_COMBO	(31)
#define AS_SND_24_CLEARED	(32)
#define AS_SND_25_FAILED	(33)
#define AS_SND_26_YOU_WIN	(34)
#define AS_SND_27_YOU_LOSE	(35)
#define AS_SND_28_RESULT	(36)
#define AS_SND_29_YOUR_RANK_IS	(37)
#define AS_SND_30_S	(38)
#define AS_SND_31_A	(39)
#define AS_SND_32_B	(40)
#define AS_SND_33_C	(41)
#define AS_SND_34_D	(42)
#define AS_SND_35_E	(43)
#define AS_SND_36_F	(44)
#define AS_SND_37_THANK_YOU_FOR_PLAYING	(45)

/***************************************************************/
/*                          Data Member                        */
/***************************************************************/
extern const AGERomMember ageRM[44];
extern const AGERM3Member ageRM3[3];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;
extern const AGESoundRomMember ageSRM[46];

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */
