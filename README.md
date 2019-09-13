# Balanced-Symbol-Checker
CS 211: Programming Practicum
A C program that will determine whether input is given with properly balanced symbols. We will often use symbols together to specify the beginning and ending of an item, such as the use of parentheses in a mathematic expression or the use of curly braces in a C, C++ or Java program. For this program, we will be checking the following symbol pairs:
• parentheses: ( )
• curly braces: { }
• square brackets: [ ] 
• angle brackets: < >

This program will require the use of a stack implemented in a dynamic array. This dynamic array is to grow to a larger size when a push operation would be done to a full array causing an array overflow. 

Input: The input for this program will come from standard input. Each line of input will be a single expression that is to be checked for balanced symbols. It is assumed that each line of input is less than 300 characters long. The program must loop to read in multiple lines of input. If the input on the line contains only the letter q or Q, quit the program.
