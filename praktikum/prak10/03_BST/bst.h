//
// Created by dat tran on 19.04.21.
//

#ifndef INC_03_BST_BST_H
#define INC_03_BST_BST_H
namespace bst{
    struct Node{
        int data;
        int depth;
        Node * left;
        Node * right;
        Node(int d = -1, int dp = 0):data{d}, left{nullptr}, right{nullptr}, depth{dp}{}
    };
    void insert(Node* &root, int data);
    void printOut_rightLeft_Inorder(const Node* const root);
}



#endif //INC_03_BST_BST_H
