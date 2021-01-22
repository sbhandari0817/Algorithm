
#include <stdio.h>
#include <stdlib.h>

int left[200],right[200];
char color[200];
char inString[200];
int red =1;
int blackHeightCheck = 1;
int s2tStrPtr=0,s2tArrPtr=0;  // globals - position in inString, next left/right/color slot
int blackHeight;

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

int main()
{
    int root;
    int i;
    scanf("%s",inString);
    root=string2tree();
    printf("root is %d\n",root);
    printf("color  left   right\n");
    for (i=0;i<s2tArrPtr;i++)
    printf("  %c    %3d    %3d\n",color[i],left[i],right[i]);
    outputTree(root);
    printf("\n");
    checkRed(root,'B');
    blackHeight=0;
    for (i=root;i!=(-1);i=left[i])
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

