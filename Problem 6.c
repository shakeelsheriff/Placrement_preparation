/*  Name: Shakeel Sheriff M
    Batch : 24002
    Date: 02/12/2024
    Problem 6:  Problem 4: Design an algorithm and write code to remove the duplicate characters in a string
                without using any additional buffer.
                Examples:
                Input = thgyujgehtwdts
                Output thgyujewds
                Input qwertfertagwa
                Output = qwertfag
*/
#include <stdio.h>

void remove_duplicate(char *str);
int main(){
    char str1[] = "thgyujgehtwdts";
    remove_duplicate(str1);
    printf("Result: %s\n",str1);

    char str2[] = "qwertfertagwa";
    remove_duplicate(str2);
    printf("Result: %s\n",str2);

    return 0;
}

void remove_duplicate(char *str){
    int write_index = 0;

    for (int read_index = 0; str[read_index] != '\0'; read_index++){
        int is_duplicate = 0;
        //check if any char matches with the unique char
        for(int i = 0; i < write_index; i++){
            //if duplicate skip the char
            if(str[read_index] == str[i]){
                is_duplicate = 1;
                break;
            }
        }
        //if not duplicate write it at proper index(write_index)
        if(!is_duplicate){
            str[write_index] = str[read_index];
            write_index++;
        }
    }
    str[write_index] = '\0';
}