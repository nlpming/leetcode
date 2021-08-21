//
// Created by 陈志明 on 2020/5/22.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool myCmp(int a , int b){
    if(a%10 != b%10)
        return a%10 > b%10;
    return a > b;
}

int main() {

    priority_queue<int> heap;

    // 建立堆，默认是最大堆
    for(int i = 0 ; i < 10 ; i ++){
        int num = rand() % 100;
        heap.push(num);
    }

    while(!heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;

    // 生成最小堆
    priority_queue<int, vector<int>, greater<int>> heap2;

    for(int i = 0 ; i < 10 ; i ++){
        int num = rand() % 100;
        heap2.push(num);
    }

    while(!heap2.empty()){
        cout<<heap2.top()<<" ";
        heap2.pop();
    }
    cout<<endl;

    // 使用自定义Comparator的priority queue
    priority_queue<int, vector<int>, function<bool(int,int)>> heap3(myCmp);


    for(int i = 0; i < 10; i ++){
        int num = rand() % 100;
        heap3.push(num);
    }

    while(!heap3.empty()){
        cout << heap3.top() << " ";
        heap3.pop();
    }


    return 0;
}