#include <stdio.h>
#include <stdlib.h>

//����--------------�ڲ��Ƚ�����
//���ݽṹ-----------����
//���ʱ�临�Ӷ�-----ÿ��ѡȡ�Ļ�׼������󣨻���С����Ԫ�أ�����ÿ��ֻ���ֳ���һ����������Ҫ����n-1�λ��ֲ��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(n^2)
//����ʱ�临�Ӷ�-----ÿ��ѡȡ�Ļ�׼������λ��������ÿ�ζ����ȵĻ��ֳ�����������ֻ��Ҫlogn�λ��־��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(nlogn)
//ƽ��ʱ�临�Ӷ�-----O(nlogn)
//���踨���ռ�-------��Ҫ�ǵݹ���ɵ�ջ�ռ��ʹ��(��������left��right�Ⱦֲ�����)��ȡ���ڵݹ�������ȣ�һ��ΪO(logn)�����ΪO(n)
//�ȶ���-------------���ȶ�

// ������������ֵ
void Swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// ��������
int Partition(int a[], int left, int right)
{
	int pivot = a[right];			   //ÿ�ζ�ѡ�����һ��Ԫ����Ϊ��׼
	int tail = left - 1;			   //tailΪС�ڻ�׼�����������һ��Ԫ�ص�����
	for (int i = left; i < right; i++) //������׼���������Ԫ��
	{
		if (a[i] <= pivot) //��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ��������ĩβ
		{
			Swap(a, ++tail, i);
		}
	}
	Swap(a, tail + 1, right); //���ѻ�׼�ŵ�ǰһ��������ĺ�ߣ�ʣ�µ������鼴�Ǵ��ڻ�׼��������
							  //�ò������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Կ��������ǲ��ȶ��������㷨
	return tail + 1;		  //���ػ�׼������
}

// ��������
void QuickSort(int a[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot_index = Partition(a, left, right); //��׼������
	QuickSort(a, left, pivot_index - 1);
	QuickSort(a, pivot_index + 1, right);
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0, n - 1);
	printf("��������Ľ��Ϊ��");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}