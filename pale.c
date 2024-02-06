#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char string[]);
char* stripSpaces(char *noSpace);

int main(void)
{
    char usrStr[500];

    printf("Please enter a string and I will check if it is a palindrome...");
    scanf( "%499[^\n]", usrStr);
    
    printf("\n");
    isPalindrome(usrStr) ? printf("\"%s\" is a palindrome", usrStr) : printf("\"%s\" is not a palindrome", usrStr);

    printf("\n");

    return 0;
}

bool isPalindrome(char* string)
{
    char* newStr = stripSpaces(string);
    
    int middle = strlen(newStr) / 2;
    int len = strlen(newStr);

    for(int x = 0; x < middle; x++)
        if(newStr[x] != newStr[len - x - 1])
            return false;  
    // Check first char againse last char - then 2nd char against 2nd last char and so on until mismatch found.
    // If no mismatch then the string is a palindrome
    
    return true;
}

char* stripSpaces(char *noSpace)
{
    int length = strlen(noSpace);
    char *retVal = malloc(length);
    int count = 0;
    for(int idx = 0; idx < length; idx++)
    {
        if(noSpace[idx] != ' '&&
           noSpace[idx] != ','&&
           noSpace[idx] != '.'&&
           noSpace[idx] != '?'&&
           noSpace[idx] != '!'&&
           noSpace[idx] != ';'&&
           noSpace[idx] != ':')
        {
            retVal[count++] = noSpace[idx];
        }
    }
    retVal[count] = '\0';
    printf("\nFirst, strip out the spaced and punctuation...\n%s\n", retVal); /*Spaces and punctuation are now out.*/
    for(int i = 0; i < strlen(retVal); i++)
        retVal[i] = tolower(retVal[i]);

    printf("\nThen switch all the lotters to lower case...\n%s\n", retVal); /*all lower case letters (hopefully)*/

    return retVal;

}
