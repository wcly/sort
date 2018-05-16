#include <stdio.h>
#include <stdlib.h>

//分类--------------内部比较排序
//数据结构-----------数组
//最差时间复杂度-----O(n^2)
//最优时间复杂度-----O(nlogn)
//平均时间复杂度-----O(n^2)
//所需辅助空间-------O(1)
//稳定性-------------稳定

// 二分插入排序
void InsertionSortDichotomy(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int get = a[i]; //右手抓到一张扑克牌
		/*拿到左手上的牌总是排序好的，所以可以用二分法*/
		int left = 0; //手牌左右边界进行初始化
		int right = i - 1;
		while (left <= right) //采用二分法定位新牌的位置
		{
			int mid = (left + right) / 2;
			if (a[mid] > get)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		for (int j = i - 1; j >= left; j--) //将欲插入新牌位置右边的牌整体向右移动一个单位
		{
			a[j + 1] = a[j];
		}
		a[left] = get; //将抓到的牌插入手牌
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	InsertionSortDichotomy(a, n);
	printf("二分插入插入排序的结果为：");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}