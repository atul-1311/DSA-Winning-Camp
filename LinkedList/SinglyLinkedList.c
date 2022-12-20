#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* add_on_end(struct node *ptr, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    
    ptr->link = temp;
    return temp;
}

struct node* add_at_certain(struct node *head, int data, int m)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    
    struct node *ptr = head;
    int i;
    for(i=1;i<m-1;i++)
    {
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    ptr->link = temp;
    return temp;
}

struct node* delete_first(struct node *head)
{
    struct node *temp = malloc(sizeof(struct node));
    temp = head;
    head = head->link;
    free(temp);
    return head;
}

struct node* delete_last(struct node *ptr){
    struct node *temp = malloc(sizeof(struct node));
    temp = ptr;
    while(temp!=NULL)
    {
        temp = temp->link;
    }
    while(ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = NULL;
    free(temp);
    return ptr;
}

struct node* delete_certain(struct node *ptr, int b){
    struct node *temp = malloc(sizeof(struct node));
    temp = ptr;
    int i;
    for(i=1;i<b-1;i++)
    {
        ptr = ptr->link;
    }
    for(i=1;i<b;i++)
    {
        temp = temp->link;
    }
    
    ptr->link = temp->link;
    free(temp);
    return ptr;
}

struct node *delete_all(struct node *ptr){
    struct node *temp = malloc(sizeof(struct node));
    temp = ptr;
    while(ptr!=NULL)
    {
        ptr = ptr->link;
        free(temp);
        temp = ptr;
    }
    return ptr;
}

struct node *reverse(struct node *head){
    struct node *ptr = malloc(sizeof(struct node));
    struct node *temp = malloc(sizeof(struct node));
    ptr = head;
    temp = NULL;
    while(ptr!=NULL)
    {
        ptr = head->link;
        head->link = temp;
        temp = head;
        head = ptr;
    }
    return temp;
}

int no_of_node(struct node *ptr, int count){
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->link;
    }
    return count;
}

struct node *sort_ascending(struct node *head, int no_of_nodes){
    struct node *ptr1 = malloc(sizeof(struct node));
    struct node *ptr2 = malloc(sizeof(struct node));
    int temp, i;
    ptr1 = head;
    ptr2 = head->link;
    
    for(i=1; i<no_of_nodes; i++)
    {
        ptr1 = head;
        ptr2 = head->link;
        while(ptr2 != NULL)
        {
            if(ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
                ptr2 = ptr2->link;
                ptr1= ptr1->link;
            }else{
                ptr2 = ptr2->link;
                ptr1 = ptr1->link;
            }
        }
    }
    return head;
}

struct node* insert_node_sort(struct node *ptr, int insert_data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = insert_data;
    temp->link = NULL;
    if((temp->data < ptr->data) || (temp->data == ptr->data))
    {
        temp->link = ptr;
        return temp;
        
    }else{
        while(ptr!=NULL)
        {
            if(ptr->link!=NULL)
            {
                if(((temp->data > ptr->data) || (temp->data == ptr->data)) && 
                  ((temp->data < ptr->link->data) || (temp->data == ptr->link->data)))
                  {
                      temp->link = ptr->link;
                      ptr->link = temp;
                      break;
                  }
            }else if(ptr->link == NULL){
                ptr->link = temp;
                break;
            }
            ptr = ptr->link;
        }
        return ptr;
    }
}

int main()
{
    // creating nodes
    
    struct node *head = malloc(sizeof(struct node));
    head -> data=23;
    head -> link=NULL;
    struct node *ptr = head;
    int n,i,new;
    printf("Enter the number of nodes to be inserted : ");
    scanf("%d",&n);
    
    // ptr = add_on_end(ptr, 45);
    // ptr = add_on_end(ptr, 56);
    // ptr = add_on_end(ptr, 67);
    
    printf("Create node by giving data : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&new);
        ptr = add_on_end(ptr, new);
    }
    
    printf("The nodes are : ");
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    
    // adding node at certain position which we want
    
    int m;
    printf("\n\nEnter the position u want to add node : ");
    scanf("%d",&m);
    int data = 78;
    ptr = add_at_certain(head, data, m);
    ptr = head;
    printf("The datas are : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\nThe head node is %d\n\n",head->data);
    
    // deleting the first node
    
    head = delete_first(head);
    ptr = head;
    printf("The datas are : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\nThe head node is %d\n\n",head->data);
    
    // deleting the last node
    
    ptr = head;
    ptr = delete_last(ptr);
    ptr = head;
    printf("The datas are : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        if(ptr->link == NULL)
        printf("\nThe last node data is %d",ptr->data);
        ptr=ptr->link;
    }
    
    // deleting node on users demand
    
    int b;
    printf("\n\nThe index at which node is to be deleted : ");
    scanf("%d",&b);
    
    ptr = head;
    ptr = delete_certain(ptr, b);
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        if(ptr->link == NULL)
        printf("\nThe last node data is %d\n\n",ptr->data);
        ptr=ptr->link;
    }
    
    // Deleting whole linked list
    
    // ptr = head;
    // ptr = delete_all(ptr);
    // // free(ptr);
    // head = ptr;
    // if(head==NULL)
    // printf("\nThe linked list is empty");
    
    
    // Reversing the linked list
    
    head = reverse(head);
    ptr = head;
    printf("The reversed list is : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\nThe head node is %d\n\n",head->data);
    
    // Sorting the linked list
    
    ptr = head;
    int no_of_nodes,count=0;
    
    no_of_nodes = no_of_node(ptr, count);
    ptr = sort_ascending(head, no_of_nodes);
    
    printf("The sorted data is : \n");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\nThe head node is %d\n\n",head->data);
    
    // Insertion of node in sorted list
    
    ptr = head;
    int insert_data;
    printf("Enter data to be inserted : ");
    scanf("%d",&insert_data);
    ptr = insert_node_sort(ptr, insert_data);
    if(ptr->data == insert_data)
    head = ptr;
    
    ptr = head;
    printf("The sorted data is : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\nThe head node is %d\n\n",head->data);
}









