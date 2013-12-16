// ChineseConvert.h: interface for the CChineseConvert class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHINESECONVERT_H__1515F40D_636D_44CC_8A84_5F979CCE9634__INCLUDED_)
#define AFX_CHINESECONVERT_H__1515F40D_636D_44CC_8A84_5F979CCE9634__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using namespace std;

class CChineseConvert  
{
public:
	CChineseConvert();
	virtual ~CChineseConvert();

	//��UTF-8�����URLר�ø�ʽ�ַ�����ԭ����ͨ�ַ���
	static string Url_Utf8ToGB2312(string instr);
	//UTF-8תGB2312
	static char* UTF8ToGB2312(const char* pStrUTF8);

private:

	static char Char2Int(char ch);	
	static char Str2Bin(char *str);	
	static string UrlDecode(string str);

};

#endif // !defined(AFX_CHINESECONVERT_H__1515F40D_636D_44CC_8A84_5F979CCE9634__INCLUDED_)
