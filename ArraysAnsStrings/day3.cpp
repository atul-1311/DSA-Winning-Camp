#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int n, vector<vector<int>> &ans, vector<int> res, int index, int sum, int target){
    if(index>=n){
        if(sum==target){
            ans.push_back(res);
        }
        // res.pop_back();
        return;
    }

    // exclude
    solve(arr,n,ans,res,index+1,sum,target);

    // include
    res.push_back(arr[index]);
    solve(arr,n,ans,res,index+1,sum+arr[index],target);
}

void solve(vector<int> arr, int n, vector<vector<int>> &ans, vector<int> res, int index, int sum, int target, vector<vector<int>> &dp){
    if(index>=n){
        if(sum==target){

        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<vector<int>> ans;
    vector<int> res;
    // solve(arr,n,ans,res,0,0,target);
    vector<vector<int>> dp(n, vector<int> (target, -1));
    // solvemem(arr,n,ans,res,0,0,target,dp);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}