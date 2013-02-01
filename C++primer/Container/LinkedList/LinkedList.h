#pragma once

#include <iostream>
using namespace std; 

#include<assert.h>

template <typename T>
class LinkedList  
{
public:

	LinkedList(){
		T t = 0;
		m_size = 0;
		m_head = new Node<T>(t);
	}

	//插入数据
	void add(T,int);

	//插入到最后
	void add(T);

	//获取列表长度
	int getSize(){return m_size;}

	//删除指定位置的数据
	void remove(int);

	//获取指定位置的数据
	T get(int);

	//修改指定位置的数据
	void modify(T,int);

	//倒置链表
	void reverse();

	//清空链表
	void clear();

	//打印链表
	void print();

private:

	//节点类
	struct Node{
	public:
		Node(T value){
			this->value = value;
			next = NULL;
			pre = NULL;
		}
		T value;
		Node* next;
		Node* pre;
	};

	//获取指定位置节点的指针
	Node* getNodePointer(int);

	//添加第一个节点
	void firstAdd(Node*);

	//连接两个节点
	void connectTwoNode(Node*,Node*);

	//链表长度
	int m_size;

	//链表头指针
	Node * m_head;

	virtual ~LinkedList(){
		delete m_head;
	}
};


/*
template<typename T>
 LinkedList<T>::Node::Node(T value){
	this->value = value;
	next = NULL;
	pre = NULL;
}*/

template<typename T>
void LinkedList<T>::add(T value, int index){

	Node * newPtr = new Node(value);

	//如果是第一次插入
	if (m_head->next == NULL)
	{
		firstAdd(newPtr);
	}else{

		Node<T> *insertPtr = getNodePointer(index);
		Node<T> *prePtr = insertPtr->pre;

       connectTwoNode(prePtr, newPtr);
	   connectTwoNode(newPtr, insertPtr);

	}
    
	m_size++;
}

template<typename T>
void LinkedList<T>::add(T value){

	Node * newPtr = new Node(value);

	//如果是第一次插入
	if (m_head->next == NULL)
	{
		firstAdd(newPtr);

	}else{

		Node *prePtr = getNodePointer(getSize() - 1);

		connectTwoNode(prePtr, newPtr);
		connectTwoNode(newPtr, m_head);

	}

	m_size++;
}

template<typename T>
void LinkedList<T>::firstAdd(Node * newPtr){

	connectTwoNode(m_head, newPtr);
	connectTwoNode(newPtr, m_head);

}

template<typename T>
void LinkedList<T>::connectTwoNode(Node * prePtr, Node * newPtr){

	prePtr->next = newPtr;
	newPtr->pre = prePtr;

}


template<typename T>
typename LinkedList<T>::Node  * LinkedList<T>::getNodePointer(int index){

	//如果下标超出节点范围
	assert(index <  getSize() && index >= 0);

	Node<T> *head = m_head;
	//坐标小于长度的一半，从头开始遍历
	if (index < getSize() >> 1)
	{
		for (int i = 0; i <= index; i++)
		{
			head = head->next;
		}
	}else{
		for (int i = getSize() - 1; i >= index; i--)
		{
			head = head->pre;
		}
	}

	return head;


}

template<typename T>
void LinkedList<T>::remove(int index){

	Node<T> *removePtr = getNodePointer(index);

	Node<T> *nextPtr = removePtr->next;
	Node<T> *prePtr = removePtr->pre;

	connectTwoNode(prePtr,nextPtr);

	m_size--;
	delete removePtr;

}


template<typename T>
T LinkedList<T>::get(int index){

	Node<T> *p = getNodePointer(index);
	return p->value;

}

template<typename T>
void LinkedList<T>::modify(T value,int index){

	Node<T> *p = getNodePointer(index);
	p->value = value;

}

template<typename T>
void LinkedList<T>::reverse(){

    //没有节点或只有一个节点
	if (m_head->next == NULL || m_head->next->next == NULL)
	{
		return;
	}

	//初始化节点
	Node<T> *prePtr = m_head;
	Node<T> *currentPtr = prePtr->next;

	//包括头节点
	int count = getSize() + 1;

	while (count--)
	{

		Node<T> * nextPtr = currentPtr->next;

		connectTwoNode(currentPtr,prePtr);

		prePtr = currentPtr;
		currentPtr = nextPtr;

	}

}

template<typename T>
void LinkedList<T>::clear(){

	Node<T> *p = m_head->next;

	while(p != NULL){
		Node<T> *temp = p;
		p = p->next;
		delete temp;
	}

	m_head->next = NULL;

}

template<typename T>
void LinkedList<T>::print(){

	Node<T> *p = m_head->next;

	int count = m_size;

	while(count--){
		cout << p->value << " " << endl;
		p = p->next;
	}

}

