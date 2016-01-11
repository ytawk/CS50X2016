#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defining the maximum characters that can be inserted by the user
// to avoid an overflow.
#define MAXINPUT 10

char userInput[MAXINPUT] = "";

// function prototypes
int getUserInput(int userTry);
void printGraph();
int inputVal();
void menuLoop(int userInpt);

int main(void)
{
    int input  = 0, try = 0;
    
    try = 1;
    input = getUserInput(try);
    
    menuLoop(input);
    
    return 0;
}

/********* FUNCTIONS **********/

// function to get the user input and validate it
int getUserInput(int userTry)
{
    char inserted[MAXINPUT] = "";
    
    int error = 0, n = 0;
    
    if (userTry == 1)
    {
        printf("Height: ");
    }
    else
    {
        printf("Retry: ");
    }
    
    fgets(userInput, sizeof(userInput), stdin);
    
    // scan for int's and char's
    error = sscanf(userInput, "%d %s", &n, inserted) != 1 || n < 0 || n > 23; 
                                                             
    return error;
}

// function to print the pyramid shape
void printGraph()
{
    int i = 0, j = 0;

    // converting the user's input into an int, because it has been
    // stored in a char array.
    int toNumber = atoi(userInput);
   
    while (j != toNumber)
    {
        for (i = (toNumber - (j + 1)); i > 0; i--)
        {
            printf(" ");
        }
        j++;
        
        for(int x = j; x > 0; x--)
        {
            printf("#");
        }
        
        printf("  ");
        
        for(int x = j; x > 0; x--)
        {
            printf("#");
        }
        
        printf("\n");
    }
}

// looping menu if the users input is not valid
void menuLoop(int userInpt)
{
    // controls the number of user tries
    int try = 2;
    
    while(userInpt)
    {
        int reerror = getUserInput(try);
       
        if (!reerror)
        {
            break;
            printf("%i\n", userInpt);
        }
    }
    
    printGraph();
}

