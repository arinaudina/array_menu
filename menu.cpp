#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#define MAX_SIZE 200								//Максимальное количество элементов массива

	// Функционал ввода данных в массив:

int input(double arr[], int size);

int main()
{
	setlocale(LC_ALL, "Rus");
	int ansver, input_status=0;
	double a[MAX_SIZE];

	printf("Меню:\n");
	printf("  1.Ввод\n  2.Вывод\n  3.");
	scanf("%d", &ansver);

	switch (ansver)
	{
		case 1:{
			input_status = input(a, MAX_SIZE);
			break;
		}

	}
}

//Проецируемое меню для пользователя