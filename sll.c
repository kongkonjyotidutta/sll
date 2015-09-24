/*
Program: Single linked list
Description: A C implementation of Single linked list

Author: Kongkon Jyoti Dutta
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
struct node * sll_insert_node();
struct node * sll_delete_node();


int menu()
{
int item = 0;
int choice = 0;

	printf("****Menu***\n");
	printf("What do you want to do:\n");
	printf("1. Insert Operation \n");
	printf("2. Delete Operation \n");
	printf("3. Display List Operation \n");
	printf("0. Quit\n");
	printf("***********\n");
	printf("Choice please: ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 0:
		case 'q':
		case 'Q':
			exit(0);
		case 1: 
			sll_insert_node();
			traverse_list(first);
			break;

		case 2: 
			sll_delete_node();
			traverse_list(first);
			break;

		case 3: 
		default:
			traverse_list(first);
			break;
	}

	menu();

return item;
}

/*
* This routine will insert a new node to the left hand side of a linked list. And make this new node as the first node after insertion.
*/
struct node * insert_node(int data);

struct node * sll_insert_node()
{
int data;

	printf("Data to be added:");
	scanf("%d", &data);

return (insert_node(data));
}

struct node * delete_node();
struct node * sll_delete_node()
{
int data;

	printf("Data to be deleted:");
	scanf("%d", &data);

return (delete_node(data));
}

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


	// Special treatment for the deletion of the first node
	//if ((current == first) && (current->data == data))
	if (current->data == data) //data found in the first node
	{
		first = NULL;
		free(first);
		return first;
	}	
#if 1
	// the normal case
        while(current && current->data!=data)
        {
                prev = current;
                current = current->next;
        }
	
	// Special treatment if no 'data' found
	if (current == NULL)
	{
		printf("No node with data=%d found\n", data);
		return first;
	}
 	
        prev->next = current->next;
        free(current);
#endif
return first;
}
/* traver the single linked list in the forward direction */
int traverse_list(struct node *list_head)
{
        struct node * current, *prev;

        if (!first)
	{
                printf("Empty list\n");
		return 0;
	}
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

/* Searches the list and finds the first matching node */
int search_first(struct node *list_head)
{

}

main()
{

insert_node(30);
traverse_list(first);
delete_node(50);
traverse_list(first);
delete_node(30);
traverse_list(first);
insert_node(40);
traverse_list(first);
#if 1
delete_node(40);
traverse_list(first);
insert_node(50);
traverse_list(first);
insert_node(60);
traverse_list(first);
insert_node(70);
traverse_list(first);

menu();

delete_node(50);
traverse_list(first);
#endif
return 0;
}

/*
Results:
kongkon@Linkat-Luidia:~/sea> ./a.out


List =   70      60      50      40      30



List =   70      60      40      30

*/

