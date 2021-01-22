/* Author :- Santosh Bhandari
ID: 1001387116
Syntax that I used to run this code on omega
gcc Bhandari_Santosh_lab3.cab
a.out //to enter data manually
./a.out < filename //to read data from the file
*/
#include <stdio.h>
#include <stdlib.h>

void subsetSum(int n,int t1, int t2,int* S,int** C)
{
int j,potentialSum,leftover,potentialSum2;
C[0][0]=0;
for (potentialSum=1; potentialSum<=t1; potentialSum ++)
    {
       for (j=1;j<=n;j++)
      {
        leftover=potentialSum-S[j];
        if (leftover>=0 && C[leftover][0]<j){
            break;
        }
      }
        C[potentialSum][0]=j;
    }

for (potentialSum=1; potentialSum<=t2; potentialSum ++)
{
  for (j=1;j<=n;j++)
  {
    leftover=potentialSum-S[j];
    if (leftover>=0 &&
      C[0][leftover]<j)
      break;
  }
  C[0][potentialSum]=j;
}
for (potentialSum2= 1; potentialSum2 <= t1; potentialSum2++){
    for (potentialSum=1; potentialSum<=t2; potentialSum ++)
    {
       for (j=1;j<=n;j++)
      {
            if(((potentialSum2 - S[j]) >=0 && C[potentialSum2 - S[j]][potentialSum] < j)||((potentialSum - S[j]) >=0 && C[potentialSum2][potentialSum - S[j]]<j)){
                        break;
                }

        }

        C[potentialSum2][potentialSum]=j;
    }

}
}

void writeOutput(int n,int t1,int t2, int* S,int** C)
{
int i;

// Output the input set
printf("  i   S\n");
printf("-------\n");
for (i=0;i<=n;i++)
  printf("%3d %3d\n",i,S[i]);

// Output the backtrace
if (C[t1][t2]==n+1)
  printf("No solution\n");
else
{
    int valuefortarget1[n];
    int valuefortarget2[n];
    int count1 = 0;
    int count2 = 0;
    int d1 = t1;
    int d2 = t2;
    int hv = 0;
    while (t1 != 0 || t2 != 0) {
        if (hv == 0){
            if (t1 - S[C[t1][t2]] >=0 && C[t1 -S[C[t1][t2]]][t2] < n){
                valuefortarget1[count1] = S[C[t1][t2]];
                count1++;
                t1 = t1 -S[C[t1][t2]];
            }
            else{
                hv = 1;
            }
        }
        else{
           if (t2 - S[C[t1][t2]] >=0 && C[t1][t2-S[C[t1][t2]]] < n){
                valuefortarget2[count2] = S[C[t1][t2]];
                count2++;
                t2 = t2 -S[C[t1][t2]];
            }
            else{
                hv = 0;
            }
        }
    }
   printf("Subsequence for %d is\n",d1);
   for (i = 0; i < count1; i++){
        printf("\t%d\n",valuefortarget1[i]);
   }
   printf("Subsequence for %d is\n",d2);
   for (i =0; i < count2; i++){
        printf("\t%d\n",valuefortarget2[i]);
   }
}
}

int main()
{
int n;    // Size of input set
int t1; // target value 1
int t2;   // Target value
int *S;   // Input set
int **C;   // Cost table

int i;

scanf("%d",&n);
scanf("%d",&t1);
scanf("%d",&t2);

S=(int*) malloc((n+1)*sizeof(int));
C=(int**) malloc((t1+1)*sizeof(int*));
for (i = 0; i < (t1+1);i++){
    (C[i]) = (int*) malloc((t2+1)*sizeof(int));
}
if (!(S) || !(C))
{
  printf("malloc failed %d\n",__LINE__);
  exit(0);
}

(S)[0]=0;                // Sentinel zero
for (i=1;i<=n;i++)
  scanf("%d",S+i);

subsetSum(n,t1,t2,S,C);

writeOutput(n,t1,t2,S,C);

free(S);
free(C);
}
