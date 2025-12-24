#include <cs50.h>
#include <stdio.h>


int main(void)
{
    string resp = get_string("What's your name?\n");
    printf("hello, %s\n", resp);
}