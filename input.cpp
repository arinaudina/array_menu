#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#define RAND_MAXIMUM 10000

	// Функционал ввода данных в массив:

int input(double arr[], int size) 
{
	int res, i;

	do												//Количество элементов в массиве
	{
		printf("Введите размер массива:\n");
		if(scanf("%d", &res) != 1)
		{
			printf("Введены некоректные данные. Ошибка\n");
			return 1;
		}
	} while ((res < 1) || (res > size));

	if (res <= 20)									//Вариативность заполнения
	{
		printf("Введите элементы массива:\n");		//Ручной ввод
		for (i = 0; i < res; i++)
		{
			scanf("%lf", &arr[i]);
		} return res;
	}
	else
	{
		srand(time(NULL));
		int ansver;
		printf("Выберите желаемый массив:\n");		//Предоставляемые виды заполнения
		printf("1.Массив со случайными числами в полном диапазоне\n2.Массив со случайными неотрицательными числами\n3.Массив чисел от _ до _\n");
		printf("4.Массив арифметической прогрессии\n5.Массив геометрической прогрессии\n6.Массив квадратов чисел\n7.Массив степени числа\nВаш выбор:");
		scanf("%d", &ansver);

		switch (ansver)								// Обработка запроса пользователя
		{

			case 1:
			{
				for (int i = 0; i < res; i++) 
				{
					arr[i] = (double)rand();		// Числа в полном диапазоне
				}

				printf("\nМассив со случайными числами в полном диапазоне:\n");
				for (int i = 0; i < res; i++)
				{
					printf("\n%lf", arr[i]);
				}
				break;
			}

			case 2:
			{
				for (int i = 0; i < res; i++)
				{
					arr[i] = abs((double)rand() - RAND_MAXIMUM);	// числа примерно от 0 до RAND_MAXIMUM
				}

				printf("\nМассив со случайными неотрицательными числами:\n");
				for (int i = 0; i < res; i++)
				{
					printf("\n%lf", arr[i]);
				}
				break;
			}

			case 3:
			{
				double min, max;
				printf("Введите минимальное значение (может быть отрицательным): ");
				scanf("%lf", &min);
				printf("Введите максимальное значение: ");
				scanf("%lf", &max);

				for (int i = 0; i < res; i++)				// Заполнение массива случайными числами в диапазоне [min, max]
				{
					arr[i] = (((double)rand() / (RAND_MAXIMUM*10))*(max-min))+min;
				}

				printf("\nМассив со случайными числами (%lf до %lf):\n", min, max);
				for (int i = 0; i < res; i++) 
				{
					printf("\n%lf", arr[i]);
				}
				break;
			}

			case 4:
			{
				double start, step;
				printf("Введите начальное число: ");
				scanf("%lf", &start);
				printf("Введите шаг прогрессии: ");
				scanf("%lf", &step);

				for (int i = 0; i < res; i++)				// Арифметическая прогрессия
				{
					arr[i] = start + i * step;				//aₙ = a₁ + (n-1) * d
				}

				printf("\nАрифметическая прогрессия (начало: %lf, шаг: %lf):\n", start, step);
				for (int i = 0; i < res; i++) {
					printf("\n%lf ", arr[i]);
				}
				break;
			}

			case 5:
			{
				double start, ratio;
				printf("Введите начальное число: ");
				scanf("%lf", &start);
				printf("Введите знаменатель прогрессии: ");
				scanf("%lf", &ratio);

				arr[0] = start;							// Геометрическая прогрессия
				for (int i = 1; i < res; i++) {
					arr[i] = arr[i - 1] * ratio;		// aₙ = a₁ * qⁿ⁻¹
				}

				printf("\nГеометрическая прогрессия (начало: %lf, знаменатель: %lf):\n", start, ratio);
				for (int i = 0; i < res; i++)
				{
					printf("\n%lf ", arr[i]);
				}
				break;
			}

			case 6:
			{
				double start;
				printf("Введите начальное число: ");
				scanf("%lf", &start);

				for (int i = 0; i < res; i++)			// Квадраты чисел
				{
					arr[i] = (start + i) * (start + i);
				}

				printf("\nМассив квадратов чисел (начиная с %lf):\n", start);
				for (int i = 0; i < res; i++) {
					printf("\n%lf ", arr[i]);
				}
				break;
			}

			case 7:
			{
				double start, start_power;
				printf("Введите число: ");
				scanf("%lf", &start);
				printf("Введите начальную степень: ");
				scanf("%lf", &start_power);

				for (int i = 0; i < res; i++)			// Степень числа
				{
					arr[i] = pow(start, start_power + i);
				}

				printf("\nМассив степеней числа (начиная с %lf^%lf):\n", start,start_power);
				for (int i = 0; i < res; i++) {
					printf("\n%lf ", arr[i]);
				}
				break;
			}

		} return res;
	}
}
