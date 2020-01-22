#include <stdio.h>
#include <stdlib.h>
/**
 * program for create node in linklist
 */

/***********************************************************************************************//**
structur for store the data of students
***************************************************************************************************/
struct student {
	//char name[10];
	int roll;
	struct student *next;
};

struct student *start=NULL;

/***********************************************************************************************//**
function for create node
@param[in] name[] which is pass name of node which will be created
***************************************************************************************************/
struct student *create_node(int r);
void addNodeAtLast( int );
void addNodeAtFirst( int );
void addNodeBetween( int );
int transerv();
void delNodeAtFirst();
void delNodeAtLast();
void delNodeBetween( int );
/***************************************************************************************************/

int main(int argc, char *argv[])
{
	int add;
	//start = create_node(10);
	addNodeAtFirst(10); 
	//printf("My roll no is %d\n", start->roll);
	
	addNodeAtLast(45);
	//start = start->next;
	//printf("My roll number is %d\n", start->roll);
	
	addNodeAtFirst( 25);	
	//printf("My roll number is %d\n", start->roll);

	//add = transerv();
	//printf("Sum is %d\n", add);

	//addNodeAtLast();
	//start = start->next;
	//printf("My roll number is %d\n", start->roll);

	addNodeBetween(40);
	//printf("My roll number is %d\n", start->roll);
	
	//delNodeAtFirst();
	//delNodeAtLast();
	//delNodeBetween(20);
	add = transerv();   //TO print sum of all rolls no in linklist
	printf("new sum is %d\n", add);
	return 0;
}

/**************************************************************************************************/
/**************************************************************************************************/
struct student	*create_node(int r) {
	struct student *pointer;

	pointer = (struct student*)malloc(sizeof(struct student));
	if( NULL == pointer )
	{
		printf("Error! Unable to allocate memory\n");
		exit(1);
	}

	pointer->roll = r;
	pointer->next = NULL;

	printf("Node created successfully\n");

	return pointer;
}

void addNodeAtLast( int r ) {
	struct student *temp=NULL,  *temp1=NULL;

	if( NULL == start )
	{
		printf("The list is empty\nCreate first node here itself\n");
		temp = create_node( r);
                start = temp;
                printf("The roll number is %d\n", start->roll);
		return;
	}
	// This condition occurs when you have only single node in the list
	if( start->next == NULL)
	{
		temp = create_node( r );
		start->next = temp;
		printf("The node is added at last\n");
		return;
	}

	temp = start;

	while( temp->next != NULL )
	{
		temp = temp->next;
	}
	
	temp1 = create_node(r);
        temp->next = temp1;
        printf("The node is added in the last\n");
}

void addNodeAtFirst( int r ) {

	struct student *temp=NULL;

	if( start == NULL )
	{
		printf("The list is empty\n");
		temp = create_node(r);
		start = temp;
		return;
	} 
	
	temp = create_node(r);
	temp->next = start;
	start = temp;
	printf("The node is added at first in the list\n");
}

void addNodeBetween( int r ) {
	struct student *temp = NULL;
	struct student *temp1 = NULL;
	temp = start;
	while ( temp != NULL ) {
		if (temp->roll == r) {
			
			temp1 = temp->next;
			temp->next = create_node(50);
			temp = temp->next;
			temp->next = temp1;
			printf("between roll is %d", temp->roll);
			return;
		}
		printf("\nroll no are %d", temp->roll);
		temp = temp->next;
	}
		printf("\nNo value found\n");
}

int transerv() {
	struct student *temp = start;
	int sum = 0;
	while (temp != NULL ) {
		sum = sum+temp->roll;
		temp = temp->next;
	}
	return sum;
}

void delNodeAtFirst() {
	struct student *temp = NULL;
	temp = start;
	if (start == NULL ) {
		printf("NO First node found");
		return;
	}
	temp = start;
	start = temp->next;
	free(temp);
	temp = NULL;
	printf("The very first node is deleted from the list\n");
}

void delNodeAtLast() {
	 struct student *temp=NULL, *temp1=NULL;

	// This condition occurs when you do not have any node in the list
        if( start == NULL )
        {
                printf("The list is empty @delNodeAtLast\n");
                return;
        }

	// This condition occurs when you have only single node in the list
        if( start->next == NULL)
        {
                free(start);
                start = NULL;
                printf("The node is deleted\n");
                return;
        }

	temp = start;
        temp1 = start;

        // Traverse to the last node of the list
        while(temp->next != NULL) {
            temp1 = temp;
            temp = temp->next;
        }

        // Disconnects the link of second last node with last node 
        temp1->next = NULL;

        // Delete the last node
        free(temp);
	printf("The last node is deleted\n");
}

void delNodeBetween( int r ) {
	struct student *temp = NULL;
	struct student *temp1 = NULL;
	temp = start;

	while ( temp != NULL ) {
		if (temp->roll == r ) {
			temp1 = temp->next;
			free(temp);
			start = temp1;
			return;
		}else if (temp->next->roll == r) {
			temp = temp->next;
			temp1 = temp->next;
			//temp1 = temp1->next;
			free(temp);
			if (temp1 == NULL ) {
				temp = NULL;
				return;
			}
			temp = temp1;
			return;
		}

		temp = temp->next;
		//printf("\nnot return");
	}
	printf("\nNo value found");

}
