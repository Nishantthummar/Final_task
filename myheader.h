struct student {
	//char name[10];
	int roll;
	struct student *next;
};

struct student *start=NULL;

struct student *create_node( int );
void addNodeAtLast( int);
void addNodeAtFirst( int );
void addNodeBetween( int , int );
int transerv();
void delNodeAtFirst();
void delNodeAtLast();
void delNodeBetween( int );

/******************************************************************//**
*Function to create first node
*@param[in] r here r is the roll number of that node
**********************************************************************/
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

/******************************************************************//**
*Function to add node at last if list is present
**********************************************************************/
void addNodeAtLast( int r ) {
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
	
	temp->next = create_node(r);
	 temp->next->next = NULL; //remove if not work me change on 22/01/20
	 
}

/******************************************************************//**
*Function to add node at first 
**********************************************************************/
void addNodeAtFirst( int r ) {

	struct student *temp=NULL;

	if( start == NULL )
	{
		printf("The list is empty\n");
		start = create_node(r);
		return;
	} 
	
	temp = start;
	start = create_node(r);
	start->next = temp; //may be temp->next
	
}

/******************************************************************//**
*Function to add node at after the passing roll number structur
*@param[in] r which is roll number after that roll number containing node add one more node 
**********************************************************************/
void addNodeBetween( int r, int r_add ) {
	struct student *temp = NULL;
	struct student *temp1 = NULL;
	temp = start;
	while ( temp != NULL ) {
		if (temp->roll == r) {
			
			temp1 = temp->next;
			temp->next = create_node(r_add);
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

/******************************************************************//**
*Function to sum all the roll number from all the node
**********************************************************************/
int transerv() {
	struct student *temp = start;
	int sum = 0;
	while (temp != NULL ) {
		sum = sum+temp->roll;
		temp = temp->next;
	}
	return sum;
}

/******************************************************************//**
*Function to delete node at first 
**********************************************************************/
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

/******************************************************************//**
*Function to delete node at last 
**********************************************************************/
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

/******************************************************************//**
*Function to delete node at between
**********************************************************************/
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

