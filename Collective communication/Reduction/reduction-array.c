//
// Created by matth on 2024/05/31.
//
#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int n, num_procs, rank, value[4], sum[4];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        printf("Enter the number to be broadcasted: (0 quits)");
        scanf("%d", &n);
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("%d:\tRank %d received value %d\n", rank + 1, rank + 1, n);
    for (int i = 0; i < num_procs; i++) {
        value[i] = n * (2 + i);
        printf("%d:\tValue of array at index %d:\t%d\n", rank, i, value[i]);
    }
    MPI_Reduce(&value, &sum, 4, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        for (int i = 0; i < num_procs; i++) {
            printf("Sum = %d \n", sum[i]);
        }
    }
    MPI_Finalize();
}
