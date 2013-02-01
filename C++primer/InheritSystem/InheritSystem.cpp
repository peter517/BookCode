#include <iostream>
#include <stdlib.h>
using namespace std;

class Base {

public:
	int a;
protected:
	int b;
private:
	int c;

};

class DerivedA : public Base {

public:
	DerivedA(){

	}
	void f1(){this->a;}
	void f2(){this->b;}
	//   void f3(){this->c;}
};

class DerivedB : private Base {
public:
	void f1(){}
	void f2(){this->b;}
	//   void f3(){this->c;}

};

int main(){

	cout << "hello world" << endl;

	DerivedA da;
	// int a = da.a;
	//int b = da.b;
	//cout << da.Base::a << endl;

	// DerivedB db;
	// a = db.a

	system("pause");
	return 0;
}
