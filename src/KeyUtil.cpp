#include "KeyUtil.h"
#include"../PiEncrypt.h"
#include "EncIniFile.h"
#include "SeriesNum.h"
#include <unistd.h>
#include "pencode.h"
#include "SoBind.h"
#include "TimeFunc.h"
#include "CHardInfo.h"
#include <algorithm>
#include<iostream>
#include <stdio.h>
#include <memory.h>
#include <stddef.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <elf.h>
//#include <sys/system_properties.h>
const int CONFIG_PATH_TYPE = 2; //1:模拟器路径； 2:资源路径； 3:/documents/piclesoft/目录；(2和3必须是真机调试)
//河南遥感院 027292   487
//湖南省二院  027275  977 B2ZE-97L7-UC07-I25Q-H7PP
#define TXETLENG 300
__attribute__((section(".txet"))) char global_path[TXETLENG]={0};



char global_Sn[100] = "251E-B0L0-UC01-I0QZ-H0PP";
char global_Cpy[100] = "武汉圆周率软件科技有限公司";
//char global_Sn[100] = "B2ZE-97L7-UC07-I25Q-H7PP";
//char global_Cpy[100] = "湖南省第二测绘院";
//const char * SERIAL_NUMBER = "027275"/*"027272"*/;//单位序列编号
//const int RANDOM_CODE = 977/*607*/;//单位随机码
char * DEFAULT_CONFIG_PATH = "/opt/piencrypttool/";
CKeyUtil* g_KeyUtil = NULL;
#define S_CHECK_SN

CKeyUtil::CKeyUtil(char* cfgPath)
{
    if(!InitConfigPath(cfgPath))
        return ;
    m_nErrCode = PI_E_UNKONWN;
    m_keyFile.Initialize();
    m_strEncProductKey = ""; //利用密钥加密后的产品序列号
    m_strPclPath = "";
    m_strPkyPath = "";
    m_nEncMode = 1; //默认为中等强度
    SetPclPath(DEFAULT_CONFIG_PATH );
    SetPkyPath(DEFAULT_CONFIG_PATH);
    Readelf();
	Initialize();

}

CKeyUtil::~CKeyUtil(void)
{
}
void CKeyUtil::SetPclPath(const char*filename)
{
    m_strPclPath.assign(filename);
    m_strPclPath += "piencsys.pcl";
}
void CKeyUtil::SetPkyPath(const char*filename)
{
    m_strPkyPath.assign(filename);
    m_strPkyPath += "piencsys.pky";
}
bool CKeyUtil::CheckProductSerialNumber()
{
//	return true;
    //格式 “B3ZE-41L7-UC08-I22Q-H7PP”
#ifndef S_CHECK_SN
    //TODO 不检测序列号
    return true;
#endif
    if (m_strEncProductKey.size() < 24)
    {

        m_strEncProductKey = "";
        return  false;
    }
    char seriesbuf[25] = {0};
    char hardnum[65]={0};
    memcpy(seriesbuf, m_strEncProductKey.c_str(), 24);
    //从ELF文件中读取序列号并解密之后匹配
    //计算global_path的校验合是否为空,如果为空,那么表示当前是使用的武汉圆周率的序列号
    int nCount = 0;
    for (int i = 0; i < TXETLENG; ++i) {
        nCount += global_path[i];
        if(nCount > 0)
            break;
    }
    if (nCount == 0)
    {   //设置为圆周率的序列号
        strcpy(global_Sn , "251E-B0L0-UC01-I0QZ-H0PP");
        strcpy(global_Cpy,"武汉圆周率软件科技有限公司");
    } else
    {
    	int pos=0;
    	string strConf(global_path);
    	string bFlag=strConf.substr(pos,1);
    	pos+=1;
    	if(strcmp(bFlag.c_str(),"N")==0)
    		return true;
    	string strSn=strConf.substr(pos,24);
    	pos+=24;
    	strcpy(global_Sn,strSn.c_str());
    	string strHn=strConf.substr(pos,64);
    	int n=strHn.find("#");
    	if(n!=-1)
    		strHn=strHn.substr(0,n);
    	pos+=64;
    	strcpy(hardnum,strHn.c_str());
    	//扩展内容
//        CSoBind so;
//        if(so.FromEncByte((BYTE*)global_path,(BYTE*)seriesbuf,25))
//        {
//            strcpy(global_Sn , so.GetSn());
//            strcpy(global_Cpy, so.GetCompany());
//        } else  //解密失败就将序列号设置为空
//        {
//            memset(global_Sn,0,100);
//            memset(global_Cpy,0,100);
//        }
    }
    //显示当前授权单位
    //LOGE(Logger::info,"授权单位:%s",global_Cpy);
    bool bOK  = false;
//    cout<<"seriesbuf"<<seriesbuf<<endl;
//    cout<<"global_sn"<<global_Sn<<endl;
    if  (0 == strcmp(seriesbuf , global_Sn))
        bOK = true;
    if(hardnum[0]!='\0')
    {
    	//此处获取当前系统的网卡号
		CHardInfo hardInfo;
		std::vector<std::string> vecMacList;
		hardInfo.getMacAddress(vecMacList);
		std::string sh = "";
		if(0 == vecMacList.size())
		{
			m_keyFile.keyTable.clear();
			m_nErrCode = PI_E_PKY_READ_HARDWARE_COUNT_ERROR;
			return false;
		}
		std::vector<std::string>::iterator it_hardInfo;
		std::string strHardInfo = "";
		std::vector<HARD_INF>::iterator it;
		bool bFind = false;
		for (it_hardInfo = vecMacList.begin();it_hardInfo != vecMacList.end(); it_hardInfo ++)
		{
			sh = *it_hardInfo;
			if (0 == strcmp(hardnum, sh.c_str()))
			{
					bFind = true;
					break;
			}

		}
		if(bFind)
			bOK=true;
		else
			bOK=false;
    }

    if (bOK)
    {
        //LOGE(Logger::info,"don't check se.");
        return  true;
    }
    m_strEncProductKey = "";
    //LOGE(Logger::info,"许可授权失败,许可对应:%s",m_strCompany.c_str());
    return false;
}

bool CKeyUtil::Initialize()
{
    //初始化字符集转换
    dl_icuuc_init();
    m_nErrCode = PI_E_UNKONWN;
    m_strEncProductKey = "";
    m_keyFile.Initialize();
    bool bOk = false;
    FILE *fpPcl = NULL, *fpPky = NULL;
    if (NULL == (fpPcl = fopen(m_strPclPath.c_str(), "rb")))
    {
        LOGE(Logger::error,"初始化pcl许可失败 : %s",m_strPclPath.c_str());
        m_nErrCode = PI_E_PCL_FILE_NOT_EXIST;
        return false;
    }
    if (NULL == (fpPky = fopen(m_strPkyPath.c_str(), "rb")))
    {
        LOGE(Logger::error,"初始化许可失败 : %s",m_strPkyPath.c_str());
        m_nErrCode = PI_E_PKY_FILE_NOT_EXIST;
        return false;
    }
    fclose(fpPcl);
    fclose(fpPky);

	bOk = m_pclFile.ReadFromEncFile(m_strPclPath);
    if (!bOk)
    {
        LOGE(Logger::error,"读取pcl失败");
        m_nErrCode = m_pclFile.GetErrCode();
        return false;
    }
	bOk = m_pclFile.GetEntryValue("Summary" , "ProductKey" , m_strEncProductKey);
    m_pclFile.GetEntryValue("Summary","UnitName" , m_strCompany);
    m_nEncMode = m_pclFile.GetEncMode();
    char buffer[1024] = {0};
    int32_t strlength =  dl_icuuc_gbk2utf8(buffer,1024,m_strCompany.c_str(),m_strCompany.length());
    if (strlength > 0)
        m_strCompany = buffer;
    if (bOk )
    {
//        m_nErrCode = PI_E_PCL_PRODUCT_KEY_ERROR;
//        return false;
        if (!CheckProductSerialNumber())
        {
//            LOGE(Logger::info,"pcl和程序绑定的产品序列号不匹配");
            m_nErrCode = PI_E_PCL_SERIES_NUMBER_UNMATCH;
            return false;
        }
    }

    
    CKeyFileHelper keyhelper;

    bOk = keyhelper.FillKeyFileStruct( m_keyFile, (char*)m_strPkyPath.c_str());
    if (!bOk)
    {
//        LOGE(Logger::info,"获取密钥结构体");
        m_nErrCode = keyhelper.GetErrCode();
        return false;
    } else
    {
    	if(m_pclFile.IsCheckLimitTime())
    	{
			if(IsTimeDue())
			{
				m_keyFile.keyTable.clear(); //许可到期，就清空密钥表，那么就无法解密，此初始化函数调用未检测返回值
	//            LOGE(Logger::info,"许可已到期，或修改了系统时间,如修改了系统时间，请修改到正确的时间");
				m_nErrCode = PI_E_PKY_TIME_DUE;
				return false;
			} else
			ChangeClientStartTimeToFile();
    	}
        //检查硬件绑定，硬件绑定目前绑定网卡
        if(m_pclFile.IsCheckBindHard())
        {
            //此处获取当前系统的网卡号
            CHardInfo hardInfo;
        	std::vector<std::string> vecMacList;
        	hardInfo.getMacAddress(vecMacList);
        	std::string sh = "";
        	if(0 == vecMacList.size())
        	{
                m_keyFile.keyTable.clear();
                m_nErrCode = PI_E_PKY_READ_HARDWARE_COUNT_ERROR;
                return false;
        	}
        	std::vector<std::string>::iterator it_hardInfo;
        	std::string::iterator it_sh;
            std::string strHardInfo = "";
            std::vector<HARD_INF>::iterator it;
            bool bFind = false;
            for (it_hardInfo = vecMacList.begin();it_hardInfo != vecMacList.end(); it_hardInfo ++)
            {
            	sh = *it_hardInfo;
                for (it = m_keyFile.hardTable.begin(); it != m_keyFile.hardTable.end() ; it ++){
                    HARD_INF& hardInfo = *it;
                    strHardInfo = hardInfo.hwCode;
                    transform(strHardInfo.begin(), strHardInfo.end(), strHardInfo.begin(), ::tolower);
                    transform(sh.begin(), sh.end(), sh.begin(), ::tolower);
                    int tempnum=1;
                    for(it_sh=sh.begin();it_sh!=sh.end();it_sh++)
                    {
                    	if(*it_sh==':' && (tempnum==3 ||tempnum==6 ||tempnum==9 ||tempnum==12 || tempnum==15))
                    	{
                    		*it_sh='-';
                    	}
                    	tempnum++;
                    }
                    if (0 == strcasecmp(strHardInfo.c_str(), sh.c_str()))
                    {
                        bFind = true;
                        break;
                    }
                }
            }

            if (!bFind){
                m_keyFile.keyTable.clear();
                m_nErrCode = PI_E_PKY_READ_HARDWARE_FIND_ERROR;
                return false;
            }

        }
    }
    //作调试用
   //CHardInfo hardInfo;
   //std::string ss =   hardInfo.getMacAddress();
    //初始化钩取的格式
     m_hookInfo.Init(&m_pclFile);

    m_nErrCode = PI_S_SUCCESS;
    return  true;
}

int CKeyUtil::GetKeyCount()
{
	return int(m_keyFile.keyTable.size());
}

bool CKeyUtil::IsExistKey(long uKeyVer)
{
	return FindKey(uKeyVer) != -1;
}

int CKeyUtil::FindKey(long uKeyVer)
{
	for(int i = 0 ; i < m_keyFile.keyTable.size() ; i++)
	{
		UNIT_KEY	&aUnitKey = m_keyFile.keyTable.at(i);
		if(uKeyVer == (long)aUnitKey.id)	//找到了对应版本号
		{
			return i;
		}
	}

	return -1;
}

bool CKeyUtil::QueryKeyByIndex(int nIndex , /*索引 */ int nBufLen , /*缓存大小 */ BYTE *pBuffer , /*缓存区 */ int &nKeyLen , /*返回的密钥长度 */ long &uKeyVer /*返回的密钥版本 */)
{
	//检查索引越界
	if ( nIndex < 0 || nIndex >= GetKeyCount() ) return false;

	UNIT_KEY &aUnitKey = m_keyFile.keyTable.at(nIndex);
	nKeyLen	= aUnitKey.len;//记录密钥长度

	//检查缓存是否足够
	if ( nBufLen < aUnitKey.len )
		return false;

	uKeyVer	= aUnitKey.id;
	memcpy(pBuffer , aUnitKey.key , nKeyLen);

	return true;
}

bool CKeyUtil::QueryKey(long uKeyVer , /*密钥版本 */ int nBufLen , /*缓存区长度 */ Byte *pBuffer , /*在外部分配的缓存区 */ int &nKeyLen /*返回的密钥长度 */)
{
	nKeyLen	= 0;
	//找到密钥索引
	int nIndex = FindKey( uKeyVer );
	if ( nIndex == -1 )
	{
		nKeyLen = 9;
		return false;
	}

	UNIT_KEY &aUnitKey = m_keyFile.keyTable.at(nIndex);
	nKeyLen	= aUnitKey.len;//记录密钥长度

	//检查缓存是否足够
	if ( nBufLen < aUnitKey.len )
    {
        return false;
    }


	uKeyVer	= aUnitKey.id;
	memcpy(pBuffer , aUnitKey.key , nKeyLen);

	return true;
}
string CKeyUtil::GetProductKey()
{
	return m_strEncProductKey;
}

int CKeyUtil::GetEncMode()
{
    return m_nEncMode;
}

bool CKeyUtil::ChangeClientStartTimeToFile() {
    char strNow[32];
    time_t  tmNow = time(NULL);
    strftime(strNow , sizeof(strNow) , "%Y-%m-%d %H:%M:%S" , localtime(&tmNow));
    //修改开始时间
    strcpy(m_keyFile.startTime , strNow);
    //更新到文件
    CKeyFileHelper keyhelper;
    keyhelper.CreateKeyFileNew(1,m_keyFile , m_strPkyPath.c_str());
    return true;
}

bool CKeyUtil::IsTimeDue() {

    const char* start = m_keyFile.startTime;
    const char* end = m_keyFile.endTime;
    char now[32] = {0};
    GetCurrentTimeString(now);
    if (StringTimeCompare(start  , now)  == 1 || StringTimeCompare(end , now ) == -1 )
    {
        return true;
    }
    return false;
}

bool CKeyUtil::InitConfigPath(char* cfgPath) {
    //storage/emulated/0/
    //storage/extSdCard
    ///storage/sdcard0/

    //如果提供了配置文件,使用提供的配置文件进行配置,配置前判断路径是否存在
    if(cfgPath)
    {
        if (access(cfgPath , F_OK) == 0 )
        {
            char* mPath = new char[1024];
            memset(mPath,0,1024);
            strcpy(mPath, cfgPath);
            DEFAULT_CONFIG_PATH = mPath;
        } else
        {
            //LOGE(Logger::info,"指定的配置文件路径,无效");
            return false;
        }

    }
    return true;
}

int CKeyUtil::Readelf()
{

		// 打开文件
		FILE *fp;
		char cpath[256]={0};
		getcwd(cpath,255);
//		printf("cpath=%s\n",cpath);
		fp = fopen("/usr/lib/libPiEncrypt.so", "r");
		if (NULL == fp)
		{
			printf("fail to open the file\n");
			exit(0);
		}

		// 解析head
		Elf64_Ehdr elf_head;
		int shnum, a;

		// 读取 head 到elf_head
		a = fread(&elf_head, sizeof(Elf64_Ehdr), 1, fp);   //fread参数1：读取内容存储地址，参数2：读取内容大小，参数3：读取次数，参数4：文件读取引擎
		if (0 == a)
		{
			printf("fail to read head\n");
			exit(0);
		}

		// 判断elf文件类型
		if (elf_head.e_ident[0] != 0x7F ||
			elf_head.e_ident[1] != 'E' ||
			elf_head.e_ident[2] != 'L' ||
			elf_head.e_ident[3] != 'F')
		{
			printf("Not a ELF file\n");
			exit(0);
		}

		// 解析section 分配内存 section * 数量
		Elf64_Shdr *shdr = (Elf64_Shdr*)malloc(sizeof(Elf64_Shdr) * elf_head.e_shnum);
		if (NULL == shdr)
		{
			printf("shdr malloc failed\n");
			exit(0);
		}

		// 设置fp偏移量 offset，e_shoff含义
		a = fseek(fp, elf_head.e_shoff, SEEK_SET); //fseek调整指针的位置，采用参考位置+偏移量
		if (0 != a)
		{
			printf("\nfaile to fseek\n");
			exit(0);
		}

		// 读取section 到 shdr, 大小为shdr * 数量
		a = fread(shdr, sizeof(Elf64_Shdr) * elf_head.e_shnum, 1, fp);
		if (0 == a)
		{
			printf("\nfail to read section\n");
			exit(0);
		}

		// 重置指针位置到文件流开头
		rewind(fp);

		// 将fp指针移到 字符串表偏移位置处
		fseek(fp, shdr[elf_head.e_shstrndx].sh_offset, SEEK_SET);

		// 第e_shstrndx项是字符串表 定义 字节 长度 char类型 数组
		char shstrtab[shdr[elf_head.e_shstrndx].sh_size];
		char *temp = shstrtab;

		// 读取内容
		a = fread(shstrtab, shdr[elf_head.e_shstrndx].sh_size, 1, fp);
		if (0 == a)
		{
			printf("\nfaile to read\n");
		}

		// 遍历
		for (int i = 0; i < elf_head.e_shnum; i++)
		{
			temp = shstrtab;
			temp = temp + shdr[i].sh_name;
	        if (strcmp(temp, ".txet") != 0) continue;//该section名称
//	        LOGE(Logger::debug,"节的名称: %s", temp);
//	        LOGE(Logger::debug,"节首的偏移: %x", shdr[i].sh_offset);
//	        LOGE(Logger::debug,"节的大小: %x", shdr[i].sh_size);
	        uint8_t *sign_data=(uint8_t*)malloc(sizeof(uint8_t)*shdr[i].sh_size);
			// 依据此段在文件中的偏移读取出
			fseek(fp, shdr[i].sh_offset, SEEK_SET);
			fread(sign_data, sizeof(uint8_t)*shdr[i].sh_size, 1, fp);
			// 显示读取的内容
			uint8_t *p = sign_data;
			uint8_t str[1028]="";
			int j = 0;
			for (j=0; j<shdr[i].sh_size; j++)
			{
				str[j]=*p;
	            p++;
			}
			str[j]='\0';
			strcpy(global_path,(char*)str);
			free(sign_data);
		 }
		return 1;
}

