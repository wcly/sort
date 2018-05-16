#include <stdio.h>
#include <stdlib.h>

//分类--------------内部比较排序
//数据结构-----------数组
//最差时间复杂度-----根据步长序列的不同而不同，已知最好的为O(n(logn)^2)
//最优时间复杂度-----如果序列在一开始已经大部分排序过的话，会接近O(n)
//平均时间复杂度-----根据步长序列的不同而不同
//所需辅助空间-------O(1)
//稳定性-------------稳定

// 希尔排序
void SelectionSort(int a[], int n)
{
	int h = 0;
	while (h <= n) //生成初始增量
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
		h = (h - 1) / 3; //递增增量
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	SelectionSort(a, n);
	printf("希尔排序的结果为：");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}