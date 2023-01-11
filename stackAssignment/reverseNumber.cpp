#include <bits/stdc++.h>
using namespace std;
stack <int> stck;
void pushDigts(int num1){
   int rem;
   while (num1 > 0){
      rem=num1 % 10;
      stck.push(rem);
      num1 = num1 / 10;
   }
}
int revrseNum(){
   int revrs = 0;
   int i = 1;
   int temp;
   int topp;
   while (!stck.empty()){
      topp=stck.top();
      stck.pop();
      temp=topp*i;
      revrs = revrs + temp;
      i *= 10;
   }
   return revrs;
}
int main(){
   int Num = 43556;
   pushDigts(Num);
   cout<<"Reverse of number is: "<<revrseNum();
   return 0;
}