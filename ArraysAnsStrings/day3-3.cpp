#include <bits/stdc++.h>
using namespace std;

void nextGreaterElement(int *arr, int n){
    stack<int> st;
    st.push(arr[n-1]);
    arr[n-1]=0;
    for(int i=n-2;i>=0;i--){
        int k=arr[i];
        while(!st.empty() && st.top()<arr[i]){
            st.pop();
        }
        if(st.empty())
        arr[i]=0;
        else
        arr[i]=st.top();

        st.push(k);
    }
}

int main(){
    int arr[8] = {2,4,6,1,8,3,9,5};

    nextGreaterElement(arr,8);

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}