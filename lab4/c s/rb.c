#include<stdio.h>
#include<string.h>

int main(){

    char data[100];
    int i;

    printf("Enter the pre order traversal sequence of nodes:");
    fgets(data,100,stdin);
    int count = 0;
    int valid = 1;
    for (i = 0; i<strlen(data)-1; i++){
        if (data[i] == '.'){
           count++;
        }
        if (data[i] == 'R' && data[i+1] == 'R'){
           valid = 0;
           break;
        }
    }
    if (valid == 1 && count == strlen(data)+1)
       printf("It is a Red black tree\n");
    else
       printf("It is not a Red black tree\n");
    return 0;
   
   
}