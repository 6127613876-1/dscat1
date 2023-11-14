#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapifyUp(int heap[], int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] < heap[parent]) {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void insertIntoMinHeap(int heap[], int *heapSize, int element) {
    if (*heapSize >= 100) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }
    heap[*heapSize] = element;
    (*heapSize)++;
    minHeapifyUp(heap, *heapSize - 1);
}
int findMinInMinHeap(int heap[]) {
    if (heap == NULL) {
        printf("Heap is not initialized.\n");
        return -1; // Return some sentinel value to indicate error.
    }

    if (heap[0] != -1) {
        return heap[0];
    } else {
        printf("Heap is empty. There is no minimum element.\n");
        return -1; // Return some sentinel value to indicate error.
    }
}
void minHeapifyDown(int heap[], int size, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < size && heap[leftChild] < heap[smallest])
        smallest = leftChild;

    if (rightChild < size && heap[rightChild] < heap[smallest])
        smallest = rightChild;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapifyDown(heap, size, smallest);
    }
}

int deleteMinFromMinHeap(int heap[], int *heapSize) {
    if (*heapSize <= 0) {
        printf("Heap is empty. Cannot delete.\n");
        return -1; // Return some sentinel value to indicate error.
    }

    int min = heap[0];
    heap[0] = heap[*heapSize - 1];
    (*heapSize)--;
    minHeapifyDown(heap, *heapSize, 0);

    return min;
}

int main() {

    int heapSize = 0;
    int n,i;
    int num;
    int min;
    int op;
    int c=1;
    printf("no. of elements to be inserted:");
   
    scanf("%d",&n);
    int minHeap[n];
    while(c==1)
    {
        printf("1.insert\n2.delete\n3.find min\n4.print\nenter choice:");
        scanf("%d",&op);
    switch(op)
    {
    case 1:
        printf("enter:");
        scanf("%d",&num);
        insertIntoMinHeap(minHeap, &heapSize, num);
        break;
    case 2:
        min = deleteMinFromMinHeap(minHeap, &heapSize);
        printf("Deleted min element: %d\n", min);
        break;
    case 3:
        min = findMinInMinHeap(minHeap);
        if (min != -1) {
        printf("Minimum element in the min-heap: %d\n", min);
        }
        break;
    case 4:
        printf("Min-Heap elements: ");
        for (int i = 0; i < heapSize; i++) {
        printf("%d ", minHeap[i]);
    }
    printf("\n");
    }
    printf("enter 1 to cntnu:");
    scanf("%d",&c);
    }
    return 0;
}