# orbislink
FSELF loader

What does this do?
===================
 orbislink in the past have been our try to have a standard way to load elf files compatible with Hitodama PS4SDK for developers since more than 2 years ago, highly inspired on other PlayStation families

 Now it has evolved!!!! 

 If you want piracy stop here buy originals, this is not for you.


Features
===================

- Build all using open source vanilla compiler(clang 11) and linker (binutils)
- oelf tool orbis-elf-create
- fself signing tool make_fself.py 
- liborbis compliant orbisdev sdk
- pkg builder pkgTool

Instructions
===================
- Install pkg
- Open in your pc/mac debugnet log listener
```
socat udp-recv:18194 stdout
```
- You will need patches for fself stuff from /data/fself/.....

- You will need a orbislink_config.ini file check pkg directory modify your log pc/mac server ip and your nfs pc/mac server share

- You will need a nfs server with a share exported with access for your PlayStation ip

- You will need the first time sprx files for your firmware for piglet libScePigletv2VSH.sprx and libSceShaccVSH.sprx(shader compiler) in the root of your exported share

- pkg is vanilla only have eboot.bin and you will see orbislink logo waiting it will listening for config file

- to load the first time(only the first time) config file when you see the orbislink logo is listening so:
```
socat -u FILE:orbislink_config.ini TCP:YOURPLAYSTATIONIP:18193
```
- After upload config magic is done directories are created and modules uploaded to /data/.....

- Finally it will try to upload, and run your homebrew.self from your nfs server

- Ready to have a lot of fun devoloping your stuff

Sample Output
=============
```
[HOST] debugnet listener up
[HOST] ready to have a lot of fun!!!
[ORBIS][INFO]: debugnet initialized
[ORBIS][INFO]: Copyright (C) 2010,2016 Antonio Jose Ramos Marquez aka bigboss @psxdev
[ORBIS][INFO]: ready to have a lot of fun...
[ORBIS][DEBUG]: [ORBISLINK initOrbisLinkAppInternal 0x00000000 0x00000000 0x00000000
[ORBIS][DEBUG]: [ORBISLINK initOrbisLinkAppInternal config ready placed on /data/orbislink/orbiskink_config.ini
[ORBIS][DEBUG]: [ORBISLINK] initOrbisLinkAppInternal nfsurl nfs://x.x.x.x/hostapp
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsCreateConf
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit calling nfs_init_context
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit nfs_init_context return valid nfs object
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit calling nfs_parse_url_dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit nfs_parse_url_dir return valid urls object
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit calling nfs_mount
[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.3
[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.3
[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.3
[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.3
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit nfs_mount return fine
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit liborbisNfs initialized readChunkSize=65536 writeChunkSize=65536
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean cleaning head tail and length
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetDirectoryEntries
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDopen path=.
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDopen directory . open slot=0 dfd=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry homebrew.self size=839168
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry homebrew.self type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry libScePigletv2VSH.sprx size=744208
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry libScePigletv2VSH.sprx type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry assets size=256
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry assets type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry GRADIUS2.ROM size=131072
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry GRADIUS2.ROM type=8 customType=4
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry raylib_logobackup.png size=3760
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry raylib_logobackup.png type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry lighting.fs size=2052
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry lighting.fs type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry raymarching.fs size=11048
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry raymarching.fs type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry KAISG.ttf size=79912
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry KAISG.ttf type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry config.ini size=405
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry config.ini type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry system size=192
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry system type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry resources size=288
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry resources type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry raylib_logo.png size=3760
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry raylib_logo.png type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry texel_checker.png size=57153
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry texel_checker.png type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry base_lighting.vs size=1578
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry base_lighting.vs type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry nightk.rom size=32768
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry nightk.rom type=8 customType=4
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry homebrew.elf size=236872
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry homebrew.elf type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry julia_set.fs size=3331
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry julia_set.fs type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry app size=96
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry app type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry .DS_Store size=8196
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry .DS_Store type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry MGEAR2.ROM size=524288
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry MGEAR2.ROM type=8 customType=4
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry ABADIA.DSK size=737280
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry ABADIA.DSK type=8 customType=6
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry libSceShaccVSH.sprx size=10394272
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry libSceShaccVSH.sprx type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry MGEAR1.ROM size=131072
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry MGEAR1.ROM type=8 customType=4
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry .. size=1184
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry .. type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry . size=800
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry . type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDclose slot=0 dfd=0  closed
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen opening file libScePigletv2VSH.sprx
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen libScePigletv2VSH.sprx opened fd=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek fd=0 offset=0 whence=2
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek slot=0 fd=0 return=744208
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek fd=0 offset=0 whence=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek slot=0 fd=0 return=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=744208
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=744208
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose slot=0 fd=0 libScePigletv2VSH.sprx closed
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose closing fd 0
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules libScePigletv2VSH.sprx module already on PlayStation file system
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen opening file libSceShaccVSH.sprx
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen libSceShaccVSH.sprx opened fd=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek fd=0 offset=0 whence=2
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek slot=0 fd=0 return=10394272
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek fd=0 offset=0 whence=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek slot=0 fd=0 return=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=1048576
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules orbisNfsRead: chunk 0  read 1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=1048576
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules orbisNfsRead: chunk 1  read 1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=1048576
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules orbisNfsRead: chunk 2  read 1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=1048576
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules orbisNfsRead: chunk 3  read 1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=1048576
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules orbisNfsRead: chunk 4  read 1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=1048576
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules orbisNfsRead: chunk 5  read 1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=1048576
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules orbisNfsRead: chunk 6  read 1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=1048576
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules orbisNfsRead: chunk 7  read 1048576
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=2005664
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=2005664
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules orbisNfsRead: chunk 8  read 2005664
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose closing fd 0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose slot=0 fd=0 libSceShaccVSH.sprx closed
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadPigletModules libSceShaccVSH.sprx module already on PlayStation file system
[ORBIS][DEBUG]: [ORBISLINK] main ready to loading homebrew.self
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen opening file homebrew.self
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen homebrew.self opened fd=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek fd=0 offset=0 whence=2
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek slot=0 fd=0 return=839168
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek fd=0 offset=0 whence=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek slot=0 fd=0 return=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=839168
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=839168
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose closing fd 0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose slot=0 fd=0 homebrew.self closed
[ORBIS][DEBUG]: [ORBISLINK] orbisLinkUploadSelf sceKernelChmod return 0x00000000 homebrew.self  already on PlayStation file system
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsFinish
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free .
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free ..
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free homebrew.self
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free libScePigletv2VSH.sprx
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free assets
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free GRADIUS2.ROM
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free raylib_logobackup.png
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free lighting.fs
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free raymarching.fs
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free KAISG.ttf
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free config.ini
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free system
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free resources
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free raylib_logo.png
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free texel_checker.png
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free base_lighting.vs
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free nightk.rom
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free homebrew.elf
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free julia_set.fs
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free app
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free .DS_Store
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free MGEAR2.ROM
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free ABADIA.DSK
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free libSceShaccVSH.sprx
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean before free MGEAR1.ROM
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean after free entry
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean cleaning head tail and length
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsFinish liborbisNfs finished
[ORBIS][INFO]: debugnet initialized
[ORBIS][INFO]: Copyright (C) 2010,2016 Antonio Jose Ramos Marquez aka bigboss @psxdev
[ORBIS][INFO]: ready to have a lot of fun...
[ORBIS][DEBUG]: [ORBISLINK] initOrbisLinkApp before get nfsurl from config.ini
[ORBIS][DEBUG]: [ORBISLINK] initOrbisLinkApp nfsurl nfs://x.x.x.x/hostapp
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsCreateConf
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit calling nfs_init_context
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit nfs_init_context return valid nfs object
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit calling nfs_parse_url_dir
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit nfs_parse_url_dir return valid urls object
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit calling nfs_mount
[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.3
[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.3
[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.3
[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.3
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit nfs_mount return fine
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit liborbisNfs initialized readChunkSize=65536 writeChunkSize=65536
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListClean cleaning head tail and length
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetDirectoryEntries
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDopen path=.
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDopen directory . open slot=0 dfd=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry homebrew.self size=839168
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry homebrew.self type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry libScePigletv2VSH.sprx size=744208
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry libScePigletv2VSH.sprx type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry assets size=256
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry assets type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry GRADIUS2.ROM size=131072
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry GRADIUS2.ROM type=8 customType=4
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry raylib_logobackup.png size=3760
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry raylib_logobackup.png type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry lighting.fs size=2052
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry lighting.fs type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry raymarching.fs size=11048
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry raymarching.fs type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry KAISG.ttf size=79912
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry KAISG.ttf type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry config.ini size=405
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry config.ini type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry system size=192
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry system type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry resources size=288
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry resources type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry raylib_logo.png size=3760
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry raylib_logo.png type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry texel_checker.png size=57153
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry texel_checker.png type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry base_lighting.vs size=1578
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry base_lighting.vs type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry nightk.rom size=32768
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry nightk.rom type=8 customType=4
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry homebrew.elf size=236872
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry homebrew.elf type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry julia_set.fs size=3331
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry julia_set.fs type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry app size=96
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry app type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry .DS_Store size=8196
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry .DS_Store type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry MGEAR2.ROM size=524288
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry MGEAR2.ROM type=8 customType=4
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry ABADIA.DSK size=737280
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry ABADIA.DSK type=8 customType=6
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry libSceShaccVSH.sprx size=10394272
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry libSceShaccVSH.sprx type=8 customType=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry MGEAR1.ROM size=131072
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserGetFileType
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry MGEAR1.ROM type=8 customType=4
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry .. size=1184
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry .. type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread slot=0 dfd=0 entry . size=800
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsBrowserListAddEntry . type=4 customType=1
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDread
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsDclose slot=0 dfd=0  closed
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsGetConf
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen opening file config.ini
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen config.ini opened fd=0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=512
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=405
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose closing fd 0
[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose slot=0 fd=0 config.ini closed
[ORBIS][DEBUG]: [ORBISLINK] initOrbisLinkApp sceSysmoduleLoadModuleInternal(SCE_SYSMODULE_INTERNAL_PAD) return: 0x00000000
[ORBIS][DEBUG]: [ORBISPAD] orbisPadInit sceUserServiceInitialize return 0x       0!
[ORBIS][DEBUG]: [ORBISPAD] orbisPadInit scePadInit return 0
[ORBIS][DEBUG]: [ORBISPAD] orbisPadInit scePadOpen return handle 0x 3090500
[ORBIS][DEBUG]: [ORBISPAD] orbisPadInit liborbispad initialized
[ORBIS][DEBUG]: [ORBISLINK] initOrbisLinkApp liborbisPad initialized
[ORBIS][DEBUG]: [ORBISLINK] loadPigletModules sceKernelLoadStartModule(libScePigletv2VSH.sprx) return id: 63
[ORBIS][DEBUG]: [ORBISLINK] loadPigletModules sceKernelLoadStartModule(libSceShaccVSH.sprx) return id: 64
[ORBIS][DEBUG]: [ORBISLINK] initOrbisLinkApp piglet modules loaded
[ORBIS][DEBUG]: [ORBISLINK] patch_module module base=0x80000000 size=704512
[ORBIS][DEBUG]: [ORBISLINK] patch_module patching module
[ORBIS][DEBUG]: [ORBISLINK] initOrbisLinkApp piglet modules patched
[ORBIS][INFO]: [orbisAudio] sceAudioOutInit return 0
[ORBIS][INFO]: [orbisAudio] initialized!
[ORBIS][INFO]: [orbisAudio] buffer 0 for audio channel 0 created (4096b)
[ORBIS][INFO]: [orbisAudio] buffer 1 for audio channel 0 created (4096b)
[ORBIS][INFO]: setting format:1
[ORBIS][INFO]: [orbisAudio] sceAudioOutOpen 1024 samples
[ORBIS][INFO]: [orbisAudio] audio channel 0 thread UID: 0x880F4CE40 created
[ORBIS][INFO]: -- audio thread --
[ORBIS][ERROR]: localChannel:0 0 '0000000000000000' 4c8458 4c8458 8 0000000000000000, 0000000000000000
[ORBIS][INFO]: [orbisAudio] orbisAudioChannelThread 0 1 ready to have a lot of fun!
[ORBIS][DEBUG]: [ORBISLINK] orbisAudioInitChannel return 0
[ORBIS][DEBUG]: liborbiskeyboard is initialized!
[ORBIS][DEBUG]: [ORBISLINK] initOrbisLinkApp orbisKeyboardInit return 1
[ORBIS][DEBUG]: liborbiskeyboard sceImeKeyboardOpen in
[ORBIS][DEBUG]: liborbiskeyboard orbisKeyboardConf not null
[ORBIS][DEBUG]: liborbiskeyboard sceImeKeyboardOpen return success 0
[ORBIS][DEBUG]: [ORBISLINK] initOrbisLinkApp orbisKeyboardOpen return 0
[ORBIS][INFO]: [ORBISGL] raylib fself sample for Playstation 4 Retail fucking yeah!!!
[ORBIS][INFO]: [ORBISGL] scePigletSetConfigurationVSH success.
[ORBIS][INFO]: [ORBISGL] eglGetDisplay success.
[ORBIS][INFO]: [ORBISGL] EGL version major:1, minor:4
[ORBIS][INFO]: [ORBISGL] eglBindAPI success.
[ORBIS][INFO]: [ORBISGL] eglSwapInterval success.
[ORBIS][INFO]: [ORBISGL] eglChooseConfig success.
[ORBIS][INFO]: [ORBISGL] eglCreateWindowSurface success.
[ORBIS][INFO]: [ORBISGL] eglCreateContext success.
[ORBIS][INFO]: [ORBISGL] eglMakeCurrent success.
[ORBIS][INFO]: [ORBISGL] GL_VENDOR:   "Sony Interactive Entertainment Inc."
[ORBIS][INFO]: [ORBISGL] GL_VERSION:  "OpenGL ES 2.0 Piglet"
[ORBIS][INFO]: [ORBISGL] GL_RENDERER: "Piglet"
[ORBIS][INFO]: [ORBISGL] SL_VERSION:  "OpenGL ES GLSL ES 2.0"
[ORBIS][INFO]: [ORBISGL] Number of supported extensions: 35
[ORBIS][ERROR]: [ORBISGL] VAO extension not found, VAO usage not supported
[ORBIS][INFO]: [ORBISGL] NPOT textures extension detected, full NPOT textures supported
[ORBIS][INFO]: [ORBISGL] DXT compressed textures supported
[ORBIS][INFO]: [ORBISGL] ETC1 compressed textures supported
[ORBIS][INFO]: [ORBISGL] Anisotropic textures filtering supported (max: 16X)
[ORBIS][INFO]: [ORBISGL] Debug Marker supported
[ORBIS][DEBUG]: [ORBISGL] rlLoadTexture Load texture from data memory address: 0xeeff9dac
[ORBIS][DEBUG]: [ORBISGL] rlLoadTexture Load mipmap level 0 (1 x 1), size: 4, offset: 0
[ORBIS][INFO]: [ORBISGL] rlLoadTexture [TEX ID 35] Texture created successfully (1x1 - 1 mipmaps)
[ORBIS][INFO]: [ORBISGL] [TEX ID 35] Base white texture loaded successfully
[ORBIS][INFO]: [ORBISGL] CompileShader [SHDR ID 36] Shader compiled successfully
[ORBIS][INFO]: [ORBISGL] CompileShader [SHDR ID 37] Shader compiled successfully
[ORBIS][INFO]: [ORBISGL] LoadShaderProgram [SHDR ID 38] Shader program loaded successfully
[ORBIS][INFO]: [ORBISGL] LoadShaderDefault [SHDR ID 38] Default shader loaded successfully
[ORBIS][INFO]: [ORBISGL] LoadBuffersDefault Internal buffers initialized successfully (CPU)
[ORBIS][INFO]: [ORBISGL] LoadBuffersDefault Internal buffers uploaded successfully (GPU)
[ORBIS][DEBUG]: [ORBISGL] doTransform=0
[ORBIS][DEBUG]: [ORBISGL] doTransform=0
[ORBIS][DEBUG]: [ORBISGL] doTransform=0
[ORBIS][INFO]: [ORBISGL] default states initialized successfully
[ORBIS][INFO]: [DEBUG] InitTimer before srand
[ORBIS][INFO]: [DEBUG] InitTimer after srand
[ORBIS][INFO]: [DEBUG] InitTimer in if
[ORBIS][INFO]: [DEBUG] InitTimer before GetTime
[ORBIS][INFO]: [DEBUG] InitTimer after GetTime
[ORBIS][INFO]: [ORBISGL] after InitTimer
[ORBIS][INFO]: [ORBISGL] after ClearBackground
[ORBIS][INFO]: [ORBISGL] liborbisGl2 initialized
[ORBIS][DEBUG]: [ORBISGL] rlLoadTexture Load texture from data memory address: 0x801f1a00
[ORBIS][DEBUG]: [ORBISGL] rlLoadTexture Load mipmap level 0 (128 x 128), size: 32768, offset: 0
[ORBIS][INFO]: [ORBISGL] rlLoadTexture [TEX ID 43] Texture created successfully (128x128 - 1 mipmaps)
[ORBIS][DEBUG]: [ORBISGL] orbisGlDestroyImage
[ORBIS][DEBUG]: [ORBISGL] orbisGlDestroyImage width=128 height=128 format=2
[ORBIS][DEBUG]: [ORBISGL] orbisGlDestroyImage after free data
[ORBIS][DEBUG]: [ORBISGL] orbisGlDestroyImage image destroyed
[ORBIS][INFO]: [ORBISGL] LoadFontDefault TEX ID=43 Default font loaded successfully
[ORBIS][DEBUG]: [ORBISGL] rlLoadTexture Load texture from data memory address: 0x80239b80
[ORBIS][DEBUG]: [ORBISGL] rlLoadTexture Load mipmap level 0 (2 x 2), size: 16, offset: 0
[ORBIS][INFO]: [ORBISGL] rlLoadTexture [TEX ID 44] Texture created successfully (2x2 - 1 mipmaps)
[ORBIS][DEBUG]: [ORBISGL] orbisGlDestroyImage
[ORBIS][DEBUG]: [ORBISGL] orbisGlDestroyImage width=2 height=2 format=7
[ORBIS][DEBUG]: [ORBISGL] orbisGlDestroyImage after free data
[ORBIS][DEBUG]: [ORBISGL] orbisGlDestroyImage image destroyed
[ORBIS][INFO]: [ORBISGL] rlLoadMesh [VBOs] Mesh uploaded successfully to VRAM (GPU)
[ORBIS][INFO]: [ORBISGL] rlLoadMesh [VBOs] Mesh uploaded successfully to VRAM (GPU)
[ORBIS][INFO]: [ORBISGL] rlLoadMesh [VBOs] Mesh uploaded successfully to VRAM (GPU)
[ORBIS][INFO]: [ORBISGL] rlLoadMesh [VBOs] Mesh uploaded successfully to VRAM (GPU)
[ORBIS][INFO]: [ORBISGL] rlLoadMesh [VBOs] Mesh uploaded successfully to VRAM (GPU)
[ORBIS][INFO]: [ORBISGL] rlLoadMesh [VBOs] Mesh uploaded successfully to VRAM (GPU)
[ORBIS][INFO]: [ORBISGL] rlLoadMesh [VBOs] Mesh uploaded successfully to VRAM (GPU)
[ORBIS][INFO]: [ORBISGL] rlLoadMesh [VBOs] Mesh uploaded successfully to VRAM (GPU)
[ORBIS][INFO]: [ORBISGL] SetTargetFPS Target time per frame: 16.667 milliseconds
```

Credits
===================

- ORBISDEV team :P less than 2 months to have a full open solution end to end and with CI ready
- hitodama the one and only
- flatz for fself signing, patching and gl stuff
- maxton for liborbispkg tool to create pkg
- All ps3dev and ps2dev old comrades
- To openorbis team thanks to make us finish this, we didn't think in do our own tools 2 months ago. Congrats for all your work paella and msx time :P !!!!



