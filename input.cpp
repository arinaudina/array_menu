#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>



int manual_input(double arr[], int size)            //Ручной ввод
{
    printf("\n  Введите элементы массива:\n");

    for (int i = 0; i < size; i++) {
        if (scanf("%lf", &arr[i]) != 1)    //Проверка
        {
            printf("ERROR\n");
            return 1;
        }
    }

    return size;
}


int random_full_input(double arr[], int size)       //Рандомные числа в полном диапазоне
{
    srand(time(NULL)); //сбрасывает random при входе в функцию

    for (int i = 0; i < size; i++) 
    {
        arr[i] = ((double)rand() / RAND_MAX * 20000 - 10000);
    }

    return size;
}


int random_natural_input(double arr[], int size)    // Рандомные числа больше 0
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
	{
		arr[i] = ((double)rand() / RAND_MAX * 10000);
	}

    return size;
}


int random_range_input(double arr[], int size)      // Рандомные числа в диапазоне [min, max]
{              
    int min, max;

    srand(time(NULL));

	do
    {
        printf("\n  Введите целое минимальное значение: ");
	    if(scanf("%d", &min) !=1) //Проверка
        {
            printf("ERROR");
            return 1;
        }
	    printf("  Введите целое максимальное значение: ");
	    if(scanf("%d", &max) != 1) //Проверка
        {
            printf("ERROR");
            return 1;
        }
    } while (min >= max); //Получение корректных значений от пользователя

	for (int i = 0; i < size; i++)				// Заполнение массива случайными числами в диапазоне [min, max]
	{
		arr[i] = (double)rand() / RAND_MAX * (max - min) + min;
	}

    return size;
}


int arithmetic_progression_input(double arr[], int size)      // Арифметическая прогрессия
{
    double start, step;

		printf("\n  Введите начальное число: ");
	    if(scanf("%lf", &start) !=1) //Проверка
        {
            printf("ERROR");
            return 1;
        }
	    do
        {
            printf("  Введите шаг прогрессии: ");
	        if(scanf("%lf", &step) != 1) //Проверка
            {
                printf("ERROR");
                return 1;
            }
        }while(step == 0);      //чтоб не заполнять массив одинаковыми числами

		for (int i = 0; i < size; i++)				
		{
			arr[i] = start + i * step;				//aₙ = a₁ + (n-1) * d
		}

    return size;
}


int geometric_progression_input(double arr[], int size)     // Геометрическая прогрессия
{
    double start, ratio;

        do
        {
		    printf("\n  Введите начальное число: ");
            if(scanf("%lf", &start) !=1) //Проверка
            {
                printf("ERROR");
                return 1;
            }
        }while(start == 0);
        do
        {
		    printf("  Введите знаменатель прогрессии: ");
            if(scanf("%lf", &ratio) != 1) //Проверка
            {
                printf("ERROR");
                return 1;
            }
        }while(ratio == 0);         //Чтоб не заполнять массив одинаковыми числами

		arr[0] = start;							
		for (int i = 1; i < size; i++)
        {
			arr[i] = arr[i - 1] * ratio;		// aₙ = a₁ * qⁿ⁻¹
		}
        return size;
}


int squares_num_input(double arr[], int size)     // Квадраты чисел
{
    double start;
    int ansver;
			
    printf("\n  Введите начальное число: ");
	if(scanf("%lf", &start) != 1)
            {
                printf("ERROR");
                return 1;
            }
    printf ("\n- Введите 1 если хотите заполнять массив по возрастанию\n- Введите 2 если хотите заполнять массив по убыванию\n");
    do
    {
        printf("\n  Ваш ответ: ");

        if(scanf("%d", &ansver) != 1)
            {
                printf("ERROR");
                return 1;
            }
        
        switch (ansver)
        {
            case 1:
            {
	            for (int i = 0; i < size; i++)			
	            {
		            arr[i] = (start + i) * (start + i);
	            }
                break;
            }
            case 2:
            {
                for (int i = 0; i < size; i++)			
	            {
		            arr[i] = (start - i) * (start - i);
	            }
                break;
            }
        }
    }while ((ansver != 1) && (ansver != 2));

    return size;
}


int pow_num_input(double arr[], int size)       // Массив степени числа
{
    double start, start_power;
    int ansver;

	do
    {
    printf("\n  Введите число: ");
    if(scanf("%lf", &start) != 1)
            {
                printf("ERROR");
                return 1;
            }
    }while((start == 0) || (start == 1));
	printf("  Введите начальную степень: ");
    if(scanf("%lf", &start_power) != 1)
            {
                printf("ERROR");
                return 1;
            }

    printf ("\n- Введите 1 если хотите заполнять массив по возрастанию степени\n- Введите 2 если хотите заполнять массив по убыванию степени\n");
    do
    {
        printf("\n  Ваш ответ: ");

        if(scanf("%d", &ansver) != 1)
            {
                printf("ERROR");
                return 1;
            }
        
        switch (ansver)
        {
            case 1:
            {
	           for (int i = 0; i < size; i++)	
				{
					arr[i] = pow(start, start_power + i);
				} 
                break;
            }
            case 2:
            {
                for (int i = 0; i < size; i++)	
				{
					arr[i] = pow(start, start_power - i);
				} 
                break;
            }
        }
    }while ((ansver != 1) && (ansver != 2));

    return size;
}


// Функционал ввода данных в массив:


int input(double arr[], int size, int *error_remark) 
{    
    *error_remark = 0;
    
    printf("\nИнструкция по заполнению массива:\n");
	printf(" - Для заполнения массива необходимо указать его размер\n");
    printf(" - При указании размера массива введите любое число от 1 до 200\n");
    printf("    Если размер массива 20 и меньше - вам будет доступен ручной ввод\n");
    printf("    Если размер массива больше 20 - вам будет доступно меню с вариантами заполнения массива\n");
    printf(" - Введите 1 если хотите продолжить или 0 если хотите вернуться назад в главное меню\n \n");

    int forward_back;
    do                                              //Ожидание ответа от пользователя
    { 
        printf("Введите требуемое значение: ");
        if (scanf("%d",&forward_back) != 1)
        {
            *error_remark = +1;
			return 1;
        }
    } while ((forward_back != 0) && (forward_back != 1));
    if (forward_back == 0)
    {
        return 0;
    }
    
    int user_size;
    do												//Количество элементов в массиве
	{
		printf("\nВведите размер массива: ");
		if(scanf("%d", &user_size) != 1)
		{
            *error_remark = +1;
			return 1;
		}
	} while ((user_size < 1) || (user_size > size));


	if (user_size <= 20)									//Вариативность заполнения
	{
        user_size = manual_input(arr, user_size);
	}
	else
	{
		printf("\nВарианты заполнения массива:\n");		    //Предоставляемые виды заполнения
		printf(" 1.Массив со случайными числами в полном диапазоне\n 2.Массив со случайными неотрицательными числами\n 3.Массив чисел от _ до _\n");
		printf(" 4.Массив арифметической прогрессии\n 5.Массив геометрической прогрессии\n 6.Массив квадратов чисел\n 7.Массив степени числа\n\nВыберите как заполнить массив: ");
		
        int ansver1;
        if (scanf("%d", &ansver1) != 1)
        {
            *error_remark = +1;
            return 1;
        }

		switch (ansver1)								// Обработка запроса пользователя
		{
			case 1:
			{
                user_size = random_full_input(arr, user_size);
				break;
			}

			case 2:
			{
				user_size = random_natural_input(arr, user_size);
				break;
			}

			case 3:
			{
                user_size = random_range_input(arr, user_size);
				break;
			}

			case 4:
			{
                user_size = arithmetic_progression_input(arr, user_size);
				break;
			}

			case 5:
			{
				user_size = geometric_progression_input(arr, user_size);
				break;
			}

			case 6:
			{
				user_size = squares_num_input(arr, user_size);
				break;
			}

			case 7:
			{
				user_size = pow_num_input(arr, user_size);
				break;
			}

		} return user_size;
	}
    return user_size;
}
