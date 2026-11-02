#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[]) 
{
    if (argc != 3)
    {
        printf("Output: ./message.c message search\n");
        return 1;
    }

    if (strlen(argv[2]) != 1) 
    {
        printf("Search input must be a character only\n");
        return 1;
    }

    int digit_counter = 0;
    int alpha_counter = 0;
    int space_counter = 0;
    int punct_counter = 0;

    for (int i = 0, length = strlen(argv[1]) ; i < length ; i++) 
    {
        if (isalpha((unsigned char) argv[1][i]))
        {
            alpha_counter++;
        }

        if (isdigit((unsigned char) argv[1][i]))
        {
            digit_counter++;
        }
        
        if (isspace((unsigned char) argv[1][i]))
        {
            space_counter++;
        }

        if (ispunct((unsigned char) argv[1][i]))
        {
            punct_counter++;
        }
    }
    printf("Total alphabetic characters: %d\n", alpha_counter);
    printf("Total digits: %d\n", digit_counter);
    printf("Total spaces: %d\n", space_counter);
    printf("Total punctuations: %d\n", punct_counter);

/* Making the connections between the argv[1] & argv[2]*/

int count = 0;
int first_position = -1;
int last_position = -1;

char input = argv[2][0];


 for (int i = 0, length = strlen(argv[1]) ; i < length ; i++)
 {
    if (tolower(argv[1][i]) == tolower(input))
    {
        count++;

        if (count == 1)
        {
            first_position = i;
        }

        last_position = i;

    }
    
 }   
    
    printf("Number of occurrences of the target character: %d\n", count);

    if (count == 0)
    {
         printf("The character was not found in the message.\n");
    }

    else
    {
        printf("First occurrence index: %d\n", first_position);
        printf("Last occurrence index: %d\n", last_position);
    }
    printf("\n");
    return 0;
}