//
// Created by matth on 2024/05/21.
//
# include <mpi.h>
# include <stdio.h>
# include <time.h>
#include <stdlib.h>
#include <limits.h>

void round_robin(int rank, int procs, FILE *fptr) {
           //this processors random value
    long int rand_mine, rand_prev; //random values
                      //random value received from previous processor
    int rank_next = (rank + 1) % procs; //the rank of the next processor
                             //modulo ensures number of processors always remains within the number of procs
    int rank_prev = rank == 0 ? procs - 1 : rank -1; //the rank of the previous processor
                  //if my rank is 0, then rank_prev=procs-1, else, rank_prev=rank-1
    MPI_Status status;

    srandom(time(NULL) + rank);//seed the random value
    rand_mine = random() / (RAND_MAX / 100);
    fprintf(fptr,"%d: random is %ld\n", rank, rand_mine);

    if (rank%2==0){//if the processors are even, send first, then receive
    fprintf(fptr,"%d: sending %ld to %d\n", rank, rand_mine, rank_next);
                               //number of longs to send //tag is 1
    MPI_Send((void *)&rand_mine, 1, MPI_LONG, rank_next, 1, MPI_COMM_WORLD);
            //buffer              //sending a long //destination is rank_next
    fprintf(fptr,"%d: receiving from %d\n", rank, rank_prev);
        //number of longs to send //tag is 1
    MPI_Recv((void *)&rand_prev, 1, MPI_LONG, rank_prev, 1, MPI_COMM_WORLD, &status);
        //buffer              //receiving a long //source is rank_prev     //status of communication
    }else {
    fprintf(fptr,"%d: receiving from %d\n", rank, rank_prev);
    MPI_Recv((void *)&rand_prev, 1, MPI_LONG, rank_prev, 1, MPI_COMM_WORLD, &status);

    fprintf(fptr,"%d: sending %ld to %d\n", rank, rand_mine, rank_next);
    MPI_Send((void *)&rand_mine, 1, MPI_LONG, rank_next, 1, MPI_COMM_WORLD);

    }

    fprintf(fptr,"%d: >> I had %ld, %d had %ld\n", rank, rand_mine, rank_prev, rand_prev);
}
int main(int argc, char **argv)
{
    int num_procs;
    int rank;
    FILE *fptr;
    fptr = fopen("output.txt","w");

    fptr = fopen("output.txt","a");
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    fprintf(fptr,"%d: Hello World from communicator %d of %d!\n", rank, rank, num_procs);
    round_robin(rank, num_procs, fptr);


    MPI_Finalize();

    fclose(fptr);
}

