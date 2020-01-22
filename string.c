#include <stdio.h>

int mystrlen( );
void mystrcpy( );
int mystrcmp( );
void myupper( );
void mylower( );
int main() {
	char str1[5], str2[5];
	
	printf("\nEnter first string\t");
	scanf("%s", &str1[0]);
	printf("\nEnter second string\t");
	scanf("%s", &str2[0]);
	
	//printf("\nSize of first string is %d", mystrlen(str1)); 
	//mystrcpy(str1, str2);
	//printf("\nNew string is %s", str1);

	//printf("\n %d ", mystrcmp( str1, str2 ));
	//myupper(str1);
	mylower(str1);
	printf("\n\tUpper case %s", str1);
} 
 
int mystrlen(char p[]) { 
	int len=0;
	int i;
	for (i=0; p[i] != '\0'; i++) {
		len++;
		//printf("%c", p[i]);
	}
	return len;
}

void mystrcpy( char p[], char q[] ) {
	int count = 0,i;
	for ( i=0; p[i] != '\0'; i++ ) {
		count++;
	}
	for ( i=0; q[i] != '\0'; i++ ) {
		p[count] = q[i];
		count++;
		printf("\nIn side %d", count);
	}
}	

int mystrcmp( char p[], char q[] ) {
	int count1 = 0,count2 = 0,i,compare=0;
	count1 = mystrlen(p);
	count2 = mystrlen(q);

	if ( count1 == count2 ) {
		for (i=0; i <=count1; i++ ) {
			if (p[i] == q[i] ) {
				compare++;
			}
		}
		if(compare == count1+1 ) {
			return 1;
		} else {
			return -1;
		}
	} else {
		return 0;
	}
}

void myupper( char p[] ) {
	int count,i;
	count = mystrlen(p);
	for (i=0; i<=count+1; i++ ) {
		if (p[i]>=97 && p[i]<=122) {
			p[i] =p[i] - 32;
	}
}	

}

void mylower( char p[] ) {
	int count, i;
	count = mystrlen(p);
	for (i=0; i<=count+1; i++ ){
		if ( p[i]>=65 && p[i]<=90) {
			p[i] = p[i] + 32;
		}
	}
}

int myisdigit( chra
