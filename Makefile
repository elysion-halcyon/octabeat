###########################################################################
#
#   Makefile for sample
#
###########################################################################

#���݂̃f�B���N�g�����烉���^�C�����[�g�f�B���N�g���ւ̑��΃p�X
ROOTDIR = ../../..

# CGROM �f�B���N�g��
CGROMDIR = .
CGROM = $(CGROMDIR)/export_0.bin

# ���W���[���Q
C_SRC = main.c Timer.c Bms.c pad.c Game.c fumen.c export.c

include $(ROOTDIR)/include/makefile.def

## Makefile ends here.
