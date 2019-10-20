#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 * This program tests credit card numbers to see if they are valid. It will test VISA, AMEX, and Mastercard,
 * returning the type of card if successful. INVALID is returned if unsuccessful.
 */
bool creditTest(char * input, int digitNum);

int main(int argc, char **argv) {

    bool validFlag = true; // Determines whether the card is valid.

    char * creditInput = (char*) malloc(21); // Allocates enough space for the card.

    unsigned long byteNumber = 20;

    int cardType = -1; // 0 is AMEX, 1 is VISA, 2 is Mastercard.

    puts("Number: ");

    int digits = getline(&creditInput, &byteNumber, stdin) - 1; // Gets number of characters minus the newline.

    if(creditTest(creditInput, digits) == false) // Ensures all characters are integers 1-9.
    	validFlag = false;

    else if(digits == 15) // Test to see if it's an AMEX.
    {
        if(creditInput[0] == '3' && (creditInput[1] == '4' || creditInput[1] == '7'))
        	cardType = 0;

        else
        	validFlag = false;
    }

    else if(digits == 16) // Test to see if it's a 16-digit VISA or Mastercard.
    {
        int secondDigit = (int)creditInput[1] - 48;

        if(creditInput[0] == '4')
        	cardType = 1;

        else if(creditInput[0] == '5' && secondDigit > 0 && secondDigit < 6)
        	cardType = 2;

        else
            validFlag = false;
    }

    else if(digits == 13) // Test to see if it's a VISA.
    {
        if(creditInput[0] == '4')
        	cardType = 1;

        else
            validFlag = false;
    }

    else
    	validFlag = false; // Anything else is invalid.

    if(validFlag == true) // We proceed to the algorithm.
    {
    	int runningTotal = 0;

    	for(int i = digits - 2; i<= 1; i-= 2)	// First half of computation does the product digits.
    	{
    		int num = (int)creditInput[i] - 48;

    		if(2*num >= 10)
    			runningTotal += 1 + (2*num)%10;

    		else
    			runningTotal += num;
    	}

    	for(int i = digits - 1; i<= 1; i -=2) // Second half sums the remaining digit.
    		runningTotal += (int)creditInput[i];

    	if(runningTotal % 10 != 0) // Tests the sum to see if it fits the algorithm.
    		validFlag = false;
    }

    if(validFlag == false)
    	printf("INVALID");

    else
    {
    	switch(cardType)
    	{
    		case(0): printf("AMEX");
    			break;

    		case(1): printf("VISA");
    			break;

    		case(2): printf("Mastercard");
    			break;

    		default: printf("INVALID");
    			break;
    	}
    }

    free(creditInput);

    return 0;

}

/**
 * This function runs through the input data to see if all characters are integers.
 *
 * input: The input data, hopefully a credit card number.
 *
 * digitNum: The number of digits in the input.
 *
 * return: Returns true for all integers, false if there's a bad character.
 */
bool creditTest(char * input, int digitNum)
{
	for(int i = 0; i < digitNum; i++)
	{
		int j = (int)input[i] - 48;

		if(j < 0 || j > 9)
			return false;
	}

	return true;
}
