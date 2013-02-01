#pragma once


#include<assert.h>
#include "../Allocator/memory.h"

template <typename T, class Alloc = _allocator<T>>
class _vector
{

	void init(size_t size = 3){
		m_start = Alloc::alloc(size * sizeof(T));
		m_finish = m_start;
		m_available = m_start + size; 
	}

public:

	typedef T* iterator; 

	_vector(size_t size = 3){
		init(size);
	}

	~_vector(void){
		delete[] m_start;
	}

	//��������
	void insert(T, size_t);

	//�������ݵ�ĩβ
	void push_back(T);

	//��ȡ�б���
	size_t getSize(){return m_count;}

	//ɾ��ָ��λ�õ�����
	void remove(size_t);

	//��ȡָ��λ�õ�����
	T get(size_t);

	//�޸�ָ��λ�õ�����
	void modify(T,size_t);

	//�������
	void clear();

	//��ӡ����
	void print();

	//���ָ��ͷλ�õĵ�����
	iterator begin(){return m_start;}

	//���ָ��βλ�õĵ�����
	iterator end(){return m_finish;}


private:

	//�����б���
	void resize();

	//�������
	void outOfBoundsAssert(size_t index){assert(index >=0 && index < (m_finish - m_start));}

	//ָ��ͷλ�õĵ�����
	iterator m_start;

	//ָ�����ÿռ�βλ�õĵ�����
	iterator m_finish;

	//ָ����ÿռ�ĳλ�ĵ�����
	iterator m_available;

};

template<typename T, class Alloc>
void _vector<T, Alloc>::insert(T value, size_t index){

	outOfBoundsAssert(index);

	resize();

	_copy_backward(m_start + index, m_finish - 1, m_finish);

	m_start[index] = value;
	m_finish++;

}

template<typename T, class Alloc>
void _vector<T, Alloc>::push_back(T value){

	resize();

    _uninitialized_fill_n(m_finish, 1, value);
	m_finish++;

}

template<typename T, class Alloc>
void _vector<T, Alloc>::remove(size_t index){

	outOfBoundsAssert(index);

	_uninitialized_copy(m_start + 1, m_finish, m_start);
	m_finish--;


}

template<typename T, class Alloc>
T _vector<T, Alloc>::get(size_t index){

	outOfBoundsAssert(index);
	return m_start[index];

}

template<typename T, class Alloc>
void _vector<T, Alloc>::modify(T data, size_t index){

	outOfBoundsAssert(index);
	m_start[index] = data;

}

template<typename T, class Alloc>
void _vector<T, Alloc>::clear(){

	delete[] m_start;
	init();

}

template<typename T, class Alloc>
void _vector<T, Alloc>::resize(){

	if (m_finish + 1 == m_available)
	{
		size_t oldLen = m_finish - m_start;
		size_t newLen = (m_finish - m_start) * 2;

		iterator newStart = Alloc::alloc(newLen  * sizeof(T));
        _uninitialized_copy(m_start, m_finish, newStart);

        m_start = newStart;
	    m_finish = m_start + oldLen;
		m_available = m_start + newLen;

	}

	}



template<typename T, class Alloc>
void _vector<T, Alloc>::print(){

	for (iterator i = m_start; i != m_finish; i++)
	{
		cout << *i << endl;
	}

}

