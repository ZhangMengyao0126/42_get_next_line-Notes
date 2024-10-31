# 42_get_next_line-Notes
## The **objective** of this project
To customize the get_next_line() function.

The function signature of "get_next_line":  char *get_next_line(int fd);<br>
1. The return value is the next line read by the function, or NULL when there is nothing to read or an error.<br>
2. int fd:<br>
We are asked to repeatedly call (e.g., using a loop) the get_next_line() function to read the text file pointed to by the file descriptor.

## The **solution** of this project
1. The main function: <br>
char *get_next_line(int fd)<br>
The main function is basically a combination of all the subfunctions, with no new logic added.<br>

3. Subfunction for ft_get_buffer:<br>
static char *ft_get_buffer(int fd, char *buffer)<br>
Set the buffer and read data until it encounters a newline ('\n') or reaches the end of the file (including our target line) from the file descriptor and adds the data to buffer.

5. Subfunction for ft_get_oneline:<br>
static char *ft_get_oneline(char *buffer)<br>
Extract the target line(up to and including the newline character) from the buffer as the return value.<br>

7. Subfunction for ft_to_nextline:<br>
static char *ft_to_nextline(char *buffer)<br>
Move the buffer pointer to the start of the next line in buffer.<br>

## Everything is a file
Linux abstracts and treats most system resources (like hardware devices, directories, and even processes) as files.<br>

## File descriptor
### File Descriptors (FDs)
A file descriptor is an integer that represents an open file or file-like object in a process. This file could be a regular file, a device (like /dev/ttys001, /dev/ttys002), or even network sockets, pipes, etc.<br>

The process uses file descriptors to interact with these objects, and the operating system manages these file descriptors in a per-process file descriptor table.<br>
### Standard File Descriptors (FDs 0, 1, 2)
Every process starts with three standard file descriptors by default:
1. 0: Standard Input (stdin) — used for input, typically from the keyboard or another input stream.
2. 1: Standard Output (stdout) — used for output, typically displaying data on the screen.
3. 2: Standard Error (stderr) — used for error messages, typically also directed to the screen but can be redirected separately from standard output.
### Additional File Descriptors
When a process opens more files or resources, they are assigned new file descriptors (starting from 3 and increasing). These can be for reading and writing to files, network connections, pipes, or other I/O streams.<br>

The process interacts with them using system calls (e.g., open(), read(), write(), close()), and the OS uses the file descriptor table to keep track of these open files for each process.<br>
### Related shell commands
tty: display the file name of the terminal connected to the standard input (stdin).<br>

la: ls -a, list all files, including hidden ones (files that start with a .) in the current directory.<br>

ps: display information about the currently running processes on the system. It stands for process status and provides details such as process IDs (PID: the system will give every executing process a numerical ID), the terminal associated with the processes, CPU usage, memory consumption, and more.<br>

lsof -p 1800: list all open files associated with the process with the PID (Process ID) 1800.<br>

## RAM (Random Access Memory)
RAM is the CPU's working area, which is used to temporarily store the operating system, applications, and data currently in use. When a program ends or the device loses power, the RAM will be cleared. Note: When creating a virtual machine, setting RAM is equivalent to setting Base Memory.<br>

RAM Hardware:<br>
RAM Modules: RAM is typically packaged in modules known as DIMMs (Dual Inline Memory Modules) for desktops and SO-DIMMs (Small Outline DIMMs) for laptops. These modules contain multiple RAM chips mounted on a circuit board.<br>

RAM Chips:<br>
Each RAM module contains several chips, often made of silicon. These chips are the actual memory cells that store data. Common types include:<br>
DRAM (Dynamic RAM): Requires periodic refreshing to maintain data.<br>
SRAM (Static RAM): Faster and more reliable but more expensive; used in cache memory.<br>

## Buffer
A buffer can be seen as a storage mechanism based on RAM. Instead of waiting for the full dataset to be loaded from the slower hard disk, the buffer preloads small chunks of data, allowing the process to retrieve and work with this portion of data without waiting for the entire dataset to be read from the disk.<br>

Buffer_Size refers to the amount of RAM allocated for the buffer. It determines how much data the buffer can hold at one time during data transfer or processing.<br>

## Macro
Macros have no type; They are purely a text substitution mechanism performed by the preprocessor before the actual compilation of the code. Macros do not necessarily need to have an associated value.<br>

### Header file protection
#ifndef GET_NEXT_LINE_H<br>
`#`  define GET_NEXT_LINE_H<br>
#endif<br>

The name GET_NEXT_LINE_H is indeed related to the header file, but it serves a specific purpose as a macro name in the context of header file protection. <br>
The line #define GET_NEXT_LINE_H defines GET_NEXT_LINE_H as a preprocessor macro. This macro acts as a flag to indicate whether the header file has already been included in the current compilation unit.<br>
When the header file is included for the first time, GET_NEXT_LINE_H is not defined, allowing the contents of the header file to be processed. On subsequent inclusions, the macro is already defined, so the contents are skipped.<br>

### Macro definition
#ifndef BUFFER_SIZE<br>
`#`  define BUFFER_SIZE 10<br>
#endif<br>

This means that wherever BUFFER_SIZE appears in the code, the preprocessor will replace it with the value 10 during the preprocessing stage, before the code is compiled.<br>

## Concatenate(cat)
cat will read the contents of files **sequentially** and print them to the terminal or another output destination.<br>
1. cat file1.txt<br>
This command will simply display the content of file1.txt on the terminal. Cause the default value of cat command is like cat file1.txt > /dev/tty<br>
2. cat file1.txt file2.txt > combined.txt<br>
This command will concatenate the contents of file1.txt and file2.txt and save the output into a new file called combined.txt. If you don't specify an output file, it simply prints the combined contents to the terminal.<br>

## Error Handling
1. If the return value of the subfunction could be NULL;
2. If you have used the function malloc————Always remember to add the error handling and memory-free part.

## Read
Function signature: ssize_t read(int fd, void *buf, size_t count)<br>
1. Return Value: <br>
read will return the number of bytes (or characters) successfully read into the buffer.<br>
(1) Positive: Indicates the number of bytes read. This could be less than the requested amount if fewer bytes are available.<br>
(2) 0: Signifies that the end of the file (EOF) has been reached.<br>
(3) -1: Indicates an error. Common errors include invalid file descriptor (EBADF), permissions error (EACCES), or interrupted system call (EINTR).<br>


2. Data Transfer to Buffer:<br>
read will transfer the data directly into the buffer you specify. If read succeeds, the buffer will contain up to the number of bytes you requested, with the actual number of bytes read indicated by the return value.

## char *ptr ; *ptr ; &c
1. char *ptr:<br>
(1) char: the type of variable that the pointer is pointing to, which means ptr holds the address of such variable.<br>
(2) *: the sign of a pointer.<br>
(3) ptr: the pointer's name.<br>

2. ptr = &c, *ptr = c<br>
(1) *: dereference sign, access the value at a given address.<br>
(2) &: address-of sign, get the address of a variable.<br>
(3) * and & are inverse operations.<br>

 
