//
// Created by Chang on 22/07/2021.
//

#ifndef INC_04_UNIONFIND_UNIONFINDTESTHELPER_H
#define INC_04_UNIONFIND_UNIONFINDTESTHELPER_H

#include <iostream>
#include <ctime>
#include <random>  // C++11, to replace srand(), rand()
#include "UnionFind.h"

using std::cout, std::endl;

namespace UnionFindTestHelper{

    void testUF1( int n ){

        srand( time(nullptr) );  // 设置随机种子
        UF1::UnionFind uf = UF1::UnionFind(n);  // 类的实例声明

        time_t startTime = clock();  // 开始计时

        // 并操作
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        // 查操作
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();  // 结束计时

        cout << "UF1, " << 2*n << " ops, " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" <<endl;
    }

    void testUF2( int n ){

        srand( time(nullptr) );
        UF2::UnionFind uf = UF2::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout << "UF2, " << 2*n << " ops, " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;
    }

    void testUF3( int n ){

        srand( time(NULL) );
        UF3::UnionFind uf = UF3::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }

        time_t endTime = clock();

        cout << "UF3, " << 2*n << " ops, " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;
    }

    void testUF4( int n ){

        srand( time(NULL) );
        UF4::UnionFind uf = UF4::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout << "UF4, " << 2*n << " ops, " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;
    }

    void testUF5( int n ){

        srand( time(NULL) );
        UF5::UnionFind uf = UF5::UnionFind(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout << "UF5, " << 2*n << " ops, " << double(endTime-startTime)/CLOCKS_PER_SEC << " s" << endl;
    }
}

#endif //INC_04_UNIONFIND_UNIONFINDTESTHELPER_H
