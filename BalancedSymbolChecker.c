/* Class: CS 211
   Author: Sakina Master
   Date: May 28th 2018 */
   
#include <stdio.h>		//For printf and scanf
#include <stdlib.h>		//For using malloc()

// typical C boolean set-up
#define TRUE 1
#define FALSE 0


//Struct defining Stack datastructure.
typedef struct Stack
{
   char* stackArray;	// pointer to dynamic array  
   int size;  		    // amount of space allocated 
   int top; 			    // top of stack indicator 
}Stack;


//----------------------------------------------------------------------------------------------------------------
//This function initializes the stack. It takes a pointer to the struct Stack as its parameter.
//It does not return anything.
void init (Stack* s)
{
   s->size = 2;													//Initial size of the dynamic array.
   s->stackArray = (char*) malloc ( sizeof(char) * s->size );		//Dynamically allocate the size of the character array.
   s->top  = -1;												//Since the stack is initailly empty, the top value is assigned as -1.
}


//----------------------------------------------------------------------------------------------------------------
//This function pushes all the opening symbols inside the stack. If the stack array is full, it also dynamically grows the array.
//It takes a pointer to the struct Stack, the opening symbol and the value of debugMode as parameters.
void push (Stack* s, char val, int debugMode)
{
  int count = 0;	
  if(s->size - 1 == s->top)	{	  //If stack array if full, it grows the array.
    int i;
    char *temp = (char*) malloc(sizeof(char) * (s->size + 2)); 	//Increases the size of the stack array by 2.
    for(i = 0; i < s->top + 1; i++) {							//For loop iterates through all the elements in the old stack.
      temp[i] = s->stackArray[i];								  //Copies all the elements from the old stack to the new stack.
      count++;												//Increaments the counter which gives the number of values copied from old array to new array.
    }
        
    if ( debugMode == TRUE )	{								//Checks if debugMode is true and prints the following statements
      printf("Old Size of the dynamic array = %d\n", s->size);
      printf("New size of the dynamic array = %d\n", s->size + 2);
      printf("Number of values copied from the old array to the new array = %d\n", count);
    }
		
    free(s->stackArray);		    //Deallocate the memory of the old array.
    s->stackArray = temp;		    //Make the temp varaiable point to the new stack array.
    s->size = s->size + 2;		  //Update the size to the new size. 
  }
  (s->top)++;						        //Increment top to point to the new top variable.
  s->stackArray[s->top] = val;	//Add the new value to the stack.

  if ( debugMode == TRUE ) {		//If debugMode is true print the value pushed into tsack.
  		printf("%c is pushed into stack.\n", val);
  	}
}


//-------------------------------------------------------------------------------------------------------------------
//This function checks if the stack is empty and returns value of true or false. It takes a pointer to the struct Stack as its parameter.
int isEmpty (Stack* s) {
	if ( s->top == -1) {				//If the the value of top is -1, it returns true.
  	return TRUE;	
  }
  else {
    return FALSE;	
  }
}


//-------------------------------------------------------------------------------------------------------------------
//This function returns the value stored at the top of the stack. It takes a pointer to the struct Stack as its parameter.
char top (Stack* s) {
	return (s->stackArray[s->top]);
}


//-------------------------------------------------------------------------------------------------------------------
//This function pops the element from the top of the stack. It takes a pointer to the struct Stack and the value of debugMode as its parameter.
void pop (Stack* s, int debugMode)
{
	if(debugMode == TRUE) {			//If debugMode is true it prints the value which got deleted from the stack.
  		printf("%c is popped from stack.\n", top(s));
	}
	s->top = s->top - 1;			//Decrements the top value of the stack array.
}


//-------------------------------------------------------------------------------------------------------------------
//It deallocates the memory of the stack array so that it is empty and can be used again. It takes a pointer to the struct Stack as its parameter.
void reset (Stack* s) {
	free(s->stackArray);
}


//-------------------------------------------------------------------------------------------------------------------
//This function returns true if an opening symbol is encountered. It takes the character which is being checked as parameter.
int isOpeningSymbol( char ch ) 
{ 
	if ( ch == '{' || ch == '(' || ch == '[' || ch == '<' ) {  //If any of these opening symbols is encountered, return true.
    return TRUE;	
  } 
	else {
    return FALSE;	
  } 
}


//--------------------------------------------------------------------------------------------------------------------
//This function returns true if a closing symbol is encountered. //If any of these opening symbols is encountered, return true.
int isClosingSymbol (char ch)
{
	if ( ch == '}' || ch == ')' || ch == ']' || ch == '>' ) { //If any of these closing symbols is encountered, return true.
  	return TRUE;	
  } 
	else {
  	return FALSE;	
  } 
}


//---------------------------------------------------------------------------------------------------------------------
//This function returns the matching closing symobol for an opening symbol and vice versa. It takes a character as a parameter.
char getMatchingSymbol (char ch) 
{   
	if ( ch == '(' ) {
    return ')'; }
	if ( ch == ')' ) {
    return '(';	} 
	if ( ch == '{' ) {
    return '}';	}  
	if ( ch == '}' ) {
    return '{';	} 
	if ( ch == '[' ) {
    return ']'; }
	if ( ch == ']' ) {
    return '['; }  
	if ( ch == '<' ) {
    return '>';	} 
	if ( ch == '>' ) {
    return '<';	} 
	return '&';					//It never returns this value.
}


//---------------------------------------------------------------------------------------------------------------------------
//This function checks if the opening symbol matches with the corresponding closing symbol. It takes two characters which are compared with each other as parameters.
//It returns true if the symbol matches else it return false. 
int doSymbolsMatch ( char ch1, char ch2 ) 
{
	char symbols[8] = { '(', '{', '[', '<', ')', '}', ']', '>' }; 	//Array of all opening and closing symbols.
	int a; 
    for ( a = 0 ; a < 8 ; a++ ) {									//For loop iterates through this array of symbols.    
      int b  = (a + 4) % 8;										//For each value of 'a', 'b' is assigned its corresponding opening or closing symbol.
      if ( ch1 == symbols[a] && ch2 == symbols[b] )	{			//If the symbols 'a' and 'b' are the same symbol with opposite openings, return true.
	    	return TRUE;  }  
	  }
	return FALSE; 
}


//This function displays the user input. It takes userInput[] and the size of the array as parameters.
//This function does not return anything.
void displayExpression(char userInput[], int a)
{
	int i;
	for(i=0; i<a-1; i++) {		//For loop iterates through the entire size of the userInput[]
		printf("%c ",userInput[i]);
	}
	printf("\n");
}


int main (int argc, char** argv)
{
	int debugMode = FALSE;      		//Declare a variable debugMode with initial value of false.
	int i; 
	for ( i = 0 ; i < argc ; i++ ) {
		if (( argv[i][0] == '-') && (argv[i][1] == 'd')) {	//If user enters '-d' in command line argument, the program runs in debug mode.
			debugMode = TRUE;
		}
	}
	printf("\t  Class : CS 211 \n\t  Author: Sakina Master \n");
	Stack s;
	init (&s);							//Call the function to initialize the stack.
	int maxSize = 302;
	char userInput[maxSize];			    //Declare a userInput array which stores the userInput.
	while(TRUE) {					            //A never ending loop which goes on until user inputs 'q' or 'Q'
		printf("\nEnter an expression with parenthesis:");
		fgets(userInput, 302, stdin);		//Reads the input from the standard input with a max of 300 characters.	
		int numCharacters = 0;			
		int notBalanced = 0;
		//remove the \n character  
		while ( userInput[numCharacters] != '\0' ) { 		//While user input is not null keep reading the characters.   
			if ( '\n' == userInput[numCharacters]  ) {  	//If a new line is encountered
				userInput[numCharacters] = '\0';		//Change that new line to null.
			}
			numCharacters++;							  //Increment numCharacters, this gives the number of characters entered by the user.
		}
	
		if(numCharacters == 2) {					//Check if the user enetrs only one character.
			if(userInput[0] == 'q'||userInput[0] == 'Q') {  //If the character entered is 'q' or 'Q' exit the program.
				return 0;
			}
		}
	
		displayExpression(userInput, numCharacters);
		int i;
		for(i=0; i<numCharacters - 1; i++) {					//For loop itereates through the entire size of the array.
			if(isOpeningSymbol(userInput[i]) == TRUE){	//If an opening symbol is encountered, the symbol is pushed in the stack array.
				push (&s, userInput[i], debugMode);			
			}
	
			else if (isClosingSymbol(userInput[i]) == TRUE) {	  //Check if the symbol is a closing symbol
        char topValue = top (&s);					//The top value is stored in a char variable topValue.
        if(isEmpty(&s) == TRUE) {					//Checks if the stack is empty
          if ( debugMode == TRUE ) {			//If debugMode is true, display the userInput.
            displayExpression(userInput, numCharacters);
          }
          int k;
          for(k=0; k<i*2; k++) {
            printf(" ");
					}
					printf("^ missing %c \n", getMatchingSymbol(userInput[i]));
					printf("Not a Balanced expression!\n");
          notBalanced = 1;						  //Set notBalanced to 1.
          break;
        }
	   		
        else if (doSymbolsMatch(topValue , userInput[i]) == FALSE )	{ //Check if opening and closing symbols does not match
          int k;
          if ( debugMode == TRUE ) {		//If debugMode is true, display the userInput.
            displayExpression(userInput, numCharacters);
          }
          for(k=0; k<i*2; k++) {
            printf(" ");
          }
          printf("^ expecting %c \n", getMatchingSymbol(topValue));
          printf("Not a Balanced expression!\n");
          notBalanced = 1;						  //Set notBalanced to 1.
          break;
				}
				else {
					pop(&s, debugMode);						//Pop the top element from the stack array.
				}
			}
		}
		if((isEmpty(&s) == TRUE) && (notBalanced == 0)){
        	printf("Expression is balanced.\n");
    }
		else if(notBalanced == 0) {
			int k;
			if ( debugMode == TRUE ) {				//If debugMode is true, display the userInput
				displayExpression(userInput, numCharacters);
			}
 			for(k=0; k < numCharacters * 2; k++) {
				printf(" ");
			}
			printf("^missing %c \n", getMatchingSymbol(top(&s)));
      printf("Not a Balanced expression!\n");
		}
		
		reset(&s);										//Call the reset()
		init(&s);											//Call the init()
		continue;											//Goes back to the start of the for loop.
	}		
	return 0;
}//end main()
