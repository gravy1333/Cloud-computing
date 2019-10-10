#include <stdio.h>
#include <time.h> 
#include "mpi.h"

int main(int argc, char *argv[]) {
	int rank,size;
	char message[22];
	MPI_Init(&argc,&argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	
	double start = MPI_Wtime();
	if (rank==0)
		strcpy(message, "Hello world, from #0!\n");
	MPI_Bcast(message,22,MPI_CHAR,0,MPI_COMM_WORLD);
	printf("Message at proccess #%2d:%.21s\n",rank,message);
	MPI_Barrier(MPI_COMM_WORLD);
	double end = MPI_Wtime();
	if (rank==0){
		printf("Time is %f seconds.\n",end-start);
	}
	MPI_Finalize();
	return 0;
}
