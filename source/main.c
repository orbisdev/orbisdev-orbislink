/*
#  ____   ____    ____         ___ ____   ____ _     _
# |    |  ____>   ____>  |    |        | <____  \   /
# |____| |    \   ____>  | ___|    ____| <____   \_/	ORBISDEV Open Source Project.
#------------------------------------------------------------------------------------
# Copyright 2010-2020, orbisdev - http://orbisdev.github.io
# Licenced under MIT license
# Review README & LICENSE files for further details.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ps4sdk.h>
#include <stdarg.h>
#include <string.h>
#include <sys/socket.h>
#include <ps4sdk.h>
#include <debugnet.h>
#include <orbisNfs.h>
#include <orbislink.h>
#include <sys/stat.h>


int main()
{
	
	int ret=initOrbisLinkAppInternal();
	
	if(ret>=0)
	{
		debugNetPrintf(3,"[ORBISLINK] %s ready to loading homebrew.self\n",__FUNCTION__);
		ret=orbisLinkUploadSelf("homebrew.self");
		if(ret==0)
		{
			orbisNfsFinish();
			debugNetPrintf(3,"[ORBISLINK] %s after orbisNfsFinish\n",__FUNCTION__,ret);
			char *elfName = "puta_madre";
			char *elfName2 = "mal_pario";
			char *argv[3] = { elfName, elfName2, NULL };

			debugNetPrintf(3,"[ORBISLINK] %s before loadexec 0x%08X\n",__FUNCTION__,ret);
			ret=sceSystemServiceLoadExec("/data/self/system/common/lib/homebrew.self", NULL);	
			debugNetPrintf(3,"[ORBISLINK] %s after loadexec 0x%08X\n",__FUNCTION__,ret);
		}
		else
		{
			debugNetPrintf(3,"[ORBISLINK] %s no homebrew.self available\n",__FUNCTION__);
		}
	}
	else
	{
		//debugNetPrintf(3,"[ORBISLINK] %s something wrong happen initOrbisLinkApp return 0x%8x %d \n",__FUNCTION__,ret,ret);
		//debugNetPrintf(3,"[ORBISLINK] %s Exiting\n",__FUNCTION__);
	}
	
	exit(0);

	return 0;
}
void catchReturnFromMain(int exit_code) 
{

}


