//
// Created by 陈志明 on 2020/5/26.
//

/**
 * C++ 语言: 二叉搜索树
 */

#include <iostream>
#include <vector>
#include "binary_search_tree.h"

using namespace std;

int main(){

    vector<int> nums = {28,16,13,22,30,29,42};

    //创建二叉搜索树；
    BST<int, int> bst;
    for(int i = 0; i < nums.size(); i++){
        bst.insert(nums[i], nums[i]);
    }

    //先序遍历二叉搜索树；
    bst.preOrder();

    //最大，最小值；
    cout << "max value:" << bst.maximum() << endl;
    cout << "min value:" << bst.minimum() << endl;
    cout << "contain value:" << bst.contain(12) << endl;
    cout << "search value:" << *bst.search(29) << endl;

    //删除元素；
    bst.remove(30);
    bst.preOrder();

    return 0;
}