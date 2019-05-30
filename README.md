# push_swap - A sorting algorithm using two stacks and limited operations.

Push Swap was the first project implementing algorithms using C at Codam. 
The following is a description of the program:
 </br>
>Summary:
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.
</br>


__The operations we were allowed to use:__ </br>
__sa__ : swap a - swap the first 2 elements at the top of stack a.
</br>
__sb__ : swap b - swap the first 2 elements at the top of stack b.
</br>
__ss__ : sa and sb at the same time.
</br>
__pa__ : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
</br>
__pb__ : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
</br>
__ra__ : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
</br>
__rb__ : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
</br>
__rr__ : ra and rb at the same time.
</br>
__rra__ : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
</br>
__rrb__ : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
</br>
__rrr__ : rra and rrb at the same time.
</br>

__The program should be able to sort:__
* 3 integers in a maximum of 3 commands.
* 5 integers in a maximum of 12 commands. 
* 100 integers in a maximum of 700 commands. 
* 500 integers in a maximum of 5500 commands.

__My program had the following amount of commands on average:__
* 2 commands for 3 integers.
* 9 commands for 5 integers.
* 640 commands for 100 integers.
* 4950 commands for 500 integers.
</br>
</br>

**I enjoyed working on this project and liked to challenge to modify an algoritm to work using the limited operations.**

