#include <stdio.h>

void insertion_sort(int array[], int size) {
    
    
    for (int i = 1; i < size; i++) {
        int temp = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > temp) {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = temp;

    }

    for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }

    printf("\n");
}


int main() {
    int array[] = {5, 4, 10, 1, 6, 2};
    int size = *(&array + 1) - array;
    
    insertion_sort(array, size);
    return 0;
    
}