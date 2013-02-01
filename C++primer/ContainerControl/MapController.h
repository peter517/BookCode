// MapController.h: interface for the MapController class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPCONTROLLER_H__4FF76D18_29C2_4DC4_A244_96E23CCAC68D__INCLUDED_)
#define AFX_MAPCONTROLLER_H__4FF76D18_29C2_4DC4_A244_96E23CCAC68D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>
#include <iostream>
using namespace std; 

class MapController  
{
public:
	MapController(map<int, int> * dataMap){
           this->m_Map = dataMap;
	}
	void fillMap();
	void deleteMapByKey(int key);
	void printMap();
	virtual ~MapController(){
		delete m_Map;
	}

private:
	map<int, int> * m_Map;
};

#endif // !defined(AFX_MAPCONTROLLER_H__4FF76D18_29C2_4DC4_A244_96E23CCAC68D__INCLUDED_)
