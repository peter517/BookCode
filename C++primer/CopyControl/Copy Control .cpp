  
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

//	 vector<Exmpl> vec(3); //������ʱ Exmpl ���� , ���ε��ø��ƹ��캯����ÿ��Ԫ�ؽ���ֱ�Ӹ�ֵ

	// delete p;

	 system("PAUSE");

     return 0;   
}


