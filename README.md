# push_swap - A sorting algorithm using two stacks and limited operations.

__Push Swap was the first project implementing algorithms using C at Codam. 
The project consist of two programs, checker and push_swap. push_swap sort a array of integers and writes the commands to the stdout. Checker reads these commands and executes them. If the array is sorted the output is "OK", if not the output will be "KO".
The following is a description of the program:__

 </br>
<em>Summary:
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.</em>
</br>
</br>

## Installation:

```
git clone https://github.com/tmeulenb/push_swap
cd push_swap && make
```

## Usage:
```
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"; 
./push_swap $ARG | ./checker $ARG
```

## Flags
```
Flags that can be used for [checker]
-v | Displays the stack after every command in the program checker.
-o | Visualizes the sorting algorithm. Would not advice to use this on arrays larger than 100.
-x | Displays the total amount of commands.
-c | Displays the total amount of commands per command.

Flags that can be used for [push_swap]
-checker | Makes push_swap work as checker.
--help | Shows all the information about flags and usage.
```

## Rules
```
The operations we were allowed to use:

sa : swap a 
swap the first 2 elements at the top of stack a.
sb : swap b
swap the first 2 elements at the top of stack b.
ss : sa and sb at the same time.

pa : push a
take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b
take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

ra : rotate a
shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b
shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.

rra : reverse rotate a
shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b
shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.

```

## Expected result
```
The program should be able to sort:
- 3 integers in a maximum of 3 commands.
- 5 integers in a maximum of 12 commands. 
- 100 integers in a maximum of 700 commands. 
- 500 integers in a maximum of 5500 commands.
```


## My result
```
My program had the following amount of commands on average:
- 3 integers in 2 commands on average.
- 5 integers in 9 commands on average.
- 100 integers in 650 commands on average.
- 500 integers in 4950 commands on average.
```
</br>
</br>

<em>I enjoyed working on this project and liked the challenge to modify an algoritm to work using the limited operations.</em>

