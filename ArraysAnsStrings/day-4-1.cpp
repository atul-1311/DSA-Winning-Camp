#include <bits/stdc++.h>
using namespace std;

void concat(string &s1, string s2){
    int i=0;
    while(s1[i]!='\0'){
        i++;
    }

    int j=0;
    while(s2[j]!='\0'){
        s1[i]=s2[j];
        i++;j++;
    }
    s1[i]='\0';
}

int main(){
    string str = "university";
    
    int length=0, i=0;
    while(str[i]!='\0'){
        length++;
        i++;
    }
    cout<<length<<endl;

    i=0;
    string str2;
    while(str[i]!='\0'){
        str2[i]=str[i];
        i++;
    }
    str2[i]='\0';

    int length2=0;i=0;
    while(str2[i]!='\0'){
        length2++;
        i++;
    }
    cout<<length2;

    string s1 = "Chandigarh";
    string s2 = "University";
    concat(s1,s2);
    cout<<s1;
}