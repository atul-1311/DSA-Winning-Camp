#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int size, int k){
    vector<int> temp(size);
    int j=k;
    for(int i=0;i<size;i++){
        if(j>=size)
        j=0;
        temp[j]=arr[i];
        j=j+1;
    }

    for(int i=0;i<size;i++){
        cout<<temp[i]<<" ";
    }
}

int firstOccurence(int arr[], int size, int num){
    int i=0,j=size-1;
    int ind=-1;
    while(i<j){
        int mid = (i+j)/2;
        if(arr[mid]==num){
            ind = mid;
            j=mid-1;
        }else if(arr[mid]>num){
            j=mid-1;
        }else{
            i=mid+1;
        }

    }

    return ind;
}

int lastOccurence(int arr[], int size, int num){
    int i=0,j=size-1;
    int ind=-1;
    while(i<j){
        int mid = (i+j)/2;
        if(arr[mid]==num){
            ind = mid;
            i=mid+1;
        }else if(arr[mid]>num){
            j=mid-1;
        }else{
            i=mid+1;
        }

    }

    return ind;
}

int findMissing(int arr[], int size, int s, int e){
    int sum = ((size+1)*(s+e))/2;
    int temp = 0;
    for(int i=0;i<size;i++){
        temp+=arr[i];
    }

    return sum-temp;
}

void reverse(int arr[], int size){
    int i=0, j=size-1;

    while(i<=j){
        swap(arr[i],arr[j]);
        i++;j--;
    }

    for(int k=0;k<size;k++){
        cout<<arr[k]<<" ";
    }
}

int main(){
    int arr[8] = {11,12,13,14,14,14,15,15};

    // rotate(arr,8,3);
    // int ans = findMissing(arr,8,11,19);
    // cout<<ans<<endl;
    // reverse(arr,8);
    int first = firstOccurence(arr,8,14);
    int last = lastOccurence(arr,8,14);
    cout<<last-first+1;
}