#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void ShellSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int tmp = -1;
	int gap = len;

	do
	{

		//业界统一实验的  平均最好情况  经过若干次后  收敛为1；
		gap = gap / 3 + 1;
		for (i = gap;i < len;i++)
		{
			k = i;
			tmp = array[k];

			for (j = i - gap;(j >= 0) && (array[j] > tmp);j -= gap)
			{
				array[j + gap] = array[j];
				k = j;
			}
			array[k] = tmp;
		}
	} while (gap > 1);
}

void main04()
{
	int array[] = { 12,242,123,412,54,3,2 };
	printf("sizeof(array):%d\n", (int)sizeof(array));
	printf("sizeof(*array):%d\n", (int)sizeof(*array));
	int len = sizeof(array) / sizeof(*array);
	printf("len:%d\n", len);

	ShellSort(array, len);
	for (int i = 0;i < len;i++)
	{
		printf("%d  ", array[i]);
	}


	system("pause");
	return;
}