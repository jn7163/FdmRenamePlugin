// ChineseConvert.cpp: implementation of the CChineseConvert class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ChineseConvert.h"

#include <windows.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChineseConvert::CChineseConvert()
{

}

CChineseConvert::~CChineseConvert()
{

}

char CChineseConvert::Char2Int(char ch)
{
	if(ch>='0' && ch<='9')return (char)(ch-'0');
	if(ch>='a' && ch<='f')return (char)(ch-'a'+10);
	if(ch>='A' && ch<='F')return (char)(ch-'A'+10);
	return -1;
}

char CChineseConvert::Str2Bin(char *str)
{
	char tempWord[2] = {0};
	char chn;

	tempWord[0] = Char2Int(str[0]);			//make the B to 11 -- 00001011
	tempWord[1] = Char2Int(str[1]);			//make the 0 to 0  -- 00000000

	chn = (tempWord[0] << 4) | tempWord[1];	//to change the BO to 10110000

	return chn;
}

string CChineseConvert::UrlDecode(string str)
{
	string output = "";
	char tmp[2] = {0};
	int i = 0;
	int len = str.length();
        
	while(i < len)
	{
		if(str[i]=='%')
		{
			tmp[0] = str[i+1];
			tmp[1] = str[i+2];
			output += Str2Bin(tmp);
			i += 3;
		}
		else if(str[i]=='+')
		{
			output += ' ';
			i++;
		}
		else
		{
			output += str[i];
			i++;
		}
	}
        
	return output;
}

char* CChineseConvert::UTF8ToGB2312(const char* pStrUTF8)
{
	// ��ת�ɿ��ַ�
	int nStrLen = MultiByteToWideChar(CP_UTF8, 0, pStrUTF8, -1, NULL, 0);
	wchar_t* pWStr = new wchar_t[nStrLen + 1];
	memset(pWStr, 0, nStrLen + 1);
	MultiByteToWideChar(CP_UTF8, 0, pStrUTF8, -1, pWStr, nStrLen);
	
	// ��ת��GB2312
	nStrLen = WideCharToMultiByte(CP_ACP, 0, pWStr, -1, NULL, 0, NULL, NULL);
	char* pStr = new char[nStrLen + 1];
	memset(pStr, 0, nStrLen + 1);
	WideCharToMultiByte(CP_ACP, 0, pWStr, -1, pStr, nStrLen, NULL, NULL);
	if(pWStr)
	{
		delete[] pWStr;
	}

	return pStr;
}

//����url_Utf-8 ,��� gb2312
string CChineseConvert::Url_Utf8ToGB2312(string instr)
{
	string input = UrlDecode(instr);
	string output = UTF8ToGB2312(input.c_str());

	return output;
}

bool CChineseConvert::IsUTF8String(const char* pStr)
{
    int i = 0;
    int nBytes = 0;//UTF8����1-6���ֽڱ���,ASCII��һ���ֽ�
    unsigned char chr = 0;
    bool bAllAscii = true;//���ȫ������ASCII,˵������UTF-8

	int length = strlen(pStr);
	
    while (i < length)
    {
        chr = *(pStr + i);
        if ((chr & 0x80) != 0)
            bAllAscii = false;

        if (nBytes == 0)//�����ֽ���
        {
            if ((chr & 0x80) != 0)
            {
                while ((chr & 0x80) != 0)
                {
                    chr <<= 1;
                    nBytes++;
                }

                if (nBytes < 2 || nBytes > 6)
                    return false;//��һ���ֽ�����Ϊ110x xxxx

                nBytes--;//��ȥ����ռ��һ���ֽ�
            }
        }
        else//���ֽڳ��˵�һ���ֽ���ʣ�µ��ֽ�
        {
            if ((chr & 0xc0) != 0x80)
                return false;//ʣ�µ��ֽڶ���10xx xxxx����ʽ

            nBytes--;
        }

        ++i;
    }

    if (bAllAscii)
        return false;

    return nBytes == 0;
}
