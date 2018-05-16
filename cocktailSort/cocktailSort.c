#include <stdio.h>
#include <stdlib.h>

//分类--------------内部比较排序
//数据结构-----------数组
//最差时间复杂度-----O(n^2)
//最优时间复杂度-----如果序列在一开始已经大部分排序过的话，会接近O(n)
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

// 鸡尾酒排序
void CocktailSort(int a[], int n)
{
	//初始化边界
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++) //前半轮，将最大元素放到后面
		{
			if (a[i] > a[i + 1])
			{
				Swap(a, i, i + 1);
			}
		}
		right--;
		for (int i = right; i > left; i--) //后半轮将最小元素放到前面
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
	printf("鸡尾酒排序的结果为：");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}