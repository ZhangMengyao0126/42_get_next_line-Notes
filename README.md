# 42_get_next_line-Notes

## Everyting is a file
Linux abstracts and treats most system resources (like hardware devices, directories, and even processes) as files.<br>

## file descriptor
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
### related shell commands
tty: display the file name of the terminal connected to the standard input (stdin).<br>
la: ls -a, list all files, including hidden ones (files that start with a .) in the current directory.<br>
ps: display information about the currently running processes on the system. It stands for process status and provides details such as process IDs (PID: the system will give every executing process a numerical ID), the terminal associated with the processes, CPU usage, memory consumption, and more.<br>
lsof -p 1800: list all open files associated with the process with the PID (Process ID) 1800.<br>
