#pragma once

#include "GlobalDefine.h"
#pragma pack(1)
class CSoBind
{
private:
	char m_sign[5];	//固定设置为#PSO#
	unsigned short m_ver;	//默认为01,用于版本控制
	char m_sn_sign[2]; //固定设置为SN
	char m_sn[100];		//上限为100字节
	char m_cpy[7];		//固定设置为COMPANY
	char m_company[100]; //上限为100字节

	int m_size;

public:
	CSoBind(void);
	~CSoBind(void);

	void SetCompany(const char *sn ,const char *company);
	int GetSize(){return m_size;}
	char* GetSn(){return m_sn;}
	char* GetCompany(){ return  m_company;}
	int ToByte(BYTE *outBuffer );
	bool FromByte(const BYTE*inBuffer);
	int ToEncByte(BYTE *outBuffer, BYTE *key, int len);
	bool FromEncByte(const BYTE* inBuffer, BYTE *key, int len);
	
};

