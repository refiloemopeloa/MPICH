# include <stdio.h>
# include <stdlib.h>
# include <mpi.h>

int *get_random_list(int size, int seed) {
    srand(seed * 2);
    int *array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (size * size);
    }
    return array;
}

int main(int argc, char **argv) {
    int num_procs, rank;
    char end;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int *array_before = get_random_list(4, rank);
    int *array_after = get_random_list(4, rank);


    printf("Elements on process %d before scan :\n", rank);
    for (int i = 0; i < 4; i++) {
        printf("%d |\t", array_before[i]);
    }

    MPI_Reduce(array_before, array_after, 4, MPI_INT, MPI_MIN,0, MPI_COMM_WORLD);

    printf("Elements on process %d after scan :\n", rank);
    for (int i = 0; i < 4; i++) {
        printf("%d |\t", array_after[i]);
    }

    printf("To end program, press enter\n");
    scanf("%c", &end);

    MPI_Finalize();
}
