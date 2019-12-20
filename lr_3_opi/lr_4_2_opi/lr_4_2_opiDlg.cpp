
// lr_4_2_opiDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "lr_4_2_opi.h"
#include "lr_4_2_opiDlg.h"
#include "afxdialogex.h"
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно Clr_4_2_opiDlg



Clr_4_2_opiDlg::Clr_4_2_opiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Clr_4_2_opiDlg::IDD, pParent)
	, m_edit_str_v(0)
	, m_edit_clmn_v(0)
	, m_stat_form_output(_T(""))
	, m_edit_si_v(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clr_4_2_opiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit_si_c);
	DDX_Control(pDX, IDC_BUTTON1, m_button_rand_c);
	DDX_Control(pDX, IDC_BUTTON2, m_button_si_c);
	DDX_Control(pDX, IDC_BUTTON3, m_button_file_c);
	DDX_Control(pDX, IDC_BUTTON4, m_button_output_form_c);
	DDX_Control(pDX, IDC_BUTTON5, m_button_output_file_c);
	DDX_Control(pDX, IDC_BUTTON6, m_button_accept_c);
	DDX_Control(pDX, IDC_EDIT2, m_edit_str_c);
	DDX_Control(pDX, IDC_EDIT3, m_edit_clmn_c);
	DDX_Text(pDX, IDC_EDIT2, m_edit_str_v);
	DDV_MinMaxInt(pDX, m_edit_str_v, 2, 20);
	DDX_Text(pDX, IDC_EDIT3, m_edit_clmn_v);
	DDV_MinMaxInt(pDX, m_edit_clmn_v, 2, 20);
	DDX_Text(pDX, IDC_STATIC1, m_stat_form_output);
	DDX_Text(pDX, IDC_EDIT1, m_edit_si_v);
	DDX_Control(pDX, IDC_BUTTON7, m_button_confirm_c);
	DDX_Control(pDX, IDC_BUTTON9, m_button_task_c);
}

BEGIN_MESSAGE_MAP(Clr_4_2_opiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &Clr_4_2_opiDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Clr_4_2_opiDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Clr_4_2_opiDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Clr_4_2_opiDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Clr_4_2_opiDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Clr_4_2_opiDlg::OnBnClickedButton6)
	ON_EN_CHANGE(IDC_EDIT2, &Clr_4_2_opiDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &Clr_4_2_opiDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON7, &Clr_4_2_opiDlg::OnBnClickedButton7)
	ON_EN_CHANGE(IDC_EDIT1, &Clr_4_2_opiDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON9, &Clr_4_2_opiDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// обработчики сообщений Clr_4_2_opiDlg

BOOL Clr_4_2_opiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	ShowWindow(SW_MAXIMIZE);

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void Clr_4_2_opiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Clr_4_2_opiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR Clr_4_2_opiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int **Array = NULL;
bool bEdit1, bEdit2;
int count = 0;


void Clr_4_2_opiDlg::OnBnClickedButton2() {
	/*Selfinput button*/
	UpdateData(TRUE);
	m_button_rand_c.EnableWindow(0);
	m_button_file_c.EnableWindow(0);
	m_button_output_form_c.EnableWindow(1);
	m_button_output_file_c.EnableWindow(1);
	m_edit_si_c.EnableWindow(1);
	MessageBox(_T("You must insert numbers by this template:\n	01 11 07 99\nAnd this rules:\n  - Inserted values must be positive;\n  - Max inserted value is 99;"), _T("Warning!"), MB_OK);
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


void Clr_4_2_opiDlg::OnBnClickedButton1() {
	/*Rand input button*/
	UpdateData(TRUE);
	m_button_si_c.EnableWindow(0);
	m_button_file_c.EnableWindow(0);
	m_button_output_form_c.EnableWindow(1);
	m_button_output_file_c.EnableWindow(1);
	UpdateData(FALSE);
	for (int i = 0; i < m_edit_clmn_v; i++) {
		for (int j = 0; j < m_edit_str_v; j++) {
			Array[i][j] = rand() % 90 + 10;
		}
	}
	// TODO: добавьте свой код обработчика уведомлений
}


void Clr_4_2_opiDlg::OnBnClickedButton3() {
	/*File input button*/
	UpdateData(TRUE);
	m_button_si_c.EnableWindow(0);
	m_button_rand_c.EnableWindow(0);
	m_button_output_form_c.EnableWindow(1);
	m_button_output_file_c.EnableWindow(1);
	CStdioFile fin;
	fin.Open(_T("file.in"), CFile::modeRead);
	for (int i = 0; i < m_edit_clmn_v; i++) {
		for (int j = 0; j < m_edit_str_v; j++) {
			CString str = NULL;
			fin.ReadString(str);
			Array[i][j] = _ttoi(str.GetString());
		}
	}
	fin.Close();
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


void Clr_4_2_opiDlg::OnBnClickedButton4() {
	/*Form output button*/
	UpdateData(TRUE);
	m_button_output_file_c.EnableWindow(0);
	m_button_rand_c.EnableWindow(0);
	m_button_si_c.EnableWindow(0);
	m_button_file_c.EnableWindow(0);
	m_edit_si_c.EnableWindow(0);
	for (int i = 0; i < m_edit_clmn_v; i++) {
		for (int j = 0; j < m_edit_str_v; j++) {
			CString str;
			str.Format(_T("%d"), Array[i][j]);
			m_stat_form_output += str;
			m_stat_form_output += " ";
		}
		m_stat_form_output += "\n";
	}
	m_button_output_form_c.EnableWindow(0);
	m_button_task_c.EnableWindow(1);
	if (count == 1) {
		m_button_task_c.EnableWindow(0);
	}
	++count;
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


/*Start of useless code*/
void Clr_4_2_opiDlg::OnBnClickedButton5() {
	/*File output button*/
	UpdateData(TRUE);
	m_button_output_form_c.EnableWindow(0);
	m_button_rand_c.EnableWindow(0);
	m_button_si_c.EnableWindow(0);
	m_button_file_c.EnableWindow(0);
	m_edit_si_c.EnableWindow(0);
	CStdioFile fout;
	fout.Open(_T("file.out"), CFile::modeCreate | CFile::modeWrite);
	for (int i = 0; i < m_edit_clmn_v; i++) {
		for (int j = 0; j < m_edit_str_v; j++) {
			CString str = NULL;
			str.Format(_T("%d"), Array[i][j]);
			str += "\n";
			fout.Write(str, sizeof(str));
		}
	}
	m_stat_form_output = "Data was successfuly loaded to file!";
	m_button_output_file_c.EnableWindow(0);
	fout.Close();
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}
/*End of useless code*/


void Clr_4_2_opiDlg::OnBnClickedButton6() {
	/*Accept button*/
	UpdateData(TRUE);
	if ((bEdit1 == true) && (bEdit2 == true) && (m_edit_str_v > 1) && (m_edit_clmn_v > 1) && (m_edit_str_v < 21) && (m_edit_clmn_v < 21)) {
		m_button_rand_c.EnableWindow(1);
		m_button_si_c.EnableWindow(1);
		m_button_file_c.EnableWindow(1);
		m_button_accept_c.EnableWindow(0);
		m_edit_str_c.EnableWindow(0);
		m_edit_clmn_c.EnableWindow(0);
		UpdateData(FALSE);
		Array = new int*[m_edit_clmn_v];
		int max_value = 0;
		if (m_edit_clmn_v > m_edit_str_v) {
			max_value = m_edit_clmn_v;
		}
		else if (m_edit_clmn_v < m_edit_str_v) {
			max_value = m_edit_str_v;
		}
		else max_value = m_edit_str_v;
		for (int i = 0; i < max_value; i++) {
			Array[i] = new int[max_value];
		}
	}
	// TODO: добавьте свой код обработчика уведомлений
}


void Clr_4_2_opiDlg::OnEnChangeEdit2() {
	/*Count of str*/
	bEdit1 = true;
	// TODO:  Добавьте код элемента управления
}


void Clr_4_2_opiDlg::OnEnChangeEdit3() {
	/*Count of clmn*/
	bEdit2 = true;
	// TODO:  Добавьте код элемента управления
}


void Clr_4_2_opiDlg::OnBnClickedButton7() {
	/*Confirmation button of selfinput*/
	UpdateData(TRUE);
	m_edit_si_c.EnableWindow(0);
	m_button_confirm_c.EnableWindow(0);
	int k = 0;
	for (int i = 0; i < m_edit_clmn_v; i++) {
		for (int j = 0; j < m_edit_str_v; j++) {
			CString str;
			str = m_edit_si_v[k];
			str += m_edit_si_v[++k];
			Array[i][j] = _ttoi(str);
			k += 2;
		}
	}
	/**/
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


void Clr_4_2_opiDlg::OnEnChangeEdit1() {
	/*Area for selfinput*/
/*Button of conformation will be enabled only when user will insert required count of symbols*/
	UpdateData(TRUE);
	if (m_edit_si_v.GetLength() >= (2 * m_edit_clmn_v * m_edit_str_v + m_edit_clmn_v * m_edit_str_v - 1)) {
		m_button_confirm_c.EnableWindow(1);
	}
	UpdateData(FALSE);
	// TODO:  Добавьте код элемента управления
}


void Clr_4_2_opiDlg::OnBnClickedButton9() {
	/*Button of task operation*/
	UpdateData(TRUE);
	m_stat_form_output = "";
	if (m_edit_clmn_v == m_edit_str_v) {
		for (int i = 0; i < m_edit_str_v; i++) {
			for (int j = i; j < m_edit_clmn_v; j++) {
				int temp;
				temp = Array[i][j];
				Array[i][j] = Array[j][i];
				Array[j][i] = temp;
			}
		}
	}
	else {
		for (int i = 0; i < m_edit_str_v; i++) {
			for (int j = i; j < m_edit_clmn_v; j++) {
				int temp;
				temp = Array[i][j];
				Array[i][j] = Array[j][i];
				Array[j][i] = temp;
			}
		}
	}
	int temp;
	temp = m_edit_str_v;
	m_edit_str_v = m_edit_clmn_v;
	m_edit_clmn_v = temp;
	m_button_task_c.EnableWindow(0);
	m_button_output_form_c.EnableWindow(1);
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}
