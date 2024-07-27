#include <stdio.h>


void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub];


    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }

        k++;

    }

    if (i > mid) {
        while (j <= ub) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for (int x = lb; x <= ub; x++) {
        a[x] = b[x];
    }

}


void mergeSort(int a[], int lb, int ub) {

    if (lb < ub) {
        int mid = (ub + lb) / 2;

        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }

}


int main() {
    int a[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
    int size = *(&a + 1) - a;

    mergeSort(a, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}