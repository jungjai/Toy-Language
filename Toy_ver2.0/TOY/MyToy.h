#ifndef _MYTOY_H_
#define _MYTOY_H_
#define MAX_TOKEN 20000
class MyToy{
public:
	int lcount;
	int rcount;
	char *tokenTable[MAX_TOKEN];
	int tokenType[MAX_TOKEN];
	int type;
	int tokenNum;

	char value[10];
	MyToy *operand1;
	MyToy *operand2;
	char op[10];
	int errNumber;
public:
	MyToy(char* input);
	MyToy();
	void lexicalAnalysis(char *input);
	void syntaxAnalysis();
};
char* toPre(MyToy *input);
char* toInter(MyToy *input);
int checkErr(MyToy *input);

#endif

#define LEFT_ERR -1
#define RIGHT_ERR -2
#define REAL_ERR -3
#define NEGATIVE_ERR -4
#define UNDEFINE_ERR -5
#define DEFAULT_ERR -6
#define COUNT_ERR -7
#define NOOP_ERR -8

#define FUN 10
#define CST 11
#define VAR 12
