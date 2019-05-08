#ifndef _MYSTACK_H_
#define _MYSTACK_H_

class MyStack{
private:
	char* item[20000];
	int count;

public:
	MyStack();
	void push(char *);
	char* pop();
	int size();

};
char* toyValue(char* op, char* operand2, char* operand1);
#endif