#define NDEBUG

#include "Stack.h"
#include "LinkedStack.h"
#include "ArrayStack.h"

#include <stdlib.h>
#include <windows.h> 
#include <stdio.h>
#include <string>

#include "../Algorithms/algorithm.h"
#include "../Algorithms/functional.h"

using namespace std;

#include "test.h"
#include <vector>

class A{
public:
	 A(){
		test();
	}
	virtual A*  test(){cout << "A" << endl; return this;}
};

class B:public A{
public:
	//两种都合法
	//A* test(){cout << "B" << endl;return this;}
	 B* test(){cout << "B" << endl;return this;}
};


void f(const int* a, const int* b){
   
}

int main(){

	A*a = new B();
	a->test();

	int b[3] = {1,2,3};
	int c[3] = {1,2,3};

	int *d;
	int *e;

	f(d, e);

//	B *b = dynamic_cast<B*>(a);
//	B *b = (B*)(a);

	if (typeid(*a) == typeid(B))
	{
		int i;
		cout << typeid(*a).name() << endl;
	}

//	vector<A> a(3);

	//heapSort(data, 6);

/*
	for (int i = 0; i < 6; i ++)
	{
		cout << data[i] << endl;
	}*/

/*
	_vector<int> a;
	for (int i = 11; i <= 19; i++)
	{
		a.insert(i,0);
	}

	a.print();

	cout << _count_if(a.begin(), a.end() ,_not1(_bind2nd(_less<int>(), 12))) << endl;*/
 
/*
	Stack<int> *s = new ArrayStack<int>;
	
		for (int i = 1; i <= 10; i++)
		{
			s->push(i);
		}

		for (int i = 1; i <= 10; i++)
		{
			cout << s->pop() << endl;
		}
		
	    cout << s->getSize() << endl;*/

/*
	_vector<int> a;
	for (int i = 11; i <= 20; i++)
	{
		a.push_back(i);
	}

	a.remove(a.getSize());

	_vector<int>::iterator it = a.begin();

	for (_vector<int>::iterator it = a.begin();it != a.end(); it++)
	{
		cout << *it << endl;
	}

	_vector<int>::iterator result =  find(a.begin(),a.end(), 20);

	if (result != a.end())
	{
			cout << *result<< endl;
	}else{
		cout << "mei" << endl;
	}*/


	system("pause");
	return 0;
}