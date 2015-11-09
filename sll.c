/*
Program: Single linked list
Description: A C implementation of Single linked list

Author: Kongkon Jyoti Dutta
Module: SLL
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

int find_menu(int option, int data);
int sll_find_menu();
int find_first(struct node *list_head, int data);
int find_last(struct node *list_head, int data);
int find_count(struct node *list_head, int data);

int sll_find_menu()
{
	printf("test\n");
	find_menu(1, 11);
	printf("done\n");
}

int menu()
{
int item = 0;
int choice = 0;

	printf("****Menu***\n");
	printf("What do you want to do:\n");
	printf("1. Insert Operation \n");
	printf("2. Delete Operation \n");
	printf("3. Count List Nodes Operation \n");
	printf("4. Display List Operation \n");
	printf("5. Find in List\n");
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
			//traverse_list(first);
			break;

		case 3: 
			sll_count_list(first);
			break;
		
		case 4:
		default:
			traverse_list(first);
			break;

		case 5:
			sll_find_menu();
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

	// Another special case of deleting null list
	if(!current)
		return first;

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
 	
	// Another special case when deleting the last node
	if (current->next == NULL)
	{
		free(current);
		prev->next = NULL;
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
int find_first(struct node *list_head, int data)
{
	printf("Find First\n");
}

/* Searches the list and finds the last matching node */
int find_last(struct node *list_head, int data)
{

}

/* Searches the list and finds the count of number of matching nodes */
int find_count(struct node *list_head, int data)
{

}

int find_menu(int option, int data)
{
	switch(option)
	{
		case 1: 
			printf("Find First instance\n");
			find_first(first, data);
			break;
		
		case 2: 
			printf("Find Last instance\n");
			find_last(first, data);
			break;

		default:
			find_count(first, data);
			break;
	}

return 0;
}

/* Count nodes in the list */
int count_list(struct node *list_head)
{
	struct node *temp;
	int count = 0;
	temp = first;
	
	while(temp)
	{
		count++;
		temp = temp->next;
	}
return count;
}

int sll_count_list(struct node *list_head)
{
	int count;
	count = count_list(list_head);
	printf("Total number of nodes = %d\n", count);
}
main()
{

	menu();

return 0;
}

/*
Results:
kongkon@Linkat-Luidia:~/sea> ./a.out


List =   70      60      50      40      30



List =   70      60      40      30

*/

