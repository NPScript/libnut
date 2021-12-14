# args - Organize Your Arguments

The `args` library helps to organize the command-line arguments.

# Documentation

`args` only consists of two function and one structure.
The `Args` structure holds the following information:

* The argument list [`char ** argv`]
* The amount of strings in the list [`int argc`]

To understand the to functions we have to differ between
`arguments` and `flags`. A flag is a standalone command-line argument
such as `--help` an argument is a `flag` followed by an additional string like
`-n 5`.

So there are two functions `has_flag` to know if a flag is set. And
`get_argument` to get the string following the flag.
