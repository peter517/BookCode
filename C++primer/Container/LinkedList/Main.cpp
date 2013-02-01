
#include "LinkedList.h"

#include <iostream>
#include<stdlib.h>

using namespace std;

int main(){


	LinkedList<int> *list = new LinkedList<int>();


	for (int i = 1; i <= 10; i++)
	{
		list->add(i);
	}

	/*
    list->remove(7);
    	list->modify(0,1);
        list->reverse();*/
    
	list->print();

	system("pause");

	return 0;
}