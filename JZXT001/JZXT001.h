// JZXT001.h : JZXT001 DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CJZXT001App
// �йش���ʵ�ֵ���Ϣ������� JZXT001.cpp
//

class CJZXT001App : public CWinApp
{
public:
	CJZXT001App();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
