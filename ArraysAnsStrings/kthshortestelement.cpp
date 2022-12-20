#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n, int k){
    priority_queue<int> pq;

    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k)
        pq.pop();
    }

    cout<<pq.top();
}

int main(){
    int arr[] = {8,2,4,9,1,0,5,6};
    int k;
    cin>>k;
    solve(arr,8,k);
}