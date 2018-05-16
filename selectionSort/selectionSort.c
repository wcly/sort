#include <stdio.h>
#include <stdlib.h>

//����--------------�ڲ��Ƚ�����
//���ݽṹ-----------����
//���ʱ�临�Ӷ�-----O(n^2)
//����ʱ�临�Ӷ�-----���������һ��ʼ�Ѿ��󲿷�������Ļ�����ӽ�O(n)
//ƽ��ʱ�临�Ӷ�-----O(n^2)
//���踨���ռ�-------O(1)
//�ȶ���-------------���ȶ�

// ������������ֵ
void Swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// ѡ������
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) //iΪ���������е�ĩβ
	{
		int min = i;
		for (int j = i + 1; j < n; j++) //δ��������
		{
			if (a[min] > a[j])  //�ҳ�δ���������е���Сֵ
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(a, min, i); //�ŵ����������е�ĩβ���ò������п��ܰ��ȶ��Դ��ң�����ѡ�������ǲ��ȶ��������㷨
		}
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	SelectionSort(a, n);
	printf("ѡ������Ľ��Ϊ��");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}