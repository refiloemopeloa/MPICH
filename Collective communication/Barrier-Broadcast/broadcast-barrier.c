# include <stdio.h>
# include <mpi.h>
#include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include "../Debugging wth Varargs/debugger.c"

double timer=0;

long broadcast(int rank,int procs) {
    long random_value;
    int broadcaster_rank = procs - 1;

    if (rank == broadcaster_rank) {
        srandom(time(NULL) + rank),
        random_value = random() / (RAND_MAX / 10);
        debug(timer,rank, "broadcasting %ld\n", random_value);
    }

    MPI_Bcast((void *)&random_value,
                1,
                MPI_LONG,
                broadcaster_rank,
                MPI_COMM_WORLD);

    if (rank != broadcaster_rank) {
        debug(timer,rank, "received %ld\n", random_value);
    }

    return random_value;
}

void barrier(int rank, long random_value) {
    int nap_time = random_value + (2 * rank);
    debug(timer,rank, "sleeping %ds\n", nap_time);
    sleep(nap_time);

    debug(timer,rank, "enter b-a-r-r-i-e-r-\n");
    MPI_Barrier(MPI_COMM_WORLD);
    debug(timer,rank, "leave barrier\n");
}

int main(int argc, char **argv) {
    int num_procs;
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    start_timer(&timer);

    debug(timer,rank, "hello (p=%d)\n", num_procs);
    long random_value = broadcast(rank, num_procs);
    barrier(rank, random_value);
    debug(timer,rank, "goodbye\n");

    MPI_Finalize();

}
