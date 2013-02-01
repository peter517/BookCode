
#include "vector.h"

#include <iostream>
#include<stdlib.h>


using namespace std;

int main(){

    _vector<int> *list = new _vector<int>();

	for (int i = 1; i <= 10; i++)
	{
		list->push_back(i);
	}

	list->print();

	system("pause");
	return 0;
}