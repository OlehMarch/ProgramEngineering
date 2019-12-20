
// lr_4_2_opi.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Clr_4_2_opiApp:
// О реализации данного класса см. lr_4_2_opi.cpp
//

class Clr_4_2_opiApp : public CWinApp
{
public:
	Clr_4_2_opiApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Clr_4_2_opiApp theApp;