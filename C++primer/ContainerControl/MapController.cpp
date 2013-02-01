// MapController.cpp: implementation of the MapController class.
//
//////////////////////////////////////////////////////////////////////

#include "MapController.h"


void MapController::fillMap()
{
	for (int i = 0; i < 10; i++)
	{
		m_Map->insert(pair<int,int>(i, 10 - i));
	}
	
}

void MapController::deleteMapByKey(int key)
{
	m_Map->erase(key);
}

void MapController::printMap()
{

//	map<int, int>::iterator iterFind = m_Map->find(1);
//	cout << "iterFind: " << iterFind->first << " " << iterFind->second << endl;
	
	cout << "map Info: " << endl;
	map<int, int>::iterator iter = m_Map->begin();
	
	while(iter != m_Map->end()){
		cout << iter->first << " " << iter->second << endl;
		iter++;
	}
}
