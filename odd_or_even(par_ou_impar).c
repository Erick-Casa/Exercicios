//read user's number input, process and print the result odd or even

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void read_int(int *ptr_number){
	while(true){
	printf("Write the number to check if it is odd or even, type 0 to exit: ");
	
	if(scanf("%d", ptr_number) != 1 ){    //treatment for invalid characters
		getchar();
		printf("Write an integer!\n");
		continue;
	}
		
	if(*ptr_number == 0){
		exit(EXIT_SUCCESS);
	}
	
	break;
	}
}

void print_parity(int number){
	if(number % 2 == 0){	//if number divided by 2 equals 0 is even else odd
		printf("The number is even\n");
	}
	else{
		printf("The number is odd\n"); 
	}		
}

int main(){
	int number = 0;
	
	while(true){
		read_int(&number);
		print_parity(number);		  
	}
	
	return 0;
}
