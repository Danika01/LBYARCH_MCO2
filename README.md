# LBYARCH_MCO2

This project computes the linear acceleration of multiple cars using C and x86-64 Assembly. The following formula was used for the project:
Acceleration = (Vf - Vi)/T

Steps to run the program:
1. Open the command line in the project folder (ensure the path leads to the folder of the project)
2. Enter: nasm -f win64 compute.asm -o compute.o
3. Enter: gcc 86toC.c compute.o -o main.exe
4. Enter: main.exe
   
ANALYSIS

Below is the screenshot of the program output showing mode selection, execution timing, and correctness verification between C and ASM:

<img width="373" height="682" alt="image" src="https://github.com/user-attachments/assets/aac15407-341d-46a9-8f2d-0351e9422c28" />

The time performance for 10 and 100 rows does not mean the data set takes 0 time to run. The scope of the timer cannot capture the speed and efficiency of small datasets unlike in 1,000 and 10,000. The results show a positive linear relationship, showcasing that as the data increases, the time also increases. Nevertheless, the use of assembly is very efficient for computations with large datasets.

Runtime will most likely scale linearly (O(n)) as the number of cars increases. The assembly implementation will definitely outperform or match C due to its direct register usage and reduced abstraction.

