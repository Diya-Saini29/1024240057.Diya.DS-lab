#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
#include <cmath>
using namespace std;
/*1. Write program using functions for binary tree traversals: Pre-order, In-order and Post
order using recursive approach.
*/
class tree{
    public:
    int data;
    tree* left;
    tree* right;
    tree(int val,tree* left1=nullptr,tree* right1=nullptr){
        data=val;
        left=left1;
        right=right1;
    }
};
void preorder(tree* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void post(tree* root){
    if(root==NULL)return;
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}
void inorder(tree* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
/*2. Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)
(b) Maximum element of the BST
(c) Minimum element of the BST
(d) In-order successor of a given node the BST
(e) In-order predecessor of a given node the BST 
*/
int search(tree* root,int k){
    if(root==NULL){
        cout<<"not valid";
        return -1;
    }
    if(root->data==k){
        cout<<"FOUND ";
        return root->data;
    }
    else if(k>root->data){
        search(root->right,k);
    }
    else{
        search(root->left,k);
    }
}
int ceil_bst(tree* root,int val,int &c){
    if(root==NULL)return c;
    if(root->data>=val){
        c=root->data;
        ceil_bst(root->left,val,c);
    }
    else{
        ceil_bst(root->right,val,c);
    }
    return c;
}
int floor_bst(tree* root,int val,int &c){
    if(root==NULL)return c;
    if(root->data<=val){
        c=root->data;
        floor_bst(root->right,val,c);
    }
    else{
        floor_bst(root->left,val,c);
    }
    return c;
}
/*3. Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,
(c) Maximum depth of BST
(d) Minimum depth of */
tree* insert(tree* root, int k) {
    if (root == NULL) {
        return new tree(k);
    }
    tree* curr = root;
    while (true) {
        if (k < curr->data) {
            if (curr->left == NULL) {
                curr->left = new tree(k);
                break;
            } else {
                curr = curr->left;
            }
        } 
        else {
            if (curr->right == NULL) {
                curr->right = new tree(k);
                break;
            } else {
                curr = curr->right;
            }
        }
    }
    return root; 
}
void del_bst(tree* &root, int k) {
    if (root == NULL) {
        cout << "Empty tree.";
        return;
    }
    tree* prev = NULL;
    tree* curr = root;
    while (curr != NULL && curr->data != k) {
        prev = curr;
        if (k < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (curr == NULL) {
        cout << "Key not found.";
        return;
    }
    if (curr->left != NULL && curr->right != NULL) {
        tree* succParent = curr;
        tree* succ = curr->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        curr->data = succ->data;
        prev = succParent;
        curr = succ;
    }
    tree* child = (curr->left != NULL) ? curr->left : curr->right;
    if (prev == NULL) {
        root = child;
        delete curr;
        return;
    }
    if (prev->left == curr)
        prev->left = child;
    else
        prev->right = child;
    delete curr;
}
int max_depth(tree* root){
    if(root==NULL){
        return 0;
    }
    int l=max_depth(root->left);
    int r=max_depth(root->right);
    return 1+max(l,r);
}
int min_depth(tree* root) {
    if (root == NULL)
        return 0;
    int l = min_depth(root->left);
    int r = min_depth(root->right);
    if (l == 0)
        return 1 + r;
    else if (r == 0)
        return 1 + l;
    return 1 + min(l, r);
}
/* Write a program to determine whether a given binary tree is a BST or not.
*/
bool is_bst(tree* root, tree* &prev) {
    if (!root) return true;
    if (!is_bst(root->left, prev))
        return false;
    if (prev && root->data <= prev->data)
        return false;
    prev = root;
    return is_bst(root->right, prev);
}
bool check_bst(tree* root) {
    tree* prev = NULL;
    return is_bst(root, prev);
}
int main(){
    tree* root = new tree(50);
    root->left = new tree(30);
    root->right = new tree(70);
    root->left->left = new tree(20);
    root->left->right = new tree(40);
    root->right->left = new tree(60);
    root->right->right = new tree(80);
    preorder(root);
    cout<<endl;
    return 0;
}