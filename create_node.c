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
void addNodeAtLast( void );
void addNodeAtFirst( void );
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
	addNodeAtFirst( ); 
	//printf("My roll no is %d\n", start->roll);
	
	addNodeAtLast();
	//start = start->next;
	//printf("My roll number is %d\n", start->roll);
	
	addNodeAtFirst( );	
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
	return pointer;
}

void addNodeAtLast( void ) {
	struct student *temp=NULL;

	if( NULL == start )
	{
		printf("The list is empty\n");
		return;
	}

	temp = start;

	while( temp->next != NULL )
	{
		temp = temp->next;
	}
	
	temp->next = create_node(20);
	 temp->next->next = NULL; //remove if not work me change on 22/01/20
	 
}

void addNodeAtFirst( void ) {

	struct student *temp=NULL;

	if( start == NULL )
	{
		printf("The list is empty\n");
		start = create_node(30);
		return;
	} 
	
	temp = start;
	start = create_node(40);
	start->next = temp; //may be temp->next
	
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
	temp = start->next;
	free(start);
	start = temp;
}

void delNodeAtLast() {
	struct student *temp = NULL;
	temp = start;
	if (start == NULL ) {
		printf("List is empty!!");
		return;
	}

	while (temp->next != NULL) {  
		temp = temp->next;
	}
	free(temp);
	temp = NULL;

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
