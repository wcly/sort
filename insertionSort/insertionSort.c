#include <stdio.h>
#include <stdlib.h>

//分类--------------内部比较排序
//数据结构-----------数组
//最差时间复杂度-----最坏情况为输入序列是降序排序的，此时时间复杂度为O(n^2)
//最优时间复杂度-----最好的情况为输入序列是升序排序的，此时时间复杂度为O(n)
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

// 插入排序
void insertionSort(int a[], int n)
{
	// //方法一：
	// for (int i = 0; i < n - 1; i++)
	// {
	// 	int sorted = i;  //有序序列的末尾，相当于左边已整理好的扑克牌，一开始是第一张
	// 	for (int j = sorted + 1; j >= 0; j--)  //抽未整理的扑克牌的第一张与前面已整理好的扑克牌比较
	// 	{
	// 		if (a[j] < a[j - 1]) //类似冒泡往左边浮动
	// 		{
	// 			Swap(a, j-1, j);
	// 		}
	// 		else
	// 		{
	// 			break;
	// 		}
	// 	}
	// }

	//方法二：
	for (int i = 1; i < n; i++)
	{
		int get = a[i];				//右手抓到一张扑克牌
		int j = i - 1;					//拿左手上的牌总是排好序的
		while (j >= 0 && a[j] > get) //将抓到的牌与手牌从右向左进行比较
		{
			a[j + 1] = a[j]; //如果该手牌比抓到的牌大，就将其右移
			j--;
		}
		a[j + 1] = get; //直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边(相等元素的相对次序未变，所以插入排序是稳定的)
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4, 4};
	int n = sizeof(a) / sizeof(int);
	insertionSort(a, n);
	printf("插入排序的结果为：");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}