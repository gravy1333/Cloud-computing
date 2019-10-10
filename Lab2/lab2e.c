#include <stdio.h>
#include <time.h> 
#include "mpi.h"

int main(int argc, char *argv[]) {
	int rank,size, type=99;
	char m1[23], m2[23];
	MPI_Status status;
	MPI_Init(&argc,&argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	
	double start = MPI_Wtime();
	sprintf(m2,"hello, droz from #%2d!\n",rank);
	if (rank==0){
		MPI_Send(m2,24,MPI_CHAR,1,type,MPI_COMM_WORLD);
		printf("Message at proc #%d: %.22s\n", rank,m1);
	}	else if(rank==1) {
		MPI_Recv(m1,24,MPI_CHAR,0,type,MPI_COMM_WORLD,&status);
		printf("Message at proc #%d: %.22s\n", rank,m1);
		MPI_Send(m2,24,MPI_CHAR,2,type,MPI_COMM_WORLD);
	}	else if(rank==2) {
		MPI_Recv(m1,24,MPI_CHAR,1,type,MPI_COMM_WORLD,&status);
		printf("Message at proc #%d: %.22s\n", rank,m1);
		MPI_Send(m2,24,MPI_CHAR,3,type,MPI_COMM_WORLD);
	}	else if(rank==3) {
		MPI_Recv(m1,24,MPI_CHAR,2,type,MPI_COMM_WORLD,&status);
		printf("Message at proc #%d: %.22s\n", rank,m1);
		MPI_Send(m2,24,MPI_CHAR,4,type,MPI_COMM_WORLD);
	}	else if(rank==4) {
		MPI_Recv(m1,24,MPI_CHAR,3,type,MPI_COMM_WORLD,&status);
		printf("Message at proc #%d: %.22s\n", rank,m1);
		MPI_Send(m2,24,MPI_CHAR,5,type,MPI_COMM_WORLD);
	}	else if(rank==5) {
		MPI_Recv(m1,24,MPI_CHAR,4,type,MPI_COMM_WORLD,&status);
		printf("Message at proc #%d: %.22s\n", rank,m1);
		MPI_Send(m2,24,MPI_CHAR,6,type,MPI_COMM_WORLD);
	}	else if(rank==6) {
		MPI_Recv(m1,24,MPI_CHAR,5,type,MPI_COMM_WORLD,&status);
		printf("Message at proc #%d: %.22s\n", rank,m1);
		MPI_Send(m2,24,MPI_CHAR,7,type,MPI_COMM_WORLD);
	}	else if(rank==7) {
		MPI_Recv(m1,24,MPI_CHAR,6,type,MPI_COMM_WORLD,&status);
		printf("Message at proc #%d: %.22s\n", rank,m1);
	}
	MPI_Barrier(MPI_COMM_WORLD);
	double end = MPI_Wtime();
	if (rank==0){
		printf("Time Elapsed is %f seconds.\n",end-start);
	}
	MPI_Finalize();
	return 0;
}
