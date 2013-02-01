#pragma once

#include <iostream>

using namespace std; 

#include<assert.h>


template <typename T>
class Stack
{
public:
	Stack(void){}
	virtual void push(T)=0;
	virtual T pop()=0;
	virtual T peek()=0;
	virtual int getSize()=0;
	virtual void clear()=0;	
	virtual bool isEmpty()=0;
};
