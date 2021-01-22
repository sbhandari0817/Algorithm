/*
Author: Santosh Bhandari
ID: 10013877116

I checked this code on omega by doing
gcc Bhandari_Satosh_Lab4.c
a.out
entering the input string
*/

#include <stdio.h>
#include <stdlib.h>

//Decleration global varibles.

int left[200],right[200];
char color[200];
char inString[200];
int red =1;   //To check red property
int blackHeightCheck = 1;        //To check black property
int s2tStrPtr=0,s2tArrPtr=0;  // globals - position in inString, next left/right/color slot
int blackHeight;

//Inserting data into the table recursively.

int string2tree()
{
    char ch;
    int posNumber;
    posNumber = s2tArrPtr;
    ch = inString[s2tStrPtr];
    if (ch != '\0'){
        if (ch != '.'){
            color[posNumber] = ch;
            s2tStrPtr++;
            s2tArrPtr++;
        }
        else{
            s2tStrPtr++;
            return -1;
        }
        left[posNumber] = string2tree();
        right[posNumber] = string2tree();
    }
     return posNumber;
}

//Funtion to print the input data on the screen 

void outputTree(int nodeNumber)
{
    if (nodeNumber==(-1))
    {
      printf(".");
      return;
    }
    printf("%c",color[nodeNumber]);
    outputTree(left[nodeNumber]);
    outputTree(right[nodeNumber]);
}

//Function to check red property

void checkRed(int nodeNumber,char parentColor)
{
       if (nodeNumber == -1){
            return;
       }
       char baby;
       baby = color[nodeNumber];
       if (parentColor == 'R'){
           if (baby == parentColor){
                red = 0;
           }
       }
       checkRed(left[nodeNumber], baby);
       checkRed(right[nodeNumber],baby);
       return;
}

//Function to check black height. 

void checkBlackHeight(int nodeNumber,int count)
{
    if (nodeNumber == -1){
        if (blackHeight != count){
            blackHeightCheck = 0;
        }
        return;
    }
    else if (color[nodeNumber] == 'B'){
            count++;
    }
    checkBlackHeight(left[nodeNumber], count);
    checkBlackHeight(right[nodeNumber], count);
}

//Main program. 

int main()
{
    int root;
    int i;
    scanf("%s",inString); //Asking user for input
    root=string2tree();   //returning the value of position in which data is enterd. 
    outputTree(root);
    printf("\n");
    checkRed(root,'B');
    blackHeight=0;
    for (i=root;i!=(-1);i=left[i]) //Finding the black height for one branch to check properties with others. 
        blackHeight+=color[i]=='B';
     checkBlackHeight(root,0);
     if (red ==1){
        printf("Red property OK\n");
        printf("Black height should be %d\n",blackHeight);
         if (blackHeightCheck == 1){
            printf("Black heights OK\nSatisfies all properties");
        }
        else {
            printf("Black height problem\nDoes not satisfy");
        }
    }
    else{
        printf("Red property is not satisfied\nDoes no satisfy");
    }
    return 0;
}

