
#include <stdio.h>
#include <time.h>

#define m 5 
#define n 5 

int myCounter(int a[][n], int i, int j) ;

int main(void) 
{ 
	int a[m][n] = { 
		{1, 1, 0, 0, 0}, 
		{0, 1, 0, 0, 1}, 
		{0, 0, 0, 1, 1}, 
		{0, 0, 0, 0, 0}, 
		{1, 0, 1, 0, 1} 
	}; 
	int i=0,j=0,no=0; 

	clock_t start = clock();

	for(i=0;i<m;i++) 
		for(j=0;j<n;j++) 
			if(a[i][j] == 1) {
				// no += count(a,i,j); 
				no += myCounter(a, i, j);
			}

	clock_t end = clock();

	printf("count = %d\n",no); 
	printf("Time Taken = %lu\n", end-start);
	return 0; 
} 

int myCounter(int a[][n], int i, int j)  {

	// since we found one 1, we know that its an island.
	// now we need to reset all the 1's for this island so that we can identify all other island uniquely.

	// we can work on multiple different directions.
	// check right
	if( j+1 < n && a[i][j+1] == 1 ) {
		a[i][j+1] = 0;
		myCounter(a, i, j+1);
	}

	// check left
	if( -1 < j-1 && a[i][j-1] == 1) {
		a[i][j-1] = 0;
		myCounter(a, i, j-1);
	}

	// check up
	if( -1 < i-1 && a[i-1][j] == 1 ) {
		a[i-1][j] = 0;
		myCounter(a, i-1, j);
	}

	// check down
	if( i+1 < m && a[i+1][j] == 1) { 
		a[i+1][j] = 0;
		myCounter(a, i+1, j);
	}

	return 1;
}