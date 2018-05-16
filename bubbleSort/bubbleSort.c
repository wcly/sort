#include <stdio.h>
#include <stdlib.h>

//����--------------�ڲ��ȼ�����
//���ݽṹ-----------����
//���ʱ�临�Ӷ�-----O(n^2)
//����ʱ�临�Ӷ�-----��������ڲ�ѭ����һ������ʱ,ʹ��һ���������ʾ������Ҫ�����Ŀ���,���԰�����ʱ�临�ӶȽ��͵�O(n)
//ƽ��ʱ�临�Ӷ�-----O(n^2)
//���踨���ռ�-------O(1)
//�ȶ���-------------�ȶ�

// ������������ֵ
void Swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// ð������
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1]) //��������ĳ�A[i] >= A[i + 1],���Ϊ���ȶ��������㷨
			{
				flag = 1;
				Swap(a, j, j + 1);
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	BubbleSort(a, n);
	printf("ð������Ľ��Ϊ");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}