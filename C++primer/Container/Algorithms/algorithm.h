#pragma  once

template <class InputIterator, class Predicate>
ptrdiff_t _count_if ( InputIterator first, InputIterator last, Predicate pred )
{
	ptrdiff_t ret=0;
	while (first != last) if (pred(*first++)) ++ret;
	return ret;
}


/***********************************************************************
**功能：堆排序
**作者：                                                                   
***********************************************************************/
void maxHeap(int* data, int len, int i){

	int leftPos = 2 * i;
	int rightPos = 2 * i + 1;
    int maxPos = i;

	if (i < len)
	{
		if (leftPos < len && data[maxPos] < data[leftPos])
		{
          maxPos = leftPos;
		}
		if (rightPos < len && data[maxPos] < data[rightPos])
		{
			maxPos = rightPos;
		}

		if (maxPos != i)
		{
			int temp = data[maxPos] ;
			data[maxPos] = data[i];
			data[i] = temp;

            maxHeap(data, len, maxPos);
		}
	}
}


void buildHeap(int *data, int len){
   for (int i = len / 2; i >= 1; i--)
   {
	   maxHeap(data, len, i);
   }
}

void heapSort(int *data, int len){

	buildHeap(data, len);
	int lenBuf = len;

   for (int i = lenBuf - 1; i >=2 ; i--)
   {
       cout << data[1] << " ";
       
	   data[1] = data[i];
       len--;

      maxHeap(data, len , 1);

   }

   cout << data[1] << endl;
}