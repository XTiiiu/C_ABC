#include<string.h>
#include<stdlib.h>
#include<stdio.h>


void BubbleSort(int array[], int len)
{
	int i = 0;
	int j = 0;
	int tmp = -1;
	int exchange = 1;  //���������Ƿ����ź���  �Ѿ��ź���Ϊ0  1��ʾû���ź���
	for (i = 0;(i < len) && exchange;i++)
	{
		exchange = 0;  //��Ϊ�Ѿ��������
		for (j = len - 1;j > i;j--)
		{
			if (array[i] > array[j])  //һ������û�н����Ļ��������if��䣬���exchange = 0���ᱻ�ı�
			{
				exchange = 1;   
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}


void main03()
{
	int array[] = { 12,242,123,412,54,3,2 };
	printf("sizeof(array):%d\n", (int)sizeof(array));
	printf("sizeof(*array):%d\n", (int)sizeof(*array));
	int len = sizeof(array) / sizeof(*array);
	printf("len:%d\n", len);

	BubbleSort(array, len);
	for (int i = 0;i < len;i++)
	{
		printf("%d  ", array[i]);
	}


	system("pause");
	return;
}