#include <stdio.h>
#include <stdlib.h>

//����--------------�ڲ��Ƚ�����
//���ݽṹ-----------����
//���ʱ�临�Ӷ�-----O(nlogn)
//����ʱ�临�Ӷ�-----O(nlogn)
//ƽ��ʱ�临�Ӷ�-----O(nlogn)
//���踨���ռ�-------O(n)
//�ȶ���-------------�ȶ�

void Merge(int a[], int left, int mid, int right) //�ϲ��������ź��������a[left...mid]��a[mid+1...right]
{
	int len = right - left + 1;
	int *temp = (int *)malloc(len * sizeof(int)); //�����ռ�O(n)
	int index = 0;
	int i = left;	//ǰһ�������ʼԪ��
	int j = mid + 1; //��һ�������ʼԪ��
	while (i <= mid && j <= right)
	{
		temp[index++] = a[i] <= a[j] ? a[i++] : a[j++]; //���Ⱥű��ǹ鲢������ȶ���
	}
	while (i <= mid)
	{
		temp[index++] = a[i++];
	}
	while (j <= right)
	{
		temp[index++] = a[j++];
	}
	for (int k = 0; k < len; k++)
	{
		a[left++] = temp[k];
	}
}

void MergeSortRecursion(int a[], int left, int right) //�ݹ�ʵ�ֵĹ鲢����(�Զ�����)
{
	if (left == right) //������������г���Ϊ1ʱ���ݹ鿪ʼ���ݣ�����merge����
	{
		return;
	}
	int mid = (left + right) / 2;
	MergeSortRecursion(a, left, mid);
	MergeSortRecursion(a, mid + 1, right);
	Merge(a, left, mid, right);
}

void MergeSortIteration(int a[], int len) //�ǵݹ飨������ʵ�ֵĹ鲢����(�Ե�����)
{
	int left, mid, right;			 //������������ǰһ��Ϊa[left...mid],��һ��������Ϊa[mid+1...right]
	for (int i = 1; i < len; i *= 2) //������Ĵ���i��ʼΪ1��ÿ�ַ���
	{
		left = 0;
		while (left + i < len) //��һ����������ڣ���Ҫ�鲢��
		{
			mid = left + i - 1;
			right = mid + i < len ? mid + i : len - 1; //��һ���������С���ܲ���
			Merge(a, left, mid, right);
			left = right + 1; //ǰһ����������������ƶ�
		}
	}
}

int main()
{
	int a1[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int a2[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n1 = sizeof(a1) / sizeof(int);
	int n2 = sizeof(a2) / sizeof(int);
	MergeSortRecursion(a1, 0, n1 - 1); //�ݹ�ʵ��
	MergeSortIteration(a2, n2);		   //�ǵݹ�ʵ��
	printf("�ݹ�ʵ�ֹ鲢����Ľ��Ϊ��");
	for (int i = 0; i < n1; i++)
	{
		printf("%d", a1[i]);
	}
	printf("\n");
	printf("�ǵݹ�ʵ�ֹ鲢����Ľ��Ϊ��");
	for (int i = 0; i < n2; i++)
	{
		printf("%d", a2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}