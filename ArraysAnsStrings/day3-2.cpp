#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int mid, int r){

    int left = mid-l+1;
    int right = r-mid;
    vector<int> leftArray(left);
    vector<int> rightArray(right);

    for(int i=0;i<left;i++)
    leftArray[i]=arr[l+i];

    for(int j=0;j<right;j++)
    rightArray[j]=arr[mid+j+1];

    int k=l, i=0, j=0;
    while(i<left && j<right){
        if(leftArray[i]<=rightArray[j]){
            arr[k]=leftArray[i];
            i++;
        }else{
            arr[k]=rightArray[j];
            j++;
        }
        k++;
    }

    while(i<left){
        arr[k]=leftArray[i];
        i++;k++;
    }
    while(j<right){
        arr[k]=rightArray[j];
        j++;k++;
    }
}

void mergeSort(int *arr, int l, int r){

    if(l<r){
        int mid = (l+r)/2;

        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

int main(){
    int arr[8] = {2,4,6,1,8,3,9,5};

    mergeSort(arr,0,7);

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}