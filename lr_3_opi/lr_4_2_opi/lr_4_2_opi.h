
// lr_4_2_opi.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// Clr_4_2_opiApp:
// � ���������� ������� ������ ��. lr_4_2_opi.cpp
//

class Clr_4_2_opiApp : public CWinApp
{
public:
	Clr_4_2_opiApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern Clr_4_2_opiApp theApp;