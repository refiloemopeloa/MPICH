# MPICH
 Message passing interface programs

# Terminology

## MPI

-   Message Passing Interface
-   Each active MPI process executes its own copy of the program

## Communication domain

-   groups of processes that can communicate with each other
-   stored in communicator
-   comminucator type:
    ```
    MPI_Comm
    ```
-   Default:
    ```
    MPI_COMM_WORLD
    ```
    includes all the processes

# Set up

## Installing MPI

### MPICH

```
sudo apt-get install libmpich-dev
```

# Documentation

## Set up

Set up our parallel environment

```
int MPI_Init(int *argc,
             char ***argv);
```

-   `int *argc`

    number of arguments passed from command line

-   `int ***argv`

    array of arguments passed from command line

MPI will take its arguments from the command line arguments and remove them from the list of arguments

## Tear down

Close the parallel environment

```
int MPI_Finalize();
```

Returns a status code

> `MPI_SUCCESS`

or

> `MPI_ERROR`

## Total Processes

Get number of communicators (processors)

```
int MPI_Comm_size(MPI_Comm comm,
                  int *size);
```

## Local process index

Get index of current communicator

```
int MPI_Comm_rank(MPI_Comm com,
                  int *rank);
```

## Function Prototypes

Get time

```
double MPI_Wtime();
```

Get time interval

```
double MPI_Wtick();
```

# Communication

## Point to Point Communication

### Send messages

```
int MPI_Send(void *buf,
             int count,
             MPI_Datatype datatype,
             int dest,
             int tag,
             MPI_Comm comm)
```

> `void *buf`

where to get stuff from memory

> `int count`

number of some primitive element in our buffer, determined by `datatype`

> `MPI_Datatype datatype`

primitve datatype

-   `MPI_CHAR`
-   `MPI_INT`
-   `MPI_FLOAT`
-   `MPI_BYTE`

and many more

> `int dest`

rank of process we are sending buffer to

> `int tag`

used to distinguish messages from each other

> `MPI_Comm comm`

communicators in environment

### Receive messages

```
int MPI_Recv(void *buf,
             int count,
             MPI_Datatype datatype,
             int source,
             int tag,
             MPI_Comm comm,
             MPI_Status *status)
```

> `void *buf`

where to store stuff in memory

> `int count`

number of some primitive element in our buffer, determined by `datatype`

> `MPI_Datatype datatype`

primitve datatype

-   `MPI_CHAR`
-   `MPI_INT`
-   `MPI_FLOAT`
-   `MPI_BYTE`

and many more

> `int source`

rank of process we are receiving buffer from

> `int tag`

used to distinguish messages from each other

> `MPI_Comm comm`

communicators in environment

> `MPI_Status *status`

status of communication

### Status

```
typedef strcut MPI_Status {
    int MPI_SOURCE;
    int MPI_TAG
    int MPI_ERROR;
}
```

### Simultaneous Send-Receive

```
int MPI_Sendrecv(
            // send group
                void *sendbuf,  //send buffer pointer
                int sendcount,  // number of elements being sent
                MPI_Datatype senddatatype,  // sent data type
                int dest,   //destination rank
                int sendtag,    //tag

            // receive group
                void *recvbuf,  //received buffer
                int recvcount,  //number of elements being received
                MPI_Dataype recvdatatype,   //received data type
                int source, //sending rank
                int recvtag,    //tag
            // communicator group
                MPI_Comm comm,  //communicator
                MPI_Status *status);    //status
```

### Non-Blocking Communication

Computation can proceed concurrently with send and receive. no need to wait to send or receive.

#### Non-blocking send

-   Start send operation
-   Return before data is copied from buffer

```
int MPI_Isend(void *buf,    //address of data being sent
              int count,    //how many of that data is being sent
              MPI_Datatype, //data type of that data
              int dest,     //destination process
              int tag,      //tag
              MPI_Comm comm,    //communicator
              MPI_Request *request);    //information about progress
```

#### Non-blocking receive

-   Start receive operation
-   Return before data is received and copied to buffer

```
int MPI_Irecv(void *buf,
              int count,
              MPI_Datatype,
              int source,
              int tag,
              MPI_Comm comm,
              MPI_Request *request);
```

#### Await non-blocking communication

```
int MPI_Test(MPI_Request *request,
             int *flag,
             MPI_Status *status);
```

-   Test whether request is complete
-   Non-blocking

```
int MPI_Wait(MPI_Request *request,
             MPI_Status *status);
```

-   Wait for request to complete
-   Blocking

```
int MPI_Waitall(int count,
                MPI_Request array_of_requests[],    //array of all requests
                int *flag,  //true if all requests are complete, false otherwise
                MPI_Status array_of_statuses[]);    //array of statuses
```

## Collective communication

### Barrier

```
int MPI_Barrier(MPI_Comm comm);
```

Puts a barrier that prevents every process from continuing until all processes have reached the barrier

#### Broadcast

```
int MPI_Bcast(void *buf,
              int count,
              MPI_Datatype datatype,
              int source,
              MPI_Comm comm);
```

Broadcast buffer from this processor (source) to all other processors

### Reduction

```
int MPI_Reduce(void *sendbuf,   //send buffer
               void *recvbuf,   //receive buffer
               int count,   //number of elements in send buffer
               MPI_Datatype datatype,   //data type of elements in send buffer
               MPI_Op op,   //reduce operation
               int target,  //rank of root process
               MPI_Comm comm);
```

#### Operations

-   `MPI_MAX`
-   `MPI_MIN`
-   `MPI_SUM`
-   `MPI_PROD`
-   and more...

### All reduce

```
int MPI_Allreduce(void *sendbuf,
                  void *recvbuf,
                  int count,
                  MPI_Datatype datatype,
                  MPI_Op op,
                  MPI_Comm comm);
```

-   Reduces value to all processes
-   Equivalent to reduce then broadcast

### Scatter

```
int MPI_Scatter(void *sendbuf,  //address of send buffer
                int sendcount,  //number of elements in send buffer
                MPI_Datatype senddatatype,  //datatype of elements in send buffer
                void *recvbuf,  /address of receive buffer
                int recvcount,  //number of elements in receive buffer
                MPI_Datatype recvdatatype,  //datatype of elements in receive buffer
                int source, //rank of sending process
                MPI_Comm comm); //communicator
```

Sends chunks of an array to different processes

### Scan

```
int MPI_Scan(void *sendbuf,
             void *recvbuf,
             int count,
             MPI_Datatype datatype,
             MPI_Op op,
             MPI_Comm comm
);
```

Performs a reduction on every process up to and including that process

-   process 0 will only perform reduction on 0
-   process 1 will perform reduction on 0 and 1
-   process 2 will perform reduction on 0, 1, and 2
