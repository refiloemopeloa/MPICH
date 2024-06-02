cmake_minimum_required(VERSION 3.22)
project(reduce_min_array C)

set(CMAKE_C_STANDARD 11)

# Find MPI package
find_package(MPI REQUIRED)

# Set the compiler to mpicc
set(CMAKE_C_COMPILER mpicc)

# Include MPI headers
include_directories(SYSTEM ${MPI_INCLUDE_PATH})

# Add the executable
add_executable(reduce_min_array reduce_min_array.c)

# Link the MPI library
target_link_libraries(reduce_min_array MPI::MPI_C)

# Add a custom target to run the MPI program with 4 processors
add_custom_target(run
        COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} 4 ${CMAKE_CURRENT_BINARY_DIR}/reduce_min_array
        DEPENDS reduce_min_array
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Running reduce_min_array with 4 processors"
)
