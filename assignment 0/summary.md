# CS106L - Assignment 0 Summary

### 1. Assignment Goal Overview

The core objective of Assignment 0 was to set up and configure a C++ development environment and to become familiar with the complete workflow, from writing code to compiling and running it from the command line. This process builds a solid foundation for the more complex C++ programming and project work in the upcoming assignments.

---

### 2. Key Learnings & Takeaways

* **Familiarity with the C++ Compilation Workflow**: I learned how to use the `g++` (or `Clang`) compiler via the command line to compile `.cpp` source code into an executable file. I now understand the meaning of common compiler flags like `-o` (to specify an output filename) and `-std` (to specify a language standard, such as `c++23`).

* **Mastery of Environment Configuration**: I successfully configured VS Code as my code editor on my macOS machine. Through this process, I solved various integration issues with the terminal and compiler, such as installing the `code` shell command and fixing `PATH` environment variables.

* **Basic Git & GitHub Proficiency**: I grasped the fundamentals of version control. Through this assignment, I learned how to create a new repository on GitHub, `clone` it to my local machine, and use the `git add`, `commit`, and `push` flow to submit and synchronize my code. I also learned how to troubleshoot authentication issues using Personal Access Tokens (PATs).

---

### 3. Challenges & Solutions

During the setup process, I encountered a few challenges. Solving them deepened my understanding of the system and the tools.

#### Challenge 1: Fixing the `g++` Command

When trying to compile in the terminal, I received a `command not found: g++-14` error, indicating a problem with my shell's configuration.

```bash
(base) lin@lindeMacBook-Pro assignment0 % g++ -std=c++23 main.cpp -o main
zsh: command not found: g++-14
Solution: I discovered this was caused by an incorrect line (alias g++="g++-14") in my ~/.zshrc file. I resolved the issue by opening the file with the open ~/.zshrc command, deleting the erroneous line, and restarting my terminal.

Challenge 2: Fixing the VS Code code Command

When attempting to open the project folder from the terminal using code ., I received a command not found: code error.

Bash
(base) lin@lindeMacBook-Pro assignment0 % code .
zsh: command not found: code
Solution: I fixed this by opening the VS Code Command Palette (Cmd + Shift + P) and running the "Shell Command: Install 'code' command in PATH" command, which successfully integrated the code shortcut with my system's terminal.

4. Final Verification

Finally, to ensure all configurations were correct, I successfully compiled and ran the test program from within the VS Code integrated terminal. The program executed as expected and passed the autograder check, confirming a successful setup.

Bash
# Step 1: Compile the program, which executed without any errors
(base) lin@lindeMacBook-Pro assignment0 % g++ -std=c++23 main.cpp -o main

# Step 2: Run the executable, which showed the successful autograder message
(base) lin@lindeMacBook-Pro assignment0 % ./main
Hello, World!
Autograder: Installation is correct.
