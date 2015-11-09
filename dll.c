/* Double Linked List */
#include <stdio.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *first = NULL;

int menu();
struct node * _dll_insert_node();
struct node * dll_insert_node();
struct node * dll_delete_node();

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
                        dll_insert_node();
                        //traverse_list(first);
                        break;

                case 2:
                        //dll_delete_node();
                        //traverse_list(first);
                        break;

                case 3:
                        //dll_count_list(first);
                        break;

                case 4:
                default:
                        //traverse_list(first);
                        break;

                case 5:
                        //dll_find_menu();
                        break;

        }

        menu();

return item;
}

/*
* This routine will insert a new node to the left hand side of a doubly linked list. And make this new node as the first node after insertion.
*/
struct node * _dll_insert_node(int data);

struct node * dll_insert_node()
{
int data;

        printf("Data to be added:");
        scanf("%d", &data);

return (_dll_insert_node(data));
}

struct node * _dll_insert_node(int data)
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
                temp->left = first;
		temp->right = NULL;
                //printf("data=%d\n", temp->data);
        }
        else
        {
                temp->left = first;
                first = temp;
        }

return first;
}


main()
{

        menu();

return 0;
}
