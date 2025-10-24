#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 200 // Maximum allowable size of the array
#define MANUAL_LIMIT 20 // Size limit for manual input

/**
 * Function to fill the array based on user preferences
 * 
 * \param arr - array to be filled
 * \param max_size - maximum allowable size of the array
 * \param manual_limit - size limit for manual input
 * \return size of the filled array or -1 in case of error
 */
int menu_fill_array(double arr[], int max_size, int manual_limit);


int main() {
	double array[MAX_SIZE]; // Array to be filled
	int size = 0; // Size of the filled array

	int answer = 0;
	do {
		// Display menu options
		printf(
			"1. Enter array data\n"
			"2. Display array\n"
			"3. Sort array\n"
			"4. Search element\n"
			"5. Add element\n"
			"0. Exit\n"
			"Select: "
		);

		// Get user input
		if (scanf("%d", &answer) != 1) {
			printf("ERR: Invalid input\n");
			return -1;
		}
		printf("\n"); // New line for better readability after scanf

		// Handle menu options
		switch (answer) {
		case 1:
			size = menu_fill_array(array, MAX_SIZE, MANUAL_LIMIT);
			if (size < 0) {
				printf("ERR: Input error\n");
				return -1;
			}
			break;
		default:
			answer = 0;
			break;
		};
	} while (answer != 0);

	return 0;
}
