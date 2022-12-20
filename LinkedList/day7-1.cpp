#include <bits/stdc++.h>
using namespace std;

struct student{
    string name;
    string uid;
    int age;
    double cgpa;

    struct student *next=NULL;
};

void insert(struct student* &head, string name, string uid, int age, double cgpa){
    struct student * temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = new student;
    temp->next->name=name;
    temp->next->uid=uid;
    temp->next->age=age;
    temp->next->cgpa=cgpa;
}

void print(struct student *head){
    struct student *temp = head;
    while(temp!=NULL){
        cout<<temp->name<<" "<<temp->uid<<" "<<temp->age<<" "<<temp->cgpa<<endl;
    }
}

int main(){
    struct student *stud = new student;
    struct student *head = stud;
    int n;
    cout<<"Enter the number of students : ";
    cin>>n;

    for(int i=0;i<n;i++){
        string name, uid;
        int age; double cgpa;
        cin>>name>>uid>>age>>cgpa;
        insert(head,name,uid,age,cgpa);
    }

    print(head);
}