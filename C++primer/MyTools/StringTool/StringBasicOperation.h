#pragma once

#include <assert.h>
#include<stdlib.h>
#include <math.h>

class StringBasicOperation
{
public:
	StringBasicOperation(void);
	~StringBasicOperation(void);

	//�ַ�����ת����
	static long atoi(const char* src);

	//�ַ����鳤��
	static long strlen(const char *src);

	//����ת�ַ�����,�Ϳ⺯���е㲻һ��,����ָ���ɺ����ڲ����䣬����ȫ
	static char* itoa(const int num,const int radix);

	static char* itoa(const int num);

	//�ַ����鿽��
	static char* strcpy(char *dst, const char *src);

	//�ַ����鿽��ָ������
	static char* strncpy(char *dst, const char *src,const int len);

	//����Դ�ַ����鵽Ŀ���ַ�����ĺ���
	static char* strcat(char *dst, const char *src);

	//����Դ�ַ����鵽Ŀ���ַ�����ĺ��棬ָ����������
	static char* strncat(char *dst, const char *src, const int len);

	//�Ƚ������ַ���
	static int strcmp(const char *str1, const char *srt2);

};
