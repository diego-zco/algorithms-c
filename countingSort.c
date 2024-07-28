#include <stdio.h>


void countingSort(int a[], int n, int k) {

    int b[n];
    int count[k];

    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    
    for (int i = 1; i <= k; i++) {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n-1; i >= 0; i--) {
        b[--count[a[i]]] = a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }

}


int main() {
    int a[] = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
    int size = *(&a + 1) - a;
    int k = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] > k) {
            k = a[i];
        }
    }

    printf("Before\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    printf("\nAfter\n");

    countingSort(a, size, k);

    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}