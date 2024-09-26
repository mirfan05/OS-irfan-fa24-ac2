# Lab Assignment 2: Implementing a Simple Shell in C

## Objectives
- Understand process creation and management in C using system calls.
- Learn to handle user input and command parsing.
- Implement basic shell functionality including command execution and built-in commands.

## Requirements
You will implement a simple shell that can:
- Accept user commands from standard input.
- Execute commands using `fork()` and `execvp()`.
- Handle built-in commands like `cd` and `exit`.
- Support argument parsing from user input.
- Wait for child processes to finish execution using `wait()`.
- 
## Tasks
### 1. Set Up the Project
- Create a new C file named `myshell.c`.
- Include necessary headers: `<stdio.h>`, `<stdlib.h>`, `<unistd.h>`, `<string.h>`, `<sys/wait.h>`.
### 2. Implement the Main Loop
- Implement an infinite loop that continuously prompts the user for a command.
- Use 'fgets()' to read input and store it in a command buffer.
### 3. Process User Input
- Remove the newline character from the input.
- Check if the command is "exit" and break the loop if so.
### 4. Command Parsing
- Use `strtok()` to split the command string into arguments.
- Store arguments in an array and ensure it is null-terminated.
### 5. Process Creation
- Call `fork()` to create a new process.
- Handle potential errors from `fork()`.
### 6. Command Execution
- In the child process, use `execvp()` to execute the command.
- Handle failures from `execvp()` by printing an error message and exiting with a non-zero status.
### 7. Parent Process Management
- In the parent process, call `wait()` to wait for the child process to finish.
### 8. Built-in Commands
- Implement support for the `cd` command using `chdir()`.
- Ensure that other commands are executed using the `execvp()` method.
### 9. Error Handling
- Implement error handling for invalid commands and memory allocation failures.
- Print meaningful error messages to the user.
### 10. Testing
- Test your shell with various commands, including built-in commands and external commands.
  
## Submission Guidelines
- Submit your myshell.c source file along with a README file that includes instructions on how to compile and run your shell.
- Answer the questions.
- Ensure your code is well-commented and adheres to good coding practices.
  
## Evaluation Criteria
- Functionality (60 points): Shell executes commands correctly, handles built-in commands, and waits for child processes.
- Code Quality (20 points): Code is well-structured, follows naming conventions, and includes comments.
- Error Handling (20 points): Proper error messages are displayed for invalid commands and memory allocation failures.
