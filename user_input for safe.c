/* Question 19--There are 5 processes and 3 resource types,
   resource A with 10 instances, B with 5 instances and C with 7 instances.
   Consider following and write a c code to find whether the system is in safe state or not?

    Available       Processes        Allocation             Max
    A   B   C                       A    B    C         A    B    C  
    3   3   2          P0           0    1    0         7    5    3  
                       P1           2    0    0         3    2    2  
                       P2           3    0    2         9    0    2
                       P3           2    1    1         2    2    2  
                       P4           0    0    2         4    3    3                                                                           */

#include<stdio.h>
int main()
{
	int num;
	int n;
	int i,j,k,c,c1;
	int avail[20],arr[10];
	int need[20][20],alloc[20][20],max[20][20];
	
	printf("\nEnter number of processes :");
	scanf("%d",&num);
	
	printf("\nEnter the number of resources available :");
	scanf("%d",&n); 
	
	printf("\nEnter instances for resources(Press enter after entering each integer value) :\n");
	for(i=0;i<n;i++)
	{
		printf("R%d    ",i+1);
		scanf("%d",&avail[i]);
	}
	printf("\n Enter allocation matrix(INTEGER) with one space after each integer  \n");   //Allocation Matrix
	printf("\n       A B C \n");            //For pretty formatting output
	for(i=0;i<num;i++)
	{
		printf("p%d     ",    i);          arr[i]=0;       //to print the process number
		for(j=0;j<n;j++)
		{
			scanf("%d",    &alloc[i][j]);
		}
	}
	printf("\n Enter MAX matrix(INTEGER) with one space after each integer  \n");        //MAX Matrix
	printf("\n       A B C \n");           //For pretty formatting output
	for(i=0;i<num;i++)                                 //Sorting the process
	{
		printf("p%d     ",    i);                          //to print the process number
		for(j=0;j<n;j++)                                   //Sorting the process
		{
			scanf("%d",&max[i][j]);
		}
	}
	for(i=0;i<num;i++)                                 //Sorting the process
	{
		printf("\np%d\t",i) ;
		for(j=0;j<n;j++)                                   //Sorting the process
		{
			need[i][j]=max[i][j]-alloc[i][j];                 //Need= maximum resources - currently allocated resources
			printf("\t%d",need[i][j]);
		}
	}
	k=0;     c1=0;
	printf("\n\n");
	while(k<15)
	{
		for(i=0;i<num;i++)                                 //Sorting the process
		{
			c=0;
			for(j=0;j<n;j++)                                   //Sorting the process
			{
				if(arr[i]==1) break;
				if(need[i][j]<=avail[j])
				{
					c++;
				}
				if(c==n)
				{
					for(j=0;j<n;j++)
					{
						avail[j]+=alloc[i][j];
					}
					printf("p%d\t ->",i);  arr[i]=1;     c1++;
				}
			}
		}
		k++;
	}
}
