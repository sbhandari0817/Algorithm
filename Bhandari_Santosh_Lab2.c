/* Author: Santosh Bhandari ID: 1001387116
tested in omega
unizp filenames.zip
gcc.Bhandari_Satntosh_Lab2.c
a.out
*/

//Programming to perform heap merge

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void Swap_String(char* first , char* second){
    char temp[50];
    strcpy(temp, first);
    strcpy(first, second);
    strcpy (second, temp);
}
void Swap_Index(int* first, int* second){
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}
void Minheap(char** fp, int k, int no, int index[]){
    int i;
    while ((2*k) <= no){
        i = 2*k;
        if ( i < no && (strcmp(fp[i],fp[i+1]) > 0)) {
            i = (2*k)+1;
        }
        if (strcmp(fp[k],fp[i])<= 0){
            break;
        }
        Swap_String(fp[k],fp[i]);
        Swap_Index (&index[k-1],&index[i-1]);
        k = i;
    }
}

void Build_MinHeap(char**fp, int no, int index[]){
    int k;
//    /k = no/2;
    for (k=no/2; k >=1;k--){
        Minheap(fp, k, no, index);
    }
}
int main(){
	int n,i;
	FILE *key = fopen("in.dat", "r");
	FILE *Output = fopen("out.dat","w");
	fscanf(key, "%d",&n);
	char**Filenames;
	char** Data_file;
	int index[n];
	Filenames = (char**) malloc(n * sizeof(char*));
	Data_file = (char**) malloc((n+1)* sizeof(char*));
	FILE *fp[n];
    for (i = 0; i < n; i++)
        {
            Filenames[i] = (char*) malloc(50* sizeof(char));
            Data_file[i+1] = (char*) malloc(50 * sizeof(char));
            fscanf(key, "%s",Filenames[i]);
            fp[i]  = fopen(Filenames[i],"r");
            fscanf(fp[i], "%s",Data_file[i+1]);
            index[i] = i;
        }
    while (n > 0){
            char *data;
            data = (char*) malloc (50 * sizeof(char));
            int k;
            if (n > 1){
                Build_MinHeap(Data_file,n,index);
            }
            int No_ofloop;
            No_ofloop = n;
            for (i = 0; i < No_ofloop; i++){
                if (i == 0){
                    strcpy(data,Data_file[1]);
                    k = 1;
                     if (!feof(fp[index[0]])){
                         fscanf(fp[index[0]],"%s",Data_file[1]);
                         if (strcmp(data, Data_file[1]) == 0){
                            i--;
                            continue;
                         }
                         if (n > 1){
                            Build_MinHeap(Data_file,n,index);
                         }
                    }
                    else{
                             Swap_String(Data_file[1],Data_file[n]);
                             Swap_Index (&index[0],&index[n-1]);
                             n--;
                             if (n > 1){
                                Build_MinHeap(Data_file,n,index);
                             }
                    }
                }
                else{
                    if (strcmp(data, Data_file[1])== 0){
                        k++;
                        if (!feof(fp[index[0]]))
                        {
                             fscanf(fp[index[0]],"%s",Data_file[1]);
                             if (strcmp(data, Data_file[1]) == 0){
                                k--;
                                i--;
                                continue;
                             }
                             if (n > 1){
                                Build_MinHeap(Data_file,n,index);
                             }
                        }
                        else
                        {
                             Swap_String(Data_file[1],Data_file[n]);
                             Swap_Index (&index[0],&index[n-1]);
                             n--;
                             if (n > 1){
                                Build_MinHeap(Data_file,n,index);
                             }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            fprintf(Output, "%s %d\n",data, k);
			free(data);
    }
	free(Data_file);
	free(Filenames);
	return 0;
}

