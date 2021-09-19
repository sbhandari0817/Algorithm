
int binarySearch(int arr*, int index, int first , int last)

{

if (r >= l)

{

int mid = l + (r - l)/2;

// If the element is present at the middle

// itself

if (arr[mid] == x)

return mid;

// If element is smaller than mid, then

// it can only be present in left subarray

if (arr[mid] > x)

return binarySearch(arr, l, mid-1, x);

// Else the element can only be present

// in right subarray

return binarySearch(arr, mid+1, r, x);

}

// We reach here when element is not

// present in array

return -1;

}

int main()

{

int counter[1000];

int n,p;

printf("Enter the value of n\n");

scanf("%d",&n); //input n from user

for(int i=0;i<n;i++) //initializing all the values of counter to 0

counter[i]=0;

printf("\n0- terminate\n");

printf("1- print the counters in ascending index\n");

printf("2- print the counters in ascending counter value order as (index, count) pairs.\n");

printf(" 3 i - add one to the counter indexed by i. (O(log n) time\n");

printf("4 i - subtract one from the counter indexed by i. (O(log n) time\n");

printf("5 i j - determine the number of counters whose values are no smaller than i and no larger than j. \n");

while(1)

{

printf("\nSelect the appropriate option\n");

scanf("%d",&p);

if(p==0)

{

printf("Oops! program terminated");

break;

}

else if(p==1)

{

printf("\ncounters in ascending index as (index, count) pairs is:\n");

for(int i=0;i<n;i++)

printf("%d %d\n",i,counter[i]);

}

else if(p==2)

{

for(int i=0;i<n;i++)

{

counter1[i].x=counter[i];

counter1[i].y=i;

}

printf("\ncounters in ascending counter value order as (index, count) pairs\n");

for (int i = 1; i < n; i++)

{

for (int j = 0; j < n - i; j++)

{

if (counter1[j].x > counter1[j+1].x)

{

var1 = counter1[j];

counter1[j] = counter1[j + 1];

counter1[j + 1] = var1;

}

}

}

for(int i=0;i<n;i++)

printf("%d %d\n",counter1[i].y ,counter1[i].x);

}

else if(p==3)

{

int u;

printf("\nEnter the position where increment is to be done\n");

scanf("%d",&u);

counter[u]++;

printf("Increment Successful\n");

}

else if(p==4)

{

int u;

printf("\nEnter the position where decrement is to be done\n");

scanf("%d",&u);

counter[u]--;

printf("Decrement Successful\n");

}

else if(p==5)

{

int u,v;

printf("\nEnter the positions of i & j\n");

scanf("%d%d",&u,&v);

int countt[1000];

for(int i=0;i<n;i++)

countt[i]=counter[i];

qsort(countt , countt+n);

int val= binarySearch(counter, 0, n-1, u);

int val1= binarySearch(counter, 0, n-1, v);

int value=(val1-val);

printf("\nThe no of counters is %d\n",value);

}

else

printf("\nIncorrect choice\n");

}

}