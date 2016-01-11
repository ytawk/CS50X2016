#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXINPUT 20
#define INPUTSET 100

char userInput[MAXINPUT] = "";

// function prototypes
int validateCard();
int parseInput();

int main(void)
{
    int validate = 0, parse = 0; 
    
    validate = validateCard();
    parse = parseInput();
    
    while(validate == 0)
    {
        int valid = validateCard();
        
        if (valid)
        {
            if (validate == 15)
            {
                printf("AMEX\n");
            }
            else if (validate == 16)
            {
                printf("MASTERCARD\n");
            }
            else if (validate == 22)
            {
                printf("VISA\n");
            }
            
            break;
        }
    }
    
    if (validate == 15)
    {
        printf("AMEX\n");
    }
    else if (validate == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (validate == 22)
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }
     
    return 0;
}

// function to validate if the inserted Card number, and check which type it is
int validateCard()
{
    char inserted[MAXINPUT] = "";
    int length = 0, flag = 0, proceed = 0, n = 0, insertedLen = 0;
    long long FTD = 0, FOD = 0, oDigitNumber = 1, tDigitNumber = 2, Log10= 0, 
              divisor = 0;
    long long convertInput = 0;
    
    printf("Number: ");
    fgets(userInput, sizeof(userInput), stdin);
    
    sscanf(userInput, "%d %s", &n, inserted); 
    
    insertedLen = strlen(inserted);
    
    convertInput = atoll(userInput);
    
    /***********SIDE NOTE***************
    // get the length of the inserted number for digits
    length = floor(log10(abs(convertInput))) + 1;
    ************SIDE NOTE***************/
    
    length = strlen(userInput) - 1;
    
    if (length >= 13 && insertedLen == 0)
    {
        // get the first 2 digits of the inserted number
        Log10 = (log(convertInput) / log(10)) + 1;
        divisor = pow(10, Log10 - tDigitNumber);
        FTD = convertInput / divisor;
        
        // get the first 1 digit of the inserted number
        Log10 = (log(convertInput) / log(10)) + 1;
        divisor = pow(10, Log10 - oDigitNumber);
        FOD = convertInput / divisor;
        
        proceed = 0;
    }
    else
    {
        proceed = 1;
    }
    
    if (proceed == 0)
    {
        // American Express criteria
        if (convertInput > 0 && ((FTD == 34) || (FTD == 37)) && length == 15)
        {
            flag = 15;
        }
        
        // MAsterCard criteria
        else if (convertInput > 0 && ((FTD == 51) || (FTD == 52) || 
        (FTD == 53) || (FTD == 54) || 
        (FTD == 55)) && length == 16)
        {
            flag = 16;
        }
                
        // Visa criteria
        else if (convertInput > 0 && (FOD == 4) && ((length == 16) || 
        (length == 13)))
        {
            flag = 22;
        }    
    }
    // invalid numbers and strings criteria
    else
    {
        if (insertedLen > 0)
        {
            flag = 0;
        }
        else if (insertedLen == 0 && n > 0)
        {
            flag = 1;
        }
    }
    
    return flag;
}

// function to convert the string input into an int array 
// then get the sum of the first and second part of the inserted number
int parseInput()
{
    int length = 0, sum = 0, validate = 0;
    
    // a- variables for the first part
    char firstSet[INPUTSET] = "";
    int conFirst[INPUTSET] = {0}, sumFirst = 0;
    
    // b- variables for the second part
    char secondSet[INPUTSET] = "";
    int conSecond[INPUTSET] = {0}, multiSecond[INPUTSET] = {0}, sumSecond = 0;
    
    // d- variables for getting the sum of the second part
    int j = 0, digit = 0;
    
    length = strlen(userInput);
    
    // a- iterating and getting the first part of the number
    for (int i = 0; i < length - 1; i = i + 2)
    {
        firstSet[i] = userInput[i];
        conFirst[i] = atoi(&firstSet[i]);
        sumFirst = sumFirst + conFirst[i];
    }
    
     // b- iterating and getting the second part of the number
    for (int i = 1; i < length - 1; i = i + 2)
    {
        secondSet[i] = userInput[i];
        conSecond[i] = atoi(&secondSet[i]);
        multiSecond[i] = conSecond[i] * 2;
    }
    
    // d- getting the sum of the second part
    while (j < INPUTSET)
    {
        digit = multiSecond[j] % 10;
        multiSecond[j] /= 10; 
        sumSecond = sumSecond + (digit + multiSecond[j]);
        
        j++;
    }
    
    sum = sumFirst + sumSecond;
    
    validate = sum % 10;
  
    return validate;
}
