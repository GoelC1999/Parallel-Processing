#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpi.h>
const int mod = 1e4;
int main(){
double x,y,z;
int rank,size,inc= 1;
int inside = 0,total = 0,cnt = 0;
MPI_Init(NULL,NULL);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
srand(123123 + rank);
for(int i =0;i<10000;i++){
 x = (double)rand()/RAND_MAX;
 y = (double)rand()/RAND_MAX;
 z = x*x+y*y;
if(z<=1){
	cnt++;}}
MPI_Reduce(&cnt,&total,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
if(rank == 0){
printf("%f ",(double)4*total/(10000*size));
}

MPI_Finalize();
return 0;
}
