# Push_swap

The goal of the project if to sort a given stack.
To store at any point the data, you only have two stack.
You only have a few moves allowed : 
- sa : swap a (swap the first 2 elements at the top of stack a)
- sb : swap b (swap the first 2 elements at the top of stack b)
- ss : sa and sb
- pa : push a (take first element at the top of b and put it at the top of a)
- pb : push b (take first element at the top of a and put it at the top of b)
- ra : rotate a (shift up all ellement of stack a by 1, the first element becomes the last one)
- rb : rotate b (shift up all ellement of stack b by 1, the first element becomes the last one)
- rr : ra and rb
- rra : reverse rotate a
- rrb : reverse rotate b
- rrr : rra and rrb

Techno : C

Programming method : Sorting algorithm (sort of merge sort)

