#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"module.h"
 

int main()
{
	int num = 0;
	void(*t1)() = task1;
	void(*t2)() = task2;
	void(*t3)() = task3;
	void(*t4)() = task4;
	void(*t5)() = task5;
	void(*t6)() = task6;
	void(*t7)() = task7;
	void(*t8)() = task8;
	void(*tasks[8])() = { t1, t2, t3, t4, t5, t6, t7, t8 };
	while (true)
	{
		printf("\nEnter task number. Press zero if you want to quit. ");
		scanf_s("%d", &num);
		printf("\n\n");
		if (num == 0)
		{
			break;
		}
		else if (num < 1 || num > 8)
		{
			printf("\nYou entered something wrong.\n");
		}
		else
		{
			tasks[num - 1]();
		}
	}
	system("pause");
	return 0;
}
