//
// Created by Chang on 04/07/2021.
//

#ifndef INC_02_HEAP_HEAP_H
#define INC_02_HEAP_HEAP_H

#include <cassert>
#include <cmath>

template <typename Item>
class MaxHeap {

private:
    Item* data;
    int count;
    int capacity;

    void shiftUp(int k) {
        // 该结点的值大于其父结点，且该结点不为根结点
        while(k >= 2 && data[k/2] < data[k]) {
            std::swap(data[k/2],data[k]);
            k = k/2;
        }
    }

    void shiftDown(int k) {
        // 该结点有子结点
        while(2*k <= count) {
            // 该结点默认与其左孩子交换
            int j = 2*k;

            // 如果存在右孩子，且右孩子最大，则与右孩子交换
            if (j+1 <= count && data[j+1] > data[j] )
                j = j+1;

            // 该结点大于其子结点
            if (data[k] >= data[j])
                break;

            std::swap(data[k], data[j]);
            k = j;
        }
    }

public:
    // 构造函数
    MaxHeap(int n) {
        // 最大堆存储，数组索引从 1 开始
        data = new Item[capacity+1];
        count = 0;
        this->capacity = n;
    }

    MaxHeap(Item arr[], int n) {
        data = new Item[n+1];
        capacity = n;
        for (int i = 0; i <= n-1; i++)
            data[i+1] = arr[i];
        count = n;

        // 最大二叉树叶子结点均满足最大堆
        // 第一个非叶子结点的索引为 count/2
        for (int i = count/2; i >= 1; i--)
            shiftDown(i);
    }

    // 析构函数
    ~MaxHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    // 向堆中插入元素
    void insert(Item item) {
        assert(count+1 <= capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }

    // 从堆中取出元素（优先级最高元素）
    Item extractMax() {
        assert(count >= 1);

        Item ret = data[1];

        std::swap(data[1], data[count]);
        count--;

        shiftDown(1);
        return ret;
    }

public:
    // 以最大二叉树的形式打印最大堆
    void testPrint(){

        if( size() >= 100 ){
            std::cout << "Fancy print can only work for less than 100 int";
            return;
        }

        if( typeid(Item) != typeid(int) ){
            std::cout << "Fancy print can only work for int item";
            return;
        }

        std::cout << "The Heap size is: " << size() << std::endl;
        std::cout << "data in heap: ";
        for( int i = 1 ; i <= size() ; i ++ )
            std::cout << data[i] << " ";
        std::cout << std::endl;
        std::cout << std::endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            std::string line1 = std::string(max_level_number*3-1, ' ');

            int cur_level_number = std::min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            std::cout << line1 << std::endl;

            if( level == max_level - 1 )
                break;

            std::string line2 = std::string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            std::cout << line2 << std::endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
    void putNumberInLine( int num, std::string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( std::string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
};
#endif //INC_02_HEAP_HEAP_H
