#pragma once

#include <assert.h>
#include<stdlib.h>
#include <math.h>

class StringBasicOperation
{
public:
	StringBasicOperation(void);
	~StringBasicOperation(void);

	//字符数组转整型
	static long atoi(const char* src);

	//字符数组长度
	static long strlen(const char *src);

	//整型转字符数组,和库函数有点不一样,这里指针由函数内部分配，更安全
	static char* itoa(const int num,const int radix);

	static char* itoa(const int num);

	//字符数组拷贝
	static char* strcpy(char *dst, const char *src);

	//字符数组拷贝指定长度
	static char* strncpy(char *dst, const char *src,const int len);

	//拷贝源字符数组到目的字符数组的后面
	static char* strcat(char *dst, const char *src);

	//拷贝源字符数组到目的字符数组的后面，指定拷贝长度
	static char* strncat(char *dst, const char *src, const int len);

	//比较两个字符串
	static int strcmp(const char *str1, const char *srt2);

};
