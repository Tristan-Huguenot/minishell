# Modular libft

As the projects of school 42 goes more and more challenging our first project libft become more and more big.
In order to keep learning beyond what is explicitly requested i tried to separate my libft into modules.

---

## Modules

Here a list of modules as [module : dependancies]

*	memory
*	char
*	write
*	math
*	string : memory, char
*	num_string : string
*	file : memory, char, write
*	ft_lst : memory
*	ft_printf : num_string, write

## Make

All modules get their Makefile inside the src/[module]/ directory.

`make all` : create libft.a with all modules

`make [modules]` : will create libft.a with specified modules

`make clean` : Delete all objects

`make fclean` : Delete libft.a
