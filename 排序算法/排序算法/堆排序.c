#include<stdio.h>


void heap_com(int arry[], int n, int i)
{
	int x = i;
	int lheap = i * 2 + 1;
	int rheap = i * 2 + 2;


	//寻找三个元素中的最大值
	if (lheap < n && arry[x] < arry[lheap])
		x = lheap;
	if (rheap < n && arry[x] < arry[rheap])
		x = rheap;
	if (x != i) {
		swap(&arry[i], &arry[x]);
		heap_com(&arry, n, x);
	}

}

void heap_sort(int arry[], int n)
{

	//建堆
	for (int i = n / 2 - 1;i >= 0;i--)
	{
		heap_com(&arry, n, i);
	}

	//排序
	for (int j = n - 1;j > 0;j--)
	{
		swap(&arry[j],&arry[0]);
		heap_com(&arry, n, 0);

	}
	
}



int main123()
{
	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(b);
	heap_sort(b,10);
	return 0;
}