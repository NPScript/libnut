#ifndef PROGRESS_H
#define PROGRESS_H

typedef struct {
	unsigned limit;
	unsigned progress;
	char * title;
	unsigned show_percentage;
} Progressbar;

typedef struct {
	Progressbar * progressbars;
	unsigned num_progressbars;
	char fill_char;
	char last_char;
} ProgressInfo;

void print_bars(ProgressInfo *);
void init_bars(ProgressInfo *);

#endif
