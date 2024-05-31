cmake_minimum_required(VERSION 3.22)
project(Scatter C)

set(CMAKE_C_STANDARD 11)

# Find MPI package
find_package(MPI REQUIRED)

# Set the compiler to mpicc
set(CMAKE_C_COMPILER mpicc)

# Include MPI headers
include_directories(SYSTEM ${MPI_INCLUDE_PATH})

# Add the executable
add_executable(Scatter Scatter.c)

# Link the MPI library
target_link_libraries(Scatter MPI::MPI_C)

# Add a custom target to run the MPI program with 4 processors
add_custom_target(run
        COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} 4 ${CMAKE_CURRENT_BINARY_DIR}/Scatter
        DEPENDS Scatter
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Running Scatter with 4 processors"
)
