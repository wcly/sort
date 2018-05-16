#include <stdio.h>
#include <stdlib.h>

//分类--------------内部比较排序
//数据结构-----------数组
//最差时间复杂度-----O(n^2)
//最优时间复杂度-----如果序列在一开始已经大部分排序过的话，会接近O(n)
//平均时间复杂度-----O(n^2)
//所需辅助空间-------O(1)
//稳定性-------------不稳定

// 交换两个数的值
void Swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// 选择排序
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) //i为已排序序列的末尾
	{
		int min = i;
		for (int j = i + 1; j < n; j++) //未排序序列
		{
			if (a[min] > a[j])  //找出未排序序列中的最小值
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(a, min, i); //放到已排序序列的末尾，该操作很有可能把稳定性打乱，所以选择排序是不稳定的排序算法
		}
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	SelectionSort(a, n);
	printf("选择排序的结果为：");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}