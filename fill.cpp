#include <stdio.h>
#include <time.h>
#include <math.h>

// Forward declarations of input functions
int manual_input(double arr[], int size);
int random_full_input(double arr[], int size);
int random_natural_input(double arr[], int size);
int random_range_input(double arr[], int size);
int arithmetic_progression_input(double arr[], int size);
int geometric_progression_input(double arr[], int size);
int squares_num_input(double arr[], int size);
int pow_num_input(double arr[], int size);


int menu_fill_array(double arr[], int max_size, int manual_limit) {
	// Instructions for filling the array
    printf(
		"Filling instructions:\n"
		"- To fill the array, you must specify its size\n"
		"- When specifying the array size, enter any number from 1 to 200\n"
		"   If the array size is 20 or less, manual input will be available\n"
		"   If the array size is greater than 20, a menu with filling options will be available\n"
	);

	// Asking the user whether to continue filling the array or return to the main menu
    int answer1 = 0;
    do {
		printf(
			"1. Continue filling the array\n"
			"0. Return to the main menu\n"
			"Select: "
		);

		if (scanf("%d", &answer1) != 1) {
			printf("ERR: Invalid input\n");
			return -1;
		}
		printf("\n"); // New line for better readability after scanf
    } while ((answer1 != 0) && (answer1 != 1));

	// If the user chooses to return to the main menu
    if (answer1 == 0) {
        return 0;
    }

	// Getting the array size from the user
    int user_size = 0; // Size of the array specified by the user
    do {
		printf("Enter the array size: ");
		if (scanf("%d", user_size) != 1) {
			printf("ERR: Invalid input\n");
			return -1;
		}
		printf("\n"); // New line for better readability after scanf
	} while ((user_size < 1) || (user_size > max_size));


	// If the array size is less than or equal to the manual limit, use manual input
	if (user_size <= manual_limit) {
        return manual_input(arr, user_size);
	}

	// Displaying the filling options menu and getting the user's choice
	int answer2 = 0;
	do {
		printf(
			"Variants for filling the array:\n"
			"1. Array with random numbers in the full range\n"
			"2. Array with random non-negative numbers\n"
			"3. Array of numbers from _ to _\n"
			"4. Array of arithmetic progression\n"
			"5. Array of geometric progression\n"
			"6. Array of squares of numbers\n"
			"7. Array of powers of a number\n"
			"0. Return to main menu\n"
			"Select: "
		);

		if (scanf("%d", &answer2) != 1) {
			printf("ERR: Invalid input\n");
			return -1;
		}
		printf("\n"); // New line for better readability after scanf

		// Filling the array based on the user's choice
		switch (answer2) {
		case 1:
			user_size = random_full_input(arr, user_size);
			break;
		case 2:
			user_size = random_natural_input(arr, user_size);
			break;
		case 3:
			user_size = random_range_input(arr, user_size);
			break;
		case 4:
			user_size = arithmetic_progression_input(arr, user_size);
			break;
		case 5:
			user_size = geometric_progression_input(arr, user_size);
			break;
		case 6:
			user_size = squares_num_input(arr, user_size);
			break;
		case 7:
			user_size = pow_num_input(arr, user_size);
			break;
		case 0:
			printf("Returning to main menu.\n");
			user_size = 0;
			break;
		default:
			printf("Incorrect option. Try again.\n");
			break;
		}
	} while ((answer2 < 0) || (answer2 > 7));

    return user_size;
}

/**
 * Function for manual input of array elements
 * 
 * \param arr - array to be filled
 * \param size - size of the array
 * \return size of the filled array or -1 in case of error
 */
int manual_input(double arr[], int size) {
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
		printf("  Element %d: ", i + 1);
        if (scanf("%lf", &arr[i]) != 1) {
            return -1;
        }
		printf("\n"); // New line for better readability after scanf
    }
    return size;
}

/**
 * Function to fill the array with random numbers in the full range
 * 
 * \param arr - array to be filled
 * \param size - size of the array
 * \return size of the filled array or -1 in case of error
 */
int random_full_input(double arr[], int size) {
    srand(time(NULL)); // Reset random number generator

    for (int i = 0; i < size; i++) {
        arr[i] = ((double)rand() / RAND_MAX * 20000 - 10000);
    }
    return size;
}

/**
 * Function to fill the array with random non-negative numbers
 * 
 * \param arr - array to be filled
 * \param size - size of the array
 * \return size of the filled array or -1 in case of error
 */
int random_natural_input(double arr[], int size) {
    srand(time(NULL)); // Reset random number generator

    for (int i = 0; i < size; i++) {
        arr[i] = ((double)rand() / RAND_MAX * 10000);
    }
    return size;
}

/**
 * Function to fill the array with random numbers in a specified range
 * 
 * \param arr - array to be filled
 * \param size - size of the array
 * \return size of the filled array or -1 in case of error
 */
int random_range_input(double arr[], int size) {
    srand(time(NULL)); // Reset random number generator

    int min = 0; // Minimum value of the range
    int max = 0; // Maximum value of the range
    do {
		printf("  Enter an integer minimum value: ");
        if (scanf("%d", &min) != 1) {
            return -1;
        }
		printf("\n"); // New line for better readability after scanf

	    printf("  Enter an integer maximum value: ");
        if (scanf("%d", &max) != 1) {
            return -1;
        }
		printf("\n"); // New line for better readability after scanf
    } while (min >= max);

	// Filling the array with random numbers in the specified range
	for (int i = 0; i < size; i++) {
		arr[i] = (double)rand() / RAND_MAX * (max - min) + min;
	}
    return size;
}

/**
 * Function to fill the array with an arithmetic progression
 * 
 * \param arr - array to be filled
 * \param size - size of the array
 * \return size of the filled array or -1 in case of error
 */
int arithmetic_progression_input(double arr[], int size) {
    double start = 0.; // First term of the progression
    double step = 0.; // Common difference of the progression

	printf("\n  Enter the initial number: ");
	if (scanf("%lf", &start) != 1) {
		return -1;
	}
	printf("\n"); // New line for better readability after scanf

	do {
		printf("  Enter the step of the progression: ");
		if (scanf("%lf", &step) != 1) {
			return -1;
		}
		printf("\n"); // New line for better readability after scanf
	} while(step == 0); // To avoid filling the array with identical numbers step cannot be 0

	for (int i = 0; i < size; i++) {
		// aₙ = a₁ + (n-1) * d
		arr[i] = start + i * step;
	}
    return size;
}

/**
 * Function to fill the array with a geometric progression
 * 
 * \param arr - array to be filled
 * \param size - size of the array
 * \return size of the filled array or -1 in case of error
 */
int geometric_progression_input(double arr[], int size) {
    double start = 0.; // First term of the progression
    double ratio = 0.; // Common ratio of the progression

	// Getting the first term of the progression from the user
	do {
		printf("  Enter the initial number: ");
		if (scanf("%lf", &start) != 1) {
			return -1;
		}
		printf("\n"); // New line for better readability after scanf
	} while(start == 0); // To avoid filling the array with identical numbers start cannot be 0

	// Getting the common ratio of the progression from the user
	do {
		printf("  Enter the ratio of the progression: ");
		if (scanf("%lf", &ratio) != 1) {
			return -1;
		}
		printf("\n"); // New line for better readability after scanf
	} while(ratio == 0); // To avoid filling the array with identical numbers ratio cannot be 0

	// Filling the array with geometric progression
	arr[0] = start; // First element
	for (int i = 1; i < size; i++) {
		// aₙ = a₁ * qⁿ⁻¹
		arr[i] = arr[i - 1] * ratio;
	}
	return size;
}

/**
 * Function to fill the array with squares of numbers
 * 
 * \param arr - array to be filled
 * \param size - size of the array
 * \return size of the filled array or -1 in case of error
 */
int squares_num_input(double arr[], int size) {
    double start = 0.; // Initial number

    printf("\n  Enter the initial number: ");
	if (scanf("%lf", &start) != 1) {
		return -1;
	}
	printf("\n"); // New line for better readability after scanf

    int answer = 0;
    do {
		printf (
			"1. Fill array in ascending order\n"
			"2. Fill array in descending order\n"
			"Select: "
		);

		if (scanf("%d", &answer) != 1) {
			return -1;
		}
		printf("\n"); // New line for better readability after scanf
        
        switch (answer) {
		case 1:
			// Filling the array in ascending order
			for (int i = 0; i < size; i++) {
				arr[i] = (start + i) * (start + i);
			}
			break;
		case 2:
			// Filling the array in descending order
			for (int i = 0; i < size; i++) {
				arr[i] = (start - i) * (start - i);
			}
			break;
        }
    } while ((answer != 1) && (answer != 2));

    return size;
}

/**
 * Function to fill the array with powers of a number
 * 
 * \param arr - array to be filled
 * \param size - size of the array
 * \return size of the filled array or -1 in case of error
 */
int pow_num_input(double arr[], int size) {
    double start = 0.; // Base number
    double start_power = 0.; // Initial exponent

    int answer = 0;
	do {
        printf("  Enter the base number (not 0 or 1): ");
		if (scanf("%lf", &start) != 1) {
			return -1;
		}
		printf("\n"); // New line for better readability after scanf
    } while((start == 0) || (start == 1));

	printf("  Enter the initial exponent: ");
	if (scanf("%lf", &start_power) != 1) {
		return -1;
	}
	printf("\n"); // New line for better readability after scanf

    do {
		printf (
			"- 1. Fill the array in ascending order of exponent\n"
			"- 2. Fill the array in descending order of exponent\n"
			"  Select: "
		);

		if (scanf("%d", &answer) != 1) {
			return -1;
		}
		printf("\n"); // New line for better readability after scanf
        
        switch (answer) {
		case 1:
			for (int i = 0; i < size; i++) {
				arr[i] = pow(start, start_power + i);
			}
			break;
		case 2:
			for (int i = 0; i < size; i++) {
				arr[i] = pow(start, start_power - i);
			}
			break;
		default:
			printf("\nInvalid option. Try again.\n");
			break;
        }
    } while ((answer != 1) && (answer != 2));

    return size;
}
