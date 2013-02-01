#pragma  once

#include <new.h>

template<class T1, class T2>
inline void _construct(T1 *p, const T2 & value){
	   new (p) T2(value);
}

template<class T1, class T2>
inline void _destory(T1 *p){
	   p->~destory();
}