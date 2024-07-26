#include <stdio.h>


int partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (a[start] <= pivot) {
            start++;
        }
        while (a[end] > pivot) {
            end--;
        }

        if (start < end) {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
        int t = a[lb];
        a[lb] = a[end];
        a[end] = t;
    }

    return end;

}

void quickSort(int a[], int lb, int ub) {
    int loc;
    if (lb < ub) {
        loc = partition(a, lb, ub);
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}


int main() {
    int a[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int size = *(&a + 1) - a;

    printf("Before\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    printf("\nAfter\n");

    quickSort(a, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}