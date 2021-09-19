/* Author: Santosh Bhandari ID: 1001387116
tested in omega
gcc.Sbhandari_Lab1.c
a.out
*/

//Start of the C program to do binary search

#include<stdio.h>
#include <stdlib.h>
typedef struct inco{
	int index; //index
	int count; //count
}inco;
void swapdata(inco *data,int high,int id){
	inco temp=data[id];
	data[id] = data[high];
	data[high] = temp;
	
}
void swaparray(int arr[],int a, int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
	
}
int binSearchLast(inco* a,int n,int key)
	{
		// Input: int array a[] with n elements in ascending order.
		//        int key to find.
		// Output: Returns subscript of the last a element <= key.
		//         Returns -1 if key<a[0].
		// Processing: Binary search.
		  int low,high,mid;
		  low=0;
		  high=n-1;
		// subscripts between low and high are in search range.
		// size of range halves in each iteration.
		// When low>high, low==high+1 and a[high]<=key and a[low]>key.
		  while (low<=high)
		  {
			mid=(low+high)/2;
			if (a[mid].count<=key)
			  low=mid+1;
			else
			  high=mid-1;
		  }
		 return high;
	}
int binSearchFirst(inco *data,int n,int key)
{
	// Input: int array a[] with n elements in ascending order.
	//        int key to find.
	// Output: Returns subscript of the first a element >= key.
	//         Returns n if key>a[n-1].
	// Processing: Binary search.
    int low,high,mid;
    low=0;
    high=n-1;
	// Subscripts between low and high are in search range.
	// Size of range halves in each iteration.
	// When low>high, low==high+1 and a[high]<key and a[low]>=key.
    while (low<=high)
    {
		mid=(low+high)/2;
		if (data[mid].count < key)
        low=mid+1;
		else
        high=mid-1;
  }
  return low;
}

int main (){
	printf("Enter the no of data that you want to enter: ");
	int n;
	scanf("%d",&n);
	inco* data =(inco*) malloc (n * sizeof(inco));
	int *map=(int*)malloc(n*sizeof(int));
	int i;
	for (i = 0; i < n; i++){
		(data + i)->index  = i;
		(data + i) ->count = 0;
		map[i]=i;
	}
	/*
	
	}
	printf("\n");
	
	*/
	int run;
	int high,low, address, key,lower_bound, upper_bound,id, map_index1, map_index2;
	printf("\n");
	printf("Enter 0 to terminate execution\nEnter 1 to print the counters in ascending index value order as (index,count)pairs.\nEnter 2 to print the counters in ascending count value order as (index, count)pairs.");
	printf("\nEnter 3 to add one to the count indexed by i. \nEnter 4 to subtract one from the count indexed by i.\nEnter 5 to determine the numbers whose values are no smaller than i and no larger than j\n");
	
	do {
		scanf("%d",&run);
		//printf("\n");
		
		//Running conditional statements to run the function that user want to run
		if ( run == 1)
		{
			printf("\nPrinting the counters in ascending index value order as (index, count) pairs\n");
			for (i = 0; i < n; i++){
			printf("%d %d\n",i,data[map[i]].count);
			}
		}
		else if (run == 2)
		{
			printf("\nPrinting the counters in ascending counter value order as (index, count) pairs\n");
			for (i = 0; i < n ; i++)
		    {
			    printf("%d %d\n",data[i].index,data[i].count);
		    }
		}
		else if (run == 3)
		{
			//printf("Enter the index of data that you want to add: ");
			scanf("%d",&id);
			key=data[map[id]].count;
			high=binSearchLast(data,n,key);
			
			map_index1=data[map[id]].index;
			map_index2=data[high].index;
			swapdata(data,map[id],high);
			swaparray(map,map_index1,map_index2);
			data[high].count++;
			
		}
		else if (run == 4)
		{
			//printf("Enter the index of data that you want to subtract: ");
			scanf("%d",&id);
			key=data[map[id]].count;
			low=binSearchFirst(data,n,key);
			map_index1=data[map[id]].index;
			map_index2=data[low].index;
			swapdata(data,map[id],low);
			swaparray(map,map_index1,map_index2);
			data[low].count--;
		}
		else if (run == 5)
		{
			
			scanf("%d",&lower_bound);
			
			scanf("%d",&upper_bound);
			high = binSearchLast(data,n,upper_bound);
			low = binSearchFirst(data,n,lower_bound);
			int sub = (high - low +1);
			printf("Total no values between the interval is %d.\n",sub);
		}
		
	}while ( run != 0);
	
	return 0;
}




