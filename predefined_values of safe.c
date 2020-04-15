/* Question 19--There are 5 processes and 3 resource types,
   resource A with 10 instances, B with 5 instances and C with 7 instances.
   Consider following and write a c code to find whether the system is in safe state or not?

    Available       Processes        Allocation             Max
    A   B   C                       A    B    C         A    B    C  
    3   3   2          P0           0    1    0         7    5    3  
                       P1           2    0    0         3    2    2  
                       P2           3    0    2         9    0    2
                       P3           2    1    1         2    2    2  
                       P4           0    0    2         4    3    3                                                                        */


#include <stdio.h> 
int main() 
{ 
	// P0, P1, P2, P3, P4 are the Process names here 

	int n, m, i, j, k; ///declaration of variables
	n = 5; // Indicates the total number of processes of the system
	m = 3; // Indicates the total number of resources in the system
	int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix 
						{ 2, 0, 0 }, // P1 // Indicates where the process you have received a resource
						{ 3, 0, 2 }, // P2 
						{ 2, 1, 1 }, // P3 
						{ 0, 0, 2 } }; // P4 

	int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix 
					{ 3, 2, 2 }, // P1 
					{ 9, 0, 2 }, // P2 
					{ 2, 2, 2 }, // P3 
					{ 4, 3, 3 } }; // P4 

	int avail[3] = { 3, 3, 2 }; // Available Resources 

	int f[n], ans[n], ind = 0; 
	for (k = 0; k < n; k++) {   //Sorting the process
		f[k] = 0; 
	} 
	int need[n][m];                 //Express how many more resources can be allocated in future
	for (i = 0; i < n; i++) {        //Sorting the process
		for (j = 0; j < m; j++)     //Sorting the process
			need[i][j] = max[i][j] - alloc[i][j];    //Need= maximum resources - currently allocated resources
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < m; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < m; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 

	printf("Following is the SAFE Sequence\n"); 
	for (i = 0; i < n - 1; i++) 
		printf(" P%d ->", ans[i]);              //Sorting the process for safe state.
	printf(" P%d", ans[n - 1]);                 //Printing all hte process in safe state order

	return (0); 

} 

