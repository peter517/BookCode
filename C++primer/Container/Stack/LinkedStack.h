#pragma once

#include "Stack.h"
#include "../LinkedList/LinkedList.h"

template <typename T>
class LinkedStack:public Stack<T>
{
public:

	LinkedStack(void){
		list = new LinkedList<T>();
	}

	~LinkedStack(void){
		list->clear();
	}

	void push(T);

	T pop();

	T peek();

	int getSize(){return list->getSize();}

	void clear(){list->clear();}

	bool isEmpty(){return list->getSize() > 0 ? true : false;}


private:
	LinkedList<T> *list;
};

template<typename T>
void LinkedStack<T>::push(T value){
	list->insert(value,0);
}

template<typename T>
T LinkedStack<T>::pop(){

	T value = list->get(0);
	list->remove(0);
	return value;

}

template<typename T>
T LinkedStack<T>::peek(){
	return list->get(0);
}
