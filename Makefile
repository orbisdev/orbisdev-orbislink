ifndef ORBISDEV
$(error ORBISDEV, is not set)
endif

target ?= ps4_elf_sce
TargetFile=homebrew.elf

include $(ORBISDEV)/make/ps4sdk.mk
LinkerFlags+=  -luser_mem_sys -lkernel_stub  -lSceLibcInternal_stub -lorbisLink -lkernelUtil -ldebugnet -lorbisNfs   -lSceSysmodule_stub -lSceSystemService_stub -lSceNet_stub -lSceUserService_stub -lScePigletv2VSH_stub -lSceVideoOut_stub -lSceGnmDriver_stub  -lScePad_stub -lSceAudioOut_stub -lSceIme_stub -lSceNetCtl_stub -lSQLite

CompilerFlags +=-D_BSD_SOURCE -DSQLITE_ENABLE_MEMORY_MANAGEMENT -DSQLITE_OS_OTHER=1  -DSQLITE_OMIT_WAL 
IncludePath += -I$(ORBISDEV)/usr/include/orbis

AUTH_INFO = 000000000000000000000000001C004000FF000000000080000000000000000000000000000000000000008000400040000000000000008000000000000000080040FFFF000000F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

oelf:
	orbis-elf-create bin/$(TargetFile)  bin/orbislink.oelf
eboot:
	python $(ORBISDEV)/bin/make_fself.py --auth-info $(AUTH_INFO) bin/orbislink.oelf pkg/eboot.bin
