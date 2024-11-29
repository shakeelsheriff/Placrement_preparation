/*  Name: Shakeel Sheriff M
    Batch : 24002
    Date: 29/11/2024
    Problem 5:  Problem : Implement an algorithm to determine if a string has all unique characters. 
                What if you can not use additional data structures?
                Examples:
                Input: qwertyuiop
                Output: true
                Input: qwesrtwop
                Output: false
                Input: plotfro
                Output: false
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool hasuniqueChar(char *str);
int main(){
    char str[256];
    printf("Enter the String: ");
    fgets(str, sizeof(str), stdin);
    // Check for newline at the end and replace it with null terminator
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }
    printf("%s : %s\n",str, hasuniqueChar(str)?"true":"false");
    return 0;
}

bool hasuniqueChar(char *str){
    for (int i =0 ; str[i] != '\0'; i++){
        for (int j = i + 1; str[j] != '\0'; j++){
            if(str[i] == str[j]){
                return false;
            }
        }
    }
    return true;
}