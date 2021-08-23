//
// Created by Chang on 22/07/2021.
//

#ifndef INC_04_UNIONFIND_UNIONFIND_H
#define INC_04_UNIONFIND_UNIONFIND_H

#include <cassert>

// Quick Find, 通过数组 id[i] 存储元素 i 所属组别
namespace UF1{
    class UnionFind{

    private:
        int count;
        int* id;  // 数组 id[i] 存储每个元素所属组别

    public:

        UnionFind(int n){
            count = n;
            id = new int[n];
            for(int i = 0; i < n; i++)
                id[i] = i;
        }

        ~UnionFind(){
            delete[] id;
        }

        // Quick find, 时间复杂度 O(1)
        int find(int p){
            assert(p >= 0 && p < count);
            return id[p];
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        // 时间复杂度 O(n)
        void unionElements(int p, int q){
            int pID = find(p);
            int qID = find(q);

            if(pID == qID)
                return;

            for(int i = 0; i < count; i++)
                if(id[i] == pID)
                    id[i] = qID;
        }
    };
}

// Quick Union, 并操作时, 修改 parent[i] 为指向元素的根
namespace UF2{

    class UnionFind{

    private:
        int count;
        int* parent;  // 数组 parent[i] 存储每个元素指向的父亲

    public:
        UnionFind(int count){
            this->count = count;
            parent = new int[count];
            for(int i = 0; i < count; i++ )
                parent[i] = i;
        }

        ~UnionFind(){
            delete[] parent;
        }

        int find(int p){
            assert(p >= 0 && p < count);
            while(p != parent[p])
                p = parent[p];
            return p;
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);

            if(pRoot == qRoot)
                return;

            parent[pRoot] = qRoot;
        }
    };
}

// 优化 UF2, 根据每个集合中元素多少,
// Union 操作时, 将元素少的集合的根结点 指向 元素多的集合的根结点
namespace UF3{

    class UnionFind{

    private:
        int count;
        int* parent;
        int* sz;  // sz[i] 表示以 i 为根的集合中，元素的个数

    public:
        UnionFind(int count){
            this->count = count;
            parent = new int[count];
            sz = new int[count];

            for(int i = 0; i < count; i++){
                parent[i] = i;
                sz[i] = 1;
            }
        }

        ~UnionFind(){
            delete[] parent;
            delete[] sz;
        }

        int find(int p){
            assert(p >= 0 && p < count);
            while(p != parent[p])
                p = parent[p];
            return p;
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);

            if(pRoot == qRoot)
                return;

            if(sz[pRoot] < sz[qRoot]){
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
            else{
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    };
}

// 优化 UF3, 根据每个集合中树的层数大小,
// Union 操作时, 将层数少的集合的根结点 指向 层数多的集合的根结点
namespace UF4{

    class UnionFind{

    private:
        int count;
        int* parent;
        int* rank;  // rank[i] 表示以 i 为根的集合，所表示的树的层数
  
    public:
        UnionFind(int count){
            this->count = count;
            parent = new int[count];
            rank = new int[count];

            for(int i = 0; i < count; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind(){
            delete[] parent;
            delete[] rank;
        }

        int size(){
            return count;
        }

        int find(int p){
            assert(p >= 0 && p < count);
            while(p != parent[p])
                p = parent[p];
            return p;
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);

            if(pRoot == qRoot)
                return;

            if(rank[pRoot] < rank[qRoot])
                parent[pRoot] = qRoot;
            else if(rank[qRoot] < rank[pRoot])
                parent[qRoot] = pRoot;
            else{
                parent[pRoot] = qRoot;
                rank[qRoot]++;
            }

        }
    };
}

// 优化 UF4, 在查找时进行路径压缩,
// find 操作时, 遍历结点时使树的层数更少
namespace UF5{

    class UnionFind{

    private:
        int count;
        int* parent;
        int* rank;

    public:
        UnionFind(int count){
            this->count = count;
            parent = new int[count];
            rank = new int[count];

            for(int i = 0; i < count; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind(){
            delete[] parent;
            delete[] rank;
        }

        int find(int p){
            assert(p >= 0 && p < count);

            // 路径压缩 1
            while(p != parent[p]){
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;

            // 路径压缩 2, 递归引发额外开销, 逻辑上更优, 实践略差
//            if(p != parent[p])
//                parent[p] = find(parent[p]);
//            return parent[p]
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);

            if( pRoot == qRoot )
                return;

            if(rank[pRoot] < rank[qRoot])
                parent[pRoot] = qRoot;
            else if(rank[qRoot] < rank[pRoot])
                parent[qRoot] = pRoot;
            else{
                parent[pRoot] = qRoot;
                rank[qRoot] ++;
            }
        }
    };
}

#endif //INC_04_UNIONFIND_UNIONFIND_H
