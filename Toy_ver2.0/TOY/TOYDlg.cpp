
// TOYDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "TOY.h"
#include "TOYDlg.h"
#include "afxdialogex.h"

#include "MyToy.h"
#include "MyStack.h"
#include "MyFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



MyFunc *functions[MAX_FUNC];
int functionNum = 0;





// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

														// 구현입니다.
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


// CTOYDlg 대화 상자



CTOYDlg::CTOYDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTOYDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTOYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTOYDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTOYDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTOYDlg::OnBnClickedButton2)
	//	ON_BN_CLICKED(IDC_BUTTON3, &CTOYDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTOYDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTOYDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTOYDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTOYDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CTOYDlg::OnBnClickedButton9)

	ON_BN_CLICKED(IDC_BUTTON8, &CTOYDlg::OnBnClickedButton8)

	ON_BN_CLICKED(IDC_BUTTON10, &CTOYDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CTOYDlg 메시지 처리기

BOOL CTOYDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

									// TODO: 여기에 추가 초기화 작업을 추가합니다.

	initDefun();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTOYDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTOYDlg::OnPaint()
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
HCURSOR CTOYDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//화면 지우기
void CTOYDlg::OnBnClickedButton1()
{
	//edit control 변수 
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	//전체 선택 및 지우기
	textBox->SetSel(0, -1);
	textBox->Clear();
}

//프로그램 로드
void CTOYDlg::OnBnClickedButton2()
{
	ULONGLONG length;
	char buff[20000] = { 0 };
	//파일 불러오기 대화상자
	CFileDialog dlgaFile(TRUE, _T("txt"), _T("pre*.txt"), OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, NULL);
	dlgaFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");

	//파일내용 읽어오기
	if (IDOK == dlgaFile.DoModal()) {

		CString strPathName = dlgaFile.GetPathName();
		CFile file;
		file.Open(strPathName, CFile::modeRead);
		length = file.GetLength();
		file.Read(buff, length * sizeof(char));
		file.Close();

		//edit control 변수 
		CEdit *textBox;
		textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
		//파일 내용 쓰기
		textBox->SetWindowTextW(CA2W(buff));
	}
}

//에러 메세지 출력
void printErr(int errNum, int row) {
	char message[100] = { 0 };
	if (errNum == LEFT_ERR) {
		sprintf(message, "%d번째 행의 ( 위치가 잘못되었습니다.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == RIGHT_ERR) {
		sprintf(message, "%d번쨰 행의 ) 위치가 잘못되었습니다.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == REAL_ERR) {
		sprintf(message, "%d번쨰 행의 피연산자가 실수 입니다.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == NEGATIVE_ERR) {
		sprintf(message, "%d번쨰 행의 피연산자에 -기호가 반복되었습니다.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == UNDEFINE_ERR) {
		sprintf(message, "%d번쨰 행의 연산자는 없는 연산자 입니다.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == DEFAULT_ERR) {
		sprintf(message, "%d번쨰 행에 잘못된 문자가 씌었습니다.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == COUNT_ERR) {
		sprintf(message, "%d번쨰 행의 피연산자의 갯수가 잘못되었습니다.", row + 1);
		AfxMessageBox(CA2W(message));
	}
	else if (errNum == NOOP_ERR) {
		sprintf(message, "%d번쨰 행의 연산자가 없습니다.", row + 1);
		AfxMessageBox(CA2W(message));
	}
}



//중간코드 생성
void CTOYDlg::OnBnClickedButton4()
{
	MyToy *toy[10];

	CString tmpinput;
	char input[20000] = { 0 };
	char output[20000] = { 0 };
	char *token;
	int pc = 0;
	int errNum = 0;

	//edit control 변수
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	textBox->LineScroll(textBox->GetLineCount());
	textBox->GetWindowTextW(tmpinput);

	for (int i = 0; i < tmpinput.GetLength(); i++) {
		input[i] = tmpinput.GetAt(i);
	}

	//개행 단위로 토큰
	token = strtok(input, "\r\n");
	while (token != NULL) {
		toy[pc] = new MyToy(token);
		pc++;
		token = strtok(NULL, "\r\n");
	}

	// output buff set
	strcat(output, "+ PROCESS DESCRTION\r\n");
	//toy1에서 사용했던 toPre함수 하용
	for (int i = 0; i < pc; i++) {
		errNum = checkErr(toy[i]);
		if (errNum == 0) {
			strcat(output, toPre(toy[i]));
			strcat(output, "\r\n");
		}
		//else
		//printErr(errNum, i);
	}
	strcat(output, "\r\n");
	strcat(output, "+ INTERMEDIATE CODE\r\n");
	//중간코드 생성 함수 toInter사용
	for (int i = 0; i < pc; i++) {
		errNum = checkErr(toy[i]);
		if (errNum == 0) {
			strcat(output, "begin\r\n");
			strcat(output, toInter(toy[i]));
			strcat(output, "end\r\n\r\n");
		}
		else
			printErr(errNum, i);
	}
	if (errNum == 0)
		textBox->SetWindowTextW(CA2W(output));

}

//중간코드 저장
void CTOYDlg::OnBnClickedButton5()
{
	CString tmpinput;
	char input[20000] = { 0 };

	//edit control 변수
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);

	textBox->GetWindowTextW(tmpinput);

	for (int i = 0; i < tmpinput.GetLength(); i++) {
		input[i] = tmpinput.GetAt(i);
	}

	CFileDialog dlgFile(FALSE, _T("txt"), _T("inter*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
	dlgFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");

	if (IDOK == dlgFile.DoModal()) {
		CString strPathName = dlgFile.GetPathName();
		CFile file;
		file.Open(strPathName, CFile::modeWrite | CFile::modeCreate);
		file.Write(input, strlen(input));

		file.Close();
	}

}


//중간코드 로드
void CTOYDlg::OnBnClickedButton6()
{
	ULONGLONG length;
	char buff[20000] = { 0 };
	//파일 불러오기 대화상자
	CFileDialog dlgaFile(TRUE, _T("txt"), _T("inter*.txt"), OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, NULL);
	dlgaFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");


	//파일내용 읽어오기
	if (IDOK == dlgaFile.DoModal()) {

		CString strPathName = dlgaFile.GetPathName();
		CFile file;
		file.Open(strPathName, CFile::modeRead);
		length = file.GetLength();
		file.Read(buff, length * sizeof(char));
		file.Close();

		//edit control 변수 
		CEdit *textBox;
		textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
		//파일 내용 쓰기
		textBox->SetWindowTextW(CA2W(buff));
	}
}

//연산
void CTOYDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here

	CString tmpinput;
	char input[20000] = { 0 };
	char output[20000] = { 0 };
	int pc = 0;

	//edit control 변수
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);

	textBox->GetWindowTextW(tmpinput);

	textBox->SetSel(0, -1);
	textBox->Clear();


	//저장용 스택
	MyStack *preStack = new MyStack();
	//연산용 스택
	MyStack *postStack = new MyStack();
	//결과용 스택
	MyStack *outputStack = new MyStack();
	char tmpStackItem[20000] = { 0 };

	for (int i = 0; i < tmpinput.GetLength(); i++) {
		input[i] = tmpinput.GetAt(i);
		output[i] = tmpinput.GetAt(i);
	}

	char *token = strtok(input, "\r\n\0");
	//저장용 스택에 저장
	while (token != NULL) {
		//상수는 push 제외하고 숫자만 저장
		if (strncmp(token, "push", 4) == 0)
			preStack->push(token + 5);
		else if (strcmp(token, "begin") == 0) {
			preStack->push(token);
			//입력된 행 갯수 카운트
			pc++;
		}
		else
			preStack->push(token);
		token = strtok(NULL, "\r\n\0");
	}
	//입력된 행 갯수 만큼
	for (int i = 0; i < pc; i++) {
		while (true) {
			char tmp[10] = { 0 };
			strcpy(tmp, preStack->pop());
			//연산자면 pop두번 연산후 push
			if (strcmp(tmp, "IF") == 0) {
				char test[10] = { 0 };
				//toyValue함수 사용
				strcpy(test, toyValue("IF", postStack->pop(), postStack->pop()));
				postStack->push(test);
			}
			else if (strcmp(tmp, "MINUS") == 0) {
				char test[10] = { 0 };
				strcpy(test, toyValue("MINUS", postStack->pop(), postStack->pop()));
				postStack->push(test);
			}
			else if (strcmp(tmp, "end") == 0)
				;
			//begin이면 한 행 종료
			else if (strcmp(tmp, "begin") == 0)
				break;
			//피연산자 push
			else
				postStack->push(tmp);
		}
		//결과도 거꾸로 되기 때문에 결과 스택에 저장
		strcpy(tmpStackItem, postStack->pop());
		strcat(tmpStackItem, "\r\n");
		outputStack->push(tmpStackItem);
	}
	//결과 배열에 결과 스택내용 저장
	strcat(output, "+ RESULT\r\n");
	int size = outputStack->size();
	for (int i = 0; i < size; i++) {
		strcat(output, outputStack->pop());
	}

	textBox->SetWindowTextW(CA2W(output));
}

void CTOYDlg::initDefun()
{
	// TODO: Add your control notification handler code here


	char buff[20000] = { 0 };
	CFile file;
	file.Open(_T("defun.txt"), CFile::modeRead);
	int length = file.GetLength();
	file.Read(buff, length * sizeof(char));
	file.Close();
	//********************************************CHANGE*****************************************//
	for (int i = 0; i < functionNum; i++) {
		delete functions[functionNum];
	}
	functionNum = 0;
	//*****************************************************************************************//
	//function초기화
	char *token = strtok(buff, "\r\n");
	while (token != NULL) {
		char *tmp = new char[strlen(token)];
		memset(tmp, 0, strlen(token));
		strcpy(tmp, token);
		functions[functionNum] = new MyFunc(tmp);
		functionNum++;
		token = strtok(NULL, "\r\n\0");
	}

}


/*

* MyToy 객체의 구현부
* defun의 내용을 검색할 필요가 있어서
* 전역변수를 사용하기 때문에
* cpp파일을 따로 두지 않고 같은 파일에 구현

*/



MyToy::MyToy() {
	//멤버 초기화
	lcount = 0;
	rcount = 0;
	type = 0;
	operand1 = NULL;
	operand2 = NULL;
	memset(value, 0, sizeof(char) * 10);
	memset(op, 0, sizeof(char) * 10);
	errNumber = 0;

	for (int i = 0; i < MAX_TOKEN; i++) {
		tokenTable[i] = NULL;
		tokenType[i] = 0;
	}
	tokenNum = 0;
}

MyToy::MyToy(char *input) {
	lcount = 0;
	rcount = 0;
	type = 0;
	operand1 = NULL;
	operand2 = NULL;
	memset(value, 0, sizeof(char) * 10);
	memset(op, 0, sizeof(char) * 10);
	errNumber = 0;

	for (int i = 0; i < MAX_TOKEN; i++) {
		tokenTable[i] = NULL;
		tokenType[i] = 0;
	}
	tokenNum = 0;

	//파싱, tokenTable 완성
	lexicalAnalysis(input);

	//defun함수가 사용되었으면, 그 index값이 errNumber
	while (errNumber > 0) {
		int index;
		//function에서 확인
		for (int i = 0; i < functionNum; i++) {
			if (strcmp(tokenTable[errNumber], functions[i]->op) == 0)
				index = i;
		}

		//tmpopr 포인터 배열에 function에 정의되어있는
		//opernads만큼 tokenTable값 저장
		char *tmpopr[MAX_OPR];
		int next = errNumber + 1;
		for (int i = 0; i < functions[index]->oprNum; i++) {
			//operand가 숫자면 그대로 저장
			if (tokenType[next] == 3) {
				tmpopr[i] = new char[strlen(tokenTable[next])];
				memset(tmpopr[i], 0, strlen(tokenTable[next]));
				strcpy(tmpopr[i], tokenTable[next]);
				next++;
			}
			//operand가 함수면 () 괄호 문자열 저장
			else if (tokenType[next] == 1) {
				int j = next;
				tmpopr[i] = new char[20000];
				memset(tmpopr[i], 0, 20000);
				int count = 0;
				while (j < tokenNum) {
					if (tokenType[j] == 1)
						count++;
					else if (tokenType[j] == 2)
						count--;

					strcat(tmpopr[i], tokenTable[j]);
					strcat(tmpopr[i], " ");
					if (count == 0)
						break;
					j++;
				}
				next = j + 1;
			}
			else {
				errNumber = COUNT_ERR;
				break;
			}
		}

		//errnumber까지 
		//tmpopr삽입

		//defun의 함수를 함수구현부의 토큰으로 변경한 문자열 
		char interner[20000] = { 0 };
		for (int i = 0; i < errNumber; i++) {
			//defun 함수 쓰이기 전까지는 그대로
			strcat(interner, tokenTable[i]);
			strcat(interner, " ");
		}
		//********************CHANGE**********************//
		if (strcmp(functions[index]->op, "DIV") == 0) {
			MyToy *oper = new MyToy(tmpopr[0]);
			char* oper1 = new char[100];
			char* oper2 = new char[100];

			if (oper->tokenNum > 1) {
				for (int i = 0; i < oper->tokenNum; i++) {
					if (oper->tokenType[i] == 3) {
						strcpy(oper1, oper->tokenTable[i]);
						i++;
						for (; i < oper->tokenNum; i++) {
							if (oper->tokenType[i] == 3) {
								strcpy(oper2, oper->tokenTable[i]);
							}
						}
					}
				}
				strcpy(tmpopr[0], toyValue("MINUS", oper2, oper1));
			}
			if (atoi(tmpopr[0]) < atoi(tmpopr[1])) {
				memset(interner, 0, 20000);
				for (int i = 0; i < errNumber - 1; i++) {
					//defun 함수 쓰이기 전까지는 그대로
					strcat(interner, tokenTable[i]);
					strcat(interner, " ");
				}
				strcat(interner, tmpopr[0]);
				strcat(interner, " ");
				next++;
			}
			else {
				for (int i = 1; i < functions[index]->tokenNum - 1; i++) {
					BOOL check = TRUE;
					//오퍼랜드 자리면, tmpopr로 저장
					for (int j = 0; j < functions[index]->oprNum; j++) {
						if (strcmp(functions[index]->tokenTable[i], functions[index]->operands[j]) == 0) {
							strcat(interner, tmpopr[j]);
							strcat(interner, " ");
							check = FALSE;
						}
					}
					if (check) {
						strcat(interner, functions[index]->tokenTable[i]);
						strcat(interner, " ");

					}
				}
			}
		}
		else if (strcmp(functions[index]->op, "TIMES") == 0) {
			MyToy *oper = new MyToy(tmpopr[0]);
			char* oper1 = new char[100];
			char* oper2 = new char[100];

			if (oper->tokenNum > 1) {
				for (int i = 0; i < oper->tokenNum; i++) {
					if (oper->tokenType[i] == 3) {
						strcpy(oper1, oper->tokenTable[i]);
						i++;
						for (; i < oper->tokenNum; i++) {
							if (oper->tokenType[i] == 3) {
								strcpy(oper2, oper->tokenTable[i]);
							}
						}
					}
				}
				strcpy(tmpopr[0], toyValue("MINUS", "1", oper1));
			}
			if (atoi(tmpopr[0]) <= 0) {
				memset(interner, 0, 20000);
				for (int i = 0; i < errNumber - 1; i++) {
					//defun 함수 쓰이기 전까지는 그대로
					strcat(interner, tokenTable[i]);
					strcat(interner, " ");
				}
				strcat(interner, "0");
				strcat(interner, " ");
				next++;
			}
			else {
				for (int i = 1; i < functions[index]->tokenNum - 1; i++) {
					BOOL check = TRUE;
					//오퍼랜드 자리면, tmpopr로 저장
					for (int j = 0; j < functions[index]->oprNum; j++) {
						if (strcmp(functions[index]->tokenTable[i], functions[index]->operands[j]) == 0) {
							strcat(interner, tmpopr[j]);
							strcat(interner, " ");
							check = FALSE;
						}
					}
					if (check) {
						strcat(interner, functions[index]->tokenTable[i]);
						strcat(interner, " ");

					}
				}
			}
		}
		else {
			//함수 구현부의 토큰을 문자열에 순서대로 저장
			for (int i = 1; i < functions[index]->tokenNum - 1; i++) {
				BOOL check = TRUE;
				//오퍼랜드 자리면, tmpopr로 저장
				for (int j = 0; j < functions[index]->oprNum; j++) {
					if (strcmp(functions[index]->tokenTable[i], functions[index]->operands[j]) == 0) {
						strcat(interner, tmpopr[j]);
						strcat(interner, " ");
						check = FALSE;
					}
				}
				if (check) {
					strcat(interner, functions[index]->tokenTable[i]);
					strcat(interner, " ");
				}
			}
		}
		//defun함수 쓰인 뒷부분도 그대로 저장하여
		for (int i = next; i < tokenNum; i++) {
			strcat(interner, tokenTable[i]);
			strcat(interner, " ");
		}
		//초기화
		lcount = 0;
		rcount = 0;
		type = 0;
		operand1 = NULL;
		operand2 = NULL;
		memset(value, 0, sizeof(char) * 10);
		memset(op, 0, sizeof(char) * 10);
		errNumber = 0;

		for (int i = 0; i < MAX_TOKEN; i++) {
			tokenTable[i] = NULL;
			tokenType[i] = 0;
		}
		tokenNum = 0;
		//다시 랙시칼
		lexicalAnalysis(interner);
	}

	if (errNumber == 0) {
		syntaxAnalysis();
	};


	if (errNumber == 0) {
		if (tokenNum > 3) {
			if (strcmp(op, "") == 0)
				errNumber = NOOP_ERR;
		}
	}

}

//토크라이져
void MyToy::lexicalAnalysis(char *input) {
	int i = 0;
	while (input[i] != '\0') {
		//토큰은 (
		if (input[i] == '(') {
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = '(';
			tokenTable[tokenNum][1] = '\0';
			tokenType[tokenNum] = 1;
			tokenNum++;
		}
		// )
		else if (input[i] == ')') {
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = ')';
			tokenTable[tokenNum][1] = '\0';
			tokenType[tokenNum] = 2;
			tokenNum++;
		}
		//숫자
		else if (input[i] == '.' || input[i] == '-' || (input[i] >= '0' && input[i] <= '9')) {
			int tmp = i;
			while (input[i] == '.' || input[i] == '-' || (input[i] >= '0'&&input[i] <= '9'))
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], input + tmp, i - tmp);
			tokenType[tokenNum] = 3;
			tokenNum++;
			i--;
		}
		//문자 IF/THEN/ELSE 때문에 /추가
		else if ((input[i] >= 'A'&& input[i] <= 'Z') || input[i] == '/') {
			int tmp = i;
			while ((input[i] >= 'A'&& input[i] <= 'Z') || input[i] == '/')
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], input + tmp, i - tmp);
			tokenType[tokenNum] = 4;
			tokenNum++;
			i--;
		}
		else if (input[i] != ' ') {
			//쓸수 없는 문자 사용 에러
			errNumber = DEFAULT_ERR;
			return;
		}
		i++;
	}

	for (int j = 0; j < tokenNum; j++) {
		//숫자일 경우
		if (tokenType[j] == 3) {
			int nc = 0;
			int dc = 0;
			for (int k = 0; k < strlen(tokenTable[j]); k++) {
				if (tokenTable[j][k] == '.')
					dc++;
				else if (tokenTable[j][k] == '-')
					nc++;
			}
			if (nc > 1) {
				// -갯수 에러
				errNumber = NEGATIVE_ERR;
				return;
			}
			else if (dc > 0) {
				// 실수 에러
				errNumber = REAL_ERR;
				return;
			}
		}
		else if (tokenType[j] == 4) {
			//op배열, 변수 배열을 만들어서 검사, op면 4 그래도 변수면 5
			if (strcmp(tokenTable[j], "IF") != 0 && strcmp(tokenTable[j], "MINUS") != 0) {

				BOOL check = TRUE;
				//defun에 정의된 함수와 일치여부 검사
				for (int k = 0; k < functionNum; k++) {
					if (strcmp(tokenTable[j], functions[k]->op) == 0)
						check = FALSE;
				}

				if (check) {
					errNumber = UNDEFINE_ERR;
					return;
				}
				//일치하면 그 token의 index를 errNumber로 셋팅
				else
					errNumber = j;
			}
		}
	}
}
//MyToy 할당
void MyToy::syntaxAnalysis() {
	char opr[10000] = { 0 };
	if (tokenNum == 1) {
		strcpy(value, tokenTable[0]);
		return;
	}
	else
		for (int i = 0; i < tokenNum; i++) {
			if (tokenType[i] == 1) {
				// ( 괄호 카운트
				if (lcount == 0)
					lcount++;
				else if (lcount == 1) {
					//(괄호 안에 (괄호가 쓰이면 -> 피연산자도 함수면
					lcount++;
					memset(opr, 0, 10000);
					int count = 0;
					while (i < tokenNum) {
						if (tokenType[i] == 1)
							count++;
						else if (tokenType[i] == 2)
							count--;

						strcat(opr, tokenTable[i]);
						strcat(opr, " ");
						//매칭되는 )까지 
						if (count == 0) {
							break;
						}
						i++;
					}
					//피연산자 자리에 찾은 (...) 할당
					if (operand1 == NULL)
						operand1 = new MyToy(opr);
					else if (operand2 == NULL)
						operand2 = new MyToy(opr);
					else {
						errNumber = LEFT_ERR;
						return;
					}


				}
				//마찬가지
				else if (lcount == 2) {
					lcount++;
					memset(opr, 0, 10000);
					int count = 0;
					while (i < tokenNum) {
						if (tokenType[i] == 1)
							count++;
						else if (tokenType[i] == 2)
							count--;

						strcat(opr, tokenTable[i]);
						strcat(opr, " ");
						if (count == 0)
							break;
						i++;
					}

					if (operand1 == NULL)
						operand1 = new MyToy(opr);
					else if (operand2 == NULL)
						operand2 = new MyToy(opr);
					else {
						errNumber = LEFT_ERR;
						return;
					}

				}
				//마찬가지
				else if (lcount == 3) {
					lcount++;
					memset(opr, 0, 10000);
					int count = 0;
					while (i < tokenNum) {
						if (tokenType[i] == 1)
							count++;
						else if (tokenType[i] == 2)
							count--;

						strcat(opr, tokenTable[i]);
						strcat(opr, " ");
						if (count == 0)
							break;
						i++;
					}

					if (operand1 == NULL)
						operand1 = new MyToy(opr);
					else if (operand2 == NULL)
						operand2 = new MyToy(opr);
					else {
						errNumber = LEFT_ERR;
						return;
					}

				}
				//마찬가지
				else if (lcount == 4) {
					lcount++;
					memset(opr, 0, 10000);
					int count = 0;
					while (i < tokenNum) {
						if (tokenType[i] == 1)
							count++;
						else if (tokenType[i] == 2)
							count--;

						strcat(opr, tokenTable[i]);
						strcat(opr, " ");
						if (count == 0)
							break;
						i++;
					}

					if (operand1 == NULL)
						operand1 = new MyToy(opr);
					else if (operand2 == NULL)
						operand2 = new MyToy(opr);
					else {
						errNumber = LEFT_ERR;
						return;
					}

				}
				//마찬가지
				else if (lcount == 5) {
					lcount++;
					memset(opr, 0, 10000);
					int count = 0;
					while (i < tokenNum) {
						if (tokenType[i] == 1)
							count++;
						else if (tokenType[i] == 2)
							count--;

						strcat(opr, tokenTable[i]);
						strcat(opr, " ");
						if (count == 0)
							break;
						i++;
					}

					if (operand1 == NULL)
						operand1 = new MyToy(opr);
					else if (operand2 == NULL)
						operand2 = new MyToy(opr);
					else {
						errNumber = LEFT_ERR;
						return;
					}
				}
				else
					errNumber = LEFT_ERR;

			}
			// ) 괄호
			else if (tokenType[i] == 2) {
				rcount++;
			}
			//숫자
			else if (tokenType[i] == 3) {
				if (operand1 == NULL)
					operand1 = new MyToy(tokenTable[i]);
				else if (operand2 == NULL)
					operand2 = new MyToy(tokenTable[i]);
				else
				{
					errNumber = COUNT_ERR;
					return;
				}
			}
			//문자 -> 문자는 함수 이름
			else if (tokenType[i] == 4) {
				strcpy(op, tokenTable[i]);
			}
			else if (tokenType[i] == 5) {
				if (operand1 == NULL)
					operand1 = new MyToy(tokenTable[i]);
				else if (operand2 == NULL)
					operand2 = new MyToy(tokenTable[i]);
			}
		}

	if (rcount != 1) {
		errNumber = RIGHT_ERR;
	}
}


char* toPre(MyToy *input) {
	char *result = new char[20000];
	memset(result, 0, 20000);

	strcat(result, "( ");

	if (input->op != NULL) {
		strcat(result, input->op);
	}
	strcat(result, " ");
	if (input->operand1 != NULL) {
		if (strcmp(input->operand1->value, "") != 0) {
			strcat(result, input->operand1->value);
		}
		else
			strcat(result, toPre(input->operand1));
	}
	strcat(result, " ");
	if (input->operand2 != NULL) {
		if (strcmp(input->operand2->value, "") != 0) {
			strcat(result, input->operand2->value);
		}
		else
			strcat(result, toPre(input->operand2));
	}

	strcat(result, " )");


	return result;
}


char* toInter(MyToy *input) {
	char *result = new char[20000];
	memset(result, 0, 20000);

	if (strcmp(input->op, "") != 0) {
		strcat(result, input->op);
		strcat(result, "\r\n");
	}
	else {
		if (input->operand1 == NULL) {
			strcat(result, "push ");
			strcat(result, input->value);
			strcat(result, "\r\n");
		}
	}

	if (input->operand1 != NULL)
		strcat(result, toInter(input->operand1));
	if (input->operand2 != NULL)
		strcat(result, toInter(input->operand2));

	return result;
}

int checkErr(MyToy *input) {
	int result = 0;

	if (input->operand1 != NULL) {
		if (checkErr(input->operand1) != 0)
			result = input->operand1->errNumber;
	}
	if (input->operand2 != NULL) {
		if (checkErr(input->operand2) != 0)
			result = input->operand2->errNumber;
	}
	if (input->errNumber != 0)
		result = input->errNumber;

	return result;
}


//함수목록
void CTOYDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	ULONGLONG length;
	char buff[20000] = { 0 };

	//edit control 변수 
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);

	CFile file;
	file.Open(_T("defun.txt"), CFile::modeRead);
	length = file.GetLength();
	file.Read(buff, length * sizeof(char));
	file.Close();


	//파일 내용 쓰기
	textBox->SetWindowTextW(CA2W(buff));
}

int defun(char *func, int line) {
	int i = 0;
	char *tokenTable[MAX_TOKEN];
	int tokenNum = 0;
	int tokenType[MAX_TOKEN];
	int errNumber = 0;

	char *operands[5];
	int oprNum = 0;
	int oprCheck[5] = { 0, 0, 0, 0, 0 };

	while (func[i] != '\0') {
		//열린 괄호
		if (func[i] == '(') {
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = '(';
			tokenTable[tokenNum][1] = '\0';
			tokenType[tokenNum] = 1;
			tokenNum++;
		}
		//닫힌 괄호
		else if (func[i] == ')') {
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = ')';
			tokenTable[tokenNum][1] = '\0';
			tokenType[tokenNum] = 2;
			tokenNum++;
		}
		//숫자
		else if (func[i] == '.' || func[i] == '-' || (func[i] >= '0' && func[i] <= '9')) {
			int tmp = i;
			while (func[i] == '.' || func[i] == '-' || (func[i] >= '0'&&func[i] <= '9'))
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], func + tmp, i - tmp);
			tokenType[tokenNum] = 3;
			tokenNum++;
			i--;
		}
		//함수명 function name
		else if ((func[i] >= 'A'&& func[i] <= 'Z') || func[i] == '/') {
			int tmp = i;
			while ((func[i] >= 'A'&& func[i] <= 'Z') || func[i] == '/')
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], func + tmp, i - tmp);
			tokenType[tokenNum] = 4;
			tokenNum++;
			i--;
		}
		//파라미터
		else if (func[i] >= 'a'&&func[i] <= 'z') {
			int tmp = i;
			while (func[i] >= 'a'&&func[i] <= 'z')
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], func + tmp, i - tmp);
			tokenType[tokenNum] = 8;
			tokenNum++;
			i--;
		}
		else if (func[i] != ' ') {
			errNumber = DEFAULT_ERR;
			break;
		}

		i++;
	}
	if (errNumber == 0) {
		if (!(tokenType[0] == 1 && tokenType[tokenNum - 1] == 2)) {
			//괄호문제
			AfxMessageBox(_T("(,) 괄호가 잘못되었습니다."));
			return -1;
		}
		if (!(tokenType[1] == 4 && strcmp(tokenTable[1], "DEFUN") == 0)) {
			//DEFUN 명령어 문제
			AfxMessageBox(_T("DEFUN 을 사용 바랍니다."));
			return -1;
		}
		for (int i = 0; i < functionNum; i++) {
			if (strcmp(tokenTable[2], functions[i]->op) == 0) {
				//이름중복
				AfxMessageBox(_T("이미 정의되어있는 함수 입니다. 다른 이름을 사용해주세요."));
				return -1;
			}
		}
		//오퍼랜드 저장 4번째 토큰부터 오퍼랜드
		for (int i = 4; i < 9; i++) {
			//오퍼랜트 타입 넘버 8
			if (tokenType[i] == 8) {
				if (strlen(tokenTable[i]) != 1) {
					//opernad err 오퍼랜드는 소문자 하나
					AfxMessageBox(_T("피연사자는 소문자 하나만 사용해주세요."));
					return -1;
				}
				operands[oprNum] = new char[strlen(tokenTable[i])];
				strcpy(operands[oprNum], tokenTable[i]);
				oprNum++;
			}
			else
				break;
		}
		if (oprNum == 0) {
			//오퍼랜드가 없다
			AfxMessageBox(_T("오퍼랜드가 없습니다."));
			return -1;
		}
		//오퍼랜드 사용 확인
		for (int i = 4 + oprNum; i < tokenNum; i++) {
			if (tokenType[i] == 8) {
				for (int j = 0; j < oprNum; j++) {
					if (strcmp(tokenTable[i], operands[j]) == 0) {
						//각 오퍼랜드 사용됐을시 오러랜드 채크 배열 셋팅
						tokenTable[i] = new char[4];
						tokenTable[i][0] = ' ';
						tokenTable[i][1] = '1';
						tokenTable[i][2] = ' ';
						tokenTable[i][3] = '\0';
						oprCheck[j]++;
					}
				}
			}
		}
		for (int i = 0; i < oprNum; i++) {
			if (oprCheck[i] == 0) {
				//사용되지 않은 오퍼랜드가 있다
				AfxMessageBox(_T("사용되지 않은 피연산자가 있습니다."));
				return -1;
			}
		}

		char funcdef[20000] = { 0 };

		for (int i = 4 + oprNum + 1; i < tokenNum - 1; i++) {
			strcat(funcdef, tokenTable[i]);
		}
		//*********************************CHANGE**************************************//
		//DEFUN 명령어 제외한 함수 선언 구현부 추출
		char funcfull[20000] = { 0 };
		int start = 0;
		for (int i = 0; i < strlen(func); i++) {
			if (start == 1 && func[i] >= 'A'&&func[i] <= 'Z') {
				start = i;
				break;
			}
			if (func[i] == 'N') {
				start = 1;
			}
		}
		memset(funcfull, 0, 20000);
		strncat(funcfull, func + start, strlen(func) - start - 1);
		functions[functionNum] = new MyFunc(funcfull);
		functionNum++;
		//***************************************************************************//

		MyToy *test = new MyToy(funcdef);
		if (test->errNumber == 0) {
			//성공
			return 0;
		}

		//*******************************CHANGE****************************************//
		else {
			functionNum--;
			delete functions[functionNum];
			functions[functionNum] = NULL;
		}
		//***************************************************************************//
	}
	else {
		printErr(errNumber, line);
		return -1;
	}
}

//함수추가
void CTOYDlg::OnBnClickedButton8()
{
	char *newFun[10];

	CString tmpinput;
	char input[20000] = { 0 };
	char *token;
	int pc = 0;

	//edit control 변수
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	textBox->LineScroll(textBox->GetLineCount());
	textBox->GetWindowTextW(tmpinput);

	for (int i = 0; i < tmpinput.GetLength(); i++) {
		input[i] = tmpinput.GetAt(i);

	}

	//라인별로 확인
	token = strtok(input, "\r\n");
	while (token != NULL) {
		newFun[pc] = new char[strlen(token)];
		strcpy(newFun[pc], token);
		pc++;
		token = strtok(NULL, "\r\n");
	}

	//에러확인
	int check = 0;
	for (int i = 0; i < pc; i++) {
		check += defun(newFun[i], i);
	}
	//없으면 
	if (check == 0) {

		AfxMessageBox(_T("정상적으로 등록되었습니다."));
		//DEFUN 명령어 제외한 함수 선언 구현부 추출
		for (int i = 0; i < pc; i++) {
			int start = 0;
			for (int j = 0; j < strlen(newFun[i]); j++) {
				if (start == 1 && newFun[i][j] >= 'A'&&newFun[i][j] <= 'Z') {
					start = j;
					break;
				}
				if (newFun[i][j] == 'N') {
					start = 1;
				}
			}
			//파일 쓰기
			CFile file;
			memset(input, 0, 20000);
			strcat(input, "\r\n");
			strncat(input, newFun[i] + start, strlen(newFun[i]) - start - 1);
			file.Open(_T("defun.txt"), CFile::modeWrite | CFile::modeNoTruncate | CFile::modeCreate);
			file.SeekToEnd();
			file.Write(input, strlen(input));
			file.Close();
			//initDefun함수로 functions에 다시 등록
			initDefun();
		}
	}
}

//프로그램 저장
void CTOYDlg::OnBnClickedButton10()
{
	CString tmpinput;
	char input[20000] = { 0 };

	//edit control 변수
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT1);
	textBox->GetWindowTextW(tmpinput);

	for (int i = 0; i < tmpinput.GetLength(); i++) {
		input[i] = tmpinput.GetAt(i);
	}

	CFileDialog dlgFile(FALSE, _T("txt"), _T("pre*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
	dlgFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");

	if (IDOK == dlgFile.DoModal()) {

		CString strPathName = dlgFile.GetPathName();

		CFile file;
		file.Open(strPathName, CFile::modeWrite | CFile::modeCreate);
		file.Write(input, strlen(input));

		file.Close();
	}
}