#include <stdarg.h>
#include <stdio.h>
#include <mpi.h>

void start_timer(double *time){
    *time = MPI_Wtime();
}

double get_time(double *time){
    return MPI_Wtime() - *time;
}

void debug(double time, int rank, char *format, ...)
{

    va_list args; // Variable argument list

    va_start(args, format); // Initialize variable argument list
                            //  format is the last argument before ...
                            //  tells stac how to find unknown number of arguments

    printf("%12.6f|%2d|", get_time(&time), rank);
    vprintf(format, args);

    va_end(args);
}
