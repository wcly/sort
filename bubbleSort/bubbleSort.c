#include <stdio.h>
#include <stdlib.h>

//分类--------------内部比价排序
//数据结构-----------数组
//最差时间复杂度-----O(n^2)
//最优时间复杂度-----如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
//平均时间复杂度-----O(n^2)
//所需辅助空间-------O(1)
//稳定性-------------稳定

// 交换两个数的值
void Swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// 冒泡排序
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1]) //如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
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
	printf("冒泡排序的结果为");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}