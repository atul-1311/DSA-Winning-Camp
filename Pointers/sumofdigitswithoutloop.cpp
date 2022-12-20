#include <bits/stdc++.h>
using namespace std;

void solve(int num, int &ans){
    if(num==0)
    return;
    ans=ans+num%10;
    num=num/10;
    solve(num,ans);
}

int main(){
    int num = 857, ans=0;
    solve(num,ans);
    cout<<ans;
}