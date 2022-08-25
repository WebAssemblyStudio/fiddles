#include <string.h>
#include "SoBind.h"
#include "EncM_Des.h"
#include"../PiEncrypt.h"
#define SOBINDSIGN "#PSO#"

CSoBind::CSoBind(void)
{
	memcpy(m_sign,"#PSO#",5);
	m_ver =1;
	memcpy(m_sn_sign,"SN",2);
	memset(m_sn,0,100);
	memcpy(m_cpy,"COMPANY",7);
	memset(m_company,0,100);

	m_size = sizeof(m_sign) + sizeof(m_ver) + sizeof(m_sn_sign) + sizeof(m_sn)+sizeof(m_cpy)+sizeof(m_company);
}


CSoBind::~CSoBind(void)
{
}

void CSoBind::SetCompany( const char *sn ,const char *company )
{
	memset(m_sn,0,sizeof(m_sn));
	memset(m_company,0,sizeof(m_company));
	strcpy(m_sn,sn);
	strcpy(m_company,company);
}

int CSoBind::ToByte( BYTE *outBuffer )
{
	BYTE* p = outBuffer;
	memcpy(p,m_sign,5);
	p+= 5;
	memcpy(p,&m_ver,2);
	p+= 2;
	memcpy(p,m_sn_sign,2);
	p+= 2;
	memcpy(p,m_sn,100);
	p+=100;
	memcpy(p,m_cpy,7);
	p+=7;
	memcpy(p,m_company,100);
	p+=100;
	return (int)(p - outBuffer);
}

bool CSoBind::FromByte( const BYTE*inBuffer )
{
	BYTE* p = (BYTE*)inBuffer;
	memcpy(m_sign,p,5);
	p+= 5;
	memcpy(&m_ver,p,2);
	p+= 2;
	//进行版本判断
	if (memcmp(m_sign,SOBINDSIGN,5) != 0 || m_ver != 1)
	{
		return false;
	}
	memcpy(m_sn_sign,p,2);
	p+= 2;
	memcpy(m_sn,p,100);
	p+=100;
	memcpy(m_cpy,p,7);
	p+=7;
	memcpy(m_company,p,100);

	return true;
}

int CSoBind::ToEncByte( BYTE *outBuffer, BYTE *key, int len  )
{
	BYTE *temp = new BYTE[m_size];
	memset(temp,0,m_size);
	ToByte(temp);
	//加密
	CDesEnc enc; 
	if (enc.ChangeToBlackText(key,len,temp,m_size,outBuffer))
	{
		return m_size;
	}
	return 0;
}

bool CSoBind::FromEncByte( const BYTE* inBuffer, BYTE *key, int len )
{
	CDesEnc dec; 
	BYTE *decTemp = new BYTE[m_size];
	if (dec.ChangeToWhiteText(key,len,(BYTE*)inBuffer,m_size,decTemp))
	{
//		logger.DEBUG("decTemp:%s",(char*)decTemp);
		return FromByte(decTemp);
	}
	return false;
}
