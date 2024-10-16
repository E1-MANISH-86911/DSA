#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node* next;
}node;

node *head = NULL;
node *tail = NULL;

void add_first(int data);
node* create_node();
void add_last(int data);
void backward_Display();
void forward_display();
void add_at_specific_pos(int data, int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_specific_pos(int pos);
node *find_mid();
int main()
{
    add_first(40);
    add_first(35);
    add_first(20);
    add_last(95);
    add_last(50);
    add_first(60);
    add_at_specific_pos(80,4);
    forward_display();
    node *mid = find_mid();
    printf("Mid of the linked list: %d\n", mid->data);
    return 0;
}

node* create_node()
{
   node* new_node = (node*)malloc(sizeof(node));
   if(new_node == NULL)
   {
    printf("Malloc Failed !\n");
   }
   else
   {
    new_node->data = 0;
    new_node->next = NULL;
    new_node->prev = NULL;
   }
   return new_node;
}

void add_first(int data)
{
    // 1. create
    struct node* new_node = create_node();

    new_node->data = data;

    // attach
    //a. if list is empty
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        // create a forward link between newnode and 1st node
        new_node->next = head;

        // create a backward link between first node and new node
        head->prev = new_node;

        // update the head pointer
        head = new_node;
    }
}

void add_last(int data)
{
    node *new_node = create_node();

    new_node->data = data;
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

void forward_display()
{
    if(head == NULL)
    {
        printf("List is Empty !\n");
    }
    else
    {
        struct node* trav = head;

        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}

void backward_Display()
{
    if(head == NULL)
    {
        printf("List is Empty !\n");
    }
    else
    {
        struct node *trav = tail;

        printf("Tail");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->prev;
        }
    }
    printf("\n");
}

void add_at_specific_pos(int data, int pos)
{
    if(head == NULL)
    {
        if(pos==1)
            add_first(data);
        else
            printf("Invalid !\n");
    }
    else if(pos == 1)
        add_first(data);
    else if(pos == count_nodes()+1)
        add_last(data);
    else if(pos < 1 || pos > count_nodes() + 1)
        printf("Invalid !\n");
    else
    {
        struct node *new_node = create_node();
        new_node->data = data;

        node *trav = head;
        for(int i =1; i<pos-1; i++)
        {
            trav = trav->next;
        }
        new_node->prev = trav;
        new_node->next = trav->next;
        trav->next = new_node;
        new_node->next->prev = new_node;

        /*
                    OR
            new_node->prev = trav;
            new_node->next = trav->next;
            trav->next->prev = new_node;
            trav->next = new_node;
        */
    }
}

int count_nodes()
{
    int count = 0;
    if(head == NULL)
        printf("List is Empty !\n");
    else
    {
        struct node *trav = head;

        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

void delete_first()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;
        // or head = temp->next

        head->prev = NULL;

        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("Lis is Empty !\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = tail;
        tail = temp->prev;
        tail->next = NULL;

        free(temp);
        temp = NULL;
    }
}

void delete_at_specific_pos(int pos)
{
    if(head == NULL)
        printf("List is Empty !\n ");
    else if(pos == 1)
        delete_first();
    else if(pos == count_nodes())
        delete_last();
    else if(pos < 1 || pos > count_nodes())
        printf("Invalid !\n");
    else
    {
        node *trav = head;
        for(int i =1; i<pos; i++)
        {
            trav = trav->next;
        }
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;

        free(trav);
        trav = NULL;
    }
}
node *find_mid()
{
    node *slow = head;
    node *fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
        if(fast == NULL) // for even no. of nodes
        break;
        }while(fast->next != NULL); // for odd no. of nodes
        return slow;
}