#include "MyString.h"

MyString::MyString(const char *data)
{
	if (data == NULL)
	{
		m_capacity = 0;
		m_size = 0;
	}else{
		m_size= strlen(data);
		m_capacity = m_size;
        m_data = new char[m_capacity];
		arrayCopy(m_data, data, m_size);
	}

}

MyString::MyString(const char &data)
{
		m_size= 1;
		m_capacity = 1;
		m_data = new char[m_capacity];
		arrayCopy(m_data, &data, m_size);
}

MyString::~MyString(void)
{
	clear();
}

MyString::MyString(const MyString & other)
{
	copyData(other);
}

 MyString & MyString::operator = (const MyString & other){

	if (&other == this)
	{
		return *this;
	}

    clear();
	copyData(other);
   
	return *this;
}

char & MyString::operator[](const int index){
	   assert(index < m_capacity);
       return m_data[index];
}

void MyString::copyData(const MyString & other){
    
	m_capacity = other.m_capacity;
	m_size = other.m_size;

	m_data = new char[m_capacity];
	arrayCopy(m_data, other.m_data, m_size);

}

 const MyString operator+(const MyString & str1, const MyString & str2){

	 MyString dstStr(str1);

	 for (int i = 0; i < str2.m_size; i++)
	 {
		 if (dstStr.m_size + 1> dstStr.m_capacity)
		 {
			 dstStr.resize();
		 }

		 dstStr[dstStr.m_size] = str2.m_data[i];
		 dstStr.m_size++;
	 }
	
	 return dstStr;

 }


void MyString::arrayCopy(char * dst, const char *src, int len)
{
	for (int i = 0; i < len; i++)
	{
		dst[i] = src[i];
	}
}

void MyString::clear(){

	if (m_size != 0)
	{
		delete []m_data;
		m_size = 0;
		m_capacity = 0;
	}

}

void MyString::printData(){

	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i];
	}
	cout << endl;

}

void MyString::resize(){

	char *buf = new char[m_size];

	arrayCopy(buf, m_data, m_size);

	int bufSize = m_size;

	clear();

	m_size = bufSize;
	m_capacity = max(m_size, 1) * 2;

    m_data = new char[m_capacity];

	arrayCopy(m_data, buf, m_size);

}




