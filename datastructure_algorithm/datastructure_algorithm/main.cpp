#include <stdio.h>
#include "ArrayList.h"
#include "LinkedList.h"
#include "ArrayStack.h"

int main()
{
	int array[] = { 1, 2, 3 };
	int testArray[] = { 1, 2, 3, 4 };
	ArrayList<int> arrayList = ArrayList<int>(3, array);
	arrayList.Add(4);
	//arrayList.CheckContent(testArray, 4);
	printf("LINH");
	getchar();
}