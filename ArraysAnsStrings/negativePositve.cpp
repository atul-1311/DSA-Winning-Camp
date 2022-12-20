#include <bits/stdc++.h>
using namespace std;

// void solve(int arr[], int n){
//     int i=-1;
//     for(int j=0;j<n;j++){
//         if(arr[j]<0){
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }

//     for(int k=0;k<n;k++){
//         cout<<arr[k]<<" ";
//     }
// }

void separate(int arr[],int n){
    int i=0,j=n-1;
    while(i<=j){
        if(arr[i]<0 && arr[j]<0){
            i++;
        }
        else if(arr[i]>=0 && arr[j]<0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        else if(arr[i]>=0 && arr[j]>=0){
            j--;
        }
        else{
            i++;
            j--;
        }
    }
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}
int main(){
    int arr[] = {-4,3,7,-8,0,1,-3,5,-34};
    int n = sizeof(arr)/sizeof(arr[0]);
    // solve(arr,n);
    separate(arr,n);
}