  
#include <iostream>
#include <vector>

using namespace std;

class  Exmpl
{
public:

	Exmpl(){cout << "Exmpl()" << endl;}

	Exmpl(Exmpl &e){cout << "Exmpl(const Exmpl &)" << endl;}

	
	Exmpl & operator = (Exmpl & e)
	{
       cout << "Exmpl & operator = (Exmpl & e)" << endl;
	   return *this;
	}

	~Exmpl(){cout << "~Exmpl()" << endl;}
};

void func1(Exmpl e)
{

}

void func2(Exmpl & e)
{

}

Exmpl func3()
{
	Exmpl e;
	return e;
}


int main(int argc , char ** argv)
{
      
     Exmpl e;

//	 func1(e);

//	 func2(e);

	func3();


//	 Exmpl *p = new Exmpl;

//	 vector<Exmpl> vec(3); //创建临时 Exmpl 对象 , 三次调用复制构造函数对每个元素进行直接赋值

	// delete p;

	 system("PAUSE");

     return 0;   
}


