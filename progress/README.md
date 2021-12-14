# Progressbar - Multiple Progressbars The Simple Way

This library is for easily create and update multiple progressbars.
So there is a way to show the progress of each thread for example.

It is kept simple so it is easier to use. Because of that it has just two
functions and two structures.

## Documentation

There are two structures:

* ProgressInfo
* Progressbar

The `ProgressInfo` contains the following:

* A list of Progressbars [`Progressbar * progressbars`]
* The number of progressbars [`unsigned num_progressbars`]
* With which character the progressbar is filled [`char fill_char`]
* Which character indicates the end of the progressbar [`char last_char`];

The `Progressbar` holds the following:

* Its limit [`unsigned limit`]
* Its progress [`unsigned progress`]
* Its title [`char * title`]
* Whether it should show the value in percentage or its full number [`unsigned show_percentage`]

The two function of this library are the following:

* print_bars
* init_bars

Both of them thake just the `ProgressInfo` as argument.
The `init_bars` function takes the `ProgresInfo` which has
the current progressbars set and prepares the screen for displaying
the bars. The `print_bars` function is called to update the bars on screen.
