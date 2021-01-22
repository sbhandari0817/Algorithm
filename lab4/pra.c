#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// This is node to store R or B
struct node{
    char B_R;
    struct node* left;
    struct node* right;
};

//Filling the data from the user input strings.

struct node* newdata(char str){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->B_R = str;
    temp->left = temp->right = NULL;
    return temp;
};
//Inserting given data in binary tree
struct node* insert(struct node*head, struct node* tail){
    if (head == NULL){
        head = tail;
    }
    else if (head->B_R != '.'){
        head->left = insert(head->left, tail);
    }
    return head;
}

int main(){
    struct node* head;
    struct node* tail;
    head = NULL;
    char userinput[200];
    scanf("%s",userinput);
    int i;
    i = 0;
    char s;
    s = userinput[i];
    while (s != '\0'){
        tail = NULL;
        tail = newdata(s);
        head = insert(head, tail);
        i++;
        s = userinput[i];
    }
    return 0;
}
