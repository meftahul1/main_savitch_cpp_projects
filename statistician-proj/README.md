# Statistician Project

This project implements a C++ `statistician` class designed to keep track of running statistics (such as sequence length, sum, arithmetic mean, minimum, and maximum) for a sequence of real numbers.

It avoids storing the sequence of numbers in memory, calculating all metrics on-the-fly to ensure constant space complexity.

## File Structure

* **[stats.h](stats.h)**: The header file containing the `statistician` class declaration, inline methods, and friend function declarations.
* **[stats.cxx](stats.cxx)**: The implementation file containing the constructor and function definitions.
* **[stattest.cxx](stattest.cxx)**: An interactive, menu-driven command-line program to play around with and manually test the statistician class.
* **[statexam.cxx](statexam.cxx)**: An automated test suite that thoroughly checks the correctness of the class implementation and prints a score out of 90.

---

## Compilation & Execution

To compile and run the project, make sure you have a C++ compiler installed (such as `g++` or `clang++`) that supports C++11 or newer.

### 1. Running the Interactive Test (`stattest.cxx`)

Compile the interactive program:
```bash
g++ -Wall -std=c++11 stattest.cxx stats.cxx -o stattest
```

Run the executable:
```bash
./stattest
```

### 2. Running the Verification Exam (`statexam.cxx`)

Compile the exam suite:
```bash
g++ -Wall -std=c++11 statexam.cxx stats.cxx -o statexam
```

Run the executable:
```bash
./statexam
```
