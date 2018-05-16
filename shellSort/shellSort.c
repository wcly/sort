#include <stdio.h>
#include <stdlib.h>

//����--------------�ڲ��Ƚ�����
//���ݽṹ-----------����
//���ʱ�临�Ӷ�-----���ݲ������еĲ�ͬ����ͬ����֪��õ�ΪO(n(logn)^2)
//����ʱ�临�Ӷ�-----���������һ��ʼ�Ѿ��󲿷�������Ļ�����ӽ�O(n)
//ƽ��ʱ�临�Ӷ�-----���ݲ������еĲ�ͬ����ͬ
//���踨���ռ�-------O(1)
//�ȶ���-------------�ȶ�

// ϣ������
void SelectionSort(int a[], int n)
{
	int h = 0;
	while (h <= n) //���ɳ�ʼ����
	{
		h = 3 * h + 1;
	}
	while (h >= 1)
	{
		for (int i = h; i < n; i++)
		{
			int j = i - h;
			int get = a[i];
			while (j >= 0 && a[j] > get)
			{
				a[j + h] = a[j];
				j = j - h;
			}
			a[j + h] = get;
		}
		h = (h - 1) / 3; //��������
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	SelectionSort(a, n);
	printf("ϣ������Ľ��Ϊ��");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}