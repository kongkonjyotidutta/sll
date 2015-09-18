/*
Single linked list
*/

#include <stdio.h>

struct node {
        int data;
        struct node * next;
};

struct node *first = NULL;

int menu();

struct node * insert_node(int data);
struct node * delete_node(int data);
int count_node(struct node *);
int traverse_list(struct node *);


int menu()
{
int item = 0;

return item;
}

/*
* This routine will insert a new node to the left hand side of a linked list. And make this new node as the first node after insertion.
*/
struct node * insert_node(int data)
{
        struct node * temp = NULL;

        temp = (struct node *)malloc(sizeof(struct node));
        if (!temp)
                printf("Not enough memory in the system\n");

        // insert data;
        temp->data = data;

        if(first == NULL)
        {
                first = temp;
                temp->next = NULL;
                //printf("data=%d\n", temp->data);
        }
        else
        {
                temp->next = first;
                first = temp;
        }

return first;
}
/*
delete_node(int data) deletes the first node from the singly linked list where the data matches, and returns the starting of the list.
*/
struct node * delete_node(int data)
{
struct node * current = first, *prev;
//search the list for the first occurance of "data". If no node with "data" found then the list remains the same.


        while(current && current->data!=data)
        {
                prev = current;
                current=current->next;
        }
        prev->next = current->next;
        free(current);

return first;
}
int traverse_list(struct node *list_head)
{
        struct node * current, *prev;

        if (!first)
                printf("Empty list\n");

        current = first;
        prev = current->next;
        printf("\n\nList = ");
#if 1
        while(current)
        {
                printf("\t %d", current->data);
                current = current->next;
        }
#endif
        printf("\n\n");
}

main()
{
insert_node(30);
insert_node(40);
insert_node(50);
insert_node(60);
insert_node(70);
traverse_list(first);

delete_node(50);
traverse_list(first);
return 0;
}

/*
Results:
kongkon@Linkat-Luidia:~/sea> ./a.out


List =   70      60      50      40      30



List =   70      60      40      30

*/

