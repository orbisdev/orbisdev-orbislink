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
#include <user_mem.h>
#include <stdlib.h>
#include <string.h>
#include <orbisdev.h>
#include <orbislink.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <orbisNfs.h>
#include <sqlite3.h>

//change this to your pc and nfs url serve. Use ip no names.
#define ORBISLINK_CONFIG_DB_SET "INSERT INTO orbislink_config VALUES('orbislink base','192.168.1.12',18194,3,'nfs://192.168.1.12/usr/local/orbisdev/git/ps4sh/bin/hostapp')"
int main()
{
	
	int ret=initOrbisLinkAppInternal(ORBISLINK_CONFIG_DB_SET);
	
	if(ret>=0)
	{
		debugNetPrintf(3,"[ORBISLINK] %s ready to loading homebrew.self\n",__FUNCTION__);
		ret=orbisLinkUploadSelf("homebrew.self");
		if(ret==0)
		{
			orbisNfsFinish();
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


