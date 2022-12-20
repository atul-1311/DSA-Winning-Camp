#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }

}

void selection(int *arr, int n){
    for(int i=0;i<n;i++){
        int minInd=i, min=arr[i];
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                minInd=j;
                min=arr[j];
            }
            swap(arr[minInd],arr[i]);
        }
    }
}

void insertion(int *arr, int n){
    
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                j--;
            }else{
                break;
            }
        }
    }
}

int main(){
    int arr[] = {2,4,6,1,8,3,9,5};

    // bubbleSort(arr,8);
    // selection(arr,8);
    insertion(arr,8);

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}