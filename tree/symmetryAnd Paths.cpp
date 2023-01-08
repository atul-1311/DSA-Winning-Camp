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

// Check for symmetry

void leftSymmetry(struct Node* node, vector<int> &res1){
    if(node==NULL)
    return;
    
    res1.push_back(node->data);
    leftSymmetry(node->left, res1);
    leftSymmetry(node->right, res1);
}
void rightSymmetry(struct Node* node, vector<int> &res2){
    if(node==NULL)
    return;
    
    res2.push_back(node->data);
    rightSymmetry(node->right, res2);
    rightSymmetry(node->left, res2);
}
bool isSymmetry(struct Node* root){
    vector<int> res1;
    vector<int> res2;
    if(root==NULL)
    return true;
    
    leftSymmetry(root->left, res1);
    rightSymmetry(root->right, res2);
    
    if(res1.size()!=res2.size())
    return false;
    
    for(int i=0;i<res1.size();i++){
        if(res1[i]!=res2[i]){
            return false;
            break;
        }
    }
    
    return true;
}

// Root to node path

bool findPath(struct Node* node, vector<int> &ans, int val){
    if(node==NULL)
    return false;
    
    ans.push_back(node->data);
    if(node->data==val)
    return true;
    
    if(findPath(node->left, ans, val)||(findPath(node->right, ans, val)))
    return true;
    
    ans.pop_back();
    return false;
}

vector<int> rootToNode(struct Node* root, int val){
    vector<int> ans;
    if(root==NULL)
    return ans;
    
    findPath(root, ans, val);
    return ans;
}


int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    root->left->left->left = new Node(5);
    root->left->left->right = new Node(6);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(5);
    
    cout<<"Symmetry of the tree : ";
    int symmetry = isSymmetry(root);
    cout<<symmetry;
}



