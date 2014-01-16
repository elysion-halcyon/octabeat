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
#define AG_CG_RANKS	(12)

/***************************************************************/
/*                     RM3 Member Symbol                       */
/***************************************************************/

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
#define AS_SND_CLAP1	(4)
#define AS_SND_CLAP2	(5)
#define AS_SND_SILENT1	(6)
#define AS_SND_01_OCTABEAT	(7)
#define AS_SND_02_WELCOME_TO_OCTABEAT	(8)
#define AS_SND_03_SELECT_THE_MUSIC	(9)
#define AS_SND_04_EASY	(10)
#define AS_SND_05_NORMAL	(11)
#define AS_SND_06_HARD	(12)
#define AS_SND_07_ARE_YOU_READY	(13)
#define AS_SND_08_GO	(14)
#define AS_SND_09_KEEP_THE_BEATS	(15)
#define AS_SND_10_WHAT_THE_FASCINATING_BEAT	(16)
#define AS_SND_11_FOLLOW_THE_RHYTHM	(17)
#define AS_SND_12_GET_INTO_THE_RHYTHM	(18)
#define AS_SND_13_MAKE_SOME_NOISE	(19)
#define AS_SND_14_TURN_IT_UP	(20)
#define AS_SND_15_TAKE_IT_EASY	(21)
#define AS_SND_16_NEVER_SAY_NEVER	(22)
#define AS_SND_17_PERFECT	(23)
#define AS_SND_18_GREAT	(24)
#define AS_SND_19_GOOD	(25)
#define AS_SND_20_BAD	(26)
#define AS_SND_21_POOR	(27)
#define AS_SND_22_EXCELLENT	(28)
#define AS_SND_23_FULL_COMBO	(29)
#define AS_SND_24_CLEARED	(30)
#define AS_SND_25_FAILED	(31)
#define AS_SND_26_YOU_WIN	(32)
#define AS_SND_27_YOU_LOSE	(33)
#define AS_SND_28_RESULT	(34)
#define AS_SND_29_YOUR_RANK_IS	(35)
#define AS_SND_30_S	(36)
#define AS_SND_31_A	(37)
#define AS_SND_32_B	(38)
#define AS_SND_33_C	(39)
#define AS_SND_34_D	(40)
#define AS_SND_35_E	(41)
#define AS_SND_36_F	(42)
#define AS_SND_37_THANK_YOU_FOR_PLAYING	(43)

/***************************************************************/
/*                          Data Member                        */
/***************************************************************/
extern const AGERomMember ageRM[13];
extern const AGERM3Member ageRM3[1];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;
extern const AGESoundRomMember ageSRM[44];

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */
