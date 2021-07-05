//
// Created by Chang on 29/06/2021.
//

#ifndef INC_01_SORT_SORT_H
#define INC_01_SORT_SORT_H

#include <iostream>  // 调用 std::swap() 函数
#include <ctime>     // 调用 time() 函数

/*
 * 选择排序，时间复杂度 O(n²)
 */
template <typename T>
void selectionSort(T arr, int n) {
    // 第一层循环，遍历所有元素，将当前遍历元素与其后的最小元素交换位置
    for (int i = 0; i <= n - 1; i++) {
        int MinIndex = i;
        // 第二层循环，遍历后续元素，寻找后续最小元素的索引
        for (int j = i + 1; j <= n - 1; j++) {
            if (arr[j] < arr[MinIndex])
                MinIndex = j;
        }
        std::swap(arr[i], arr[MinIndex]);
    }
}

/*
 * 插入排序，时间复杂度 O(n²)
 */
template <typename T>
void insertionSort(T arr[], int n) {
    // 从第二个元素开始，遍历所有元素
    for (int i = 1; i <= n - 1; i++) {

//        // 写法一
//        // 从当前遍历元素开始，逐一向前比较，小于前一元素，则交换位置
//        for (int j = i; j >= 1 && arr[j] < arr[j-1]; j--) {
//            // 【！】：一次交换相当于三次赋值，需优化
//            std::swap(arr[j-1], arr[j]);
//        }

        // 对上述写法中 swap() 函数的优化
        // swap() 函数相当于 3 次赋值操作，耗时
        T e = arr[i];  // 将当前需移动元素备份
        int j;         // 保存元素 e 应该插入位置
        for (j = i; j >= 1 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];

        arr[j] = e;
    }
}

/*
 * 插入排序，时间复杂度 O(n²)
 * 对arr[l...r]范围的数组进行插入排序
 */
template<typename T>
void insertionSort(T arr[], int l, int r){

    for( int i = l+1 ; i <= r ; i ++ ) {

        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}

/*
 * 希尔排序，时间复杂度 O(n^(1.3—2))
 */
template <typename T>
void shellSort(T arr[], int n) {

    int h = 1;
    while( h < n/3 )
        h = 3 * h + 1;
    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...

    while( h >= 1 ){

        // h-sort the array
        for( int i = h ; i < n ; i ++ ){

            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            T e = arr[i];
            int j;
            for( j = i ; j >= h && e < arr[j-h] ; j -= h )
                arr[j] = arr[j-h];
            arr[j] = e;
        }

        h /= 3;
    }
}

/*
 * 冒泡排序，时间复杂度 O(n²)
 */
template<typename T>
void bubbleSort(T arr[] , int n) {
    bool swapped;
    do{
        swapped = false;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ){
                std::swap( arr[i-1] , arr[i] );
                swapped = true;
            }
        n --;
    }while(swapped);
}

/*
 * 归并排序，时间复杂度 O(NlogN)
 */
template <typename T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r-l+1];
    for (int i = 0; i <= r-l; i++)
        aux[i] = arr[l+i];

    int i = 0, j = mid+1-l;
    for (int k = l; k <= r; k++) {
        if (i > mid-l )           arr[k] = aux[j++]; // 等价于 arr[k] = aux[j]; j++;
        else if (j > r-l)         arr[k] = aux[i++]; // 等价于 arr[k] = aux[i]; i++;
        else if (aux[i] < aux[j]) arr[k] = aux[i++]; // 等价于 arr[k] = aux[i]; i++;
        else                      arr[k] = aux[j++]; // 等价于 arr[k] = aux[j]; j++;
    }
}

template <typename T>
void __mergeSort(T arr[], int l, int r) {

    // 递归到底 -> 【优化】 元素量很小时，使用插入排序提高性能
    if (l >= r) return;

//    int mid = (l+r) / 2;  // l、r 都很大时，l+r 会溢出，改进如下
    int mid = (r-l) / 2 + l;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);

    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n-1);
}

/*
 * 归并排序，时间复杂度 O(NlogN)
 * 优化 :
 * 【1】 数组近乎有序
 * 【2】 小规模数组，插入排序替代
 */
template<typename T>
void __mergeSort2(T arr[], int l, int r){

    // 【优化 2】对于小规模数组,使用插入排序
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }

    int mid = (r-l) / 2 + l;
    __mergeSort2(arr, l, mid);
    __mergeSort2(arr, mid+1, r);

    // 【优化 1】对于arr[mid] <= arr[mid+1]的情况,不进行merge
    // 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
    if( arr[mid] > arr[mid+1] )
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort2(T arr[], int n){
    __mergeSort2( arr , 0 , n-1 );
}

/*
 * 归并排序 : 自底向上
 */
template <typename T>
void mergeSortBU(T arr[], int n){

//    for( int sz = 1; sz <= n ; sz += sz )  // sz : size
//        for( int i = 0 ; i < n ; i += sz+sz )
//            // 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
//            __merge(arr, i, i+sz-1, std::min(i+sz+sz-1,n-1) );

    // Merge Sort Bottom Up 优化
    for( int i = 0 ; i < n ; i += 16 )
        insertionSort(arr, i, std::min(i+15,n-1));

    for( int sz = 16; sz <= n ; sz += sz )
        for( int i = 0 ; i < n - sz ; i += sz+sz )
            if( arr[i+sz-1] > arr[i+sz] )
                __merge(arr, i, i+sz-1, std::min(i+sz+sz-1,n-1) );
}

/*
 * 快速排序，时间复杂度 O(NlogN)
 */
template <typename T>
int __partition(T arr[], int l, int r) {

    T v = arr[l];

    // arr[l+1···j] < v
    // arr[j+1···i] > v
    int j = l;
    for (int i = l+1; i <= r; i++) {
        if (arr[i] < v) std::swap(arr[++j], arr[i]); // 等价 j++; swap(arr[j], arr[i]);
    }

    // 【!】 arr[l] 不能是 v, 值相同，存储空间不一样，swap() 需详细了解
    std::swap(arr[l], arr[j]);

    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r){

    if (l >= r) return;

    int p = __partition(arr, l, r);

    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
    __quickSort(arr, 0, n-1);
}

/*
 * 快速排序 ，时间复杂度 O(NlogN)
 * 优化 :
 * 【1】 数组近乎有序
 * 【2】 数组存在大量重复元素
 */

// 【优化 2】数组存在大量【重复元素】
// 避免数组划分不平衡
template <typename T>
int __partition2(T arr[], int l, int r) {

    // 【优化 1】，在 partition 操作时，基点元素随机选取
    // 避免数组元素【基本有序】时，partition 操作两侧不平衡
    std::swap( arr[l] , arr[rand()%(r-l+1)+l] );
    T v = arr[l];

    // arr[l+1···i) <= v
    // arr(j··· r] >= v
    int i = l + 1, j = r;
    while(true) {
        while(i <= r && arr[i] < v) i++;
        while(j >= l+1 && arr[j] > v) j--;
        if (i > j) break;

        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
    std::swap(arr[l], arr[j]);
     return j;
}

template <typename T>
void __quickSort2(T arr[], int l, int r){

    // 【优化 2】数组元素较少时，使用插入排序替代
    if (r-l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);

    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort2(T arr[], int n) {

    // 【优化 1】，在 partition 操作时，基点元素随机选取
    // 避免数组元素【基本有序】时，partition 操作两侧不平衡
    srand(time(nullptr));

    __quickSort2(arr, 0, n-1);
}

/*
 * 三路快速排序，时间复杂度 O(NlogN)
 */
template <typename T>
void __quickSort3Ways(T arr[], int l, int r){

    if( r - l <= 15 ){
        insertionSort(arr,l,r);
        return;
    }

    std::swap( arr[l], arr[rand()%(r-l+1)+l ] );

    T v = arr[l];

    int lt = l;     // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l+1;    // arr[lt+1...i) == v
    while( i < gt ){
        if( arr[i] < v ){
            std::swap( arr[i], arr[lt+1]);
            i ++;
            lt ++;
        }
        else if( arr[i] > v ){
            std::swap( arr[i], arr[gt-1]);
            gt --;
        }
        else{ // arr[i] == v
            i ++;
        }
    }

    std::swap( arr[l] , arr[lt] );

    __quickSort3Ways(arr, l, lt-1);
    __quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n){


    srand(time(nullptr));

    __quickSort3Ways( arr, 0, n-1);
}

#endif //INC_01_SORT_SORT_H
