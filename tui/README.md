# TUI - A Curses Alternative

*tui* is a library to create text-based user interfaces.
It is very small and simple by design and provides just a few functions which
provide enough power to build interfaces.
Its goal is to be very small and lightweight.

## Documentation

At the moment *tui* provides just *10* functions and one *Window* structure.

The *Window* structure keeps the following information:

* The *width* of the *Window*
* The *height* of the *Window*
* The *x* position of the *Window*
* The *y* position of the *Window*
* Whether the *Window* *has_borders* or not

Additionally *tui* has following the `get_term_width` and `get_term_height`
to get the geometry of the current terminal.

To initialize and end the session there are the `inittui` and `endtui` functions.

To `printf` a string on a specific position there is `printfxy` which takes the
`x` and `y` position and a `fmt` string like in `printf`.

To `printf` only in a specific window there is `printfxy_to_window` with the same
parameters as `printfxy` except that you have to set the Window as first argument.

The `draw_window` function clears the window content and redraws the borders.

To get a char without that the user has to press return there is the `getch` function.

If it is not wanted that the pressed keys are printed use the `showecho` to set the wished behavior.

To set the cursors visibility there is the `showcursor` function.

# Example

To see an example run `make` and then execute the file `test` its source is `test.c`
