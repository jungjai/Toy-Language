
#include "stdafx.h"
#include "MyFunc.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

MyFunc::MyFunc(char *input){
	//멤버 초기화
	memset(op, 0, 15);
	oprNum = 0;
	tokenNum = 0;

	char *token;
	char tmpdef[10] = { 0 };
	int i = 0;
	int j = 0;

	//선언부
	while (input[i] != ')'){
		//(나오기 전까지가 함수이름
		while (input[i] != '('){
			op[i]= input[i];
			i++;
		}
		i++;
		//파라미터 나오는 부분 tmpdef에 저장
		while (input[i] != ')'){
			tmpdef[j] = input[i];
		i++;
		j++;
		}
	}
	i++;

	
	char tmpopr[10] = { 0 };
	for (int k = 0; k < strlen(tmpdef); k++){
		//err 파라미터는 알파벳 소문자 하나만
		if (tmpdef[k] >= 'a' && tmpdef[k] <= 'z'){
			char tmpchar[2];
			tmpchar[0] = tmpdef[k];
			tmpchar[1] = '\0';
			strcat(tmpopr, tmpchar);
		}
		else if (tmpdef[k] == ' '){
				operands[oprNum] = new char[strlen(tmpopr)];
				memset(operands[oprNum], 0, strlen(tmpopr));
				strcpy(operands[oprNum], tmpopr);
				oprNum++;
				memset(tmpopr, 0, 10);
		}
		else{
			//err 파라미터는 알파벳 소문자만
		}
	}
	operands[oprNum] = new char[strlen(tmpopr)];
	memset(operands[oprNum], 0, strlen(tmpopr));
	strcpy(operands[oprNum], tmpopr);
	oprNum++;

	//똑같이 (,),숫자, 문자로 토큰을 나눈다
	while (input[i] != '\0'){
		if (input[i] == '('){
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = '(';
			tokenTable[tokenNum][1] = '\0';
			tokenNum++; 
		}
		else if (input[i] == ')'){
			tokenTable[tokenNum] = new char[2];
			tokenTable[tokenNum][0] = ')';
			tokenTable[tokenNum][1] = '\0';
			tokenNum++;
		}
		else if (input[i] == '.' || input[i] == '-' || (input[i] >= '0' && input[i] <= '9')){
			int tmp = i;
			while (input[i] == '.' || input[i] == '-' || (input[i] >= '0'&&input[i] <= '9'))
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], input + tmp, i - tmp);
			tokenNum++;
			i--;
		}
		//구현부에도 파라미터가 쓰이기 때문에 소문자도 받는다
		else if ((input[i] >= 'A'&& input[i] <= 'Z') || (input[i] >= 'a'&&input[i] <= 'z') || input[i]=='/'){
			int tmp = i;
			while ((input[i] >= 'A'&& input[i] <= 'Z') || (input[i] >= 'a'&&input[i] <= 'z') || input[i] == '/')
				i++;
			tokenTable[tokenNum] = new char[i - tmp + 1];
			memset(tokenTable[tokenNum], 0, i - tmp + 1);

			strncpy(tokenTable[tokenNum], input + tmp, i - tmp);
			tokenNum++;
			i--;
		}
		i++;
	}

}