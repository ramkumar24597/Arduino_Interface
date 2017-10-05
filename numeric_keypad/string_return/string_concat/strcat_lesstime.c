#include<stdio.h>

void strcat(char string[], int location, char character)
{
    string[location] = character;
}

void main()
{
    char str[]= "#";
    char ch =  'a';
    int i =0;

    i++;
    strcat(str,i,ch);
    printf(str);
}
