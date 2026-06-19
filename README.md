# C++ Projects Workspace

This workspace contains two C++ projects implementing fundamental data structures and utility classes.

---

## Workspace Directory Structure

### 1. [sequence-proj](file:///Users/meftahulahsan/cpp_projects/sequence-proj)
An array-based implementation of a sequence container class. The sequence keeps track of a collection of items with a cursor index, allowing you to insert, attach, remove, and traverse elements.
* **[sequence1.h](file:///Users/meftahulahsan/cpp_projects/sequence-proj/sequence1.h)**: Header declaring the `sequence` class interface.
* **[sequence1.cxx](file:///Users/meftahulahsan/cpp_projects/sequence-proj/sequence1.cxx)**: Core implementation of the sequence class member functions.
* **[sequence_exam.cxx](file:///Users/meftahulahsan/cpp_projects/sequence-proj/sequence_exam.cxx)**: Automated test suite checking all invariants (scoring out of 100).
* **[sequence_test.cxx](file:///Users/meftahulahsan/cpp_projects/sequence-proj/sequence_test.cxx)**: Interactive command-line test menu to manually execute sequence operations.

### 2. [statistician-proj](file:///Users/meftahulahsan/cpp_projects/statistician-proj)
A class designed to track statistics (such as count, sum, mean, smallest, and largest values) of a series of double-precision numbers added over time.
* **[stats.h](file:///Users/meftahulahsan/cpp_projects/statistician-proj/stats.h)**: Header declaring the `statistician` class interface.
* **[stats.cxx](file:///Users/meftahulahsan/cpp_projects/statistician-proj/stats.cxx)**: Implementation of the statistician mathematical tracking functions.
* **[statexam.cxx](file:///Users/meftahulahsan/cpp_projects/statistician-proj/statexam.cxx)**: Automated test suite verifying the statistician functions.
* **[stattest.cxx](file:///Users/meftahulahsan/cpp_projects/statistician-proj/stattest.cxx)**: Interactive driver program to test statistician instances.

---

### 3. [sequence-proj-dds](file:///Users/meftahulahsan/cpp_projects/sequence-proj-dds)
Very similar to sequence-proj (1), except for the fact that it uses dynamic memory, meaning data structure resizes based on needs.
dds -> dynamic data structure
* **[sequence2.h](file:///Users/meftahulahsan/cpp_projects/sequence-proj-dds/sequence2.h)**: Header declaring the `sequence` class interface.
* **[sequence2.cxx](file:///Users/meftahulahsan/cpp_projects/sequence-proj-dds/sequence2.cxx)**: Implementation of the `sequence` class member functions.
* **[sequence_exam.cxx](file:///Users/meftahulahsan/cpp_projects/sequence-proj-dds/sequence_exam.cxx)**: Automated test suite checking all invariants (scoring out of 100).
* **[sequence_test.cxx](file:///Users/meftahulahsan/cpp_projects/sequence-proj-dds/sequence_test.cxx)**: Interactive driver program to test `sequence` instances.

## How to Compile & Run C++ Projects

To compile C++ programs using GCC, you need to compile the implementation (`.cxx` / `.cpp`) files together with the driver/test programs.

### Compiling and Running the Sequence Project

1. Navigate to the sequence directory:
   ```bash
   cd sequence-proj
   ```
2. **Automated Test Suite (`sequence_exam`):**
   * Compile:
     ```bash
     g++ -Wall -std=c++11 sequence_exam.cxx sequence1.cxx -o seqexam
     ```
   * Run:
     ```bash
     ./seqexam
     ```
3. **Interactive Test Runner (`sequence_test`):**
   * Compile:
     ```bash
     g++ -Wall -std=c++11 sequence_test.cxx sequence1.cxx -o seqtest
     ```
   * Run:
     ```bash
     ./seqtest
     ```

### Compiling and Running the Statistician Project

1. Navigate to the statistician directory:
   ```bash
   cd statistician-proj
   ```
2. **Automated Test Suite (`statexam`):**
   * Compile:
     ```bash
     g++ -Wall -std=c++11 statexam.cxx stats.cxx -o statexam
     ```
   * Run:
     ```bash
     ./statexam
     ```
3. **Interactive Test Runner (`stattest`):**
   * Compile:
     ```bash
     g++ -Wall -std=c++11 stattest.cxx stats.cxx -o stattest
     ```
   * Run:
     ```bash
     ./stattest
     ```

---

## General Compilation Flags Explained
* `g++`: The GNU C++ Compiler command.
* `-Wall`: Enables all warnings, helping you detect bugs early.
* `-std=c++11`: Specifies the C++11 language standard.
* `-o <executable_name>`: Names the output executable file.
