//
// Created by Chang on 04/07/2021.
//

#ifndef INC_02_HEAP_HEAPSORT_H
#define INC_02_HEAP_HEAPSORT_H

#include <iostream>
#include "Heap.h"

template <typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxheap = MaxHeap<T>(n);

    for (int i = 0; i <= n-1; i++)
        maxheap.insert(arr[i]);

    for (int i = n-1; i >= 0; i--)
        arr[i] = maxheap.extractMax();
}

template <typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);

    for (int i = n-1; i >= 0; i--)
        arr[i] = maxheap.extractMax();
}

/*
 * 原地堆排序，数组从 0 开始索引创建堆
 */
template <typename T>
void __shiftDown(T arr, int n, int k) {

    // 从 0 开始索引后，当前结点的左孩子索引为 2*k+1
    while(2*k+1 <= n-1) {
        int j = 2*k+1;
        if (j+1 <= n-1 && arr[j+1] > arr[j])
            j = j+1;
        if (arr[k] >= arr[j])
            break;
        std::swap(arr[k], arr[j]);
        k = j;
    }
}

template <typename T>
void heapSort(T arr[], int n) {
    for (int i = (n-1) / 2; i >= 0; i--)
        __shiftDown(arr, n, i);

    for (int i = n-1; i >= 1; i--) {
        std::swap(arr[0], arr[i]);
        __shiftDown(arr, i , 0);
    }
}

#endif //INC_02_HEAP_HEAPSORT_H
