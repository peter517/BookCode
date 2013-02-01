#pragma once

#include<string.h>
#include <iostream>
#include <assert.h>
using namespace std;

class MyString
{
public:
	MyString(const char *data = NULL);//�����������ַ���
	MyString(const char &data);
	MyString(const MyString &other);

	MyString & operator = (const MyString &other);
	char & operator[](const int index);

	friend const MyString  operator+(const MyString & str1, const MyString & str2);

	//�������
	void clear();
	//�ж��Ƿ�Ϊ��
	bool isEmpty(){return m_size == 0? true : false;}
	//��ӡ����
	void printData();
	
	~MyString(void);
private:

	//������������
	void copyData(const MyString & other);
	//���µ�����С
	void resize();
	//�����ַ�����
	void arrayCopy(char * dst, const char *src, int len);

    int m_capacity;
	int m_size;
	char *m_data;
};


