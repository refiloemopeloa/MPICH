# include <stdio.h>
# include <mpi.h>
#include <stdlib.h>
# include <time.h>
# include "../Debugging wth Varargs/debugger.c"


long broadcast(int rank,int procs) {
    long random_value;
    int broadcaster_rank = procs - 1;

    if (rank == broadcaster_rank) {
        srandom(time(NULL) + rank),
        random_value = random() / (RAND_MAX / 10);
        debug(rank, "broadcasting %ld\n", random_value);
    }

    MPI_Bcast((void *)&random_value,
                1,
                MPI_LONG,
                broadcaster_rank,
                MPI_COMM_WORLD);

    if (rank != broadcaster_rank) {
        debug(rank, "received %ld\n", random_value);
    }

    return random_value;
}

int main(int argc, char **argv) {
    int num_procs;
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    debug(rank, "hello (p=%d)\n", num_procs);
    long random_value = broadcast(rank, num_procs);
    // barrier(rank, random_value);
    debug(rank, "goodbye\n");

    MPI_Finalize();

}
