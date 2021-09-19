/* Author: Santosh Bhandari ID: 1001387116
tested in omega
gcc.Bhandari_Satntosh_Lab1.c
a.out
*/

//Start of the C program to do binary search

#include<stdio.h>
#include <stdlib.h>
typedef struct map{
	int index; //index
	int counter; //counter
}map;

int binSearchLast(map* a,int n,int key)
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
		  if (a[a[mid].index].counter<=key)
			  low=mid+1;
			else
			  high=mid-1;
		  }
		 return high;
	}
int binSearchFirst(map *data,int n,int key)
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
		if ((data[data[mid].index].counter) < key)
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
	map* data =(map*) malloc (n * sizeof(map));
	int i;
	for (i = 0; i < n; i++){
		(data + i)->index  = i;
		(data + i) ->counter = 0;
	}
	printf("\n");
	int run;
	map temp;
	int high,low, address, key,lower_bound, upper_bound,id;
	printf("\n");
	printf("Enter 0 to terminate execution\nEnter 1 to print the counters in ascending index value order as (index,count)pairs.\nEnter 2 to print the counters in ascending counter value order as (index, count)pairs.");
	printf("\nEnter 3 to add one to the counter indexed by i. \nEnter 4 to subtract one from the counter indexed by i.\nEnter 5 to determine the numbers whose values are no smaller than i and no larger than j\n");
	
	do {
		scanf("%d",&run);
		printf("\n");
		
		
		if ( run == 1)
		{
			for (i = 0; i < n; i++){
			printf("%d %d\n",i,data[data[i].index].counter);
			}
		}
		else if (run == 2)
		{
			for (i = 0; i < n ; i++)
		    {
			    printf("%d %d\n",data[i].index,data[i].counter);
		    }
		}
		else if (run == 3)
		{
			printf("Enter the index of data that you want to add: ");
			scanf("%d",&id);
			address = data[id].index;
			key = data[address].counter;
			high = binSearchLast(data,n,key);
			temp.index=data[address].index;
			data[address].index = data[high].index;
			data[high].index = temp.index; 
			temp.counter=data[address].counter;
			data[address].counter = data[high].counter;
			data[high].counter = temp.counter; 
			(data[high].counter)++;
		}
		else if (run == 4)
		{
			printf("Enter the index of data that you want to subtract: ");
			scanf("%d",&id);
			address = data[id].index;
			key = data[address].counter;
			low = binSearchFirst(data,n,key);
			temp.index=data[address].index;
			data[address].index = data[low].index;
			data[low].index = temp.index; 
			temp.counter=data[address].counter;
			data[address].counter = data[low].counter;
			data[low].counter = temp.counter; 
			data[low].counter--;
		}
		else if (run == 5)
		{
			printf("Please enter the lower bound: ");
			scanf("%d",&lower_bound);
			printf("Please enter the uppper bound: ");
			scanf("%d",&upper_bound);
			high = binSearchLast(data,n,upper_bound);
			low = binSearchFirst(data,n,lower_bound);
			int sub = (high - low +1);
			printf("Total no values between the interval %d.",sub);
		}
		printf("\n");
	}while ( run != 0);
	
	return 0;
}




