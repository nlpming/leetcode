//
// Created by 陈志明 on 2020/5/26.
//
#ifndef WORKSPACE_BINARY_SEARCH_TREE_H
#define WORKSPACE_BINARY_SEARCH_TREE_H

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

/*
 * 二叉搜索树实现；
 * */

template<typename Key, typename Value>
class BST{
private:
    //定义二叉树的一个结点；
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }

        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node *root;
    int count;

private:
    //以node为根的二叉搜索树中，插入结点（key, value）
    Node* insert(Node *node, Key key, Value value){
        if(node == NULL){
            count++;
            return new Node(key, value);
        }

        if(key == node->key)
            node->value = value;
        else if(key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);

        return node;
    }

    //以node为根的二叉搜索树中是否包含键值为key的结点；
    bool contain(Node* node, Key key){
        if(node == NULL)
            return false;

        if(key == node->key)
            return true;
        else if(key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }

    //以node为根的二叉搜索树中，查找key所对应的value
    Value* search(Node* node, Key key){
        if(node == NULL)
            return NULL;

        if(key == node->key)
            return &(node->value);
        else if(key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    //前序遍历
    void preOrder(Node* node){
        if(node != NULL){
            cout << node->key << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    //中序遍历
    void inOrder(Node* node){
        if(node != NULL){
            inOrder(node->left);
            cout << node->key << endl;
            inOrder(node->right);
        }
    }

    //后序遍历
    void postOrder(Node* node){
        if(node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << endl;
        }
    }

    void destory(Node *node){
        if(node != NULL){
            destory(node->left);
            destory(node->right);

            delete node;
            count--;
        }
    }

    Node* minimum(Node* node){
        if(node->left == NULL)
            return node;
        return minimum(node->left);
    }

    Node* maximum(Node* node){
        if(node->right == NULL)
            return node;
        return maximum(node->right);
    }

    Node* removeMin(Node* node){
        if(node->left == NULL){
            Node* rightNode = node->right;
            delete node;
            count--;

            return rightNode;
        }

        node->left = removeMin(node->left);
        return node;
    }

    Node* removeMax(Node* node){
        if(node->right == NULL){
            Node* leftNode = node->left;
            delete node;
            count--;

            return leftNode;
        }

        node->right = removeMax(node->left);
        return node;
    }

    Node* remove(Node *node, Key key){
        if(node == NULL)
            return NULL;

        if(key < node->key){
            node->left = remove(node->left, key);
            return node;
        }else if(key > node->key){
            node->right = remove(node->right, key);
            return node;
        }else{
            //key == node->key
            if(node->left == NULL){ //（1）左孩子为空；
                Node *rightNode = node->right;
                delete node;
                count--;

                return rightNode;
            }

            if(node->right == NULL){ //（2）右孩子为空；
                Node *leftNode = node->left;
                delete node;
                count--;

                return leftNode;
            }

            //（3）左、右孩子都不为空的情况；
            Node *successor = new Node(minimum(node->right));
            count++;

            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            count--;

            return successor;
        }
    }

public:
    BST(){
        this->root = NULL;
        count = 0;
    }

    ~BST(){
        // TODO: 析构函数
        destory(root);
    }

    //返回树的大小；
    int size(){
        return count;
    }

    //判断树是否为空；
    bool isEmpty(){
        return count == 0;
    }

    //插入一个新的结点；
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    //是否包含key
    bool contain(Key key){
        return contain(root, key);
    }

    //查找元素
    Value* search(Key key){
        return search(root, key);
    }

    //前序遍历
    void preOrder(){
        preOrder(root);
    }

    //中序遍历
    void inOrder(){
        inOrder(root);
    }

    //后序遍历
    void postOrder(){
        postOrder(root);
    }

    //层序遍历
    void levelOrder(){
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node *node = q.front();
            q.pop();

            cout << node->key << endl;

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }

    //最小值
    Key minimum(){
        assert(count != 0);
        Node *minNode = minimum(root);
        return minNode->key;
    }

    //最大值
    Key maximum(){
        assert(count != 0);
        Node *maxNode = maximum(root);
        return maxNode->key;
    }

    //删除最小值
    void removeMin(){
        if(root) root = removeMin(root);
    }

    //删除最大值
    void removeMax(){
        if(root) root = removeMax(root);
    }

    //删除某一个元素
    void remove(Key key){
        root = remove(root, key);
    }
};

#endif //WORKSPACE_BINARY_SEARCH_TREE_H
