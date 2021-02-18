#include <stdio.h>

int binsearch_1(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int binsearch_2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid]) {
            high = mid;
        }
        /* reducing to one condition means that we end up shifting low right until it equals our search value */
        else {
            low = mid + 1;
        }
    }

    /* use low instead of mid */
    if (x == v[low]) {
        return low;
    }

    return -1;
}

int main() {
    int x = 6;
    int v[] = {1, 2, 3, 5, 6, 7, 10, 12, 13, 14};
    int n = 10;

    printf("binary search 1: %d\n", binsearch_1(x, v, n));
    printf("binary search 2: %d\n", binsearch_2(x, v, n));

    return 0;
}
