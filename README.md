# orbislink
FSELF loader

What does this do?
===================
 orbislink in the past have been our try to have a standard way to load elf files compatible with Hitodama PS4SDK for developers since more than 2 years ago, highly inspired on other PlayStation families

 Now it has evolved!!!! 

 If you want piracy stop here buy originals, this is not for you.


Features
===================

- Build all using open source vanilla compiler(clang 13) and linker (binutils)
- oelf tool orbis-elf-create
- fself signing tool make_fself.py 
- orbisdev sdk
- pkg builder pkgTool

Instructions
===================
- Last orbisdev toolchain installed
- Modify define ORBISLINK_CONFIG_DB_SET in main.c with your own configuration for your pc and your nfs server. Don't use names only ip.
- Compile and Install pkg
- Open in your pc/mac and get klog logs from your console you will need the right payload to get it for example i use this to have a local port to filter then
```
cat klogsocat.sh
socat - TCP4:IPOFYOURCONSOLE:9998| socat STDIO TCP-LISTEN:4444,fork,reuseaddr
```
- To filter i use this i can call klogdebug.sh ORBIS and only logs from debugnet facility are displayed, less noise...
```
cat klogdebug.sh
if [ "$#" -eq 0 ]
then
socat - TCP4:localhost:4444
else
if [ "$#" -eq 1 ]
then
    #socat - TCP4:localhost:4444 |grep  "<118>\[ORBIS\]\[$1\]"
    socat - TCP4:localhost:4444 |grep  "<118>\[$1\]"
else

case $2 in
    0)
        LEVEL="INFO";;
    1)
        LEVEL="WARNING";;
    2)
        LEVEL="ERROR";;
    3)
        LEVEL="DEBUG";;
    *)
        LEVEL="INFO";;

esac
socat - TCP4:localhost:4444 |grep  "<118>\[$1\]\[$LEVEL\]"
#socat - TCP4:localhost:4444 |grep  "<118>\[ORBIS\]\[$LEVEL\]"
fi
fi
```

- You will need a nfs server with a share exported with access for your PlayStation ip

- Default Configuration now ins using SQLite and is using vanilla piglet from your console without shader compiler

- Finally it will try to upload from nfs, and run your homebrew.self

- Ready to have a lot of fun devoloping your stuff

Sample Output
=============
```

<118>[ORBIS][INFO][ORBISLINK][orbisLinkSQLiteGetConfig][627] sqlite3_bind_int  192.168.1.12 18194 3 nfs://192.168.1.12/usr/local/orbisdev/git/ps4sh/bin/hostapp
<118>[ORBIS][DEBUG][ORBISLINK][orbisLinkSQLiteGetShader][673] shader raylib vertex shader with length: 1330
<118>[ORBIS][DEBUG][ORBISLINK][orbisLinkSQLiteGetShader][673] shader raylib fragment shader with length: 1108
<118>[ORBIS][INFO]: debugnet initialized
<118>[ORBIS][INFO]: Copyright (C) 2010,2016 Antonio Jose Ramos Marquez aka bigboss @psxdev
<118>[ORBIS][INFO]: ready to have a lot of fun...
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsCreateConf
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit calling nfs_init_context
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit nfs_init_context return valid nfs object
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit calling nfs_parse_url_dir
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit nfs_parse_url_dir return valid urls object
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsInit calling nfs_mount
<118>[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.12
<118>[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.12
<118>[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.12
<118>[ORBIS][DEBUG]: [LIBNFS] rpc_set_sockaddr server=192.168.1.12
<118>[ORBIS][DEBUG]: [ORBISLINK] main ready to loading homebrew.self
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen opening file homebrew.self
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsOpen homebrew.self opened fd=0
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek fd=0 offset=0 whence=2
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek slot=0 fd=0 return=1602016
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek fd=0 offset=0 whence=0
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsLseek slot=0 fd=0 return=0
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead fd=0 size=1602016
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsRead slot=0 fd=0 bytereads=1602016
<118>[ORBIS][DEBUG]: [ORBISLINK][orbisLinkCopyModulesFromNfs][256] orbisNfsRead: chunk 0  read 1602016
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose closing fd 0
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsClose slot=0 fd=0 homebrew.self closed
<118>[ORBIS][DEBUG]: [ORBISLINK][orbisLinkUploadSelf][330]sceKernelChmod return 0x00000000 homebrew.self  already on PlayStation file system
<118>[ORBIS][DEBUG]: [ORBISNFS] orbisNfsFinish
<118>[ORBIS][INFO]: [RAYLIB4ORBIS] raylib sample for Playstation 4 Retail fucking yeah!!!
<118>[ORBIS][ERROR][ORBISLINK][orbisLinkSQLiteGetConfig][627] sqlite3_bind_int  192.168.1.12 18194 3 nfs://192.168.1.12/usr/local/orbisdev/git/ps4sh/bin/hostapp
<118>[ORBIS][DEBUG][ORBISLINK][orbisLinkSQLiteGetShader][673] shader raylib vertex shader with length: 1330
<118>[ORBIS][DEBUG][ORBISLINK][orbisLinkSQLiteGetShader][673] shader raylib fragment shader with length: 1108
<118>[ORBIS][INFO]: debugnet initialized
<118>[ORBIS][INFO]: Copyright (C) 2010,2016 Antonio Jose Ramos Marquez aka bigboss @psxdev
<118>[ORBIS][INFO]: ready to have a lot of fun...
<118>[ORBIS][DEBUG]: [ORBISLINK][orbisLinkLoadModulesGl][357] piglet module loaded 0
<118>[ORBIS][DEBUG]: [RAYLIB4ORBIS] initApp sceSysmoduleLoadModuleInternal(SCE_SYSMODULE_INTERNAL_PAD) return: 0x00000000
<118>[ORBIS][DEBUG]: [ORBISPAD] orbisPadInit sceUserServiceInitialize return 0x       0!
<118>[ORBIS][DEBUG]: [ORBISPAD] orbisPadInit scePadInit return 0
<118>[ORBIS][DEBUG]: [ORBISPAD] orbisPadInit scePadOpen return handle 0x 3060500
<118>[ORBIS][DEBUG]: [ORBISPAD] orbisPadInit liborbispad initialized
<118>[ORBIS][INFO]: Initializing raylib 4.0
<118>[ORBIS][INFO]: DISPLAY: EGL version major:1, minor:4
<118>[ORBIS][INFO]: DISPLAY: eglBindAPI success.
<118>[ORBIS][INFO]: DISPLAY: eglChooseConfig success.
<118>[ORBIS][INFO]: DISPLAY: eglCreateWindowSurface success.
<118>[ORBIS][INFO]: DISPLAY: context create EGL window surface
<118>[ORBIS][INFO]: DISPLAY: eglMakeCurrent success.
<118>[ORBIS][INFO]: GL: Supported extensions count: 37
<118>[ORBIS][INFO]: GL: OpenGL extensions:
<118>[ORBIS][INFO]:     GL_OES_texture_npot
<118>[ORBIS][INFO]:     GL_EXT_texture_filter_anisotropic
<118>[ORBIS][INFO]:     GL_EXT_texture_rg
<118>[ORBIS][INFO]:     GL_OES_rgb8_rgba8
<118>[ORBIS][INFO]:     GL_OES_depth_texture
<118>[ORBIS][INFO]:     GL_OES_depth32
<118>[ORBIS][INFO]:     GL_OES_fbo_render_mipmap
<118>[ORBIS][INFO]:     GL_EXT_texture_format_BGRA8888
<118>[ORBIS][INFO]:     GL_EXT_read_format_bgra
<118>[ORBIS][INFO]:     GL_OES_texture_float
<118>[ORBIS][INFO]:     GL_OES_texture_half_float
<118>[ORBIS][INFO]:     GL_EXT_color_buffer_half_float
<118>[ORBIS][INFO]:     GL_OES_texture_float_linear
<118>[ORBIS][INFO]:     GL_OES_texture_half_float_linear
<118>[ORBIS][INFO]:     GL_OES_vertex_half_float
<118>[ORBIS][INFO]:     GL_OES_element_index_uint
<118>[ORBIS][INFO]:     GL_EXT_texture_compression_dxt1
<118>[ORBIS][INFO]:     GL_EXT_texture_compression_dxt3
<118>[ORBIS][INFO]:     GL_EXT_texture_compression_dxt5
<118>[ORBIS][INFO]:     GL_EXT_texture_compression_s3tc
<118>[ORBIS][INFO]:     GL_EXT_texture_storage
<118>[ORBIS][INFO]:     GL_OES_compressed_ETC1_RGB8_texture
<118>[ORBIS][INFO]:     GL_OES_standard_derivatives
<118>[ORBIS][INFO]:     GL_EXT_shader_texture_lod
<118>[ORBIS][INFO]:     GL_ARB_texture_compression_bptc
<118>[ORBIS][INFO]:     GL_EXT_texture_compression_latc
<118>[ORBIS][INFO]:     GL_EXT_texture_compression_rgtc
<118>[ORBIS][INFO]:     GL_OES_texture_stencil8
<118>[ORBIS][INFO]:     GL_EXT_color_buffer_float
<118>[ORBIS][INFO]:     GL_EXT_debug_marker
<118>[ORBIS][INFO]:     GL_EXT_draw_instanced
<118>[ORBIS][INFO]:     GL_EXT_instanced_arrays
<118>[ORBIS][INFO]:     GL_SCE_piglet_shader_binary
<118>[ORBIS][INFO]:     GL_SCE_orbis_canvas_texture
<118>[ORBIS][INFO]:     GL_SCE_texture_resource
<118>[ORBIS][INFO]:     GL_SCE_commandbuffer_inject
<118>[ORBIS][INFO]:     GL_EXT_disjoint_timer_query
<118>[ORBIS][INFO]: GL: OpenGL device information:
<118>[ORBIS][INFO]:     > Vendor:   Sony Interactive Entertainment Inc.
<118>[ORBIS][INFO]:     > Renderer: Piglet
<118>[ORBIS][INFO]:     > Version:  OpenGL ES 2.0 Piglet
<118>[ORBIS][INFO]:     > GLSL:     OpenGL ES GLSL ES 2.0
<118>[ORBIS][INFO]: GL: OpenGL capabilities:
<118>[ORBIS][INFO]:     GL_MAX_TEXTURE_SIZE: 4096
<118>[ORBIS][INFO]:     GL_MAX_CUBE_MAP_TEXTURE_SIZE: 2048
<118>[ORBIS][INFO]:     GL_MAX_TEXTURE_IMAGE_UNITS: 16
<118>[ORBIS][INFO]:     GL_MAX_VERTEX_ATTRIBS: 16
<118>[ORBIS][INFO]:     GL_NUM_COMPRESSED_TEXTURE_FORMATS: 17
<118>[ORBIS][INFO]:         GL_COMPRESSED_RGB_S3TC_DXT1_EXT
<118>[ORBIS][INFO]:         GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
<118>[ORBIS][INFO]:         GL_COMPRESSED_RGBA_S3TC_DXT3_EXT
<118>[ORBIS][INFO]:         GL_COMPRESSED_RGBA_S3TC_DXT5_EXT
<118>[ORBIS][INFO]:         GL_ETC1_RGB8_OES
<118>[ORBIS][INFO]:         GL_COMPRESSED_RGBA_BPTC_UNORM_ARB
<118>[ORBIS][INFO]:         GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB
<118>[ORBIS][INFO]:         GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB
<118>[ORBIS][INFO]:         GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB
<118>[ORBIS][INFO]:         GL_COMPRESSED_UNKNOWN
<118>[ORBIS][INFO]:         GL_COMPRESSED_UNKNOWN
<118>[ORBIS][INFO]:         GL_COMPRESSED_UNKNOWN
<118>[ORBIS][INFO]:         GL_COMPRESSED_UNKNOWN
<118>[ORBIS][INFO]:         GL_COMPRESSED_RED_RGTC1
<118>[ORBIS][INFO]:         GL_COMPRESSED_SIGNED_RED_RGTC1
<118>[ORBIS][INFO]:         GL_COMPRESSED_RG_RGTC2
<118>[ORBIS][INFO]:         GL_COMPRESSED_SIGNED_RG_RGTC2
<118>[ORBIS][INFO]: GL: VAO extension detected, VAO functions loaded successfully
<118>[ORBIS][INFO]: GL: NPOT textures extension detected, full NPOT textures supported
<118>[ORBIS][INFO]: GL: DXT compressed textures supported
<118>[ORBIS][INFO]: GL: ETC1 compressed textures supported
<118>[ORBIS][INFO]: TEXTURE: [ID 38] Texture loaded successfully (1x1 | R8G8B8A8 | 1 mipmaps)
<118>[ORBIS][INFO]: TEXTURE: [ID 38] Default texture loaded successfully
<118>[ORBIS][INFO]: SHADER: [ID 41] Program shader loaded successfully
<118>[ORBIS][INFO]: SHADER: [ID 41] Default shader loaded successfully
<118>[ORBIS][INFO]: RLGL: Render batch vertex buffers loaded successfully in RAM (CPU)
<118>[ORBIS][INFO]: RLGL: Render batch vertex buffers loaded successfully in VRAM (GPU)
<118>[ORBIS][INFO]: RLGL: Default OpenGL state initialized successfully
<118>[ORBIS][INFO]: TEXTURE: [ID 47] Texture loaded successfully (128x128 | GRAY_ALPHA | 1 mipmaps)
<118>[ORBIS][INFO]: FONT: Default font loaded successfully (224 glyphs)
<118>[ORBIS][INFO]: [RAYLIB4ORBIS] creating image checked
<118>[ORBIS][INFO]: [RAYLIB4ORBIS] creating texture
<118>[ORBIS][INFO]: TEXTURE: [ID 48] Texture loaded successfully (2x2 | R8G8B8A8 | 1 mipmaps)
<118>[ORBIS][INFO]: [RAYLIB4ORBIS] unloading image
<118>[ORBIS][INFO]: [RAYLIB4ORBIS] creating mesh
<118>[ORBIS][INFO]: VAO: [ID 49] Mesh uploaded successfully to VRAM (GPU)
<118>[ORBIS][INFO]: VAO: [ID 54] Mesh uploaded successfully to VRAM (GPU)
<118>[ORBIS][INFO]: VAO: [ID 59] Mesh uploaded successfully to VRAM (GPU)
<118>[ORBIS][INFO]: VAO: [ID 63] Mesh uploaded successfully to VRAM (GPU)
<118>[ORBIS][INFO]: VAO: [ID 67] Mesh uploaded successfully to VRAM (GPU)
<118>[ORBIS][INFO]: VAO: [ID 71] Mesh uploaded successfully to VRAM (GPU)
<118>[ORBIS][INFO]: VAO: [ID 75] Mesh uploaded successfully to VRAM (GPU)
<118>[ORBIS][INFO]: VAO: [ID 79] Mesh uploaded successfully to VRAM (GPU)
<118>[ORBIS][INFO]: TIMER: Target time per frame: 16.667 milliseconds
<118>[ORBIS][DEBUG]: R1 pressed
```

Credits
===================

- @frangar @fjtrujy @psxdev aka "los nenes" and @masterzorag
- hitodama the one and only
- flatz for fself signing, patching and gl stuff
- maxton for liborbispkg tool to create pkg
- All people who have been using the old and now deprecated liborbis
- All orbisdev, ps3dev, vitasdk and ps2dev old comrades



