/*
atuhor: Santosh Bhandari
ID: 1001387116
I used gcc Bhandari_S_lab5.c to compile this conde
and input data using a.out < filename
or by inserting manuaaly; 
I tested this code using d.dat and a.dat to make sure it is working fine. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numVertices,numEdges, m, HTindex;
int strindex = 0;
//HTindex = 0;
int *parent,*weight,numTrees;
char** StringArray;
int *hash;
struct edge {
  int tail,head,weight;
};
typedef struct edge edgeType;
edgeType *edgeTab;

void findm(){
    int x = 2 * numVertices;
    int count = 0;
    int i;
    while (count == 0){
        for (i = 1; i <= x; i++){
            if (x%i == 0){
                count++;
            }
        }
        if (count > 2){
            x++;
            count = 0;
        }
    }
    m = x;
    hash = (int*)malloc(m*sizeof(int));
    for (i = 0; i < m; i++){
        hash[i] = -1;
    }
}

void doublehash(char string[], int key, int indexes[]){
        int h1;
        int h2;
        int i;
        i=h1=key%m;
        h2=key%(m-1)+1;
        if (hash[i] == -1){
            strcpy(StringArray[strindex], string);
            hash[i] = strindex;
            indexes[HTindex] = strindex;
            strindex++;
        }
        else{
            while (hash[i]!=(-1) && strcmp(StringArray[hash[i]],string)!= 0)
                i=(i+h2)%m;
            if (hash[i] == -1){
                strcpy(StringArray[strindex], string);
                hash[i] = strindex;
                indexes[HTindex] = strindex;
                strindex++;
            }
            else{
                 indexes[HTindex] = hash[i];
            }
        }

    }

// Used in call to qsort()
int weightAscending(const void* xin, const void* yin)
{
edgeType *x,*y;

x=(edgeType*) xin;
y=(edgeType*) yin;
return x->weight - y->weight;
}
int find(int x)
// Find root of tree containing x
{
    int i,j,root;

    // Find root
    for (i=x;
         parent[i]!=i;
         i=parent[i])
      ;
    root=i;
    // path compression - make all nodes on path
    // point directly at the root
    for (i=x;
         parent[i]!=i;
         j=parent[i],parent[i]=root,i=j)
      ;
    return root;
}

void unionFunc(int i,int j)
// i and j must be roots!
    {
    if (weight[i]>weight[j])
    {
      parent[j]=i;
      weight[i]+=weight[j];
    }
    else
    {
      parent[i]=j;
      weight[j]+=weight[i];
    }
    numTrees--;
}
int main(){
    int i;
    int edgeWt;
    int MSTweight = 0;
    int root1, root2;

    //Variable needed for double hashing and to take input
    char tail[25];
    char head[25];
    int indexes[2];
    int key;

    scanf("%d %d", &numVertices, &numEdges);
    StringArray = (char**)malloc(numVertices *sizeof(char*));
    edgeTab = (edgeType*)malloc(numEdges*sizeof(edgeType));
    parent = (int*) malloc(numVertices*sizeof(int));
    weight = (int*) malloc (numVertices*sizeof(int));
    //calculating m the prime number to make double hash table.
    findm();

    for ( i = 0; i < numVertices; i++){
        StringArray[i] = (char*) malloc(25*sizeof(char));
    }
    for ( i = 0; i < numEdges; i++){
        HTindex = 0;
        scanf("%s",tail);
        key = strlen(tail);
        doublehash(tail, key, indexes);
        scanf("%s",head);
        HTindex = 1;
        key = strlen(head);
        doublehash(head, key, indexes);
        scanf("%d",&edgeWt);
        edgeTab[i].tail = indexes[0];
        edgeTab[i].head = indexes[1];
        edgeTab[i].weight = edgeWt;
    }
    for (i = 0; i < numVertices; i++){
        parent[i] = i;
        weight [i] = 1;
    }
    numTrees=numVertices;
    qsort(edgeTab,numEdges,sizeof(edgeType),weightAscending);
    int table[numEdges];
    for (i=0;i<numEdges;i++)
    {
        root1=find(edgeTab[i].tail);
        root2=find(edgeTab[i].head);
        if (root1==root2){
                table[i] = -1;
        }
        else
        {
            table[i] = 1;
            MSTweight+=edgeTab[i].weight;
            unionFunc(root1,root2);
        }
    }
	if (strindex != numVertices){
		printf("Warning !! Continuing with %d vertices\n", strindex);
	}
    printf("Sum of weights of spanning edges is %d\n",MSTweight);
    printf("Outputting tree with leader %d\n",edgeTab[0].tail+1);
    for (i = 0; i < numEdges; i++){
        if (table[i] == -1){
                if (table[i+1] == 1){
                    printf("Outputting tree with leader %d\n",edgeTab[table[i+1]].tail+1);
                }
        }
        else{
            printf("%s %s %d \n",StringArray[edgeTab[i].tail],StringArray[edgeTab[i].head],
      edgeTab[i].weight);
        }
    }
    free(edgeTab);
    free(parent);
    free(weight);
    free(StringArray);
    return 0;
}
