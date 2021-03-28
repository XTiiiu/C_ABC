#include<stdio.h>


int partition(int tmp[], int low, int high) {
	int i = low - 1;
	int j = high;
	int x = tmp[high];   //��ŦԪ��
	while(1)
	{
		while (tmp[++i] < x);
		while (tmp[--j] > x);
		if (i < j)
			swap(&tmp[i], &tmp[j]);
		else
			break;
		swap(&tmp[i], &tmp[high]);
		//����ŦԪ�طŵ���ȷ��λ����
		return i;

	}
}


void qsort(int tmp[], int low, int high) {


	int i = partition(tmp, low, high);


	qsort(tmp, low, i - 1);
	qsort(tmp, i + 1, high);

}

int main()
{
	int arry[] = { 1,11,3,4,14,42,23 };
	int n = sizeof(arry);
	qsort(arry, 0, n);

	return 0;
}