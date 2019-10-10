#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define num 10000000
int vect1[num];

int main(int argc, char *argv[]) {
	unsigned long int i, n=(unsigned long int)num;
	clock_t start, end;
	double totsum =0.0;
	for (i=0; i<n; i++)
    vect1[i] = (i+1);
	start = clock();
	for (i=0; i<n; i++)
    totsum += (double)vect1[i];
	end = clock();
	double time = (double)(end-start)/CLOCKS_PER_SEC;
	printf("The sum is %f.\n",totsum);
	printf("Time is %f secs.\n",time);
	return 0;
}