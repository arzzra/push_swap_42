# push_swap_42
О проекте:
============
Задача
------------
Даны два стека A и B, над которыми можно выполнять операции:

`sa` `sb` `ss` __swap__ the first 2 elements at the top of stack _A/B/both_

`pa` `pb` take the first element at the top of _B/A_ and __push__ it at the top of _A/B_

`ra` `rb` `rr` __rotate__ all elements of stack _A/B/both_ , the first element becomes the last one.

`rra` `rrb` `rrr` __reverse rotate__ all elements of stack _A/B/both_, the last element becomes the first one.

В стеке _A_ лежит массив целых неповторяющихся чисел.

Необходимо отсортировать по возрастанию данный массив за минимальное количество операций (отсортированный массив
тоже должен лежать в стеке _A_).
 
