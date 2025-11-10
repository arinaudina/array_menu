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
/**
 * Function to sort the array based on user-selected method
 * 
 * \param arr - array to be sorted
 * \param size - size of the array
 * \return size of the sorted array or -1 in case of error
 */
int menu_sort_array(double arr[], int size);
/**
 * Function to search for an element in the array based on user-selected method
 * 
 * \param arr - array to be searched
 * \param size - size of the array
 * \param sorted - indicates if the array is sorted
 * \return index of the found element or -1 if not found
 */
int menu_search_element(double arr[], int size, bool sorted);


int main() {
	double array[MAX_SIZE]; // Array to be filled
	int size = 0; // Size of the filled array

	int answer = 0;
	bool filled = false;
	bool sorted = false;
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
			const int res = menu_fill_array(array, MAX_SIZE, MANUAL_LIMIT);
			filled = res > 0;
			if (filled) {
				size = res;
				printf("Array filled successfully. Size: %d\n", size);
			} else {
				size = 0;
				printf("ERR: Filling array failed\n");
			}
			// After filling, the array is not sorted
			sorted = false;
			break;
		case 2:
			if (filled) {
				printf("Array elements:\n");
				for (int i = 0; i < size; i++) {
					printf("  Element %d: %lf\n", i + 1, array[i]);
				}
			} else {
				printf("Array is empty. Please fill the array first.\n");
			}
			break;
		case 3: {
			if (!filled) {
				printf("Array is empty. Please fill the array first.\n");
				break;
			}

			const int error = menu_sort_array(array, size);
			sorted = (error >= 0);
			if (sorted) {
				printf("Array sorted successfully.\n");
			} else {
				printf("ERR: Array sorting failed\n");
			}
			break;
		}
		case 4:
			if (!filled) {
				printf("Array is empty. Please fill the array first.\n");
				break;
			}

			const int index = menu_search_element(array, size, sorted);
			if (index != -1) {
				printf("Element found at index: %d\n", index);
			} else {
				printf("Element not found in the array.\n");
			}
			break;
		case 5:
			if (!filled || !sorted) {
				printf("Array is empty or not sorted. Please fill and sort the array first.\n");
				break;
			}
			
			printf("Add element functionality not implemented yet.\n");
			break;
		case 0:
			printf("Exiting program.\n");
			break;
		};
	} while (answer != 0);

	return 0;
}
