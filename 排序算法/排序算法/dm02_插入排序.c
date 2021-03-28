#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void InsertionSort(int array[], int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int tmp = -1;


	for (i = 1;i < len;i++)
	{
		k = i;  //�������λ��
		tmp = array[k];
		for (j = i - 1;(j >= 0) && (array[j] > tmp);j--)
		{
			array[j + 1] = array[j];  //Ԫ�غ���
			k = j;  //k��Ҫ�����λ��
		}

		array[k] = tmp;  //Ԫ�ز���
	}
}


void main02()
{

	int array[] = { 12,242,123,412,54,3,2 };
	printf("sizeof(array):%d\n", (int)sizeof(array));
	printf("sizeof(*array):%d\n", (int)sizeof(*array));
	int len = sizeof(array) / sizeof(*array);
	printf("len:%d\n", len);

	InsertionSort(array, len);
	for (int i = 0;i < len;i++)
	{
		printf("%d  ", array[i]);
	}
	system("pause");
	return;
}