//
// Created by matth on 2024/05/18.
//
# include <mpi.h>
# include <stdio.h>

int main(int argc, char **argv)
{
    int num_procs;
    int rank;

    //Set up environment
    MPI_Init(&argc, &argv);
    //Get communicator size (number of processors in environment
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    //Get rank of current communicator
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("Hello World from communcator %d of %d!\n", rank, num_procs);

    //Close parallel environment
    MPI_Finalize();
}