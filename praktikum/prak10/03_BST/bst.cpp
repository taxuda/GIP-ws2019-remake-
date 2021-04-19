//
// Created by dat tran on 19.04.21.
//
#include <iostream>
#include "bst.h"
void bst::insert(Node* &root, int data) {
    if(root == nullptr){
        root = new Node(data, 1);
    }else{
        // search for leaf to add new node
        Node* tmp = root;
        int depth_count = 1;
        while(true){
            if(data < tmp->data && tmp->left != nullptr){
                tmp = tmp->left;
                depth_count ++;
            }else if(data > tmp->data && tmp->right != nullptr){
                tmp = tmp->right;
                depth_count++;
            }else if(data < tmp->data && tmp->left == nullptr){
                depth_count++;
                tmp->left = new Node(data, depth_count);
                break; // end insert
            }else if(data > tmp->data && tmp->right == nullptr){
                depth_count++;
                tmp->right = new Node(data, depth_count);
                break; // end insert
            }else{
                break;
            }
        }
    }
}

void bst::printOut_rightLeft_Inorder(const Node* const root) {
    if(root == nullptr){
        return;
    }
    printOut_rightLeft_Inorder(root->right);
    for(int i = 0; i < root->depth - 1; i++)
        std::cout << "++";
    std::cout << root->data << std::endl;
    printOut_rightLeft_Inorder(root->left);
}