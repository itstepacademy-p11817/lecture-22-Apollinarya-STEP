#include<stdio.h>
#include<stdbool.h>
#include"module.h"
#include<time.h>

// task 1       summa i umnozhenie elementov massiva

int func(int arr[], int size, int *sum, int *mult)
{
	for (int i = 0; i < size; i++)
	{
		//printf("%d ", arr[i]);
		*sum += arr[i];
		*mult *= arr[i];
	}
}

void task1()
{
	srand(time(NULL));
	int array[100];
	int size = 1;
	while (size > 0)
	{
		printf("\nEnter array size [1-100](0 - exit) ");
		scanf_s("%d", &size);
		if (size == 0)
		{
			break;
		}
		else if (size < 1 || size>100)
		{
			continue;
		}
		else 
		{
			for (int i = 0; i < size; i++)
			{
				array[i] = rand() % 10 + 1;
				printf("%d ", array[i]);
			}
			printf("\n");

			int *arr = array;
			int sum = 0;
			int mult = 1;
			int *summ = &sum;
			int *multt = &mult;
			func(arr, size, summ, multt);
			printf("sum = %d; mult = %d\n\n", *summ, *multt);
		}
	}
}


// task 2    kolichestvo polozhitel'nyh, otricatel'nyh i nejtral'nyh znachenie v massive

void sign(int arr[], int size, int *neg, int *pos, int *neu)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			*neg += 1;
		}
		else if (arr[i] > 0)
		{
			*pos += 1;
		}
		else
		{
			*neu += 1;
		}
		//printf("\nPositive = %d;\nNegative = %d;\nNeutral = %d;\n\n", *pos, *neg, *neu);
	}
}

void task2()
{
	srand(time(NULL));
	int array[100];
	int size = 1;
	// vybor razmera massiva i realizacija vyhoda iz cikla
	while (size != 0)
	{
		printf("\nEnter array size [1-100](0 - exit) ");
		scanf_s("%d", &size);
		if (size == 0)
		{
			break;
		}
		else if (size < 1 || size>100)
		{
			continue;
		}
		else
		{
			for (int i = 0; i < size; i++)// randomnoe zapolenie massiva
			{
				array[i] = rand() % (10 * 2) - 10;
				printf("%d ", array[i]);
			}
			printf("\n");
			// naznachenie ukazatelej
			int *arr = array;
			int negative = 0;
			int positive = 0;
			int neutral = 0;
			int *neg = &negative;
			int *pos = &positive;
			int *neu = &neutral;
			// peredacha i vypolnenie funkcii
			sign(arr, size, neg, pos, neu);
			printf("\nPositive = %d;\nNegative = %d;\nNeutral = %d;\n\n", *pos, *neg, *neu);
		}
	}
}

// task 3   proverka na nalichie sovpadenij

bool check(int arr1[], int arr2[], int size1, int size2, int *ind)
{
	for (int i = 0; i < size1; i++)
	{
		if (arr1[i] == arr2[0])
		{
			*ind = i;
			for (int i1 = 0; i1 < size2; i1++)
			{
				if (arr1[i] != arr2[i1])
				{
					break;
				}
				else if (i1 == size2 - 1)
				{
					return true;
				}
				i++;
			}
		}
	}
	return false;
}

void task3()
{
	srand(time(NULL));
	int array1[100];
	int array2[100];
	int size1 = 1;
	int size2 = 1;
	// vybor razmera massiva i realizacija vyhoda iz cikla
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
			printf("\nSize out of range!\n");
			continue;
		}
		else if (size2 > size1)
		{
			printf("\nSecond massive is bigger than first!\n");
			continue;
		}
		else
		{
			for (int i = 0; i < size1; i++)// randomnoe zapolenie massiva 1
			{
				array1[i] = rand() % 10 + 1;
				printf("%d ", array1[i]);
			}
			printf("\n");
			for (int i = 0; i < size2; i++)// randomnoe zapolenie massiva 2
			{
				array2[i] = rand() % 10 + 1;
				printf("%d ", array2[i]);
			}
			printf("\n");
			// naznachenie ukazatelej
			int *arr1 = array1;
			int *arr2 = array2;
			int index = 0;
			int *ind = &index;
			// peredacha i vypolnenie funkcii
			if (check(arr1, arr2, size1, size2, ind))
			{
				printf("\nTrue\n\n");
			}
			else
			{
				printf("\nFalse\n\n");
			}
		}
	}
}

// Task 4 kalcul'ator

float addition(float a, float b)
{
	printf("\n%f + %f = %f\n", a, b, a + b);
	return a + b;
}

float subtraction(float a, float b)
{
	printf("\n%f - %f = %f\n", a, b, a - b);
	return a - b;
}

float multiplication(float a, float b)
{
	printf("\n%f * %f = %f\n", a, b, a * b);
	return a * b;
}

float division(float a, float b)
{
	if (b == 0)
	{
		printf("\nYou can't divide by zero.\n");
		return 0;
	}
	else
	{
		printf("\n%f / %f = %f\n", a, b, a / b);
		return a / b;
	}
}

void task4()
{
	float a = 1.0;
	float b = 1.0;
	int operation = 0;
	float(*add)(float, float) = addition;
	float(*sub)(float, float) = subtraction;
	float(*mult)(float, float) = multiplication;
	float(*div)(float, float) = division;
	float(*mass[4])(float, float) = { add, sub, mult, div };
	while (true)
	{
		printf("\nChoose operation:\nAddition - 1\nSubtraction - 2\nMultiplication - 3\nDivision - 4\nPress zero to exit\n\nYou enter  ");
		scanf_s("%d", &operation);
		if (operation == 0)
		{
			break;
		}
		else if (operation < 1 || operation > 4)
		{
			printf("\nYou entered something wrong. Try again.\n\n");
			continue;
		}
		printf("\nEnter first number ");
		scanf_s("%f", &a);
		printf("Enter second number ");
		scanf_s("%f", &b);
		float result = mass[operation - 1](a, b);
		//printf("\nresult = %f\n", result);
		system("pause");
	}
}

//Task 5

void create_C(int arr[], int arr1[], int arr2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = arr1[i] + arr2[i];
	}
}

void task5()
{
	srand(time(NULL));
	int array[100];
	int array1[100];
	int array2[100];
	int size = 1;
	// vybor razmera massiva i realizacija vyhoda iz cikla
	while (size != 0)
	{
		printf("Enter array size [1-100](0 - exit) ");
		scanf_s("%d", &size);
		if (size == 0)
		{
			break;
		}
		else if (size < 1 || size > 100)
		{
			printf("\nSize out of range!\n");
			continue;
		}
		else
		{
			for (int i = 0; i < size; i++)// randomnoe zapolenie massivov
			{
				array1[i] = rand() % 10 + 1;
				array2[i] = rand() % 10 + 1;
			}
			// naznachenie ukazatelej
			int *arr1 = array1;
			int *arr2 = array2;
			int *arr = array;
			// peredacha i vypolnenie funkcii
			create_C(arr, arr1, arr2, size);
			printf("\nA:\tB:\tC:\n\n");
			for (int i = 0; i < size; i++)
			{
				printf("%d\t%d\t%d\n", array1[i], array2[i],array[i]);
			}
			printf("\n\n");
		}
	}
}

//Task 6

void add_elem_end(int arr[], int size, int elem)
{
	for (int i = size; i < size + elem; i++)// randomnoe zapolenie massiva novymi elementami v konce
	{
		arr[i] = rand() % 10 + 1;
	}
}

void task6()
{
	srand(time(NULL));
	int array[100];
	int size = 10;
	// vybor kolichestva vstavl'aemyh elementov
	int elem = 1;
	while (elem != 0)
	{
		printf("Enter amount of elements to add [1-90](0 - exit) ");
		scanf_s("%d", &elem);
		if (elem == 0)
		{
			break;
		}
		else if (elem < 1 || elem > 90)
		{
			printf("\nAmount out of range!\n");
			continue;
		}
		else
		{
			for (int i = 0; i < size; i++)// randomnoe zapolenie massiva 
			{
				array[i] = rand() % 10 + 1;
				printf("%d  ", array[i]);
			}
			printf("\n");
			// naznachenie ukazatelej
			int *arr = array;
			// peredacha i vypolnenie funkcii
			add_elem_end(arr, size, elem);
			size += elem;
			printf("Result:\n");
			for (int i = 0; i < size; i++)
			{
				printf("%d  ", array[i]);
			}
			printf("\n\n");
		}
	}
}



//Task 7

void add_elem_ind_zamena(int arr[], int size, int elem, int ind)
{
	for (int i = ind; i < ind + elem; i++)// 
	{
		printf("Enter num to add ");
		scanf_s("%d", &arr[i]);
	}
}

void add_elem_ind_sdvig(int arr[], int size, int elem, int ind)
{
	for (int i = size - 1; i >= ind; i--)
	{
		arr[i + elem] = arr[i];
	}
	for (int i = ind; i < ind + elem; i++)// 
	{
		printf("Enter num to add ");
		scanf_s("%d", &arr[i]);
	}
}

void task7()
{
	srand(time(NULL));
	int array[100];
	// vybor kolichestva vstavl'aemyh elementov
	int elem = 1;
	while (elem != 0)
	{
		int size = 10;
		printf("Enter amount of elements to add [1-90](0 - exit) ");
		scanf_s("%d", &elem);
		if (elem == 0)
		{
			break;
		}
		else if (elem < 1 || elem > 90)
		{
			printf("\nAmount out of range!\n");
			continue;
		}
		else
		{
			int ind = 20;
			while (ind > 9 || ind < 0)
			{
				printf("Enter index from where to add elements [0-9] ");
				scanf_s("%d", &ind);
			}
			printf("\n");
			int meth = 0;
			while (meth != 1 && meth != 2) // vybor metoda vypolnenia funkcii
			{
				printf("Choose method:\n1 - Replacement\n2 - Displacement\n");
				scanf_s("%d", &meth);
			}
			for (int i = 0; i < size; i++) // randomnoe zapolenie massiva 
			{
				array[i] = rand() % 10 + 1;
				printf("%d  ", array[i]);
			}
			printf("\n\n");

			int *arr = array; // naznachenie ukazatelej

			if (meth == 1) //vypolnenie funkcii
			{
				add_elem_ind_zamena(arr, size, elem, ind);
			}
			else
			{
				add_elem_ind_sdvig(arr, size, elem, ind);
				size += elem;
			}
			printf("\nResult:\n");
			for (int i = 0; i < size; i++)
			{
				printf("%d  ", array[i]);
			}
			printf("\n\n");
		}
	}
}



//Task 8


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

int avg_num(int arr1[], int size1, int arr2[], int size2)
{
	int min = min_num(arr1, size1, arr2, size2);
	int max = max_num(arr1, size1, arr2, size2);
	float avg = (min + max) / 2.0;
	//printf("\navg = %f\n", avg);
	int min1 = min;
	int max1 = max;
	int pos = 0;
	int neg = 0;
	for (int i = 0; i < size1; i++) //cikl nahozhdenija blizhajshih k avg v massive 1
	{
		if (arr1[i] > 0)
		{
			pos++;
		}
		else if (arr1[i] < 0)
		{
			neg++;
		}
		if (arr1[i] == avg)
		{
			return avg;
		}
		else if (arr1[i] < avg && min1 < arr1[i])
		{
			min1 = arr1[i]; // blizhajshee minimal'noe
		}
		else if (arr1[i] > avg && max1 > arr1[i])
		{
			max1 = arr1[i]; // blizhajshee maximal'noe
		}
	}
	int min2 = min;
	int max2 = max;
	for (int i = 0; i < size2; i++) //cikl nahozhdenija blizhajshih k avg v massive 2
	{
		if (arr2[i] == avg)
		{
			return avg;
		}
		else if (arr2[i] < avg && min2 < arr2[i])
		{
			min2 = arr2[i]; // blizhajshee minimal'noe
		}
		else if (arr2[i] > avg && max2 > arr2[i])
		{
			max2 = arr2[i]; // blizhajshee maximal'noe
		}
	}
	//printf("min 1 = %d, min2 = %d, max1 = %d, max2 = %d\n", min1, min2, max1, max2);
	if (min1 > min2) // sravnenie minimumov
	{
		min = min1;
	}
	else
	{
		min = min2;
	}
	if (max1 > max2) // sravnenie maximumov
	{
		max = max2;
	}
	else
	{
		max = max1;
	}
	//printf("min = %d, max = %d\n", min, max);
	if (avg - min > max - avg) //chto blizhe k avg
	{
		avg = max;
	}
	else if (avg - min < max - avg)
	{
		avg = min;
	}
	else // esli na odinakovom rasstojanii
	{
		if (neg > pos)
		{
			avg = min;
		}
		else // esli pos >= neg to avg = max
		{
			avg = max;
		}
	}
	return avg;
}

int action(int arr1[], int arr2[], int size1, int size2, int(*func)(int, int, int, int))
{
	int result = func(arr1, size1, arr2, size2);
	return result;
}

void task8()
{
	srand(time(NULL));
	int array1[100];
	int array2[100];
	int size1 = 1;
	int size2 = 1;
	while (size1 != 0 && size2 != 0) // razmer massivov i vyhod iz cikla
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
			int(*mass[3]) = { *max_n, *min_n, *avg_n };
			while (true)
			{
				int operation = -1;// nomer operacii i zavershenie raboty s massivom
				while (operation > 3 || operation < 0)
				{
					printf("Choose operation:\nMaximum - 1;  Minimum - 2;  Average - 3;\nOR press zero if you want to start again.\n\nYou choose: ");
					scanf_s("%d", &operation);
				}
				if (operation == 0)
				{
					break;
				}
				int result = action(arr1, arr2, size1, size2, mass[operation - 1]);// podschet rezul'tata
				printf("result = %d\n\n", result);
				system("pause");
			}
		}
	}
}