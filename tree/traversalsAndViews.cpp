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

void preOrder(struct Node* root){
    if(root==NULL)
    return;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// void preOrderItr(struct Node* root){
//     if(root==NULL)
//     return;
    
//     vector<int> pol;
//     stack<Node*> st;
//     st.push(root);
//     while(!st.empty()){
//         root = st.top();
//         st.pop();
//         pol.push_back(root->data);
//         if(root->right!=NULL){
//             st.push(root->right);
//         }
//         if(root->left!=NULL){
//             st.push(root->left);
//         }
//     }
//     cout<<endl;
//     for(int i=0; i<pol.size(); i++)
//     cout<<pol[i]<<" ";
// }

void inOrder(struct Node* root){
    if(root==NULL)
    return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// void inOrderItr(struct Node* root){
//     vector<int> iol;
//     stack<Node*> st;
//     Node* node = root;
    
//     while(true){
//         if(node!=NULL){
//             st.push(node);
//             node=node->left;
//         }else{
//             if(st.empty())
//             break;
            
//             node = st.top();
//             st.pop();
//             iol.push_back(node->data);
//             node = node->right;
//         }
//     }
//     cout<<endl;
//     for(int i=0; i<iol.size(); i++)
//     cout<<iol[i]<<" ";
    
// }

void postOrder(struct Node* root){
    if(root==NULL)
    return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
} 

// void postOrderItr(struct Node* root){
//     vector<int> pstol;
//     stack<Node*> st1;
//     stack<Node*> st2;
//     Node* node = root;
//     st1.push(root);
    
//     while(!st1.empty()){
//         st2.push(st1.top());
//         st1.pop();
//         node = st2.top();
//         if(node->left!=NULL)
//         st1.push(node->left);
//         if(node->right!=NULL)
//         st1.push(node->right);
//     }
    
//     while(!st2.empty()){
//         pstol.push_back(st2.top()->data);
//         st2.pop();
//     }
//     cout<<endl;
//     for(int i=0; i<pstol.size(); i++)
//     cout<<pstol[i]<<" ";
// }

int height(struct Node* root){
    if(root==NULL) 
    return 0;
    
    int lp = height(root->left);
    int rp = height(root->right);
    
    return 1+max(lp,rp);
}

int diameter(struct Node* root){
    if(root==NULL) 
    return 0;
    
    int lp = height(root->left);
    int rp = height(root->right);
    
    return lp+rp;
}

//maximum path sum
int maxPathDown(struct Node* node, int &maxi){
    if(node==NULL)
    return 0;
    
    int left = max(0, maxPathDown(node->left, maxi));
    int right = max(0, maxPathDown(node->right, maxi));
    
    maxi = max(maxi, left+right+node->data);
    
    return node->data + max(left,right);
}

int maxPathSum(struct Node* root){
    int maxi = 0;
    maxPathDown(root, maxi);
    return maxi;
}

// Boundary of tree
bool isLeaf(struct Node* node){
    if((node->left==NULL) && (node->right==NULL))
    return true;
    else
    return false;
}

void addLeftBoundary(struct Node* root, vector<int> &res){
    struct Node* cur = root->left;
    while(cur){
        if(!isLeaf(cur))
        res.push_back(cur->data);
        
        if(cur->left)
        cur = cur->left;
        else
        cur = cur->right;
    }
}
void addLeafNodes(struct Node* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    
    if(root->left)
    addLeafNodes(root->left, res);
    if(root->right)
    addLeafNodes(root->right, res);
}
void addRightBoundary(struct Node* root, vector<int> &res){
    struct Node* cur = root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur))
        temp.push_back(cur->data);
        
        if(cur->right)
        cur = cur->right;
        else
        cur = cur->left;
    }
    for(int i=temp.size()-1; i>=0; i--){
        res.push_back(temp[i]);
    }
}

vector<int> antiBoundary(struct Node* root){
    vector<int> res;
    if(!root)
    return res;
    if(!isLeaf(root))
    res.push_back(root->data);
    
    addLeftBoundary(root, res);
    addLeafNodes(root, res);
    addRightBoundary(root, res);
    
    return res;
}

// Top view of tree
vector<int> topView(struct Node* root){
    vector<int> res;
    if(root==NULL)
    return res;
    
    map<int,int> mpp;
    queue<pair<Node* , int>> q;
    
    q.push({root,0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        if(mpp.find(line) == mpp.end())
        mpp[line]=node->data;
        
        if(node->left!=NULL)
        q.push({node->left, line-1});
        
        if(node->right!=NULL)
        q.push({node->right, line+1});
    }
    
    for(auto it : mpp){
        res.push_back(it.second);
    }
    
    return res;
}

// Bottom view of tree
vector<int> bottomView(struct Node* root){
    vector<int> res;
    if(root==NULL)
    return res;
    
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        auto it= q.front();
        q.pop();
        
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        
        if(node->left!=NULL)
        q.push({node->left, line-1});
        
        if(node->right!=NULL)
        q.push({node->right, line+1});
    }
    
    for(auto it : mpp){
        res.push_back(it.second);
    }
}

// // Right view of the tree
// vector<int> rightView(struct Node* root){
//     vector<int> res;
//     if(root==NULL)
//     return res;
    
//     map<int, int> mpp;
//     queue<pair<Node*, int>> q;
//     q.push({root,0});
    
//     while(!q.empty()){
//         auto it = q.front();
//         q.pop();
        
//         Node* node = it.first;
//         int line = it.second;
//         if(mpp.find(line) == mpp.end())
//         mpp[line]=node->data;
        
//         if(node->right!=NULL){
//             q.push({node->right, line+1});
//         }
//         if(node->left!=NULL){
//             q.push({node->left,line+1});
//         }
//     }
    
//     for(auto it : mpp){
//         res.push_back(it.second);
//     }
    
//     return res;
// }

void rightViewRec(struct Node* node, int level, vector<int> &res){
    if(node==NULL)
    return;
    
    if(res.size()==level)
    res.push_back(node->data);
    rightViewRec(node->right, level+1, res);
    rightViewRec(node->left, level+1, res);
}

vector<int> rightView(struct Node* root){
    vector<int> res;
    rightViewRec(root, 0, res);
    return res;
}

// // Left view of the tree
// vector<int> leftView(struct Node* root){
//     vector<int> res;
//     if(root==NULL)
//     return res;
    
//     map<int, int> mpp;
//     queue<pair<Node*, int>> q;
//     q.push({root,0});
    
//     while(!q.empty()){
//         auto it = q.front();
//         q.pop();
        
//         Node* node = it.first;
//         int line = it.second;
//         if(mpp.find(line) == mpp.end())
//         mpp[line]=node->data;
        
//         if(node->left!=NULL){
//             q.push({node->left,line+1});
//         }
//         if(node->right!=NULL){
//             q.push({node->right, line+1});
//         }
        
//     }
    
//     for(auto it : mpp){
//         res.push_back(it.second);
//     }
    
//     return res;
// }
void leftViewRec(struct Node* node, int level, vector<int> &res){
    if(node==NULL)
    return;
    
    if(res.size()==level)
    res.push_back(node->data);
    leftViewRec(node->left, level+1, res);
    leftViewRec(node->right, level+1, res);
}

vector<int> leftView(struct Node* root){
    vector<int> res;
    leftViewRec(root, 0, res);
    return res;
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
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->right->right = new Node(8);
    root->left->left->right = new Node(4);
    root->right->right->left = new Node(9);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);
    
    cout<<"The preOrder traversal is "<<endl;
    preOrder(root);
    // preOrderItr(root);
    
    cout<<endl<<endl<<"The inOrder traversal is "<<endl;
    inOrder(root);
    // inOrderItr(root);
    
    cout<<endl<<endl<<"The postOrder traversal is "<<endl;
    postOrder(root);
    // postOrderItr(root);
    
    cout<<endl<<endl<<"The height of tree is ";
    int hot = height(root);
    cout<<hot;
    
    cout<<endl<<endl<<"The diameter of tree is ";
    int dot = diameter(root);
    cout<<dot;
    
    cout<<endl<<endl<<"The Maximum Path Sum of tree is ";
    int mps = maxPathSum(root);
    cout<<mps;
    
    cout<<endl<<endl<<"The boundary of tree is ";
    vector<int> abt = antiBoundary(root);
    for(int i=0; i<abt.size(); i++){
        cout<<abt[i]<<" ";
    }
    
    cout<<endl<<endl<<"The top view of tree is ";
    vector<int> tvt = topView(root);
    for(int j=0; j<tvt.size(); j++){
        cout<<tvt[j]<<" ";
    }
    
    cout<<endl<<endl<<"The bottom view of tree is ";
    vector<int> bvt = bottomView(root);
    for(int k=0; k<bvt.size(); k++){
        cout<<bvt[k]<<" ";
    }
    
    cout<<endl<<endl<<"The right view of tree is ";
    vector<int> rvt = rightView(root);
    for(int l=0; l<rvt.size(); l++){
        cout<<rvt[l]<<" ";
    }
    
    cout<<endl<<endl<<"The left view of tree is ";
    vector<int> lvt = leftView(root);
    for(int m=0; m<lvt.size(); m++){
        cout<<lvt[m]<<" ";
    }
    
    int nodeToFind;
    cout<<endl<<endl<<"Enter the node data to find path : ";
    cin>>nodeToFind;
    vector<int> rton = rootToNode(root, nodeToFind);
    for(int t=0; t<rton.size(); t++){
        cout<<rton[t]<<" ";
    }
    
}







