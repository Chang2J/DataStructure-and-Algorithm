#include <iostream>
#include "Sort.h"
#include "SortTestHelper.h"

int main() {
    int n = 1000000;

    // 测试1 一般性测试
    std::cout << "Test for Random Array, size = "
              << n
              <<", random range [0, " << n << "]"
              << std::endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);
    int* arr3 = SortTestHelper::copyIntArray(arr1,n);
    int* arr4 = SortTestHelper::copyIntArray(arr1,n);
    int* arr5 = SortTestHelper::copyIntArray(arr1,n);
    int* arr6 = SortTestHelper::copyIntArray(arr1,n);
    int* arr7 = SortTestHelper::copyIntArray(arr1,n);
    int* arr8 = SortTestHelper::copyIntArray(arr1,n);
    int* arr9 = SortTestHelper::copyIntArray(arr1,n);
    int* arr10 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr4, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr5, n);
    SortTestHelper::testSort("Merge Sort Optimization", mergeSort2, arr6, n);
    SortTestHelper::testSort("Merge Sort from Bottom to Up", mergeSortBU, arr7, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr8, n);
    SortTestHelper::testSort("Quick Sort Optimization", quickSort2, arr9, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr10, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    std::cout << std::endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    std::cout << "Test for Random Nearly Ordered Array, size = "
              << n
              <<", swap time = "
              << swapTimes
              << std::endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);
    arr8 = SortTestHelper::copyIntArray(arr1,n);
    arr9 = SortTestHelper::copyIntArray(arr1,n);
    arr10 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr4, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr5, n);
    SortTestHelper::testSort("Merge Sort Optimization", mergeSort2, arr6, n);
    SortTestHelper::testSort("Merge Sort from Bottom to Up", mergeSortBU, arr7, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr8, n);
    SortTestHelper::testSort("Quick Sort Optimization", quickSort2, arr9, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr10, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    std::cout << std::endl;


    // 测试3 测试存在包含大量相同元素的数组
    std::cout << "Test for Random Array, size = "
              << n
              << ", random range [0,10]"
              << std::endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);
    arr8 = SortTestHelper::copyIntArray(arr1,n);
    arr9 = SortTestHelper::copyIntArray(arr1,n);
    arr10 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr3, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr4, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr5, n);
    SortTestHelper::testSort("Merge Sort Optimization", mergeSort2, arr6, n);
    SortTestHelper::testSort("Merge Sort from Bottom to Up", mergeSortBU, arr7, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr8, n);
    SortTestHelper::testSort("Quick Sort Optimization", quickSort2, arr9, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr10, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    return 0;
}
