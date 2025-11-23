/* Q1: Program for binary tree traversals: preorder, inorder, postorder (recursive) */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data = v; left = right = NULL; }
};

void preorder(Node* root){
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    preorder(root);  cout << "\n";
    inorder(root);   cout << "\n";
    postorder(root); cout << "\n";
    return 0;
}