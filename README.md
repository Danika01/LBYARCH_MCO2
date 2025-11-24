# LBYARCH_MCO2

This project computes the linear acceleration of multiple cars using C and x86-64 Assembly. The following formula was used for the project:
Acceleration = (Vf - Vi)/T

Steps to run the program:
1. Open the command line in the project folder (ensure the path leads to the folder of the project)
2. Enter: nasm -f win64 compute.asm -o compute.o
3. Enter: gcc 86toC.c compute.o -o main.exe
4. Enter: main.exe
   
ANALYSIS

<img width="602" height="398" alt="image" src="https://github.com/user-attachments/assets/81dd117d-671e-4bd9-8eeb-a7a151b24c8d" />


