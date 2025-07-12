# CS106L - Assignment 0 Summary

 Challenges & Solutions

During the setup process, I encountered a few challenges. Solving them deepened my understanding of the system and the tools.

#### Challenge 1: Fixing the `g++` Command

When trying to compile in the terminal, I received a `command not found: g++-14` error, indicating a problem with my shell's configuration.

```bash
(base) lin@lindeMacBook-Pro assignment0 % g++ -std=c++23 main.cpp -o main
zsh: command not found: g++-14
```
Solution: I discovered this was caused by an incorrect line (alias g++="g++-14") in my ~/.zshrc file. I resolved the issue by opening the file with the open ~/.zshrc command, deleting the erroneous line, and restarting my terminal.


Challenge 2: Fixing the VS Code code Command

When attempting to open the project folder from the terminal using code ., I received a command not found: code error.

```bash
(base) lin@lindeMacBook-Pro assignment0 % code .
zsh: command not found: code
```
Solution: I fixed this by opening the VS Code Command Palette (Cmd + Shift + P) and running the "Shell Command: Install 'code' command in PATH" command, which successfully integrated the code shortcut with my system's terminal.

4. Final Verification

Finally, to ensure all configurations were correct, I successfully compiled and ran the test program from within the VS Code integrated terminal. The program executed as expected and passed the autograder check, confirming a successful setup.

```bash
# Step 1: Compile the program, which executed without any errors
(base) lin@lindeMacBook-Pro assignment0 % g++ -std=c++23 main.cpp -o main
```
```bash
# Step 2: Run the executable, which showed the successful autograder message
(base) lin@lindeMacBook-Pro assignment0 % ./main
Hello, World!
Autograder: Installation is correct.
```
