#include <stdio.h>
#include <stdlib.h>

//分类--------------内部比较排序
//数据结构-----------数组
//最差时间复杂度-----每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
//最优时间复杂度-----每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
//平均时间复杂度-----O(nlogn)
//所需辅助空间-------主要是递归造成的栈空间的使用(用来保存left和right等局部变量)，取决于递归树的深度，一般为O(logn)，最差为O(n)
//稳定性-------------不稳定

// 交换两个数的值
void Swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// 分区函数
int Partition(int a[], int left, int right)
{
	int pivot = a[right];			   //每次都选择最后一个元素作为基准
	int tail = left - 1;			   //tail为小于基准的子数组最后一个元素的索引
	for (int i = left; i < right; i++) //遍历基准以外的其他元素
	{
		if (a[i] <= pivot) //把小于等于基准的元素放到前一个子数组末尾
		{
			Swap(a, ++tail, i);
		}
	}
	Swap(a, tail + 1, right); //最后把基准放到前一个子数组的后边，剩下的子数组即是大于基准的子数组
							  //该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
	return tail + 1;		  //返回基准的索引
}

// 快速排序
void QuickSort(int a[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot_index = Partition(a, left, right); //基准的索引
	QuickSort(a, left, pivot_index - 1);
	QuickSort(a, pivot_index + 1, right);
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0, n - 1);
	printf("快速排序的结果为：");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}