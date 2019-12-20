
// lr_4_2_opiDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно Clr_4_2_opiDlg
class Clr_4_2_opiDlg : public CDialogEx
{
// Создание
public:
	Clr_4_2_opiDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_LR_4_2_OPI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit_si_c;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CButton m_button_rand_c;
	CButton m_button_si_c;
	CButton m_button_file_c;
	afx_msg void OnBnClickedButton3();
	CButton m_button_output_form_c;
	CButton m_button_output_file_c;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CButton m_button_accept_c;
	afx_msg void OnBnClickedButton6();
	CEdit m_edit_str_c;
	CEdit m_edit_clmn_c;
	int m_edit_str_v;
	int m_edit_clmn_v;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	CString m_stat_form_output;
	CString m_edit_si_v;
	afx_msg void OnBnClickedButton7();
	CButton m_button_confirm_c;
	afx_msg void OnEnChangeEdit1();
	CButton m_button_task_c;
	afx_msg void OnBnClickedButton9();
};
