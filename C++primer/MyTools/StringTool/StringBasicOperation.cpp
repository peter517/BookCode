#include "StringBasicOperation.h"

const char g_charTable[10] = {'0','1','2','3','4','5','6','7','8','9'};

char* resize(char *initCharPtr, int initSize, int finalSize){

     char *finalCharPtr = new char[finalSize];

	 for (int i = 0; i < initSize; i++)
	 {
             finalCharPtr[i] = initCharPtr[i];
	 }

	 delete []initCharPtr;

	 return finalCharPtr;
}


StringBasicOperation::StringBasicOperation(void)
{
}

StringBasicOperation::~StringBasicOperation(void)
{
}



long StringBasicOperation::atoi(const char* src )
{

	//默认字符数组src是以'\0'结束的
   assert(src != NULL);

   int len = strlen(src);
   
   int pos = 0;
   bool isNumNegative = (src[0] == '-');
   if (isNumNegative)
   {
	   pos++;
   }

   int num = 0;
   for (int i = pos; i < len; i++)
   {
	    int digit = int(src[i] - g_charTable[0]);
		assert(digit >=0 && digit <= 9);

        num += int(pow(10.0f,len - 1 - i) * digit);
   }

   if (isNumNegative)
   {
	   num = -num;
   }

   return num;
}

long StringBasicOperation::strlen( const char *src )
{
	//默认字符数组src是以'\0'结束的
	assert(src != NULL);

	int count = 0;
	while(*src++ != '\0'){
		count++;
	}

	return count;
}

char* StringBasicOperation::itoa(const int num)
{
	return itoa(num,10);
}


char* StringBasicOperation::itoa(const int num,const int radix)
{

	assert(radix <= 10 && radix>=1 );

	int tempNum = 0;

	bool isNumNegative = (num < 0);
	if (isNumNegative)
	{
		tempNum = -num;
	}else{
        tempNum = num;
	}

	int initSize = 3;
	char *tempCharArray = new char[initSize];

	int pos = 0;
	while(tempNum != 0){

		int digit =  tempNum % radix;
		tempNum /= radix; 

		//如果空间不足
		if (pos >= initSize)
		{
            int finalSize = initSize * 2;
            tempCharArray = resize(tempCharArray, initSize, finalSize);
            initSize = finalSize; 
		}

		tempCharArray[pos++] = g_charTable[digit];
		
	}

	//之所以增加两个空间是为了添加 '-' 和 '\0'两个字符
	char *dstCharArray = new char[initSize + 2];


	int i = 0;
	if (isNumNegative)
	{
       dstCharArray[i++] = '-';
	}

	while(pos--){
       dstCharArray[i++] = tempCharArray[pos];
	}

	dstCharArray[i] = '\0';

	return dstCharArray;

}



char* StringBasicOperation::strcpy(char *dst,const char *src){

	//默认字符数组src是以'\0'结束的
	assert((dst != NULL) && (src != NULL));

	char *init = dst;

	while((*dst++ = *src++) != '\0'){}

    return init;

}

/***********************************************************************
**功能：这个和系统函数不太一样，系统中：
             当len大于src长度时候，填充'\0'到dst至长度len
			 当len小于src长度时候，直接拷贝，dst后没有加上'\0'
**作者：                                                                   
***********************************************************************/
char* StringBasicOperation::strncpy(char *dst, const char *src, const int len){

	//默认字符数组src是以'\0'结束的
	assert((dst != NULL) && (src != NULL));

	if (len <= 0)
	{
		return dst;
	}

	char *init = dst;
	int tempLen = len;

	//当len大于src长度时候 只拷贝src长度的字符，这样就造成了dst的最终长度为src的长度，而不是len
	while((*dst++ = *src++) != '\0' && (--tempLen)){}

	init[len] = '\0';

	return init;
}

char* StringBasicOperation::strcat(char *dst, const char *src){

	//默认字符数组src是以'\0'结束的
	assert((dst != NULL) && (src != NULL));

	char *init = dst;

	while(*dst != '\0'){dst++;}

	strcpy(dst,src);

	return init;

}

char* StringBasicOperation::strncat(char *dst, const char *src, const int len){

	//默认字符数组src是以'\0'结束的
	assert((dst != NULL) && (src != NULL));

	if (len <= 0)
	{
		return dst;
	}

    char *init = dst;
    while(*dst != '\0'){dst++;}

	strncpy(dst, src, len);

	return init;
}


int StringBasicOperation::strcmp(const char *str1, const char *str2){

    while( *str1 != '\0' && *str2 != '\0'){

		if (*str1 > *str2)
		{
			return 1;
		}else if ( *str1 < *str2){
			return -1;
		}

		str1++;
        str2++;
	}
	
	return 0;
}
