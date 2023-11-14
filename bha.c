#include <stdio.h>
#include <limits.h>

int hs = 1;
int h[100];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapup(int i) {
    while (i > 1 && h[i / 2] < h[i]) {
        swap(&h[i / 2], &h[i]);
        i = i / 2;
    }
}

void heapdown(int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int large = i;
    if (l < hs && h[l] > h[large]) {
        large = l;
    }
    if (r < hs && h[r] > h[large]) {
        large = r;
    }
    if (large != i) {
        swap(&h[i], &h[large]);
        heapdown(large);
    }
}

void insert(int n) {
    if (hs >= 100) {
        printf("Heap is full\n");
    } else {
        h[hs] = n;
        heapup(hs);
        hs++;
    }
}

int delmax() {
    if (hs <= 1) {
        printf("Heap is empty\n");
        return -1;
    } else {
        int root = h[1];
        h[1] = h[hs - 1];
        hs--;
        heapdown(1);
        return root;
    }
}

int findKthLargest(int k) {
    if (k < 1 || k > hs) {
        printf("Invalid value of k.\n");
        return -1;
    }
    for (int i = 0; i < k - 1; i++) {
        delmax();
    }
    return delmax();
}

int main() {
    hs = 1;
    h[1] = INT_MIN;
    int c = 0, opt, n, k;
    printf("1.insert\n2.find kth largest\n3.exit\n");
    while (c == 0) {
        printf("enter option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &n);
                insert(n);
                break;
            case 2:
                printf("enter k value: ");
                scanf("%d", &k);
                int result = findKthLargest(k);
                if (result != -1) {
                    printf("the %dth largest element is: %d\n", k, result);
                }
                break;
            case 3:
                c++;
                break;
            default:
                printf("invalid input\n");
                break;
        }
    }
}
