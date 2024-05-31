#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int n, num_procs, rank, value, sum;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if (rank==0) {
        printf("Enter the number to be broadcasted: (0 quits)");
        scanf("%d", &n);
    }

    MPI_Bcast(&n, 1, MPI_INT,0, MPI_COMM_WORLD);
    printf("%d:\tRank %d received value %d\n", rank+1, rank+1, n);
    value = n*2;
    MPI_Reduce(&value, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank==0) {
        printf("Sum = %d \n", sum);
    }
    MPI_Finalize();
}