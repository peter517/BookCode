#pragma once

#include "my_alloc.h"
#include "my_construct.h"

/***********************************************************************
**�ڴ������������                                                              
***********************************************************************/

template<class T>
class _allocator
{
public:

	_allocator(void);
	~_allocator(void);

    static T* alloc(size_t n);
	static void dealloc(T *t);
	static void construct(T *p, const T & value);
	static void destroy(T *p);

};

template<class T>
T* _allocator<T>::alloc(size_t n){
	T *result = (T*)(::operator new(n));
	//T* result = (T*)malloc(n);
	if (result == NULL)
	{
		exit(0);
	}
	return result;
}

template<class T>
void  _allocator<T>::dealloc(T* t){
	::operator delete(T);
	//free(T)
}

template<class T>
void  _allocator<T>::construct(T *p, const T & value){
    new (p) T(value);
}

template<class T>
void  _allocator<T>::destroy(T *p){
	 p->~destory();
}


/***********************************************************************
**�ڴ濽����������                                                              
***********************************************************************/

#include "../Iterator/iterator.h"

/***********************************************************************
**���ܣ����ָ������
**���ߣ�                                                                   
***********************************************************************/
template<class ForwardIterator, class size, class T>
inline ForwardIterator _uninitialized_fill_n(ForwardIterator start, size n, const T &x)
{
	typedef typename _type_traits<T>::is_POD_type is_POD;
	return uninitialized_fill_n_aux(start, n, x, is_POD());
}

//����ǻ������ͻ���ָ������
template<class ForwardIterator, class size, class T>
inline ForwardIterator uninitialized_fill_n_aux(ForwardIterator start, size n,  const T &x, _true_type)
{
	while (n--){
		*start++ = x;
	}
	return start;
}

//�������������
template<class ForwardIterator, class size, class T>
inline ForwardIterator uninitialized_fill_n_aux(ForwardIterator start, size n, const T &x, _false_type )
{

	return start;
}


/***********************************************************************
**���ܣ����󿽱�ָ������
**���ߣ�                                                                   
***********************************************************************/
template<class ForwardIterator>
inline ForwardIterator _uninitialized_copy(ForwardIterator start, ForwardIterator finsh, ForwardIterator newStart)
{

	typedef typename _iterator_traits<ForwardIterator>::value_type T;
	typedef typename _type_traits<T>::is_POD_type is_POD;

	return uninitialized_copy(start, finsh, newStart, is_POD());
}

//����ǻ������ͻ���ָ������
template<class ForwardIterator>
inline ForwardIterator uninitialized_copy(ForwardIterator start, ForwardIterator finsh, ForwardIterator newStart, _true_type)
{
	while (start < finsh){
		*newStart++ = *start++;
	}
	return start;
}



//�������������
template<class ForwardIterator>
inline ForwardIterator uninitialized_copy(ForwardIterator start, ForwardIterator finsh, ForwardIterator newStart, _false_type )
{

	return start;
}



/***********************************************************************
**���ܣ���ǰ����ָ������
**���ߣ�                                                                   
***********************************************************************/
template<class ForwardIterator>
inline ForwardIterator _copy_backward(ForwardIterator start, ForwardIterator finsh, ForwardIterator newFinish)
{

	typedef typename _iterator_traits<ForwardIterator>::value_type T;
	typedef typename _type_traits<T>::is_POD_type is_POD;

	return copy_backward(start, finsh, newFinish, is_POD());
}

//����ǻ������ͻ���ָ������
template<class ForwardIterator>
inline ForwardIterator copy_backward(ForwardIterator start, ForwardIterator finsh, ForwardIterator newFinish, _true_type)
{
	while (start <= finsh){
		*newFinish-- = *finsh--;
	}
	return start;
}

//�������������
template<class ForwardIterator>
inline ForwardIterator copy_backward(ForwardIterator start, ForwardIterator finsh, ForwardIterator newFinish, _false_type )
{

	return start;
}