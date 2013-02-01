// VectorController.h: interface for the VectorController class.
//
//////////////////////////////////////////////////////////////////////


#if !defined(AFX_VECTORCONTROLLER_H__7B64A0E1_D253_4D67_854C_2F01F0F5E646__INCLUDED_)
#define AFX_VECTORCONTROLLER_H__7B64A0E1_D253_4D67_854C_2F01F0F5E646__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <vector>
using namespace std; 
#include <map>
#include <iostream>
#include<assert.h>

//模板类的定义和声明都要放在头文件中

//模板函数或模板类本身不能直接生成代码，而必须和特定的数据类型结合后才能生成代码的缘故吧。
//而CPP文件一般是要生成OBJ文件的
template <typename T>
class VectorController  
{
public:

	VectorController(vector<T>* dataVector){
        this->m_vector = dataVector;
	}

    void fillVector(T[], int);
    void deleteVectorByIndex(int);
    void printVector();

	virtual ~VectorController(){
		delete m_vector;
	}

private:
	vector<T>* m_vector;

};

template<typename T>
void VectorController<T>::fillVector(T dataArray[], int length){
	
	for (int i = 0; i < length; i++)
	{
		m_vector->push_back(dataArray[i]);
	}	
	
}

template<typename T>
void VectorController<T>::deleteVectorByIndex(int index){
    
    vector<int>::iterator iter = m_vector->begin();
	assert(index < m_vector->size());
	m_vector->erase(iter + index);
}

template<typename T>
void VectorController<T>::printVector()
{
	
	//	cout << m_vector->at(0) << endl;
	
	cout << "vector Info: " << endl;
	vector<int>::iterator iter = m_vector->begin();
	
	while(iter != m_vector->end()){
		cout << *iter++ << endl;
	}
}

#endif // !defined(AFX_VECTORCONTROLLER_H__7B64A0E1_D253_4D67_854C_2F01F0F5E646__INCLUDED_)
