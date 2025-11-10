#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#define MAX_SIZE 200	
#define MANUAL_LIMIT 20
#define ERROR_ONE -2
#define ERROR_TWO -1
#define NO_ERROR 0


// Обьявление всех подфункций меню:

int input(double arr[], int size, int manual_limit, int *error_remark);		 //Функция ввода


int main()
{
	setlocale(LC_ALL, "Rus");

	double array[MAX_SIZE];				
	int error = ERROR_ONE;	
	int answer = 0;	
	int input_status = 0;

	do
	{
		if(error != ERROR_TWO)
			printf("\nМеню:\n");
			printf("\n  1.Ввод\n  2.Вывод\n  3.Сортировка\n  0.Выход\n");
			printf("\nВведите пункт меню: ");

		if((scanf("%d", &answer) !=1))
		{
			printf("\nERROR 2:\nПроизошла ошибка при вводе значений. Попробуйте запустить программу снова\n");
			return -1;
		}
		switch (answer) 				// Обработка ответа пользователя
		{
			case 1:
				input_status = input(array, MAX_SIZE, MANUAL_LIMIT, &error);

				if ((error == NO_ERROR ) && (input_status > 0))
					printf("\nВаш массив готов\n");
				else if (error == ERROR_TWO)
					printf("\nERROR 2:\n  Произошла ошибка при вводе значений. Попробуйте запустить программу снова\n");

				break;

			case 0:
				printf("\n...Выход...\nРабота завершена корректно\n");
				return 0;
		};

	} while (error != ERROR_TWO);

	return -1;
}
