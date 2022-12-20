#include <bits/stdc++.h>
using namespace std;

void countSort(int *arr, int n, int k){
    int temp[k]={0};

    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }

    for(int i=1;i<k;i++){
        int m=temp[i];
        while(m--){
            cout<<i<<" ";
        }
    }

}

void countSortChar(char *arr, int n, int k){
    char temp[26]={0};

    for(int i=0;i<n;i++){
        temp[arr[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        int m = temp[i];
        while(m--){
            cout<<(char)('a'+i)<<" ";
        }
    }
}

int main(){
    int arr[8] = {2,1,3,2,4,3,1,4};
    char ar[8] = {'g','y','r','q','a','o','a','g'};
    countSort(arr,8,5);
    cout<<endl;
    countSortChar(ar,8,26);
}