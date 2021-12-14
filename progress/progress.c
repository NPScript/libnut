#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <math.h>

#include "progress.h"

void print_bars(ProgressInfo * info) {
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	printf("\033[%dF", info->num_progressbars);

	for (Progressbar * bar = info->progressbars; bar < info->progressbars + info->num_progressbars; ++bar) {
		const unsigned limitstrlen = log10(bar->limit) + 1;

		const unsigned barlen = w.ws_col - strlen(bar->title) - (bar->show_percentage ? 3 : 2 * limitstrlen) - 10;

		printf(" %s [", bar->title);

		unsigned progress_rel_to_bar = (float)bar->progress / bar->limit * barlen;

		for (int i = 0; i < progress_rel_to_bar; ++i)
			printf("%c", info->fill_char);

		if (bar->progress < bar->limit)
			printf("%c", info->last_char);
		else
			printf("%c", info->fill_char);

		printf("%*s] [", barlen - progress_rel_to_bar, "");

		if (bar->show_percentage) {
			const unsigned p = (unsigned)((float)bar->progress / bar->limit * 100);
			printf("%*s", 2 - (unsigned)log10(p), "");
			printf("%d%%", p);
		} else {
			printf("%*s", limitstrlen - 1 - (unsigned)(bar->progress ? log10(bar->progress) : 0), "");
			printf("%d/%d", bar->progress, bar->limit);
		}

		printf("]\n");
	}
}

void init_bars(ProgressInfo * info) {
	for (int i = 0; i < info->num_progressbars; ++i)
		printf("\n");
}
