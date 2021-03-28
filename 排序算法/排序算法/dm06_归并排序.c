#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void Merge(int src[], int des[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i <= mid) && (j <= high))
	{
		if (src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}
	while (i <= mid)
	{
		des[k++] = src[i++];
	}
	while (j <= high)
	{
		des[k++] = src[j++];
	}
}


void MSort(int src[], int des[], int low, int high, int max)
{
	if (low == high)   //只有一个元素，不需要归并，结果赋值给des[low]
	{
		des[low] = src[low];
	}
	else  //如果多个元素，进行两路划分
	{
		int mid = (low + high) / 2;
		int *space = (int*)malloc(sizeof(int)* max);

		//递归进行两路，两路的划分
		//当剩下一个元素的时候，递归划分结束，然后进行merge归并操作
		if (space != NULL)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid + 1, high, max);
			Merge(space, des, low, mid, high);  //调用归并函数进行归并
		}
		free(space);
	}
}


void MergeSort(int array[], int len)
{
	MSort(array, array, 0, len - 1, len);
}


void main06()
{
	int array[] = { 12,242,123,412,54,3,2 };
	printf("sizeof(array):%d\n", (int)sizeof(array));
	printf("sizeof(*array):%d\n", (int)sizeof(*array));
	int len = sizeof(array) / sizeof(*array);
	printf("len:%d\n", len);

	MergeSort(array, len);
	for (int i = 0;i < len;i++)
	{
		printf("%d  ", array[i]);
	}
	system("pause");
	return;
}