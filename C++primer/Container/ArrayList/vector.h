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

	//插入数据
	void insert(T, size_t);

	//插入数据到末尾
	void push_back(T);

	//获取列表长度
	size_t getSize(){return m_count;}

	//删除指定位置的数据
	void remove(size_t);

	//获取指定位置的数据
	T get(size_t);

	//修改指定位置的数据
	void modify(T,size_t);

	//清空链表
	void clear();

	//打印链表
	void print();

	//获得指向头位置的迭代器
	iterator begin(){return m_start;}

	//获得指向尾位置的迭代器
	iterator end(){return m_finish;}


private:

	//调整列表长度
	void resize();

	//出界断言
	void outOfBoundsAssert(size_t index){assert(index >=0 && index < (m_finish - m_start));}

	//指向头位置的迭代器
	iterator m_start;

	//指向已用空间尾位置的迭代器
	iterator m_finish;

	//指向可用空间某位的迭代器
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

