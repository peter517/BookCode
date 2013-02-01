#pragma  once

#include <stdio.h>
template<class T>
inline T* _allocate(size_t n){

	T *result = (T*)(::operator new(n));
	//T* result = (T*)malloc(n);
	if (result == NULL)
	{
		exit(0);
	}
	return result;
}

template<class T>
inline void  _deallocate(T*){
	::operator delete(T);
	//free(T)
}