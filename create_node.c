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
#if 0
int main() {
	int ro,i=0,j;
	struct student *ptr[100];

	for (i=0; i<=2; i++) {
		printf("\nEnter the %d roll no ", i);
		scanf("%d", &ro);
		ptr[i] = create_node(ro);
		if (i != 0) {
			int k=i;
			ptr[k--]->next = ptr[k];
		}
	}

	for (j=0; j<i; j++) {
		printf("\nroll no of %d student is %d", j, ptr[j]->roll);
		printf("\nAddress of %d node is %p", j, ptr[j]->next);
	}
}
#endif

int main(int argc, char *argv[])
{
	int add;
	//start = create_node(10);
	addNodeAtFirst( ); 
	printf("My roll no is %d\n", start->roll);
	
	addNodeAtLast();
	start = start->next;
	printf("My roll number is %d\n", start->roll);
	
	addNodeAtFirst( );	
	printf("My roll number is %d\n", start->roll);

	add = transerv();
	printf("Sum is %d\n", add);

	addNodeAtLast();
	start = start->next;
	printf("My roll number is %d\n", start->roll);

	addNodeBetween(40);
	//printf("My roll number is %d\n", start->roll);
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
	start->next = temp->next;
	
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

