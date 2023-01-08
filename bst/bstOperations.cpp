#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct node{
    struct node* left;
    int data;
    struct node* right;
};

struct node* root = NULL;

// creating a new node
struct node* newNode(int data){
    struct node* node = new (struct node);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Inserting a new node
struct node* insertNode(struct node* root, int data){
    if(root==NULL)
    root = newNode(data);
    else{
        if((data<root->data) || (data==root->data))
        {
            root->left = insertNode(root->left, data);
        }else{
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

// Printing data in levelorder method
void printLevelOrder(struct node* root){
    if(root==NULL)
    return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* current = q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL)
        q.push(current->left);
        if(current->right!=NULL)
        q.push(current->right);
        q.pop();
    }
}

// Searching an element in BST
int searchBST(struct node* root, int element, int level){
    if(root->data==element)
    return level;
    else{
        if(element<root->data)
        searchBST(root->left, element, ++level);
        else
        searchBST(root->right, element, ++level);
    }
}

// Find maximum
int maxBST(struct node *root){
    if(root->right==NULL)
    return root->data;
    else
    maxBST(root->right);
}

// Find minimum
int minBST(struct node *root){
    if(root->left==NULL)
    return root->data;
    else
    minBST(root->left);
}

// PreOrder traversing
void preOrder(struct node *root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// inOrder traversing
void inOrder(struct node *root){
    if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// postOrder traversing
void postOrder(struct node *root){
    if(root==NULL)
    return;
    postOrder(root->right);
    postOrder(root->left);
    cout<<root->data<<" ";
}

int main()
{
    int lev,i,data;
    cout<<"Enter the number of levels to create : ";
    cin>>lev;
    cout<<"Enter the data : ";
    for(i=0; i<(pow(2,lev+1)-1); i++)
    {
        cin>>data;
        root = insertNode(root, data);                  // Inserting node
    }
    cout<<"\nEntered datas are : ";
    printLevelOrder(root);
    
    int element,level=0;
    cout<<endl<<endl<<"Enter the element to search : ";
    cin>>element;
    cout<<"The element is found at level "<<searchBST(root, element, level);
    
    cout<<endl<<endl<<"The maximum and minimum elements are : "<<maxBST(root)<<" & "<<minBST(root);
    
    cout<<endl<<endl<<"The preorder traversing : ";
    preOrder(root);
    cout<<endl<<endl<<"The inorder traversing : ";
    inOrder(root);
    cout<<endl<<endl<<"The postorder traversing : ";
    postOrder(root);
}





