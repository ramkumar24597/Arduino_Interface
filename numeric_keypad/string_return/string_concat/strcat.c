#include<stdio.h>

void strcat(char string[], char character)
{
    int c=0;
    while(string[c] != '\0')
    {
        c++;
    }

    string[c]=character;
    c++;
    string[c] = '\0';

}

void main()
{
    char str[]= "#";
    char ch =  'a';

    strcat(str,ch);
    printf(str);
}
