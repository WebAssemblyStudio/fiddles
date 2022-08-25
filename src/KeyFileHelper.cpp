// CKeyFileHelper.cpp: implementation of the CKeyFileHelper class.
//
//////////////////////////////////////////////////////////////////////
#include "KeyFileHelper.h"
#include "string.h"
#include<iostream>
void KEY_FILE::Initialize()
{
	hwType	= 0;
	memset(hwCode , 0 , 31);

	hardTable.clear();	
	keyTable.clear();
	memset(createTime , 0 , 25);
#ifdef __FULLVER_NEW
	memset(startTime, 0, 25);
	memset(endTime, 0, 25);
#else
	//	startTime	= 0;					
	//	endTime		= 0;
#endif
	nMainKeyID	= 0;							
	bMainKeyExist	= false;			
	bUseTimeExist	= false;
	//	nBindNum ＝ 1;//add by kejun 2010-04-07			
}
bool KEY_FILE::IsHaveInfo()
{
	if(0 == hardTable.size())
		return false;
	if(0 == keyTable.size())
		return false;
// 	if(0 == strlen(createTime))
// 		return false;
	if(0 == strlen(startTime))
		return false;
	if(0 == strlen(endTime))
		return false;
	return true;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CKeyFileHelper::CKeyFileHelper()
{
    m_nErrCode = 0;
}

CKeyFileHelper::~CKeyFileHelper()
{

}

bool CKeyFileHelper::EncryMode1( unsigned char *buf, int len )
{
	EncryByBit1( buf, len, 5 );
	return 0;
}

bool CKeyFileHelper::DeEncryMode1( unsigned char *buf, int len )
{
	DeEncryByBit1( buf, len, 5 );
	return 0;
}


//将aByte的奇数位(1357位)压缩到high的高4位中
void CKeyFileHelper::GetOdd2High( unsigned char& high, unsigned char aByte )
{
	high = 0x80;//打开第一位
	high = aByte & high;//截取第1位到n的��1位
	high |= 0x40;//打开第二位
	high = ((aByte | 0xc0) << 1) & high;//截取第3位到n的第2位
	high |= 0x20;//打开第三位
	high = ((aByte | 0xF0) << 2) & high;//截取第5位到n的第3位
	high |= 0x10;//打开第四位
	high = ((aByte | 0xFC) << 3) & high;//截取第7位到n的第4位
}

//将aByte的高4位保存到odd的1357位中
void CKeyFileHelper::GetHigh2Odd( unsigned char& odd, unsigned char aByte )
{
	odd = 0x80;//打开第1位1000 0000
	odd = aByte & odd;//第1位保存到第1位
	odd |= 0x20;//打开第3位0010 0000
	odd = (aByte >> 1 | 0xc0) & odd;//第2位保存到第3位
	odd |= 0x8;//打开第5位0000 1000
	odd = (aByte >> 2 | 0xf0) & odd;//第3位保存到第5位
	odd |= 0x2;//打开第7位0000 0010
	odd = (aByte >> 3 | 0xfc) & odd;//第4位保存到第7位
}

//在data中每个pos位置插入一个key中的字节
//void CKeyFileHelper::InsertCode( char *data, int dLen, char *key, int kLen, int pos )
//{
//	int i,j,k;
//	char buffer[10240];
//	for( i = j = k = 0; i < dLen; )
//	{
//		for ( int l = 0; l < pos; l++ )
//		{
//			buffer[k++] = data[i++];
//		}
//		buffer[k++] = key[j++];
//		j = j < kLen?j:0;
//	}
//	buffer[k] = '\0';
//	strcpy( (char*)data, (char*)buffer );
//	//	WriteLog( "test.txt", "w", buf );
//	int nLen = strlen((char*)data);
//	a( "test", (char*)data );
//	return;
//}

//将data中每个字节的每个位打乱，方式1
/*
	1.对每个BYTE取出1357位存于自身的低4位，
	2.取出2468位存于另一个字节流的相同位置的字节的BYTE的高4位，
	3.将生成的字节流向右平移distance个单位
	4.平移后字节流与原字节流进行或(|)运算
*/
void CKeyFileHelper::EncryByBit1( unsigned char *data, int len, int distance )
{
	int index;
	unsigned char *pEven;
	pEven = new unsigned char[len + 1];
	//生成分别包含1357和2468位数据的2个字节流,直接保存到平移后的位置
	int pos;//平移后的位置
	distance = distance % len;
	for ( index = 0, pos = distance; index < len; index++ )
	{
		pos = pos < len?pos:0;
		GetEven2High( pEven[pos++], data[index] );
		GetOdd2Low( data[index], data[index] );
	}
	//逐位进行或操作
	for ( index = 0; index < len; index++ )
	{
		data[index] |= pEven[index];
	}
	delete[]pEven;

	return;
}

bool CKeyFileHelper::DeEncryByBit1( unsigned char *data, int len, int distance )
{
	int index;
	unsigned char *pEven;
	pEven = new unsigned char[len + 1];
	//生成分别包含1357和2468位数据的2个字节流,直接保存到平移前的位置
	int pos;//平移后的位置
	distance = distance % len;
	for ( index = 0, pos = len - distance; index < len; index++ )
	{
		pos = pos > len-1?0:pos;
		GetHigh2Even( pEven[pos++], data[index] );
		GetLow2Odd( data[index], data[index] );
	}
	//逐位进行或操作
	for ( index = 0; index < len; index++ )
	{
		data[index] |= pEven[index];
	}
	delete[]pEven;

	return true;
}


bool CKeyFileHelper::GetEncryMode( const char *fileName, int &mode )
{
    CFileUtil file;
    
    
    if(false == file.OpenFile(fileName, "rb"))
    {
        return false;
    }
	Byte buf[1025];
	if ( ReadStreamInF( &file, buf, 0 ) <= 0 ) return false;
	sscanf( (char*)buf, "[encry mode]\t\t\t%d", &mode );
	//sscanf_s( (char*)buf, "[encry mode]\t\t\t%d", &mode );

	if ( mode < 0 || mode > 1 ) return false;
	return true;
}

//int CKeyFileHelper::ReadStreamInF( FILE *fp, BYTE *stream, int mode )
//{	
//	int len;
//	BYTE str_len[11];
//	int retVal,readC;
//	memset( str_len, 0, sizeof str_len );
//	readC = fread( str_len, sizeof (BYTE), 4, fp );
//	if ( ferror( fp ) == 1 || feof( fp ) == 1 ) return -1;
//	str_len[4] = '\0';
//	sscanf( (char*)str_len, "%d", &len );
//	retVal = fread( stream, sizeof (BYTE), len, fp );
//	if ( ferror( fp ) == 1 || feof( fp ) == 1 ) return -1;
//	switch ( mode )
//	{
//	case 0:
//		break;
//	case 1:
//		DeEncryMode1( stream, len );
//		break;
//	default:
//		break;
//	}
//	stream[len] = '\0';
//	return retVal;
//}
//bool CKeyFileHelper::GetHWCode( char *fileName, char *hwCode )
//{
//	//取得加密模式
//	int mode;
//	if ( !GetEncryMode( fileName, mode ) ) return false;
//
//	//打开文件
//	FILE *fp;
//	fp = fopen( fileName, "rb" );
//	if ( fp == NULL ) return false;
//	//跳过加密模式的解析
//	BYTE buf[1025];
//	ReadStreamInF( fp, buf, 0 );
//	while ( 1 )
//	{
//		if ( ReadStreamInF( fp, buf, mode ) <= 0 )
//			break;
//		if ( strstr( (char*)buf, "[hardware No]" ) != NULL )
//		{
//			sscanf( (char*)buf, "[hardware No]\t\t\t%s", hwCode );
//			fclose( fp );
//			return true;
//		}
//	}
//	fclose( fp );
//	return false;
//}
//
//bool CKeyFileHelper::GetHWType(char *fileName, int &hwType)
//{
//	//取得加密模式
//	int mode;
//	if ( !GetEncryMode( fileName, mode ) ) return false;
//	
//	//打开文件
//	FILE *fp;
//	fp = fopen( fileName, "rb" );
//	if ( fp == NULL ) return false;
//	//跳过加密模式的解析
//	BYTE buf[1025];
//	ReadStreamInF( fp, buf, 0 );
//	while ( 1 )
//	{
//		if ( ReadStreamInF( fp, buf, mode ) <= 0 )
//			break;
//		if ( strstr( (char*)buf, "[hardware type]" ) != NULL )
//		{
//			sscanf( (char*)buf, "[hardware type]\t\t\t%d", &hwType );			
//			fclose( fp );
//			return true;
//		}
//	}
//	fclose( fp );
//	return false;
//}
//
//bool CKeyFileHelper::GetHWKeyTable( char *fileName, std::vector<UNIT_KEY> &keyTable )
//{
//	//取得加密模式
//	int mode;
//	if ( !GetEncryMode( fileName, mode ) ) return false;
//	
//	//打开文件
//	FILE *fp;
//	fp = fopen( fileName, "rb" );
//	if ( fp == NULL ) return false;
//	//跳过加密模式的解析
//	BYTE buf[1025];
//	ReadStreamInF( fp, buf, 0 );
//	UNIT_KEY aKey;
//	while ( 1 )
//	{
//		if ( ReadStreamInF( fp, buf, mode ) <= 0 )
//			break;
//		if ( strstr( (char*)buf, "[unit key]" ) != NULL )
//		{
//			sscanf( (char*)buf, "[unit key]\t\t\t%d\t\t\t%d\t\t\t%s", &(aKey.id), &(aKey.len), aKey.key );
//			int i,j,tc;
//			for ( j = tc = 0; tc < 9 ; j++ )
//			{
//				if ( buf[j] == '\t' ) tc++;
//			}
//			for ( i = 0; i < aKey.len; aKey.key[i] = '\0' )
//			{
//				aKey.key[i++] = buf[j++];
//			}
//			keyTable.push_back( aKey );
//		}
//	}
//	return true;
//}
//
//bool CKeyFileHelper::GetFileTime( char *fileName, char *dataAndTime )
//{
//	//取得加密模式
//	int mode;
//	if ( !GetEncryMode( fileName, mode ) ) return false;
//	
//	//打开文件
//	FILE *fp;
//	fp = fopen( fileName, "rb" );
//	if ( fp == NULL ) return false;
//	//跳过加密模式的解析
//	BYTE buf[1025];
//	ReadStreamInF( fp, buf, 0 );
//	char strDay[25],strTime[25];
//	while ( 1 )
//	{
//		if ( ReadStreamInF( fp, buf, mode ) <= 0 )
//			break;
//		if ( strstr( (char*)buf, "[file create time]" ) != NULL )
//		{
//			sscanf( (char*)buf, "[file create time]\t\t\t%s %s", strDay, strTime );
//			sprintf( dataAndTime, "%s %s", strDay, strTime );
//			fclose( fp );
//			return true;
//		}
//	}
//	fclose( fp );
//	return false;
//}

//将一个流加密并写入文件
bool CKeyFileHelper::WriteStream2F(CFileUtil *pfile, Byte *stream, int len, int mode )
{
	int wLen;//欲写入字节数
	char strLen[5];//流长度字符表示
	wLen = sprintf( strLen, "%d", len );
	//wLen = sprintf_s( strLen, _countof(strLen), "%d", len );
	char strFillC[5] = "0000";//填充字节数不足的位
    
	unsigned long dwIOSize;
	if ( wLen < 4 )//填充字节数不足的位
	{
		//WriteFile( fHandle, strFillC, 4 - wLen, &dwIOSize, NULL );
         pfile->WriteFile(strFillC, 4 - wLen,&dwIOSize);
		if ( 4 - wLen != dwIOSize ) return false;
	}
	//WriteFile( fHandle, strLen, wLen, &dwIOSize, NULL );//写入流长度
    pfile->WriteFile(strLen, wLen,&dwIOSize);//写入流长度
	if ( wLen != dwIOSize ) return false;
	
	CKeyFileHelper encrior;
	//流加密
	switch ( mode )
	{
	case 0:
		break;
	case 1:
		encrior.EncryMode1( stream, len );
		break;
	default:
		break;
	}
	//WriteFile( fHandle, stream, len, &dwIOSize, NULL );//写入流长度
    pfile->WriteFile((char*)stream, len,&dwIOSize);//写入流长度
	if ( len != dwIOSize ) return false;
	return true;
}

//内存连接
void CKeyFileHelper::memcat( Byte *buf1, int &len1, const Byte *buf2, int len2 )
{
	int i;
	for ( i = 0; i < len2; i++ )
	{
		buf1[len1++] = buf2[i];
	}
	return;
}

/*
HANDLE hFile = CreateFile( 
m_pszFullFileName, 
GENERIC_READ,
NULL,NULL,
OPEN_EXISTING,
FILE_ATTRIBUTE_NORMAL,NULL);
if ( INVALID_HANDLE_VALUE == hFile ) return false;
*/

//创建密钥文件
bool CKeyFileHelper::CreateKeyFile( int modeIndex , const KEY_FILE &keyInf, const char *strFilePathName )
{
	int buf_len;//写入流长度
	char buf[513];//写入流内容
	
	//写入加密模式ID
	/*HANDLE hFile = NULL;
	hFile = CreateFile( strFilePathName, GENERIC_WRITE, 
		NULL, NULL, CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL  );
	if ( INVALID_HANDLE_VALUE == hFile ) return false;
     */
    CFileUtil file;

    if(false == file.OpenFile(strFilePathName, "wb+"))
    {
        return false;
    }
    CFileUtil * hFile = &file;

	buf_len = sprintf( buf, "[encry mode]\t\t\t%d" , modeIndex );
	//buf_len = sprintf_s( buf, _countof(buf), "[encry mode]\t\t\t%d" , modeIndex );
	WriteStream2F( hFile , (Byte*)buf , buf_len , 0 );
	
	//写入绑定硬件
	int i = 0, n = 	keyInf.hardTable.size();
	//写入硬件数
	buf_len = sprintf( buf, "[hardware count]\t\t\t%d" , n );
	//buf_len = sprintf_s( buf, _countof(buf), "[hardware count]\t\t\t%d" , n );
	WriteStream2F( hFile , (Byte*)buf , buf_len , modeIndex );
	//写入硬件信息
	for ( i = 0; i < n; i++ )
	{
		//写入绑定类型
		buf_len = sprintf( buf, "[hardware type]\t\t\t%d" , keyInf.hardTable[i].hwType );
		//buf_len = sprintf_s( buf, _countof(buf), "[hardware type]\t\t\t%d" , keyInf.hardTable[i].hwType );
		WriteStream2F( hFile , (Byte*)buf , buf_len , modeIndex );
		
		//写入硬件码
		buf_len = sprintf( buf, "[hardware No]\t\t\t%s", keyInf.hardTable[i].hwCode );
		//buf_len = sprintf_s( buf, _countof(buf), "[hardware No]\t\t\t%s", keyInf.hardTable[i].hwCode );
		WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );
	}
	
	//写入密钥
	n = keyInf.keyTable.size();
	//写入密钥数
	buf_len = sprintf( buf, "[key count]\t\t\t%d" , n );
	//buf_len = sprintf_s( buf, _countof(buf), "[key count]\t\t\t%d" , n );
	WriteStream2F( hFile , (Byte*)buf , buf_len , modeIndex );
	//写入密钥信息
	for ( i = 0; i < n; i++ )
	{

		buf_len = sprintf( buf, "[unit key]\t\t\t%d\t\t\t%d\t\t\t",
						   (int)keyInf.keyTable[i].id, keyInf.keyTable[i].len );
		/*buf_len = sprintf_s( buf, _countof(buf), "[unit key]\t\t\t%d\t\t\t%d\t\t\t",
			keyInf.keyTable[i].id, keyInf.keyTable[i].len );*/
		memcat( (Byte*)buf, buf_len, keyInf.keyTable[i].key, keyInf.keyTable[i].len );
		WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入密钥
	}
	//写入当前时间
	time_t curtime;
	time( &curtime );
	tm *curtime_tm = localtime( &curtime );
	char strTime[128];
	strftime( strTime, sizeof strTime, "%Y-%m-%d %H:%M:%S", curtime_tm );
	buf_len = sprintf( buf, "[file create time]\t\t\t%s", strTime );
	//buf_len = sprintf_s( buf, _countof(buf), "[file create time]\t\t\t%s", strTime );
	WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入时间

	//写入主密钥
	buf_len = sprintf( buf, "[main key id]\t\t\t%d", keyInf.nMainKeyID );
	//buf_len = sprintf_s( buf, _countof(buf), "[main key id]\t\t\t%d", keyInf.nMainKeyID );
	WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入时间

	//写入开始时间
	buf_len = sprintf( buf, "[start time]\t\t\t%lf", keyInf.startTime );
	//buf_len = sprintf_s( buf, _countof(buf),"[start time]\t\t\t%lf", keyInf.startTime );
	WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入时间
	
	//写入结束���间
	buf_len = sprintf( buf, "[end time]\t\t\t%lf", keyInf.endTime );
	//buf_len = sprintf_s( buf, _countof(buf), "[end time]\t\t\t%lf", keyInf.endTime );
	WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入时间
	
	//写入密钥描述信息
	buf_len = sprintf( buf, "[keydesc count]\t\t\t%d" , n );
	//buf_len = sprintf_s( buf, _countof(buf), "[keydesc count]\t\t\t%d" , n );
	WriteStream2F( hFile , (Byte*)buf , buf_len , modeIndex );
	//写入密钥信息
	for ( i = 0; i < n; i++ )
	{
		//buf_len = sprintf_s( buf, _countof(buf), "[unit keydesc]\t\t\t%d\t\t\t%d\t\t\t",
		//	keyInf.keyTable[i].id, strlen(keyInf.keyTable[i].keyDes));
        buf_len = sprintf( buf,  "[unit keydesc]\t\t\t%d\t\t\t%d\t\t\t",
                            keyInf.keyTable[i].id, (int)strlen(keyInf.keyTable[i].keyDes));
		memcat( (Byte*)buf, buf_len, (Byte*)keyInf.keyTable[i].keyDes, strlen(keyInf.keyTable[i].keyDes) );
		WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入密钥描述
	}

	file.CloseFile();//CloseHandle( hFile );
	return true;
}



//从fHandle中读一条加密流并解密
int CKeyFileHelper::ReadStreamInF( CFileUtil *pfile, Byte *stream, int mode )
{
	int len;
	Byte str_len[11];
	unsigned long dwIOSize;

	memset( str_len, 0, sizeof str_len );
	//ReadFile( fHandle, (char*)str_len, 4, &dwIOSize);
    pfile->ReadFile((char*)str_len, 4, &dwIOSize);
	if ( 4 != dwIOSize ) return -1;

	str_len[4] = '\0';
	sscanf( (char*)str_len, "%d", &len );
	//sscanf_s( (char*)str_len, "%d", &len );
	//ReadFile( fHandle, (char*)stream, len, &dwIOSize);
    pfile->ReadFile((char*)stream, len, &dwIOSize);
	if ( len != dwIOSize ) return -1;

	switch ( mode )
	{
	case 0:
		break;
	case 1:
		DeEncryMode1( stream, len );
		break;
	default:
		break;
	}
	stream[len] = '\0';
	return (int)dwIOSize;
}

bool CKeyFileHelper::FillKeyFileStructOld( KEY_FILE &fileBuf, char *fileName )
{	
	fileBuf.bMainKeyExist = false;
	fileBuf.bUseTimeExist = false;
	//打开文件
	/*HANDLE hFile = CreateFileA(
		fileName,
		GENERIC_READ,
		NULL,NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,NULL);
	if ( INVALID_HANDLE_VALUE == hFile )
	{
		//modified by lhh 2006-10
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();

		return false;
	}*/
    CFileUtil file;
    if(false == file.OpenFile(fileName, "rb"))
    {
        return false;
    }
    CFileUtil *infilehandle = &file;

	int i = 0;
	Byte buf[1025];//信息流缓冲区
	char strLong[21];
	int index = 0, dataSize = 0,tabCount = 0;

	//取得加密模式
	if ( ( dataSize = ReadStreamInF( infilehandle, buf, 0 ) ) == -1 )//读取一个字节流
	{
        file.CloseFile();
		//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	if ( strstr( (char*)buf, "[encry mode]" ) == NULL )//检查字段标题
	{
        file.CloseFile();
		//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
		
	int mode;
	for ( tabCount = index = 0; index < dataSize; index++ )//移动3个tab之后
	{
		if ( tabCount == 3 ) break;
		if ( buf[index] == '\t' ) tabCount++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
	{
		//::CloseHandle( hFile );
        file.CloseFile();
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	mode = 0;
	i = 0;
	while ( index < dataSize )//一直到流末尾为实际数据
	{
		strLong[i] = buf[index];
		index++;
		i++;
	}
	strLong[i] = '\0';
	mode = atol( strLong );

	//取得硬件类型
	if ( ( dataSize = ReadStreamInF( infilehandle, buf, mode ) ) == -1 )//读取一个字节流
	{
		//::CloseHandle( hFile );
        file.CloseFile();
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	if ( strstr( (char*)buf, "[hardware type]" ) == NULL )//检查字段标题
	{
		//::CloseHandle( hFile );
        file.CloseFile();
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	for ( tabCount = index = 0; index < dataSize; index++ )//移动3个tab之后
	{
		if ( tabCount == 3 ) break;
		if ( buf[index] == '\t' ) tabCount++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
	{
		//::CloseHandle( hFile );
       file.CloseFile();
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	fileBuf.hwType = 0;
	i = 0;
	while ( index < dataSize )//一直到流末尾为实际数据
	{
		strLong[i] = buf[index];
		index++;
		i++;
	}
	strLong[i] = '\0';
	fileBuf.hwType = atol( strLong );
	
	//取得硬件码
	if ( ( dataSize = ReadStreamInF( infilehandle, buf, mode ) ) == -1 )//读取一个字节流
	{
		//::CloseHandle( hFile );
        file.CloseFile();
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	if ( strstr( (char*)buf, "[hardware No]" ) == NULL )//检查字段标题
	{
		//::CloseHandle( hFile );
        file.CloseFile();
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	for ( tabCount = index = 0; index < dataSize; index++ )//移动3个tab之后
	{
		if ( tabCount == 3 ) break;
		if ( buf[index] == '\t' ) tabCount++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
	{
		//::CloseHandle( hFile );
        file.CloseFile();
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	for ( i = 0; index < dataSize; i++ )//一直到流末尾为实际数据
	{
		fileBuf.hwCode[i] = buf[index];
		index++;
	}
	fileBuf.hwCode[i] = '\0';
	//也记录到新版增加成员中
	HARD_INF hardInf;
	hardInf.hwType = fileBuf.hwType;
	strcpy( hardInf.hwCode, fileBuf.hwCode );
	//strcpy_s( hardInf.hwCode, _countof(hardInf.hwCode), fileBuf.hwCode );
	fileBuf.hardTable.push_back( hardInf );

	//取密钥
	UNIT_KEY aKey;
	while ( 1 )
	{
		if ( ( dataSize = ReadStreamInF(infilehandle, buf, mode ) ) == -1 )//读取一个字节流
		{
            file.CloseFile();
			//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
			return false;
		}
		if ( strstr( (char*)buf, "[unit key]" ) != NULL )//检查字段标题
		{
			//取ID
			for ( tabCount = index = 0; index < dataSize; index++ )//移动3个tab之后
			{
				if ( tabCount == 3 ) break;
				if ( buf[index] == '\t' ) tabCount++;
			}
			if ( tabCount < 3 )//tab少于3个文件格式不合法
			{
				file.CloseFile();//::CloseHandle( hFile );
				//memset( &fileBuf, 0, sizeof fileBuf );
				fileBuf.Initialize();
				return false;
			}
			for ( aKey.id = i = 0; index < dataSize && buf[index] != '\t'; index++, i++ )//下一个数据前有3个tab
			{
				strLong[i] = buf[index];
			}
			strLong[i] = '\0';
			aKey.id = atol( strLong );
			//取长度
			tabCount = 1;
			index++;
			while ( index < dataSize && tabCount < 3 && buf[index] == '\t')//移动3个tab之后
			{
				tabCount++;
				index++;
			}
			if ( tabCount < 3 )//tab少于3个文件格式不合法
			{
				file.CloseFile();//::CloseHandle( hFile );
				//memset( &fileBuf, 0, sizeof fileBuf );
				fileBuf.Initialize();
				return false;
			}
			for ( aKey.len = i = 0; index < dataSize && buf[index] != '\t'; index++, i++ )//下一个数据前有3个tab
			{
				strLong[i] = buf[index];
			}
			strLong[i] = '\0';
			aKey.len = atol( strLong );
			//取内容
			tabCount = 1;
			index++;
			while ( index < dataSize && tabCount < 3 && buf[index] == '\t')//移动3个tab之后
			{
				tabCount++;
				index++;
			}
			if ( tabCount < 3 )//tab少于3个文件格式不合法
			{
				file.CloseFile();//::CloseHandle( hFile );
				//memset( &fileBuf, 0, sizeof fileBuf );
				fileBuf.Initialize();
				return false;
			}
			for (  i = 0; index < dataSize; index++, i++ )//一直到流末尾为实际密钥
			{
				aKey.key[i] = buf[index];
			}
			aKey.key[i] = '\0';
			if ( i != aKey.len )//密钥实际长度和读取长度不等文件破坏
			{
				file.CloseFile();//::CloseHandle( hFile );
				//memset( &fileBuf, 0, sizeof fileBuf );
				fileBuf.Initialize();
				return false;
			}
			fileBuf.keyTable.push_back( aKey );
			continue;
		}
		//取创建时间
		if ( strstr( (char*)buf, "[file create time]" ) == NULL )//检查字段标题
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
			return false;
		}
		for ( tabCount = index = 0; index < dataSize; index++ )//移动3个tab之后
		{
			if ( tabCount == 3 ) break;
			if ( buf[index] == '\t' ) tabCount++;
		}
		if ( tabCount < 3 )//tab少于3个文件格式不合法
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
			return false;
		}
		for ( i = 0; index < dataSize; i++ )//一直到流末尾为实际数据
		{
			fileBuf.createTime[i] = buf[index];
			index++;
		}
		fileBuf.createTime[i] = '\0';
		break;
	}
	file.CloseFile();//::CloseHandle( hFile );
	return true;
}

//从新格式的密钥文件读取信息填充KEY_FILE结构
bool CKeyFileHelper::FillKeyFileStructNew( KEY_FILE &fileBuf, char * fileName)
{	
	fileBuf.bMainKeyExist = true;
	fileBuf.bUseTimeExist = true;
	//打开文件
	/*HANDLE hFile = CreateFile(
		fileName, 
		GENERIC_READ,
		NULL,NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,NULL);
	if ( INVALID_HANDLE_VALUE == hFile )
	{
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}*/
    CFileUtil file;
    if(false == file.OpenFile(fileName, "rb"))
    {
        return false;
    }
    CFileUtil * hFile = &file;

	int i = 0;
	Byte buf[1025];//信息流缓冲区
	int index = 0, dataSize = 0, tabCount = 0;

	//取得加密模式
	if ( ( dataSize = ReadStreamInF( hFile, buf, 0 ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	//提取信息
	int mode;
	if ( !GetStreamInf( (char*)buf, dataSize, "[encry mode]", mode ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}

	//取得绑定硬件数
	if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	//提取信息
	int nCount;
	if ( !GetStreamInf( (char*)buf, dataSize, "[hardware count]", nCount ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}

	//读取所有硬件信息
	HARD_INF hardInf;
	for ( i = 0; i < nCount; i++ )
	{
		//取得硬件类型
		if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
			return false;
		}
		if ( !GetStreamInf( (char*)buf, dataSize, "[hardware type]", hardInf.hwType ) )
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
			return false;
		}
		
		//取得硬件码
		if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
			return false;
		}
		if ( !GetStreamInf( (char*)buf, dataSize, "[hardware No]", hardInf.hwCode ) )
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
			return false;
		}
		fileBuf.hardTable.push_back( hardInf );
	}
	
	//取密钥
	//取得密钥数
	if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[key count]", nCount ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	//取密钥信息
	UNIT_KEY aKey;
	for ( i = 0; i < nCount; i++ )
	{
		if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
			return false;
		}
		if ( !GetStreamInf( (char*)buf, dataSize, "[unit key]", aKey ) )
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
			return false;
		}
		fileBuf.keyTable.push_back( aKey );
	}

	//取创建时间
	if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[file create time]", fileBuf.createTime ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	
	//取主密钥
	if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[main key id]", fileBuf.nMainKeyID ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	
	//取开始时间
	if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[start time]", fileBuf.startTime ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	
	//取结束时间
	if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[end time]", fileBuf.endTime ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}
	
	file.CloseFile();//CloseHandle( hFile );
	return true;
}

#ifdef __FULLVER_NEW
bool CKeyFileHelper::FillKeyFileStructNew_to( KEY_FILE &fileBuf, char *fileName )
{
    m_nErrCode = PI_E_UNKONWN;
	fileBuf.bMainKeyExist = false;
	fileBuf.bUseTimeExist = false;
	//打开文件
	/*HANDLE hFile = CreateFile(
		fileName, 
		GENERIC_READ,
		NULL,NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,NULL);
	if ( INVALID_HANDLE_VALUE == hFile )
	{
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
		return false;
	}*/
    CFileUtil file;

    if(false == file.OpenFile(fileName, "rb"))
    {
        m_nErrCode = PI_E_PKY_OPEN_FILE_ERROR;
        return false;
    }

	int i = 0;
	Byte buf[1025];//信息流缓冲区
	int index = 0, dataSize = 0, tabCount = 0;

	//取得加密模式
	if ( ( dataSize = ReadStreamInF( &file, buf, 0 ) ) == -1 )//读取一个字节流
	{
        file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_ENC_MODEL_ERROR;
		return false;
	}
	//提取信息
	int mode;
	if ( !GetStreamInf( (char*)buf, dataSize, "[encry mode]", mode ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_ENC_MODEL_ERROR;
		return false;
	}
	//[bind num]
	//取得限定绑定的硬件数
	if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_BIND_COUNT_ERROR;
		return false;
	}
	//提取信息
	if ( !GetStreamInf( (char*)buf, dataSize, "[bind num]", fileBuf.nBindNum ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
        fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_BIND_COUNT_ERROR;
		return false;
	}

	//取得绑定硬件数
	if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_HARDWARE_COUNT_ERROR;
		return false;
	}
	//提取信息
	int nCount;
	if ( !GetStreamInf( (char*)buf, dataSize, "[hardware count]", nCount ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_HARDWARE_COUNT_ERROR;
		return false;
	}

	//读取所有硬件信息
	HARD_INF hardInf;
	for ( i = 0; i < nCount; i++ )
	{
		//取得硬件类型
		if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
            m_nErrCode = PI_E_PKY_READ_HARDWARE_TYPE_ERROR;
			return false;
		}
		if ( !GetStreamInf( (char*)buf, dataSize, "[hardware type]", hardInf.hwType ) )
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
            m_nErrCode = PI_E_PKY_READ_HARDWARE_TYPE_ERROR;
			return false;
		}

		//取得硬件码
		if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
            m_nErrCode = PI_E_PKY_READ_HARDWARE_NUMBER_ERROR;
			return false;
		}
		if ( !GetStreamInf( (char*)buf, dataSize, "[hardware No]", hardInf.hwCode ) )
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
            m_nErrCode = PI_E_PKY_READ_HARDWARE_NUMBER_ERROR;
			fileBuf.Initialize();
			return false;
		}
		fileBuf.hardTable.push_back( hardInf );
	}

	//取密钥
	//取得密钥数
	if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_KEY_COUNT_ERROR;
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[key count]", nCount ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_KEY_COUNT_ERROR;
		return false;
	}
	//取密钥信息
	UNIT_KEY aKey;
	for ( i = 0; i < nCount; i++ )
	{
		if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
            m_nErrCode = PI_E_PKY_READ_KEY_INFO_ERROR;
			return false;
		}
		if ( !GetStreamInf( (char*)buf, dataSize, "[unit key]", aKey ) )
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
            m_nErrCode = PI_E_PKY_READ_KEY_INFO_ERROR;
			return false;
		}
		fileBuf.keyTable.push_back( aKey );
	}

	//取创建时间
	if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_CREATE_TIME_ERROR;
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[file create time]", fileBuf.createTime ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_CREATE_TIME_ERROR;
		return false;
	}

	//取主密钥
	if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_MAIN_KEY_ID_ERROR;
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[main key id]", fileBuf.nMainKeyID ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_MAIN_KEY_ID_ERROR;
		return false;
	}

	//取开始时间
	if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_START_TIME_ERROR;
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[start time]", fileBuf.startTime ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_START_TIME_ERROR;
		return false;
	}

	//取结束时间
	if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_END_TIME_ERROR;
		return false;
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[end time]", fileBuf.endTime ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_END_TIME_ERROR;
		return false;
	}
	//获取密钥描述总数
	if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		//fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_KEY_DES_COUNT_ERROR;
		return true;	//密钥描述若没有,那么不需要管
	}
	if ( !GetStreamInf( (char*)buf, dataSize, "[keydesc count]", nCount ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		//memset( &fileBuf, 0, sizeof fileBuf );
		fileBuf.Initialize();
        m_nErrCode = PI_E_PKY_READ_KEY_DES_COUNT_ERROR;
        return false;
	}
	//获取密钥描述
	//UNIT_KEY aKey;
	for ( i = 0; i < nCount; i++ )
	{
		if ( ( dataSize = ReadStreamInF( &file, buf, mode ) ) == -1 )//读取一个字节流
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
            m_nErrCode = PI_E_PKY_READ_KEY_DESCRIPTION_ERROR;
			return false;
		}
		if ( !GetStreamInf( (char*)buf, dataSize, "[unit keydesc]", aKey ) )
		{
			file.CloseFile();//::CloseHandle( hFile );
			//memset( &fileBuf, 0, sizeof fileBuf );
			fileBuf.Initialize();
            m_nErrCode = PI_E_PKY_READ_KEY_DESCRIPTION_ERROR;
			return false;
		}
		//此处借用密钥的结构来填充密钥描述
#ifdef UNICODE
		AnsiToUc((char*)aKey.key,aKey.keyDes);
#else
		strcpy(aKey.keyDes, (const char*)aKey.key);
#endif
		std::vector<UNIT_KEY>::iterator it;
		for (it = fileBuf.keyTable.begin();it!= fileBuf.keyTable.end();it++)
		{
			UNIT_KEY &selKey = *it;
			if (selKey.id == aKey.id)
			{
				strcpy(selKey.keyDes,aKey.keyDes);
			}
		}
	}

	file.CloseFile();//CloseHandle( hFile );
    m_nErrCode = PI_S_SUCCESS;
	return true;

}

bool CKeyFileHelper::CreateKeyFileNew( int modeIndex , const KEY_FILE &keyInf, const char *strFilePathName )
{
	int buf_len;//写入流长度
	char buf[513];//写入流内容

	KEY_FILE keyFile;
	keyFile = keyInf;

	string strTempFile = strFilePathName;
	strTempFile += ".tmp";

	//写入加密模式ID
	/*HANDLE hFile = NULL;
// 	hFile = CreateFile( strFilePathName, GENERIC_WRITE, 
// 		NULL, NULL, CREATE_ALWAYS, 
// 		FILE_ATTRIBUTE_NORMAL, NULL  );
	
	hFile = CreateFileA( strTempFile.c_str(), GENERIC_WRITE, 
 		NULL, NULL, CREATE_ALWAYS, 
 		FILE_ATTRIBUTE_NORMAL, NULL  );

	if ( INVALID_HANDLE_VALUE == hFile ) return false;*/
    CFileUtil file;
    
    if(false == file.OpenFile(strFilePathName, "wb+"))
    {
        return false;
    }
    CFileUtil *hFile = &file;

	buf_len = sprintf( buf, "[encry mode]\t\t\t%d" , modeIndex );
	//buf_len = sprintf_s( buf, _countof(buf), "[encry mode]\t\t\t%d" , modeIndex );
	WriteStream2F( hFile , (Byte*)buf , buf_len , 0 );

	//写入绑定硬件
	int i = 0, n = 	keyInf.hardTable.size();
	////写入允许绑定的次数 add by kejun 2010-04-07
	buf_len = sprintf(buf, "[bind num]\t\t\t%d", keyInf.nBindNum);
    //buf_len = sprintf_s(buf, _countof(buf), "[bind num]\t\t\t%d", keyInf.nBindNum);
	WriteStream2F(hFile, (Byte *)buf, buf_len, modeIndex);
	//写入硬件数
	buf_len = sprintf( buf, "[hardware count]\t\t\t%d" , n );
	//buf_len = sprintf_s( buf, _countof(buf), "[hardware count]\t\t\t%d" , n );
	WriteStream2F( hFile , (Byte*)buf , buf_len , modeIndex );
	//写入硬件信息
	for ( i = 0; i < n; i++ )
	{
		//写入绑定类型
		buf_len = sprintf( buf, "[hardware type]\t\t\t%d" , keyInf.hardTable[i].hwType );
		//buf_len = sprintf_s( buf, _countof(buf), "[hardware type]\t\t\t%d" , keyInf.hardTable[i].hwType );
		WriteStream2F( hFile , (Byte*)buf , buf_len , modeIndex );

		//写入硬件码
		buf_len = sprintf( buf, "[hardware No]\t\t\t%s", keyInf.hardTable[i].hwCode );
		//buf_len = sprintf_s( buf, _countof(buf), "[hardware No]\t\t\t%s", keyInf.hardTable[i].hwCode );
		WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );
	}

	//写入密钥
	n = keyInf.keyTable.size();
	//写入密钥数
	buf_len = sprintf( buf, "[key count]\t\t\t%d" , n );
	//buf_len = sprintf_s( buf, _countof(buf), "[key count]\t\t\t%d" , n );
	WriteStream2F( hFile , (Byte*)buf , buf_len , modeIndex );
	//写入密钥信息
	for ( i = 0; i < n; i++ )
	{

		buf_len = sprintf( buf, "[unit key]\t\t\t%d\t\t\t%d\t\t\t",
		keyInf.keyTable[i].id, keyInf.keyTable[i].len );
		/*buf_len = sprintf_s( buf, _countof(buf), "[unit key]\t\t\t%d\t\t\t%d\t\t\t",
			keyInf.keyTable[i].id, keyInf.keyTable[i].len );*/
		memcat( (Byte*)buf, buf_len, keyInf.keyTable[i].key, keyInf.keyTable[i].len );
		WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入密钥
	}
	//写入当前时间
	time_t curtime;
	time( &curtime );
	tm *curtime_tm = localtime( &curtime );
	char strTime[128];
	strftime( strTime, sizeof strTime, "%Y-%m-%d %H:%M:%S", curtime_tm );
	buf_len = sprintf( buf, "[file create time]\t\t\t%s", strTime );
	//buf_len = sprintf_s( buf, _countof(buf), "[file create time]\t\t\t%s", strTime );
	WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入时间

	//写入主密钥
	buf_len = sprintf( buf, "[main key id]\t\t\t%d", keyInf.nMainKeyID );
	//buf_len = sprintf_s( buf, _countof(buf), "[main key id]\t\t\t%d", keyInf.nMainKeyID );
	WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入时间

	//写入开始时间
	buf_len = sprintf( buf, "[start time]\t\t\t%s", keyInf.startTime );
	//	buf_len = sprintf_s( buf, _countof(buf),"[start time]\t\t\t%lf", keyInf.startTime );
	//buf_len = sprintf_s( buf, _countof(buf), "[start time]\t\t\t%s", keyInf.startTime);
	WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入时间

	//写入结束时间
	buf_len = sprintf( buf, "[end time]\t\t\t%s", keyInf.endTime );
	//	buf_len = sprintf_s( buf, _countof(buf), "[end time]\t\t\t%lf", keyInf.endTime );
	//buf_len = sprintf_s( buf, _countof(buf), "[end time]\t\t\t%s", keyInf.endTime);
	WriteStream2F( hFile, (Byte*)buf, buf_len, modeIndex );//写入时间
 	//FlushFileBuffers(hFile);
	file.CloseFile();//CloseHandle( hFile );

	//if(keyFile.IsHaveInfo())
	//	::MoveFileEx(strTempFile.c_str(),strFilePathName,MOVEFILE_REPLACE_EXISTING);
		
	return true;

}
#endif


bool CKeyFileHelper::FillKeyFileStruct( KEY_FILE &fileBuf, char *fileName )
{
#ifdef __FULLVER_NEW
	//先以新格式读取方式读取，失败则以旧格式读取方式读取
	if ( FillKeyFileStructNew_to( fileBuf, fileName ) ) 
		return true;

	return false;
#else
	if ( FillKeyFileStructNew( fileBuf, fileName ) ) return true;
#endif
	//先以旧格式读取方式读取，失败则以新格式读取方式读取
	return FillKeyFileStructOld( fileBuf, fileName );
}

bool CKeyFileHelper::GetStreamInf( const char *stream, const int nLen, const char *checkName, int &nVal )
{
	if ( strstr( stream, checkName ) == NULL )//检查字段标题
		return false;
	
	int tabCount, index;
	for ( tabCount = index = 0; index < nLen; index++ )//移动3个tab之后
	{
		if ( tabCount == 3 ) break;
		if ( stream[index] == '\t' ) tabCount++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
		return false;
	int i;
	char buf[256];
	for ( i = 0; index < nLen; i++ )//一直到流末尾为实际数据
	{
		buf[i] = stream[index];
		index++;
	}
	buf[i] = '\0';
	nVal = atoi( buf );
	return true;
}

bool CKeyFileHelper::GetStreamInf( const char *stream, const int nLen, const char *checkName, long &lVal )
{
	if ( strstr( stream, checkName ) == NULL )//检查字段标题
		return false;
	
	int tabCount, index;
	for ( tabCount = index = 0; index < nLen; index++ )//移动3个tab之后
	{
		if ( tabCount == 3 ) break;
		if ( stream[index] == '\t' ) tabCount++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
		return false;
	int i;
	char buf[256];
	for ( i = 0; index < nLen; i++ )//一直到流末尾为实际数据
	{
		buf[i] = stream[index];
		index++;
	}
	buf[i] = '\0';
	lVal = atol( buf );
	return true;
}

bool CKeyFileHelper::GetStreamInf( const char *stream, const int nLen, const char *checkName, double &dVal )
{
	if ( strstr( stream, checkName ) == NULL )//检查字段标题
		return false;
	
	int tabCount, index;
	for ( tabCount = index = 0; index < nLen; index++ )//移动3个tab之后
	{
		if ( tabCount == 3 ) break;
		if ( stream[index] == '\t' ) tabCount++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
		return false;
	int i;
	char buf[256];
	for ( i = 0; index < nLen; i++ )//一直到流末尾为实际数据
	{
		buf[i] = stream[index];
		index++;
	}
	buf[i] = '\0';
	dVal = atof( buf );
	return true;
}

bool CKeyFileHelper::GetStreamInf( const char *stream, const int nLen, const char *checkName, char *strVal )
{
	if ( strstr( stream, checkName ) == NULL )//检查字段标题
		return false;
	
	int tabCount, index;
	for ( tabCount = index = 0; index < nLen; index++ )//移动3个tab之后
	{
		if ( tabCount == 3 ) break;
		if ( stream[index] == '\t' ) tabCount++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
		return false;
	int i;
	for ( i = 0; index < nLen; i++ )//一直到流末尾为实际数据
	{
		strVal[i] = stream[index];
		index++;
	}
	strVal[i] = '\0';
	return true;
}

//从一个解密流获取信息
bool CKeyFileHelper::GetStreamInf( const char *stream, const int nLen, const char *checkName, UNIT_KEY &key )
{
	//检查字段标题
	if ( strstr( (char*)stream, checkName ) == NULL ) 
		return false;

	//取ID
	int tabCount, index, i;
	for ( tabCount = index = 0; index < nLen; index++ )//移动3个tab之后
	{
		if ( tabCount == 3 ) break;
		if ( stream[index] == '\t' ) tabCount++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
		return false;
	char strLong[32];//long型字符串空间
	for ( i = 0; index < nLen && stream[index] != '\t'; index++, i++ )//下一个数据前有3个tab
	{
		strLong[i] = stream[index];
	}
	strLong[i] = '\0';
	key.id = atol( strLong );

	//取密钥长度
	tabCount = 1;
	index++;
	while ( index < nLen && tabCount < 3 && stream[index] == '\t')//移动3个tab之后
	{
		tabCount++;
		index++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
		return false;
	for ( i = 0; index < nLen && stream[index] != '\t'; index++, i++ )//下一个数据前有3个tab
	{
		strLong[i] = stream[index];
	}
	strLong[i] = '\0';
	key.len = atol( strLong );

	//取密钥
	tabCount = 1;
	index++;
	while ( index < nLen && tabCount < 3 && stream[index] == '\t' )//移动3个tab之后
	{
		tabCount++;
		index++;
	}
	if ( tabCount < 3 )//tab少于3个文件格式不合法
		return false;
	for (  i = 0; index < nLen; index++, i++ )//一直到流末尾为实际密钥
	{
		key.key[i] = stream[index];
	}
	key.key[i] = '\0';
	if ( i != key.len )//密钥实际长度和读取长度不等文件破坏
		return false;

	return true;
}
bool CKeyFileHelper::KeyFileIsNeedToTransition(char *fileName)
{

	/*HANDLE hFile = CreateFile(
		fileName, 
		GENERIC_READ,
		NULL,NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,NULL);
	if ( INVALID_HANDLE_VALUE == hFile )
	{
		return false;
	}
     */
    CFileUtil file;
    
    if(false == file.OpenFile(fileName, "wb+"))
    {
        return false;
    }
    CFileUtil *hFile = &file;

	int i = 0;
	Byte buf[1025];//信息流缓冲区
	int index = 0, dataSize = 0, tabCount = 0;

	//取得加密模式
	if ( ( dataSize = ReadStreamInF( hFile, buf, 0 ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		return false;
	}

	//提取信息
	int mode;
	if ( !GetStreamInf( (char*)buf, dataSize, "[encry mode]", mode ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		return false;
	}
	//取得版本
	//[version]从95开始表示9.5
	int version = 0;
	if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
	{
		file.CloseFile();//::CloseHandle( hFile );
		return false;
	}
	//提取信息
	if ( !GetStreamInf( (char*)buf, dataSize, "[version]", version ) )
	{
		file.CloseFile();//::CloseHandle( hFile );
		return false;
	}
// 	int vertype = 0;
// 	if ( ( dataSize = ReadStreamInF( hFile, buf, mode ) ) == -1 )//读取一个字节流
// 	{
// 		::CloseHandle( hFile );
// 		return false;
// 	}
// 	//提取信息
// 	if ( !GetStreamInf( (char*)buf, dataSize, "[vertype]",vertype ) )
// 	{
// 		::CloseHandle( hFile );
// 		return false;
// 	}

	if (version >= 95)
	{
		return true;
	}

	return false;

}
/*bool GetKeyValue(unsigned short uKeyId,char*szBuffer,int*lpKeyLen,int *lpErrCode)
{
    if (lpErrCode == NULL) {
        return false;
    }
    if (szBuffer == NULL || lpKeyLen == NULL) {
        *lpErrCode = 11;//输入参数无效
        return false;
    }
    NSString *strPkyPath = @"/Users/piclesoft/pky/Piencsys.pky";
    NSFileManager *manager = [NSFileManager defaultManager];
    bool isExist = [manager fileExistsAtPath:strPkyPath];//判断文件是否存在
    if (isExist == false) {
        NSLog(@"Not exist");
        *lpErrCode = 12;//pky文件不存在
        return false;
    }
    
    const char * pkyFileName =[strPkyPath UTF8String];
    
    CKeyFileHelper keyhelper;
    KEY_FILE fileBuf;
    bool bOk = keyhelper.FillKeyFileStruct( fileBuf, (char*)pkyFileName);
    if (bOk == false)
    {
        *lpErrCode = 13;//解析pky文件失败
        return false;
    }
    for (int i = 0; i<fileBuf.keyTable.size(); i++)
    {
        if ((unsigned short)fileBuf.keyTable[i].id == uKeyId)
        {
            memcpy(szBuffer, fileBuf.keyTable[i].key, fileBuf.keyTable[i].len);
            *lpKeyLen = fileBuf.keyTable[i].len;
            *lpErrCode = 0;//获取密钥成功
            return true;
        }
    }
    *lpErrCode = 14;//未找到指定id的密钥
    return false;
}*/

bool WriteFile(FILE* infile, char *szBuffer, int nNumberOfBytesToWrite,int &nNumberOfBytesWritten)
{
    if (infile == NULL || szBuffer == NULL)
	{
        return false;
    }

	nNumberOfBytesWritten = fwrite(szBuffer, sizeof(char), nNumberOfBytesToWrite, infile);
	if(nNumberOfBytesWritten == nNumberOfBytesToWrite)
		return true;
	else
		return false;

//    NSData *data = [NSData dataWithBytes:szBuffer length:nNumberOfBytesToWrite];
//    int nLen  = int(data.length);
//    if (nLen > 0) {
//        [infile writeData:data];
//    }
//
//    *lpNumberOfBytesWritten = nLen;
//    return true;
}

bool ReadFile(FILE* outfile, char *szBuffer, int nNumberOfBytesToRead,int &nNumberOfBytesRead)
{
	nNumberOfBytesRead = 0;
    if (outfile == NULL || szBuffer == NULL)
    {
        return false;
    }
    nNumberOfBytesRead = fread(szBuffer, sizeof(char), nNumberOfBytesToRead, outfile);
	if(nNumberOfBytesRead == nNumberOfBytesToRead)
		return true;
	else
		return false;
    int nLen = 0;
//    NSData *data = [outfile readDataOfLength:nNumberOfBytesToRead];
//     nLen  = int(data.length);
//    if (nLen <= 0)
//    {
//        return true;
//    }
//    char *buf=(char*)[data bytes];
//    memcpy(szBuffer, buf, nLen);
//    *lpNumberOfBytesRead = nLen;
   
    return true;
}
