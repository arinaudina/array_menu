#include <stdio.h>

// Forward declarations of sorting functions
int check_sorted(double arr[], int size);
void linear_sort(double arr[], int size);
void bubble_sort(double arr[], int size);
void insertion_sort(double arr[], int size);

int menu_sort_array(double arr[], int size) {
    if (check_sorted(arr, size) == 0) {
        printf("Array is already sorted.\n");
        return size;
    }

    // Display sorting method options and get user choice
    int answer = 0;
    do {
        printf(
            "Sorting methods:\n"
            "1. Linear Sort\n"
            "2. Bubble Sort\n"
            "3. Insertion Sort\n"
            "0. Return to main menu\n"
            "Select sorting method: "
        );
        if (scanf("%d", &answer) != 1) {
            printf("ERR: Invalid input\n");
            return -1;
        }
        printf("\n"); // New line for better readability after scanf
    } while (answer < 0 || answer > 3);

    switch (answer) {
    case 1:
        linear_sort(arr, size);
        break;
    case 2:
        bubble_sort(arr, size);
        break;
    case 3:
        insertion_sort(arr, size);
        break;
    case 0:
        printf("Returning to main menu.\n");
        break;
    }

    return size;
}
/**
 * Function to check if the array is sorted in ascending order
 * 
 * \param arr - array to be checked
 * \param size - size of the array
 */
int check_sorted(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return -1; // Array is not sorted
        }
    }
    return 0; // Array is sorted
}

/**
 * Function to perform linear sort on the array
 * 
 * \param arr - array to be sorted
 * \param size - size of the array
 */
void linear_sort(double arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * Function to perform bubble sort on the array
 * 
 * \param arr - array to be sorted
 * \param size - size of the array
 */
void bubble_sort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * Function to perform insertion sort on the array
 * 
 * \param arr - array to be sorted
 * \param size - size of the array
 */
void insertion_sort(double arr[], int size) {
    for (int i = 1; i < size; i++) {
        double key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
