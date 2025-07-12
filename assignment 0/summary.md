# CS106L - Assignment 0 Summary



During the setup process, I encountered a few challenges. Solving them deepened my understanding of the system and the tools.

#### Challenge 1: Fixing the `g++` Command

When trying to compile in the terminal, I received a `command not found: g++-14` error.

```bash
(base) lin@lindeMacBook-Pro assignment0 % g++ -std=c++23 main.cpp -o main
zsh: command not found: g++-14
Solution: I discovered this was caused by incorrectly adding the line alias g++="g++-14" to my ~/.zshrc file. I opened the file using the open ~/.zshrc command, deleted the incorrect line, and restarted my terminal, which resolved the issue.

Challenge 2: Fixing the VS Code code Command

When trying to open the project with code . in the terminal, I received a command not found: code error.

Bash
(base) lin@lindeMacBook-Pro assignment0 % code .
zsh: command not found: code
Solution: I ran the "Shell Command: Install 'code' command in PATH" command from the VS Code Command Palette (Cmd + Shift + P), which successfully installed the code command into the system PATH.

4. Final Verification

Finally, I successfully compiled and ran the test program in the VS Code integrated terminal, confirming that the entire environment was configured correctly.

Bash
# Compile command, which executed without any errors
(base) lin@lindeMacBook-Pro assignment0 % g++ -std=c++23 main.cpp -o main

# Run the program, which showed the successful autograder message
(base) lin@lindeMacBook-Pro assignment0 % ./main
Hello, World!
Autograder: Installation is correct.
