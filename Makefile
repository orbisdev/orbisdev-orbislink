ifndef PS4SDK
$(error PS4SDK, is not set)
endif

target ?= ps4_elf_sce
TargetFile=homebrew.elf

include $(PS4SDK)/make/ps4sdk.mk
LinkerFlags+=  -lkernel_stub -lorbis -lSceLibcInternal  -lSceSysmodule_stub -lSceSystemService_stub -lSceNet_stub -lSceUserService_stub -lScePad_stub -lSceAudioOut_stub -lSceIme_stub  
CompilerFlags +=-D__PS4__ -D__ORBIS__
IncludePath += -I$(PS4SDK)/include -I$(PS4SDK)/include/c++/v1 -I$(PS4SDK)/include/orbis

AUTH_INFO = 000000000000000000000000001C004000FF000000000080000000000000000000000000000000000000008000400040000000000000008000000000000000080040FFFF000000F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

install:
	@cp $(OutPath)/w.elf /usr/local/orbisdev/git/ps4sh/bin/hostapp
	@echo "Installed!"
oelf:
	orbis-elf-create bin/$(TargetFile)  bin/orbislink.oelf
eboot:
	python $(PS4SDK)/bin/make_fself.py --auth-info $(AUTH_INFO) bin/orbislink.oelf pkg/eboot.bin
