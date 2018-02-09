// ConsoleApplication7.cpp : 定义控制台应用程序的入口点。
//



#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)



int trimSpace(char *str, char *newstr) {
	char *p = str;
	int i, j;
	int ncount;
	i = 0;
	j = strlen(p) - 1;
	while (isspace(p[i]) && p[i] != '\0') {
		i++;
	}
	while (isspace(p[j]) && p[j] != '\0') {
		j--;
	}
	ncount = j - i + 1;
	strncpy(newstr, p + i, ncount);
	newstr[ncount] = '\0';
	return 0;
}

int getKeyByValue(char *keyvaluebuf, char *keybuf,char *valuebuf) {
	int ret = 0;
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL) {
		return ret;
	}
	char *p = keyvaluebuf;
	p = strstr(keyvaluebuf, keybuf);
	if (p == NULL) {
		return -1;
	}
	p = p + strlen(keybuf);
	p = strstr(keyvaluebuf, "=");
	if (p == NULL) {
		return -1;
	}
	p = p + strlen("=");
	ret = trimSpace(p, valuebuf);
	if (ret != 0) {
		printf("the func trimSpace err:%d", ret);
		return ret;
	}
	return ret;

}
void main()
{
	int ret = 0;
	char buf[1024] = { 0 };

	char *keyandvalue = "key2=     value2   ";
	char *key = "key2";
	ret = getKeyByValue(keyandvalue, key, buf );
	if (ret != '\0') {
		printf("func getKeyByValue err:%d", ret);
	}
	printf(" the buf is %s", buf);
}

