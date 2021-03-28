#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void SelecttionSort(int array[], int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int tmp = 0;

	for (i = 0;i < len;i++)
	{
		k = i;
		for (j = i + 1;j < len;j++)
		{
			if (array[j] < array[i]) //开始寻找最小元素的下标
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}


void main01()
{
	int array[] = { 12,123,4212,41 };
	SelecttionSort(array, 4);
	for (int i = 0;i < 4;i++)
	{
		printf("%d  ", array[i]);
	}
	system("pause");
	return;
}