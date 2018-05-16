#include <stdio.h>
#include <stdlib.h>

//����--------------�ڲ��Ƚ�����
//���ݽṹ-----------����
//���ʱ�临�Ӷ�-----O(n^2)
//����ʱ�临�Ӷ�-----���������һ��ʼ�Ѿ��󲿷�������Ļ�����ӽ�O(n)
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

// ��β������
void CocktailSort(int a[], int n)
{
	//��ʼ���߽�
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++) //ǰ���֣������Ԫ�طŵ�����
		{
			if (a[i] > a[i + 1])
			{
				Swap(a, i, i + 1);
			}
		}
		right--;
		for (int i = right; i > left; i--) //����ֽ���СԪ�طŵ�ǰ��
		{
			if (a[i - 1] > a[i])
			{
				Swap(a, i, i - 1);
			}
		}
		left++;
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	CocktailSort(a, n);
	printf("��β������Ľ��Ϊ��");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}