#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int max_num(int arr1[], int size1, int arr2[], int size2)
{
	int max = 0;
	for (int i = 0; i < size1; i++)
	{	
		if (arr1[i] > max)
		{
			max = arr1[i];
		}
	}
	for (int i = 0; i < size2; i++)
	{
		if (arr2[i] > max)
		{
			max = arr2[i];
		}
	}
	return max;
}

int min_num(int arr1[], int size1, int arr2[], int size2)
{
	int min = 0;
	for (int i = 0; i < size1; i++)
	{
		if (arr1[i] < min)
		{
			min = arr1[i];
		}
	}
	for (int i = 0; i < size2; i++)
	{
		if (arr2[i] < min)
		{
			min = arr2[i];
		}
	}
	return min;
}



int action(int arr1[], int arr2[], int size1, int size2, int (*func)(int,int,int,int))
{
	int result = func(arr1, size1, arr2, size2);	
	return result;
}

int main()
{
	srand(time(NULL));
	int array1[100];
	int array2[100];
	int size1 = 1;
	int size2 = 1;
	while (size1 != 0 && size2 != 0)
	{
		printf("Enter array size 1 [1-100](0 - exit) ");
		scanf_s("%d", &size1);
		printf("Enter array size 2 [1-100](0 - exit) ");
		scanf_s("%d", &size2);
		if (size1 == 0 || size2 == 0)
		{
			break;
		}
		else if (size1 < 1 || size1 > 100 || size2 < 1 || size2 > 100)
		{
			continue;
		}
		else
		{
			for (int i = 0; i < size1; i++)// randomnoe zapolenie massiva 1
			{
				array1[i] = rand() % (10 * 2) - 10;
				printf("%d  ", array1[i]);
			}
			printf("\n");
			for (int i = 0; i < size2; i++)// randomnoe zapolenie massiva 2
			{
				array2[i] = rand() % (10 * 2) - 10;
				printf("%d  ", array2[i]);
			}
			printf("\n");
			// naznachenie ukazatelej
			int *arr1 = array1;
			int *arr2 = array2;
			int(*max_n)(int, int, int, int) = max_num;
			int(*min_n)(int, int, int, int) = min_num;
			int(*avg_n)(int, int, int, int) = avg_num;
			int (*mass[3]) = { *max_n, *min_n, *avg_n };
			while (true)
			{
				int operation = -1;
				while (operation > 3 || operation < 0)
				{
					printf("Choose operation:\nMaximum - 1;\nMinimum - 2;\nAverage - 3;\nOR press zero if you want to start again.\n\nYou choose: ");
					scanf_s("%d", &operation);
				}
				if (operation == 0)
				{
					break;
				}
				int result = action(arr1, arr2, size1, size2, mass[operation - 1]);
				printf("result = %d\n\n", result);
				system("pause");
			}
		}
	}
	system("pause");
	return 0;
}
