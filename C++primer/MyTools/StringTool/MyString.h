#pragma once

#include<string.h>
#include <iostream>
#include <assert.h>
using namespace std;

class MyString
{
public:
	MyString(const char *data = NULL);//可以声明空字符串
	MyString(const char &data);
	MyString(const MyString &other);

	MyString & operator = (const MyString &other);
	char & operator[](const int index);

	friend const MyString  operator+(const MyString & str1, const MyString & str2);

	//清空数据
	void clear();
	//判断是否为空
	bool isEmpty(){return m_size == 0? true : false;}
	//打印数据
	void printData();
	
	~MyString(void);
private:

	//拷贝字数数据
	void copyData(const MyString & other);
	//重新调整大小
	void resize();
	//拷贝字符数组
	void arrayCopy(char * dst, const char *src, int len);

    int m_capacity;
	int m_size;
	char *m_data;
};


