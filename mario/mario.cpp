#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* This program generates a lame Super Mario pyramid of size 1 - 8.
 *
 * It will prompt for input until the user enters a valid size of 1-8.
 */

void pyramid(int value, int maxHeight); // Prototype declaration for line printing method.
char line[20]; // Array is defined and later modified with a shifting null terminator. Harcoded since size >=8.

int main(int argc, char **argv) {

	bool flag = false; // Determines whether the input is acceptable.
	int num; // Determines number of lines to print.

	while (flag == false)
	{
        char input[3]; // Contains input.
        char eatChar = 'x'; // Placeholder variable used to clear stdin.

		printf("Height: ");
		fgets(input, 3, stdin); // I used fgets because scanf is insecure.

        if(strlen(input) == 2 && input[1] == '\n') // Verifies input is 1 char long.
        {
	        if((int)input[0] > 48 && (int)input[0] < 57) // Verifies input is 1-8 using ASCII conversion.
		    {
			    num = (int)input[0] - 48;
			    flag = true;
		    }
        }

        else if(input[0] != '\n') // We don't need to eat the buffer if the input is just a newline. Otherwise, eats the buffer.
        {
            while(eatChar != '\n' && eatChar != EOF)
                eatChar = getchar();
        }
	}

	for(int i = 1; i <= num; i++) // Prints the required number of lines.
		pyramid(i, num);


	return 0;
}

/* This function reads in a value for a given line of the pyramid and prints the line accordingly.
 *
 * value: The given line to print.
 *
 * */
void pyramid(int value, int maxHeight)
{
	int pivot = maxHeight - value; // Determines number of preceeding spaces.
	int maxLength = 2*value + pivot + 2; // Stops the loop once the last # is printed

	line[maxLength] = '\0'; // limits size of array.

	for(int i = 0; i < maxLength; i++)
    {
        if(i < pivot)
            line[i] = ' ';

        else
		    line[i] = '#'; // Fills middle spaces with #'s, which are converted to spaces later.
    }

    /*The position of the middle spaces is always the same relative to the pivot.*/
    line[pivot + value] = ' ';
    line[pivot + value + 1] = ' ';

	printf("%s\n", line);

    line[0] = '\0';

	return;
}
