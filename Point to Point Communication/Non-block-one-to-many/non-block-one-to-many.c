#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
# include "../Debugging wth Varargs/debugger.c"

double timer = 0;

void await_request(int rank, MPI_Request *request) {
#if BUSY_WAIT
    int wait_count = 0;
    int flag = 0;
    MPI_Status status;

    do {
        wait_count++;
        MPI_Test(request, &flag, &status);
    } while (!flag);

    debug(timer, rank, "tested %d times\n", wait_count);
#endif

}


void send_to_many(int num_procs) {
    long rand_value = random() / (RAND_MAX / 100);
    debug(timer, 0, "random value is %ld\n", rand_value);

    MPI_Request send_request;

    for (int to_rank = 1; to_rank < num_procs; to_rank++) {
        long value_sent = rand_value + to_rank;

        MPI_Isend((void *) &value_sent, 1, MPI_LONG, to_rank, 1, MPI_COMM_WORLD, &send_request);

        await_request(0, &send_request);
        debug(timer, 0, "send %ld to %d\n", value_sent, to_rank);
    }
}

void receive_from_one(int rank) {
    long recv_buffer;
    MPI_Request recv_request;

    MPI_Irecv((void *) &recv_buffer, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD, &recv_request);

    await_request(rank, &recv_request);

    debug(timer, rank, "got value %ld\n", recv_buffer);
}

int main(int argc, char **argv) {
    int num_procs;
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    start_timer(&timer);

    srandom(time(NULL) + rank);

    debug(timer, rank, "HELLO (p=%d)\n", num_procs);
    if (rank == 0) {
        send_to_many(num_procs);
    } else {
        receive_from_one(rank);
    }

    debug(timer, rank, "GOODBYE\n");

    MPI_Finalize();
}
