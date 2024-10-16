#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *head = NULL;
node *create_node();
void insert_at_first(int data);
void insert_at_pos(int data, int pos);
void insert_at_last(int data);
void delete_at_first();
void delete_at_pos(int pos);
void delete_at_last();
void display();
int count_nodes();
node *linear_search(int key);
int main(){
    insert_at_first(5);
    insert_at_first(1);
    insert_at_first(4);
    insert_at_first(2);
    insert_at_first(3);
    insert_at_first(0);
    node *temp = linear_search(4);
    if(temp!=NULL){
        printf("Key found!\n");
    }
    else{
        printf("Key not found.\n");
    }
    return 0;
}
node *create_node(){
    node *ptr = (node*) malloc(sizeof(node));
    ptr->data = 0;
    ptr->next = NULL;
    return ptr;
}
void insert_at_first(int data){
    node *ptr = create_node();
    ptr->data = data;
    if(head == NULL){
        head = ptr;
    }
    else{
        ptr->next = head;
        head = ptr;
    }
}
void insert_at_pos(int data, int pos){
    if(head == NULL){
        if(pos == 1){
            insert_at_first(data);
        }
        else{
            printf("Invalid postion.\n");
        }
    }
    else if(pos == 1){
        insert_at_first(data);
    }
    else if(pos == count_nodes()+1){
        insert_at_last(data);
    }
    else if(pos<1 || pos>count_nodes()+1){
        printf("Invalid postion.\n");
    }
    else{
        node *trav = head;
        node *newNode = create_node();
        newNode->data = data;
        for(int i=1; i<pos-1; i++){
            trav = trav->next;
        }
        newNode->next = trav->next;
        trav->next = newNode;
    }
}
void insert_at_last(int data){
    node *trav = head;
    node *newNode = create_node();
    newNode->data = data;
    if(head == NULL){
        head = newNode;
    }
    else{
         while(trav->next != NULL){
            trav = trav->next;
            }
            trav->next = newNode;
        }
}
void delete_at_first(){
    if(head == NULL){
        printf("Linked list is empty.\n");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
}
void delete_at_pos(int pos){
    if(head == NULL){
        printf("Linked list is empty.\n");
    }
    else if(pos<1 || pos>count_nodes()){
        printf("Invalid position.\n");
    }
    else if(pos == 1){
        delete_at_first();
    }
    else if(pos == count_nodes()){
        delete_at_last();
    }
    else{
        node *trav = head;
        for(int i=1; i<pos-1; i++){
            trav = trav->next;
        }
        node *temp = trav->next;
        trav->next = temp->next;
        free(temp);
        temp=NULL;
    }
}
void delete_at_last(){
    if(head == NULL){
        printf("Linked list is empty.\n");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        node *trav = head;
        while(trav->next->next != NULL){
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
}
void display(){
    node *trav = head;
    if(trav == NULL){
        printf("Linked list is empty.\n");
    }
    else{
        printf("Head");
        while(trav != NULL){
            printf("->%d", trav->data);
            trav = trav->next;
        }
        printf("\n");
    }
}
int count_nodes(){
    int count = 0;
    if(head == NULL){
        printf("Linked list is empty.\n");
    }
    else{
        node *trav = head;
        while(trav != NULL){
            count++;
            trav = trav->next;
        }
    }
    return count;
}
node *linear_search(int key){
    node *trav = head;
    while(trav!=NULL){
        if(trav->data == key){
            return trav;
        }
        trav = trav->next;
    }
        return NULL;
}