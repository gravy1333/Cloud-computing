#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "mpi.h"
#define num 100000
int vect1[num];

int main(int argc, char *argv[]) {
	unsigned long int i, n=(unsigned long int)num;
	double totsum,locsum =0.0;
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	for (i=rank; i<n; i+=size) vect1[i] = (i+1);
	double start = MPI_Wtime();
	for (i=rank; i<n; i+=size) {
		locsum += (double)vect1[i];
	}
	MPI_Reduce(&locsum,&totsum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	double end = MPI_Wtime();
	printf("Local Sum on proccess #%d is %f.\n",rank,locsum);
	if (rank==0){
		double t = (end-start);
		printf("The total sum is %f.\n",totsum);
		printf("Time is %f secs.\n",t);
	}
	MPI_Finalize();
	return 0;
}
