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

	//��������
	void add(T,int);

	//���뵽���
	void add(T);

	//��ȡ�б���
	int getSize(){return m_size;}

	//ɾ��ָ��λ�õ�����
	void remove(int);

	//��ȡָ��λ�õ�����
	T get(int);

	//�޸�ָ��λ�õ�����
	void modify(T,int);

	//��������
	void reverse();

	//�������
	void clear();

	//��ӡ����
	void print();

private:

	//�ڵ���
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

	//��ȡָ��λ�ýڵ��ָ��
	Node* getNodePointer(int);

	//��ӵ�һ���ڵ�
	void firstAdd(Node*);

	//���������ڵ�
	void connectTwoNode(Node*,Node*);

	//������
	int m_size;

	//����ͷָ��
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

	//����ǵ�һ�β���
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

	//����ǵ�һ�β���
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

	//����±곬���ڵ㷶Χ
	assert(index <  getSize() && index >= 0);

	Node<T> *head = m_head;
	//����С�ڳ��ȵ�һ�룬��ͷ��ʼ����
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

    //û�нڵ��ֻ��һ���ڵ�
	if (m_head->next == NULL || m_head->next->next == NULL)
	{
		return;
	}

	//��ʼ���ڵ�
	Node<T> *prePtr = m_head;
	Node<T> *currentPtr = prePtr->next;

	//����ͷ�ڵ�
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

