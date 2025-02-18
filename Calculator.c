//Data input: Read two numbers and the operator chosen by the user.
//Conditional structures: Use if or switch to select the desired operation (addition, subtraction, multiplication or division).
//Functions: Modularize your code by creating functions for each operation.
//Repetition loops: Allow the user to perform several operations until they decide to exit.

#include <stdio.h>
//initializing global variables
int a, b, operation = 0;
int stop = 1;

void values_and_operator(){
	printf("\nChoose the Value A: ");
	scanf("%i", &a);
	
	printf("\nChoose the Value B: ");
	scanf("%i", &b);
	
	printf("\nChoose the Arithmetic Operator's number: 1- Sum, 2- Subtraction, 3- Multiplication, 4- Division: ");
	scanf("%i", &operation);
		  		  
		  				 }
	
//uses user's inputs A, B, operator	to do the math	  				 
void math(){
		 
	if(operation == 1){	
		printf("The result is %i", a + b);
					 }
		
	else if(operation == 2) {
		printf("The result is %i", a - b);
		              }

	else if(operation == 3) {			
		printf("The result is %i", a * b);
		              }
		
	else if(operation == 4) {		
		printf("The result is %i", a / b);
					  }
					  
	
			 }

//asks if user wants to end the program if yes end the loop with the variable "stop"
void stop_program(){
	int input = 0;
	
	printf("\nDo you want to exit? 1- Yes, 2- No: ");
	scanf("%i", &input);
	
	if(input == 1){
		stop = 0;
		}else{
			stop = 1;}
				  }

//main function with the loop
int main(){
	while(stop){
		values_and_operator();
		math();
		stop_program();		
			   }	
	               }
