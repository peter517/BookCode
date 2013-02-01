#include "StringBasicOperation.h"
#include "MyString.h"

#include <iostream>
#include<stdlib.h>
#include <stdio.h>

using namespace std;


int main(){

	MyString str(' ');
	
	str =  str + '1';
	str.printData();
	system("pause");
    
	return 0;
}
