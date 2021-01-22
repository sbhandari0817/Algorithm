#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// This is node to store R or B
struct node{
    char B_R;
    int left;
    int right;
};

//Filling the data from the user input strings.

struct node newdata[200];
char s;
int LOR = 0;

int left[100];
int right[100];

void insert(int stind, char userinput[],int  ind){
    if (s != '.' && LOR == 0){
        ind++;
        newdata[stind].B_R = s;
        newdata[stind].left = 0;
        newdata[stind].right = 0;
        if (stind != 0){
            newdata[stind -1].left =  newdata[stind].left +newdata[stind].right+ 1;
        }
        s = userinput[ind];
        if ( s != '\0'){
            stind ++;
            insert(stind, userinput, ind);
        }
    }
    else if (s != '.' && LOR ==1){
        ind++;
        newdata[stind].B_R = s;
        newdata[stind-1].right = newdata[stind].left + newdata[stind].right + 1;
        s = userinput[ind];
        if (s != '\0'){
            stind ++;
            insert(stind, userinput, ind);
        }
    }
    else {
        ind++;
        s = userinput[ind];
        if (s == '.'){
            if (LOR == 0){
                LOR = 1;
            }
            else{
                LOR = 0;
            }
        }
        if (s != '\0'){
            insert(stind, userinput, ind);
        }
    }
    return;
}

int main(){
    char userinput[200];
    scanf("%s",userinput);
    s = userinput[0];
    int ind;
    ind = 0;
    int stind;
    stind = 0;
    insert(stind,userinput,ind);
    return 0;
}
