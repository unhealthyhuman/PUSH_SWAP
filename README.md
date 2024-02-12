Push Swap:
-
This project is part of the 42 Cursus and it aimed to introduce us to the concept of performing efficiently. In this project we were given a set of integers which we needed to sort in the most competent way, given two stacks and a set of instructions to manipulate said stacks. The programm needed to swiftly and accurately calculate and display the smallest programm made of Push Swap instructions that sorts the integers received as arguments.

Common Rules
-
• The project must be written in C.

• The functions should not quit unexpectedly (segmentation fault, bus error, double
free, etc) apart from undefined behaviors.

• All heap allocated memory space must be properly freed when necessary.

• The Makefile which will compile the source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink.

• The Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

Push Swap Rules
-
• You have 2 stacks named a and b.

• At the beginning:

◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.

◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a.

Set of Instructions
-
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
