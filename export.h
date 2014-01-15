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
#define AS_SND_CLAP1	(2)
#define AS_SND_CLAP2	(3)
#define AS_SND_SILENT1	(4)

/***************************************************************/
/*                          Data Member                        */
/***************************************************************/
extern const AGERomMember ageRM[13];
extern const AGERM3Member ageRM3[1];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;
extern const AGESoundRomMember ageSRM[5];

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */
