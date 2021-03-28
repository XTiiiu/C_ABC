#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int partition(int array[], int low, int high)
{
	int tmp = -1;
	int pv = array[low];

	while (low < high)
	{
		while ((low < high) && (array[high] >= pv))
		{
			high--;
		}
		tmp = array[low];
		array[low] = array[high];
		array[high] = tmp;
		while ((low < high) && (array[low] <= pv))
		{
			low++;
		}
		tmp = array[low];
		array[low] = array[high];
		array[high] = tmp;
	}
	return low;//·µ»ØÊàÖáµÄÎ»ÖÃ£»
}

void QSort(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);
		
		QSort(array, low, pivot - 1);
		QSort(array, pivot + 1, high);
	}
}



void QuickSort(int array[], int len)
{
	QSort(array, 0, len - 1);
}

void main05()
{
	int array[] = { 12,242,123,412,54,3,2 };
	printf("sizeof(array):%d\n", (int)sizeof(array));
	printf("sizeof(*array):%d\n", (int)sizeof(*array));
	int len = sizeof(array) / sizeof(*array);
	printf("len:%d\n", len);

	QuickSort(array, len);
	for (int i = 0;i < len;i++)
	{
		printf("%d  ", array[i]);
	}
	system("pause");
	return;
}