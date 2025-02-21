/*Basic_calculator 
Data input of two numbers and the operator chosen by the user.
Conditional structures: Use if or switch to select the desired operation (addition, subtraction, multiplication or division).
Functions: Modularize your code by creating functions for each operation.
Repetition loops: Allow the user to perform several operations until they decide to exit.*/

#include <stdio.h>

//initializing global variables
int a, b, operation = 0;
int stop = 1;

//
void values_and_operator(){
	printf("Choose the Value A: \n");
	scanf("%i", &a);
	
	printf("Choose the Value B: \n");
	scanf("%i", &b);
	
	printf("Choose the Arithmetic Operator's number: 1- Sum, 2- Subtraction, 3- Multiplication, 4- Division: \n");
	scanf("%i", &operation);
		  		  
		  				 }
//modularized operations		  				 
int sum(){
	return a + b;
		 }
		 
int subtraction(){
		return  a - b;
				 }
				 
int multiplication(){	
		return a * b;				 
				    }				    
//treatment for the zero division erro				 
int division(){	
		if(b == 0){
			printf("Impossible Division by 0");
			return 0;
		}else{
			return a / b;
			 }					 
			  }

//depending of the user operator's input the switch call the right operator function				 
void math(){
	switch(operation){
		case(1):		
			printf("The result is %i", sum());
			break;
		
		case(2):		
			printf("The result is %i", subtraction());
			break;
			
		case(3):		
			printf("The result is %i", multiplication());
			break;
			
		case(4):
			printf("The result is %i", division());
			break;
	
		default:
			printf("Choose a valid operator!");
					}	
			 }

//asks if user wants to end the program if yes end the loop with the variable stop = 0 otherwise stop = 1
void stop_program(){	
	printf("\nDo you want to exit? 0- Yes, 1- No: ");
	scanf("%i", &stop);	
				  }

//main function with the loop
int main(){
	while(stop){
		values_and_operator();
		math();
		stop_program();		
			   }	
	return 0;     }
