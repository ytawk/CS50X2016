#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BPM 12
#define MAXINPUT 10

// global variable for user input
char userInput[MAXINPUT] = "";

// Function prototypes
int isDigit();
int calculate();

int main(void)
{
    int error = 0;
    
    error = isDigit();
    
    while(error)
    {
        int reerror = isDigit();
        
        if (!reerror)
        {
            break;
        }
        
    }
    
    calculate();
    
    return 0;
   
}

// *** FUNCTIONS ***

// check if user input is a digit or not
int isDigit()
{
    char inserted[MAXINPUT] = "";
    
    int error = 0, n = 0;
    
    printf("minutes: ");
    fgets(userInput, sizeof(userInput), stdin);
    
    // scan for int's and char's
    error = sscanf(userInput, "%d %s", &n, inserted) != 1 || n <= 0;
    
    return error;
}

// calculate the number of bottles
int calculate()
{
    int convert = 0, calcBotls = 0;
    
    // convert the user's input into an integer to allow calculation
    convert = atoi(userInput);
    
    calcBotls = convert * BPM;
        
    printf("bottles: %i\n", calcBotls);
    
    return calcBotls;
}
