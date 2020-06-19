//
// Created by 陈志明 on 2020/5/9.
//

#ifndef WORKSPACE_PRINT_H
#define WORKSPACE_PRINT_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

template <typename T>
void printVector(vector<T> nums){
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

template <typename T1, typename T2>
void printMap(map<T1, T2> nums){
    for(typename map<T1, T2>::iterator it=nums.begin(); it!=nums.end(); ++it){
        cout<<it->first<<" => "<<it->second<<endl;
    }
}

template <typename T1, typename T2>
void printUnorderedMap(unordered_map<T1, T2> nums){
    for(typename unordered_map<T1, T2>::iterator it=nums.begin(); it!=nums.end(); ++it){
        cout<<it->first<<" => "<<it->second<<endl;
    }
}

template <typename T>
void printSet(set<T> nums){
    for(typename set<T>::iterator it=nums.begin(); it != nums.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template <typename T>
void printUnorderedSet(unordered_set<T> nums){
    for(typename unordered_set<T>::iterator it=nums.begin(); it != nums.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template <typename T>
void printStack(stack<T> stack_nums){
    while(!stack_nums.empty()){
        cout<<stack_nums.top()<<" ";
        stack_nums.pop();
    }
    cout<<endl;
}

template <typename T>
void printQueue(queue<T> queue_nums){
    while(!queue_nums.empty()){
        cout<<queue_nums.front()<<" ";
        queue_nums.pop();
    }
    cout<<endl;
}

#endif //WORKSPACE_PRINT_H




