#include <bits/stdc++.h>
 
 using namespace std;
 
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data = val;
        left=right=NULL;
    }
};

void binaryToChildren(struct Node* root){
    if(root==NULL)
    return;
    
    int child = 0;
    if(root->left!=NULL)
    child = child + root->left->data;
    if(root->right!=NULL)
    child = child + root->right->data;
    
    if(child >= root->data)
    root->data = child;
    else{
        if(root->left!=NULL)
        root->left->data = root->data;
        if(root->right!=NULL)
        root->right->data = root->data;
    }
    
    binaryToChildren(root->left);
    binaryToChildren(root->right);
    
    int upMove = 0;
    if(root->left!=NULL)
    upMove = upMove + root->left->data;
    if(root->right!=NULL)
    upMove = upMove + root->right->data;
    if(root->left || root->right)
    root->data = upMove;
}

void traverse(struct Node* node){
    if(node==NULL)
    return;
    
    cout<<node->data<<" ";
    traverse(node->left);
    traverse(node->right);
}

int main(){
    struct Node *root = new Node(6);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);
    
    binaryToChildren(root);
    
    cout<<"The children sum tree ";
    traverse(root);
}

