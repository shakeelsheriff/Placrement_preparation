/*  Name: Shakeel Sheriff M
    Batch : 24002
    Date: 26/11/2024
    Problem 3: Write a function in C to reverse each word in a given string without changing the word order.
    The function should work within constrained memory limits, avoiding dynamic memory allocation (e.g., malloc)
    and using only a limited number of additional variables. Assume that the string can fit within a standard
    fixed-length buffer, as is typical in embedded systems.
    Input: "hello world"
    Output: "olleh dlrow"
*/
#include <stdio.h>
#include <string.h>

void reverse_word(char *str, int start, int end);
void reverse_words(char *str);

int main()
{
    char str[256];
    printf("Enter a string (max 255 characters): ");
    fgets(str, sizeof(str), stdin);
    // Check for newline at the end and replace it with null terminator
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    reverse_words(str);

    printf("Reversed string: %s\n", str);

    return 0;
}

void reverse_word(char *str, int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}
void reverse_words(char *str)
{
    int len = strlen(str);
    int start = 0;

    // Traverse the string
    for (int i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            reverse_word(str, start, i - 1);
            start = i + 1;
        }
    }
}