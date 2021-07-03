//
// Created by Chang on 03/07/2021.
//

#ifndef INC_01_SORT_SORTTESTHELPER_H
#define INC_01_SORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

namespace SortTestHelper {

    /*
     * 返回生成的随机数组，数组元素区间 [rangeL, rangeR]
     */
    int* generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);

        int *arr = new int[n];  // new 的数组后续需释放内存

        // 生成区间 [rangeL, rangeR] 内的随机数
        srand(time(nullptr));  // 随机种子设置，当前时间设为种子
        for (int i = 0; i <= n; i++)
            // 生成给定区间的随机数，rand() 返回一个随机整数
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;

        return arr;
    }

    /*
     * 生成近乎有序的数组
     */
    int* generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for(int i = 0 ; i < n ; i ++ )
            arr[i] = i;

        srand(time(nullptr));
        for( int i = 0 ; i < swapTimes ; i ++ ){
            int posx = rand()%n;
            int posy = rand()%n;
            std::swap( arr[posx] , arr[posy] );
        }

        return arr;
    }

    /*
     * 拷贝 int 型数组
     */
    int* copyIntArray(int a[], int n) {
        int* arr = new int[n];
        std::copy(a, a+n, arr);  // 输入分别为 待拷贝数组头指针、尾指针、新数组
        return arr;
    }

    /*
     * 打印数组
     */
    template <typename T>
    void printArray(T arr, int n) {
        for ( int i = 0 ; i <= n-1 ; i ++ )
            std::cout << arr[i] <<" ";
        std::cout << std::endl;
    }

    template<typename T>
    void printArray(T arr[], int l, int r) {

        for (int i = l; i <= r; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        return;
    }

    /*
     * 测试数组是否有序
     */
    template<typename T>
    bool isSorted(T arr[], int n) {

        for (int i = 0; i <= n - 2; i++)
            if (arr[i] > arr[i + 1]) return false;

        return true;
    }

    /*
     * 测试排序算法，打印算法排序时间
     */
    template <typename T>
    void testSort(std::string sortName, void(*sort)(T[], int), T arr[], int n) {

        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        std::cout << sortName
                  << " : "
                  << double(endTime - startTime) / CLOCKS_PER_SEC
                  << " s"
                  << std::endl;

        assert(isSorted(arr, n));

        return;
    }
}
#endif //INC_01_SORT_SORTTESTHELPER_H
