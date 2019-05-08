
#define MAX_OPR 5
#define MAX_TOKEN 20000
#define MAX_FUNC 200

#ifndef _MYFUNC_H_
#define _MYFUNC_H_


class MyFunc{
public:
	char op[15];
	char *operands[MAX_OPR];
	int oprNum;

	char *tokenTable[MAX_TOKEN];
	int tokenNum;

public:
	MyFunc(char*);

};


#endif

