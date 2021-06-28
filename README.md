# Push-Swap-42

Push_Swap is a 42-SP project which consist to produce a sorting Algorithm following some
concepts to standardize the process;
We were free to develop this project with any tools created or available (respecting the 42-norm);

Within the sorting process we should work the logic arround some operations determined by the subject,
Please, find bellow the list of operations:
```
- sa :swap 'a' - swap the first 2 elements at the top of stack 'a';
- sb :swap 'b' - swap the first 2 elements at the top of stack 'b';
- ss :sa and sb at the same time.
- pa :push 'a' - take the first element at the top of 'b' and put it at the top of 'a'.
- pb :push 'b' - take the first element at the top of 'a' and put it at the top of 'b'.
- ra :rotate 'a' - shift up all elements of stack 'a' by 1.
- rb :rotate 'b' - shift up all elements of stack 'b' by 1.
- rr :ra and rb at the same time.
- rra :reverse rotate 'a' - shift down all elements of stack 'a' by 1.
- rrb :reverse rotate 'b' - shift down all elements of stack 'b' by 1;
- rrr :rra and rrb at the same time.

```

## Installation

To build the programm there is only a few steps:
First of all, you can download the repository through the following steps in any shell of your preference:
```
git clone https://github.com/Victor-Akio/Push-Swap-42.git push_swap_42
cd push_swap_42
make
```
This commands will compile everything and a executable "push_swap" should be created.

### Instructions

To run the application you shall input the program plus the arguments, which is the list of numbers to organize. For example:
```
$ ./push_swap 3 4 8 9 7 5 1 0 2 6
or
$ ./push_swap "10 30 60 42 80 99 -42"
```
This project was structured to run with integers, with numbers within the range of -2147483648 to 2147483647.
Also, even accepting a string of numbers, if you try to input a word or a letter, as 'a' or 'hello', it will not work, returning an error message.

## Other Information

- This project was made using C language, obeying all 42 norms;
- The tests folder has several tests and lists to better understand the project.
- There is also a visualizer (pyviz.py), it uses the operations that your program produces and present a graphic representation of this proccess. Keep in mind that you need to have installed python and the Tkinter lib;
- There is also an script in perl to automate the list generation and execution of the program, created by a fellow cadetes in 42-SP (ps_tester.pl) - Please, check the notion produced;

## Useful Links

- [42 Push-Swap notion](https://www.notion.so/Push_swap-21758af851874d70a09c854ae200a0ae)
- [Least amount of moves](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwiLrP6CpdvvAhXmH7kGHZ21CQ0QFjACegQIBBAD&url=https%3A%2F%2Fmedium.com%2F%40jamierobertdawson%2Fpush-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a&usg=AOvVaw2KbZDpsvEv2ry63D-uw2Zx)
- [Example and Pyviz](https://github.com/anyaschukin/Push_Swap)