#pragma once

#include "../ArrayList/vector.h"
template <typename T>

class ArrayStack:public Stack<T>
{
public:
	ArrayStack(void){
         list = new _vector<T>(3);
	}

	ArrayStack(int size){
		list = new _vector<T>(size);
	}

	~ArrayStack(void){
		list->clear();
	}

	void push(T);

	T pop();

	T peek();

	int getSize(){return list->getSize();}

	void clear(){list->clear();}

	bool isEmpty(){return list->getSize() > 0 ? true : false;}

private:
   _vector<T> *list;
};

template<typename T>
void ArrayStack<T>::push(T value){
	list->push_back(value);
}

template<typename T>
T ArrayStack<T>::pop(){

	T value = list->get(getSize() - 1);
	list->remove(getSize() - 1);
	return value;

}

template<typename T>
T ArrayStack<T>::peek(){
	return list->get(getSize() - 1);
}

