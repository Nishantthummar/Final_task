#include <stdio.h>

/***************************************************************************//*
*all string functions
******************************************************************************/
int mystrlen( );
void mystrcat( );
int mystrcmp( );
void myupper( );
void mylower( );
int myisdigit( );
int myisalph( );


int main() {
	char str1[100], str2[100];  //!< Two string for performing string oprations
	
	printf("\nEnter first string\t");
	scanf("%s", &str1[0]);
	printf("\nEnter second string\t");
	scanf("%s", &str2[0]);
	
	//printf("\nSize of first string is %d", mystrlen(str1)); 
	//mystrcpy(str1, str2);
	//printf("\nNew string is %s", str1);

	//printf("\n %d ", mystrcmp( str1, str2 ));
	//myupper(str1);
	//mylower(str1);
	printf("\n\tisdigit %d", myisalph(str1));
} 

/***************************************************************************//*
*Function for find out lenth of string
******************************************************************************/
int mystrlen(char p[]) { 
	int len=0;
	int i;
	for (i=0; p[i] != '\0'; i++) { // loop untill null ch. is found
		len++;
		//printf("%c", p[i]);
	}
	return len; //return lenth of input string
}

/***************************************************************************//*
*Function for add string q after the p end 
******************************************************************************/
void mystrcat( char p[], char q[] ) {
	int count = 0,i;
	for ( i=0; p[i] != '\0'; i++ ) { // find out where is the end of first string
		count++;
	}
	for ( i=0; q[i] != '\0'; i++ ) { // now add one by one ch. after the first string
		p[count] = q[i];
		count++;
	}
}	

/***************************************************************************//*
*Function for compare two string whether is same or not
*If same return 1 else 0 or -1
******************************************************************************/
int mystrcmp( char p[], char q[] ) {
	int count1 = 0,count2 = 0,i,compare=0;
	count1 = mystrlen(p);
	count2 = mystrlen(q);

	if ( count1 == count2 ) { // comparing lenth of both the string if same compare one by one ch.
		for (i=0; i <=count1; i++ ) {
			if (p[i] == q[i] ) {
				compare++; // compare counter which is
					   // increment when same ch. found 
			}
		}
		if(compare == count1+1 ) { // if lenth of str and same ch. 
			return 1;
		} else {
			return -1; // lenth is same but ch is not
		}
	} else {
		return 0; // lenth is not same
	}
}

/***************************************************************************//*
*Function for convert lower case to upper case remaining unchanged
******************************************************************************/
void myupper( char p[] ) {
	int count,i;
	count = mystrlen(p);
	for (i=0; i<=count+1; i++ ) {
		if (p[i]>=97 && p[i]<=122) { // check ch is lower case or not
			p[i] =p[i] - 32; // if lower, convert it into upper
		}
	}	

}

/***************************************************************************//*
*Function for convert upper case to lower remaining unchanged
******************************************************************************/
void mylower( char p[] ) {
	int count, i;
	count = mystrlen(p);
	for (i=0; i<=count+1; i++ ){
		if ( p[i]>=65 && p[i]<=90) { // check ch is upper or not 
			p[i] = p[i] + 32; // if upper, convert it into lower
		}
	}
}

/***************************************************************************//*
*Function for check whether string is proper digit 
* string have each ch digit then return 1 else -1
******************************************************************************/
int myisdigit( char p[] ) {
	int count, i, temp = 0;
	count = mystrlen(p);
	for (i=0; i<=count+1; i++) {
		if (p[i]>=48  && p[i]<=57) { // ascii value of 0 to 9->48 to 57
			temp++;
		}
	}
	if (temp == count ) { //check all ch digit or not
		return 1;
	}
	return -1;
}

/***************************************************************************//*
*Function for check whether sring have all alphabet
* string have all ch alphabet then return 1 else -1
******************************************************************************/
int myisalph( char p[] ) {
	int count, i, temp = 0;
	count = mystrlen(p);
	for (i=0; i<=count+1; i++) {
		// ascii value of a-z and A-Z
		if ((p[i]>=65 && p[i]<=90) || (p[i]>=97 && p[i]<=122)) {
			temp++;
		}
	}
	if (temp == count ) { // check all ch alphabet or not
		return 1;
	}
	return -1;
}

