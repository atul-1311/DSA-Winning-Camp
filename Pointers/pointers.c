#include <stdio.h>

void sum(int arr[3][3], int r, int c){
    int sum=0;

    for(int i=0;i<r;i++){
        // int *p = &arr[i][0];
        for(int j=0;j<c;j++){
            sum+=*(*(arr+i)+j);
        }
        printf("%d ",sum);
        sum=0;
    }

    printf("\n");
    for(int i=0;i<c;i++){
        // int *p = &arr[0][i];
        for(int j=0;j<r;j++){
            sum+=*(*(arr+j)+i);

        }
        printf("%d ",sum);
        sum=0;
    }

    // printf("%d",sum);
}

void evenOdd(int arr[], int n){
    int even=0,odd=0;
    for(int i=0;i<n;i++){
        // int k = *(arr+i);
        if(*(arr+i)%2==0)
        even++;
        else
        odd++;
    }
    printf("%d %d",odd,even);
}

int main(){
    int arr[3][3] = {{1,2,7},{3,4,6},{9,5,8}};
    sum(arr,3,3);
}