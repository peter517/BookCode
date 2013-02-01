#include<iostream.h>
#include<string>

using namespace std;


class A{
public:
  char a;
  int b;
  short c;

  A (){
	  cout << (int)&a << endl;
	  cout << (int)&b << endl;
	  cout << (int)&c << endl;
	  cout << endl;
  }
};

class B{
public:

  int b;
  short c;
  char a;

  B (){
	  cout << (int)&b << endl;
	  cout << (int)&c << endl;
	  cout << (int)&a << endl;
	  cout << endl;
  }
};


class C{
public:
	virtual void fun1(){};
};

class D: public C{
public:
	int a;
	D(){a = 1;}
	virtual void fun1(){cout << a << endl;}
	void f(){cout << a << endl;}
};

void f(string strArray[]){
cout<<"sizeof(a)"<<sizeof(strArray)<<endl;
}

int main(){

  //string strArray[] = {"123", "321"};
  //f(strArray);

 // A *a = new A();
 // B *b = new B();
 // cout<<sizeof(C)<<endl;

 // cout<<"sizeof(d)"<<sizeof(D)<<endl;
   

  return 0;
}


