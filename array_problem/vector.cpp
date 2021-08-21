//
// Created by 陈志明 on 2021/8/21.
//

/*
 * 自定义vector类
 * */

#include <iostream>
using namespace std;

template <typename T>
class MyVector{
private:
    int size; //数据中当前元素数量
    int capacity; //最大容量
    T* data;

    // 在动态数组满的时候，或者数据量缩小的时候调整数组大小：O(n)
    void resize(int newCapacity){
        T *newData = new T[newCapacity];
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }

        data = newData;
        capacity = newCapacity;
    }

public:
    MyVector(){
        data = new T[10];
        capacity = 10;
        size = 0;
    }

    ~MyVector(){
        delete[] data;
    }

    // 平均时间复杂度：O(1)
    void push_back(T num){
        if(size == capacity){ //均摊时间复杂度，只会在数组满的时候才会触发resize操作；
            resize(2*capacity);
        }

        data[size++] = num;
    }

    // 平均时间复杂度：O(1)
    int pop_back(){
        assert(size > 0);

        T ret = data[size-1];
        size--;

        if(size == capacity/4){ //避免复杂度震荡；
            resize(capacity/2);
        }

        return ret;
    }

    void printElement(){
        for(int i = 0; i < size; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    MyVector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(3);
    myVector.push_back(2);

    myVector.printElement();
    myVector.pop_back();
    myVector.printElement();

    return 0;
}