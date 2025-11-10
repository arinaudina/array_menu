#include <stdio.h>

// Forward declarations of insertion functions
int binary_search_and_insert(double arr[], int size, double new_element);
int insert_element(double arr[], int size, double new_element, int pos);


int menu_insert_element(double arr[], int size, int max_size) {
    if (size >= max_size - 1) {
        printf("ERR: Array is full. Cannot insert new element.\n");
        return -1;
    }

    double new_element = 0.;
    printf("  Enter the element to insert: ");
    if (scanf("%lf", &new_element) != 1) {
        printf("ERR: Invalid input\n");
        return -1;
    }
    printf("\n"); // New line for better readability after scanf

    return binary_search_and_insert(arr, size, new_element);
}

/**
 * Searches for the new_element using binary search.
 * If the element is not found, it inserts the element in sorted order else does nothing.
 * 
 * \param arr - array to be searched and modified
 * \param size - current size of the array
 * \param new_element - element to search for and insert if not found
 * \return new size of the array or -1 in case of error
 */
int binary_search_and_insert(double arr[], int size, double new_element) {
    int left = 0;
    int right = size - 1;
    int mid = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == new_element) {
            // Element found, no insertion needed
            printf("Element already exists in the array at index %d. No insertion made.\n", mid);
            return size;
        }
        if (arr[mid] < new_element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Element not found, insert at position 'left'
    return insert_element(arr, size, new_element, left);
}

/**
 * Function to insert an element at a specified position in the array
 * 
 * \param arr - array to be modified
 * \param size - current size of the array
 * \param new_element - element to insert
 * \param pos - position to insert the element at
 * \return new size of the array or -1 in case of error
 */
int insert_element(double arr[], int size, double new_element, int pos) {
    if (pos < 0 || pos > size) {
        printf("ERR: Invalid position. Please try again.\n");
        return -1;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = new_element; // Insert the new element
    return size + 1;
}
