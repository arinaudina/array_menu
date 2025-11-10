#include <stdio.h>

// Forward declarations of search functions
int straight_search(double arr[], int size, double target);
int barrier_search(double arr[], int size, double target);
int binary_search(double arr[], int size, double target);


int menu_search_element(double arr[], int size) {
    if (size <= 0) {
        printf("ERR: Array is empty. Please fill the array first.\n");
        return -1;
    }

    double target = 0.;
    printf("  Enter the element to search for: ");
    if (scanf("%lf", &target) != 1) {
        printf("ERR: Invalid input\n");
        return -1;
    }
    printf("\n"); // New line for better readability after scanf

    int answer = 0;
    int index = -1; // Index of the found element
    do {
        printf(
            "Select search method:\n"
            "1. Straight search\n"
            "2. Barrier search\n"
            "3. Binary search (array must be sorted)\n"
            "Select: "
        );

        if (scanf("%d", &answer) != 1) {
            printf("ERR: Invalid input\n");
            return -1;
        }
        printf("\n"); // New line for better readability after scanf

        switch (answer) {
        case 1:
            index = straight_search(arr, size, target);
            break;
        case 2:
            index = barrier_search(arr, size, target);
            break;
        case 3:
            index = binary_search(arr, size, target);
            break;
        default:
            printf("ERR: Invalid selection. Please try again.\n");
        }
    } while (answer < 1 || answer > 3);

    return index;
}

/**
 * Searches for the target element in the array using linear traversal.
 * 
 * \param arr - array to be searched
 * \param size - size of the array
 * \param target - element to search for
 * \return index of the found element or -1 if not found
 */
int straight_search(double arr[], int size, double target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

/**
 * Function to perform barrier search on the array
 * 
 * \param arr - array to be searched
 * \param size - size of the array
 * \param target - element to search for
 * \return index of the found element or -1 if not found
 */
int barrier_search(double arr[], int size, double target) {
    double last = arr[size - 1];
    arr[size - 1] = target; // Set barrier

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    arr[size - 1] = last; // Restore last element

    if (i < size - 1 || arr[size - 1] == target) {
        return i; // Element found
    }
    return -1; // Element not found
}

/**
 * Function to perform binary search on the array
 * Array must be sorted in ascending order.
 * 
 * \param arr - array to be searched
 * \param size - size of the array
 * \param target - element to search for
 * \return index of the found element or -1 if not found
 */
int binary_search(double arr[], int size, double target) {
    // Check if the array is sorted
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("ERR: Binary search cannot be performed on an unsorted array.\n");
            return -1;
        }
    }

    // Binary search algorithm
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found
        }
        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}
