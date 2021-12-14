#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "progress.h"

#define SEC *1000000
#define NUM_PROGS 20 

char titles[NUM_PROGS][10];

void * thread_fun(void * b) {
	Progressbar * bar = b;

	while (bar->progress < bar->limit) {
		++bar->progress;
		usleep(0.001 SEC);
	}
}

int main() {
	srand(time(0));

	pthread_t threads[NUM_PROGS];

	Progressbar pb[NUM_PROGS];
	ProgressInfo pinfo;

	pinfo.progressbars = pb;
	pinfo.num_progressbars = NUM_PROGS;
	pinfo.fill_char = '=';
	pinfo.last_char = '>';

	for (Progressbar * bar = pb; bar < pb + NUM_PROGS; ++bar) {
		bar->limit = rand() % 10000;
		bar->progress = 0;
		bar->show_percentage = 1;
	}


	for (int i = 0; i < NUM_PROGS; ++i) {
		sprintf(titles[i], "Bar %d", i);
		pb[i].title = titles[i];
	}

	init_bars(&pinfo);

	for (int i = 0; i < NUM_PROGS; ++i) {
		pthread_create(threads + i, NULL, thread_fun, (void *)(pb + i));
	}

	int done;

	do {
		usleep(0.001 SEC);
		done = 1;
		for (int i = 0; i < NUM_PROGS; ++i) {
			if (pb[i].progress < pb[i].limit) {
				done = 0;
				break;
			}
		}

		print_bars(&pinfo);
	} while (!done);

	return 0;
}
