// Created by Administrator on 2018/7/3.
//

#include <unistd.h>
#include <errno.h>
#include "CHardInfo.h"
#include <string.h>
#include <string>

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

std::string g_MacAddress;

bool CHardInfo::getMacAddress(char* Filepath,std::string& strMacAddress)
{
    FILE *pMacFile = fopen(Filepath, "r");
    if (pMacFile == NULL){
    	return false;
    }
    char macBuf[1024] = {0};
    fgets(macBuf,1024,pMacFile);
    if(strlen(macBuf) == 18)
    {
    	if(macBuf[17] == '\n')
    	{
    		macBuf[17] = '\0';
    		if(strcmp("00:00:00:00:00:00",macBuf) != 0)
    			strMacAddress = macBuf;
    	}
    }
    else
    {
    	fclose(pMacFile);
    	return false;
    }
    fclose(pMacFile);
    return true;
}

bool CHardInfo::IsDir(const char* path)
{
	bool rbet=false;
	DIR* dp=NULL;
	dp=opendir(path);
	if(dp==NULL)
	{
		return false;
	}
	else
	{
		closedir(dp);
		return true;
	}
}

void CHardInfo::FindMacAddress(char* path, std::vector<std::string>& vecMacAddress, bool IsRoot)
{
	DIR *d_root = NULL;
	struct dirent *dp_root = NULL;
//	struct stat st_root;
	char path_root[1024] = {0};
	std::string strMacAddress = "";
	//判断路径是否正常，是否为文件夹
//    if(stat(path, &st_root) < 0 || !S_ISDIR(st_root.st_mode)) {
//        return;
//    }
	if(!IsDir(path))
		return;

    if(!(d_root = opendir(path))) {
        return;
    }
    //循环获取当前目录下的文件和文件夹
    while((dp_root = readdir(d_root)) != NULL)
    {
    	if((!strncmp(dp_root->d_name,".",1)) || (!strncmp(dp_root->d_name,"..",2)))
    		continue;

    	snprintf(path_root, sizeof(path_root) -1, "%s/%s", path, dp_root->d_name);
//    	stat(path_root,&st_root);
//    	if(!S_ISDIR(st_root.st_mode))
    	if(!IsDir(path_root))
    	{
    		if(strcmp("address",dp_root->d_name) == 0)
    		{
    			strMacAddress = "";
    			if(getMacAddress(path_root,strMacAddress))
    				vecMacAddress.push_back(strMacAddress);
    		}
    	}
    	else
    	{
    		if(IsRoot)
    		{
    			FindMacAddress(path_root, vecMacAddress, false);
    		}
    	}
    }
    closedir(d_root);
}

void CHardInfo::getMacAddress(std::vector<std::string>& vecMacAddress)
{
	char macFile[1024] = {0};
	strcpy(macFile,"/sys/class/net");
	FindMacAddress(macFile,vecMacAddress);
}

std::string CHardInfo::getMacAddress() {
    char macFile[100] = {0};
    strcpy(macFile , "/sys/class/net/wlan" );

    if( 0 != access(macFile ,F_OK ))
    {
        strcpy(macFile , "/sys/class/net/eth0/address");
        if (0!=access( macFile , F_OK)){
            return  "";
        }
    }

    FILE *pMacFile = fopen(macFile, "r");
    if (pMacFile == NULL){
        return  "";
    }
    char macBuf[1024] = {0};
    fgets(macBuf, 1024, pMacFile);
    if (strlen(macBuf) == 18) {
        if(macBuf[17] == '\n')
            macBuf[17] = 0;
        m_strMacAddress = macBuf;
        return m_strMacAddress;
    } else
        return std::string();
}
