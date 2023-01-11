#include <bits/stdc++.h>
using namespace std;
 
// Structure of a linked list node
struct Node {
    int data;
    struct Node* next;
};
 
// Function to common nodes which have
// same value node(s) both list
int countCommonNodes(struct Node* head1, struct Node* head2)
{
    // list A
    struct Node* current1 = head1;
 
    // list B
    struct Node* current2 = head2;
 
    // set count = 0
    int count = 0;
 
    // traverse list A till the end of list
    while (current1 != NULL) {
 
        // traverse list B till the end of list
        while (current2 != NULL) {
 
            // if data is match then count increase
            if (current1->data == current2->data)
                count++;
 
            // increase current pointer for next node
            current2 = current2->next;
        }
 
        // increase current pointer of list A
        current1 = current1->next;
 
        // initialize list B starting point
        current2 = head2;
    }
 
    // return count
    return count;
}
 
/* Utility function to insert a node at the beginning */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
 
/* Utility function to print a linked list */
void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 
/* Driver program to test above functions */
int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
 
    /* Create following linked list
    List A = 3 -> 4 -> 12 -> 10 -> 17
*/
 
    push(&head1, 17);
    push(&head1, 10);
    push(&head1, 12);
    push(&head1, 4);
    push(&head1, 3);
 
    // List B = 10 -> 4 -> 8 -> 575 -> 34 -> 12
    push(&head2, 12);
    push(&head2, 34);
    push(&head2, 575);
    push(&head2, 8);
    push(&head2, 4);
    push(&head2, 10);
 
    // print list A
    cout << "Given Linked List A: \n";
    printList(head1);
 
    // print list B
    cout << "Given Linked List B: \n";
    printList(head2);
 
    // call function for count common node
    int count = countCommonNodes(head1, head2);
 
    // print number of common node in both list
    cout << "Number of common node in both list is = " << count;
    return 0;
}