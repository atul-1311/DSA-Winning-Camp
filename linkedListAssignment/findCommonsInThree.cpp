#include <bits/stdc++.h>
#define max 1000000
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
/* A utility function to insert a node at the
beginning of a linked list */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
            (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
/* print the common element in between
given three linked list*/
void Common(struct Node* head1,
            struct Node* head2, struct Node* head3)
{
     
    // Creating empty hash table;
    unordered_map<int, int> hash;
     
    struct Node* p = head1;
    while (p != NULL) {
         
        // set frequency by 1
        hash[p->data] = 1;
        p = p->next;
    }
     
    struct Node* q = head2;
    while (q != NULL) {
         
        // if the element is already exist in the
        // linked list set its frequency 2
        if (hash.find(q->data) != hash.end())
            hash[q->data] = 2;
        q = q->next;
    }
     
    struct Node* r = head3;
    while (r != NULL) {
        if (hash.find(r->data) != hash.end() &&
            hash[r->data] == 2)
         
        // if the element frequency is 2 it means
        // its present in both the first and second
        // linked list set its frequency 3
        hash[r->data] = 3;
        r = r->next;
    }
 
     
    for (auto x : hash) {
         
        // if current frequency is 3 its means
        // element is common in all the given
        // linked list
        if (x.second == 3)
            cout << x.first << " ";
    }
}
 
// Driver code
int main()
{
 
    // first list
    struct Node* head1 = NULL;
    push(&head1, 20);
    push(&head1, 5);
    push(&head1, 15);
    push(&head1, 10);
 
    // second list
    struct Node* head2 = NULL;
    push(&head2, 10);
    push(&head2, 20);
    push(&head2, 15);
    push(&head2, 8);
         
    // third list
    struct Node* head3 = NULL;
    push(&head3, 10);
    push(&head3, 2);
    push(&head3, 15);
    push(&head3, 20);
 
    Common(head1, head2, head3);
     
    return 0;
}