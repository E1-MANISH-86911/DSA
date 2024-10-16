#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *head = NULL;
node *create_node();
void display();
int count_nodes();
void insert_at_first(int data);
void insert_at_pos(int pos, int data);
void insert_at_last(int data);
void delete_at_first();
void delete_at_pos(int pos);
void delete_at_last();
void rev();
int main(){
    insert_at_first(5);
    insert_at_first(4);
    insert_at_first(3);
    insert_at_first(2);
    insert_at_first(1);
    insert_at_last(6);
    insert_at_pos(1,0);
    insert_at_pos(4,4);
    insert_at_pos(count_nodes(), 7);
    display();
    rev();
    display();
    return 0;
}
node *create_node(){
    node *newNode = (node*)malloc(sizeof(node)); 
    newNode->data = 0;
    newNode->next = NULL;
    return newNode;
}
void display(){
    if(head == NULL){
        printf("Linked list is empty.\n");
    }
    else{
        node *trav = head;
        printf("Head");
        do{
            printf("->%d", trav->data);
            trav = trav->next;
        }while(trav!=head);
        printf("\n");
    }
}
int count_nodes(){
    int count = 0;
    if(head == NULL){
        return count;
    }
    else{
        node *trav = head;
        do{
            count++;
            trav = trav->next;
        }while(trav != head);
        return count;
    }
}
void insert_at_first(int data){
        node *newNode = create_node();
        newNode->data = data;
        if(head == NULL){
            head = newNode;
            newNode->next = head;
        }
        else{
            node *trav = head;
            while(trav->next != head){
                trav = trav->next;
            }
            newNode->next = head;
            head = newNode;
            trav->next = head;
        }
}
void insert_at_pos(int pos, int data){
    node *newNode = create_node();
    newNode->data = data;
    if(head == NULL){
        if(pos==1){
            insert_at_first(data);
        }
        else{
            printf("Invalid position.\n");
        }
    }
    else if(pos==1){
        insert_at_first(data);
    }
    else if(pos == count_nodes()+1){
        insert_at_last(data);
    }
    else if(pos<1 || pos>count_nodes()+1){
        printf("Invalid Position.\n");
    }
    else{
        node *trav = head;
        for(int i=1; i<pos; i++){
            trav = trav->next;
        }
        newNode->next = trav->next;
        trav->next = newNode;
    }
}
void insert_at_last(int data){
    node *newNode = create_node();
    newNode->data = data;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
         node *trav = head;
        while(trav->next!=head){
            trav = trav->next;
            }
            trav->next=newNode;
            newNode->next=head;
    }
}
void delete_at_first(){
    if(head==NULL){
        printf("Linked list is empty.\n");
    }
    else if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        node *trav = head;
        while(trav->next != head){
            trav = trav->next;
        }
        node *temp = head;
        head = temp->next;
        trav->next = head;
        free(temp);
        temp=NULL;
    }
}
void delete_at_pos(int pos){
    if(pos==1){
        delete_at_first();
    }
    else if(pos==count_nodes()){
        delete_at_last();
    }
    else if(pos<1 || pos>count_nodes()){
        printf("Invalid position.\n");
    }
    else{
        node *trav = head;
        for(int i=1; i<pos; i++){
            trav = trav->next;
        }
        node *temp = trav->next;
        trav->next=temp->next;
        free(temp);
        temp=NULL;
    }
}
void delete_at_last(){
    if(head == NULL){
        printf("Linked list is empty.\n");
    }
    else if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        node *trav = head;
        while(trav->next->next!=head){
            trav = trav->next;
        }
        free(trav->next);
        trav->next = head;
    }
}
void rev(){
    node *prev, *cur, *next, *last;
    if (head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }
    last = head;
    prev = head;
    cur = head->next;
    head = head->next;
    while (head != last)
    {
        head = head->next;
        cur->next = prev;

        prev = cur;
        cur  = head;
    }

    cur->next = prev;
    head = prev;  
}