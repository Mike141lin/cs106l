# CS106L Course Practical Knowledge Summary

This document summarizes the core concepts and skills applied and learned through the completion of the C++ programming assignments (`SimpleEnroll`, `Make a Class`, `Ispell`, etc.). This journey covered the entire development lifecycle, from environment setup to advanced debugging and version control.

## 1. Core C++ Programming Concepts

### a. File I/O (Input/Output)
- **Key Insight**: C++ uses the **stream** model for I/O, managed by the `<fstream>` header.
- **Application**: We used `std::ifstream` to read `.csv` and `.txt` files in `parse_csv` and `get_applicants`. We used `std::ofstream` to create new report files in `write_courses_offered`.

### b. Function Parameter Passing
- **Pass-by-Value**: Passes a **copy** of the data. Changes inside the function do not affect the original.
- **Pass-by-Reference (`&`)**: Passes a **direct link** to the original data. This is highly efficient and necessary for functions that need to modify their arguments.
- **Application**: We fixed a critical bug by changing function signatures like `void parse_csv(std::vector<Course>& courses)` to use pass-by-reference, allowing the function to populate the original vector in `main`.

### c. Pointers (`*`) and Memory Management
- **Key Insight**: Pointers store memory addresses. Using pointers (e.g., `const std::string*`) is more efficient than copying large objects like strings.
- **Application**: The "Marriage Pact" assignment required storing pointers in a queue. This taught us about the performance benefits and the critical risk of **dangling pointers**—what happens when the original data is destroyed but a pointer to it still exists.

### d. `const`-Correctness
- **Key Insight**: A fundamental principle for writing safe and readable C++ code. A member function declared with `const` at the end (e.g., `int getAge() const;`) promises not to modify the object's state.
- **Application**: In the "Make a Class" assignment, we correctly implemented `const` getters, which was a requirement for passing the autograder and a key short-answer question.

## 2. Key Data Structures (STL)

### a. `std::set` vs. `std::unordered_set`
This was a central theme, highlighting the trade-off between order and speed.

| Feature | `std::set` (Ordered Set) | `std::unordered_set` (Unordered Set) |
| :--- | :--- | :--- |
| **Underlying Structure** | Red-Black Tree | Hash Table |
| **Ordering** | **Automatically Sorted** | **Unordered** |
| **Average Speed**| Slower (O(log n)) | **Extremely Fast (O(1))** |
| **Application**| Chosen when sorted iteration is needed. | Chosen in the "Marriage Pact" assignment for its superior performance in storing and looking up unique names, where order was irrelevant. |

### b. `std::queue`
- **Key Insight**: A First-In, First-Out (FIFO) container.
- **Application**: Used to store pointers to potential matches in the "Marriage Pact" assignment, demonstrating how to `push` elements to the back and `pop` them from the front.

## 3. Object-Oriented Programming (OOP)

### a. Classes and Objects
- **Key Insight**: A **class** is a blueprint (e.g., our `Pet` class), and an **object** is a specific instance created from that blueprint (e.g., `Pet my_dog;`).
- **Application**: The "Make a Class" assignment was a complete exercise in OOP, from designing the class to instantiating and using objects in `sandbox.cpp`.

### b. Encapsulation (Public vs. Private)
- **Key Insight**: Hiding internal data (`private`) and exposing a controlled public interface (`public`) to interact with that data.
- **Application**: We made our `Pet`'s member variables `private` and provided `public` getters and setters, which is a fundamental practice of encapsulation.

### c. Constructors
- **Key Insight**: Special functions for object initialization. We learned to implement and overload them.
- **Application**: We created both a **default constructor** (`Pet()`) and a **parameterized constructor** (`Pet(std::string name, ...)`), allowing for flexible object creation.

## 4. Modern C++: Algorithms & Ranges

### a. STL Algorithms (The "No Loops" Challenge)
- **Key Insight**: The `<algorithm>` header provides powerful functions that replace manual loops, leading to cleaner and less error-prone code.
- **Application**: In the `Ispell` assignment's `tokenize` function, we used `std::transform` to convert pairs of iterators into `Token` objects and `std::erase_if` to clean up the results.

### b. C++20 Ranges Library
- **Key Insight**: An even more modern and expressive way to apply algorithms using the pipe (`|`) operator to create a "pipeline" of operations.
- **Application**: We used Ranges extensively in the `spellcheck` function. The code `source | rv::filter(...) | rv::transform(...) | rv::filter(...)` is a powerful demonstration of this lazy-evaluation pipeline, which is a cornerstone of modern C++ programming.

## 5. Development Workflow & Tools

### a. Multi-File Compilation
- **Key Insight**: C++ projects are often split into header (`.h` for declarations) and source (`.cpp` for definitions) files. The compiler needs all `.cpp` files to be linked together.
- **Application**: We learned the correct command `g++ main.cpp class.cpp -o main` and debugged issues related to the unconventional `#include "utils.cpp"` directive, understanding how the compiler processes files.

### b. Version Control (Git & GitHub)
- **Key Insight**: A crucial skill for any developer. We practiced the full workflow.
- **Application**: We learned to use `git pull` to avoid conflicts, the `add`/`commit`/`push` cycle, and how to troubleshoot real-world authentication issues by creating and using a **Personal Access Token (PAT)**. We also learned to use a `.gitignore` file to exclude generated directories like `autograder/`, which fixed the repository's language detection.
