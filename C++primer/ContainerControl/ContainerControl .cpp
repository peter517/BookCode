

#include "VectorController.h"  
#include "MapController.h"

#include <stdlib.h>


int main(int argc , char ** argv)
{

	int dataArray[] = {1,2,5,6,3};
	int dataLength = 5;
 
	vector<int> *testList = new vector<int>;
	VectorController<int> *objList = new VectorController<int>(testList);
   
	objList->fillVector(dataArray,dataLength);
	objList->deleteVectorByIndex(4);
	objList->printVector();
	
	map<int, int> *testMap = new map<int, int>;
	MapController *objMap= new MapController(testMap);
	

	objMap->fillMap();
	objMap->deleteMapByKey(3);
	objMap->printMap();

	system("pause");

    return 0;   
}


