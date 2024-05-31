To set the number of processors for running your MPI application to 4, you typically do this at runtime rather than in the `CMakeLists.txt` file, as the number of processors is an execution-time parameter rather than a build-time configuration. However, if you want to integrate this configuration into your CMake setup, you can create a custom command that includes the execution configuration.

Here is how you can modify your `CMakeLists.txt` to include a custom target for running the application with 4 processors:

```cmake
cmake_minimum_required(VERSION 3.22)
project(Barrier_Broadcast C)

set(CMAKE_C_STANDARD 11)

# Find MPI package
find_package(MPI REQUIRED)

# Set the compiler to mpicc
set(CMAKE_C_COMPILER mpicc)

# Include MPI headers
include_directories(SYSTEM ${MPI_INCLUDE_PATH})

# Add the executable
add_executable(Barrier_Broadcast broadcast-barrier.c)

# Link the MPI library
target_link_libraries(Barrier_Broadcast MPI::MPI_C)

# Add a custom target to run the MPI program with 4 processors
add_custom_target(run
    COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} 4 ${CMAKE_CURRENT_BINARY_DIR}/Barrier_Broadcast
    DEPENDS Barrier_Broadcast
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running Barrier_Broadcast with 4 processors"
)
```

Explanation of the new additions:
1. **`add_custom_target(run ...)`**: This creates a custom target named `run`. When you build this target, it will run the MPI program with 4 processors.
2. **`COMMAND ${MPIEXEC_EXECUTABLE} ${MPIEXEC_NUMPROC_FLAG} 4 ${CMAKE_CURRENT_BINARY_DIR}/Barrier_Broadcast`**: This command uses MPI's execution command with the `-n 4` flag (or its equivalent in your MPI implementation) to run the compiled executable with 4 processors.
3. **`DEPENDS Barrier_Broadcast`**: This ensures that the executable is built before attempting to run it.
4. **`WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}`**: This sets the working directory to the build directory where the executable is located.
5. **`COMMENT "Running Barrier_Broadcast with 4 processors"`**: This adds a comment that will be printed when the custom target is executed.

Now, you can build and run your application with 4 processors by running the following commands from your build directory:
```sh
cmake --build . --target Barrier_Broadcast
cmake --build . --target run
```

This setup ensures that your application is built and then run with the specified number of processors, all managed through CMake.