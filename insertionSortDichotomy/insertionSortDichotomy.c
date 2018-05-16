#include <stdio.h>
#include <stdlib.h>

//����--------------�ڲ��Ƚ�����
//���ݽṹ-----------����
//���ʱ�临�Ӷ�-----O(n^2)
//����ʱ�临�Ӷ�-----O(nlogn)
//ƽ��ʱ�临�Ӷ�-----O(n^2)
//���踨���ռ�-------O(1)
//�ȶ���-------------�ȶ�

// ���ֲ�������
void InsertionSortDichotomy(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int get = a[i]; //����ץ��һ���˿���
		/*�õ������ϵ�����������õģ����Կ����ö��ַ�*/
		int left = 0; //�������ұ߽���г�ʼ��
		int right = i - 1;
		while (left <= right) //���ö��ַ���λ���Ƶ�λ��
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
		for (int j = i - 1; j >= left; j--) //������������λ���ұߵ������������ƶ�һ����λ
		{
			a[j + 1] = a[j];
		}
		a[left] = get; //��ץ�����Ʋ�������
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a) / sizeof(int);
	InsertionSortDichotomy(a, n);
	printf("���ֲ����������Ľ��Ϊ��");
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}