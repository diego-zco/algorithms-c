#include <stdio.h>

void selectionSort(int a[], int size) {
    
    
    for (int i = 0; i < size - 1; i++) {
        // Get min element
        int min = i;

        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}


int main() {
    int a[] = {7, 4, 10, 8, 3, 1};
    int size = *(&a + 1) - a;

    selectionSort(a, size);
    return 0;

}