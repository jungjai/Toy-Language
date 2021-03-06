
// ToyDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Toy.h"
#include "ToyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//열린 괄호인가?
int Is_open_parentheses(int index);
//index에 문자 들어와야함
//읽은 마지막 index 리턴 err시 해당 errnum 
//변수인가?
int Is_val(int index);
//index에 숫자 들어와야함
//읽은 마지막 index 리턴 err시 해당 errnum 
//상수인가?
int Is_con(int index);
CString Rerverse_exprssion(CString ex);
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CToyDlg 대화 상자



CToyDlg::CToyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TOY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CToyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, expression_control);
	DDX_Control(pDX, IDC_EDIT2, intermediate_code_control);
	DDX_Control(pDX, IDC_EDIT3, result_control);
}

BEGIN_MESSAGE_MAP(CToyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CToyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CToyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CToyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CToyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CToyDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CToyDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CToyDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CToyDlg 메시지 처리기

BOOL CToyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CToyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CToyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CToyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CToyDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	expression_control.GetWindowText(expression);
	expression = Rerverse_exprssion(expression);
	intermediate_code_control.SetWindowText(expression);

}


void CToyDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}


void CToyDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString create = NULL;
	expression_control.SetWindowText(create);
	intermediate_code_control.SetWindowText(create);
	result_control.SetWindowText(create);
}


void CToyDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CToyDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CToyDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CToyDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CDialogEx::OnCancel();
}

CString Rerverse_exprssion(CString ex) 
{
	int errnum;
	CString errnum_string[7];
	char* oper[2];
	//에러 메세지 초기화
	errnum_string[0] = "";
	errnum_string[1] = "피연산자 자리에 정수가 아닌 실수가 들어갔습니다.\n";
	errnum_string[2] = "괄호가 잘 못 사용되었습니다.\n";
	errnum_string[3] = "기호 사용이 잘못 되었습니다\n";
	errnum_string[4] = "정의되지 않은 연산자 입니다.\n";
	errnum_string[5] = "피연산자 자리에 -가 연속으로 입력되었습니다.\n";
	errnum_string[6] = "숫자뒤에 문자 또는 기호가 공백 없이 들어 갔습니다.\n";

	oper[0] = "IF";
	oper[1] = "MINUS";
/*
	int errnum_tmp = 0;
	int linestart;
	CStringA tmp_str;
	char* tmpbuf;
	for (int i = 0; i < len; i++) {
		errnum = 0;
		errnum_tmp = 0;
		//라인의 시작 index
		linestart = i;
		//임시 tmp_str 초기화
		tmp_str.Format("");
		//괄호수 확인
		int tmpj = i;
		int count_open_parenthness = 0;
		int count_close_parenthness = 0;
		for (; tmpj < len; tmpj++)
		{
			if (tmpbuf[tmpj] == '(')
				count_open_parenthness++;
			else if (tmpbuf[tmpj] == ')')
				count_close_parenthness++;
			else if (tmpbuf[tmpj] == '\n')
				break;
		}

		//괄호수 다른경우
		if (count_open_parenthness != count_close_parenthness)
		{
			i = tmpj;
			errnum = 2;
		}
		//괄호수 같을 경우
		else
		{
			//공백 넘기기
			if (isspace(tmpbuf[i])) {
				continue;
			}
			//괄호 시작
			else if (tmpbuf[i] == '(') {
				i = Is_open_parentheses(i);
				errnum_tmp = errnum;
				i++;
				i = check_err_after_program(i);
			}
			//변수 인지 확인
			else if (isalpha(tmpbuf[i])) {
				i = Is_val(i);
				errnum_tmp = errnum;
				i++;
				i = check_err_after_program(i);
			}
			//상수 인지 확인
			else if (isdigit(tmpbuf[i])) {
				i = Is_con(i);
				errnum_tmp = errnum;
				i++;
				i = check_err_after_program(i);
			}
			//마이너스 상수 인지 확인
			else if (tmpbuf[i] == '-') {
				i = Is_minus_con(i);
				errnum_tmp = errnum;
				i++;
				i = check_err_after_program(i);
			}
			else {
				errnum = 3;
				errnum_tmp = errnum;
				i = check_err_after_program(i);
			}
		}

		//라인의 끝 index
		lineend = i;
		//첫 에러를 메세지 해줌
		if (errnum_tmp)
			errnum = errnum_tmp;

		//에러시 에러 라인을 메세시에 넣어줌
		if (errnum)
		{
			int j;
			for (j = linestart; j < lineend; j++) {
				message.AppendChar(tmpbuf[j]);
			}
			if (tmpbuf[j - 1] != '\n')
				message.Append("\r\n");
		}
		else {
			listofPostfix.push_back(tmp_str);
			message.Append(tmp_str);
		}

		//에러 출력, 없으면 아무것도 출력되지 않음
		printerror();
	}
	*/
	int len = ex.GetLength();
	for (int i = 0; i < len; i++) {
		;
	}
	return ex;
}

