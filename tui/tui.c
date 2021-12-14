#include <stdio.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include "tui.h"

struct termios term;

unsigned get_term_width() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	return w.ws_col;
}

unsigned get_term_height() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	return w.ws_row;
}

void inittui() {
	printf("\033[?1049h");
	tcgetattr(fileno(stdin), &term);
}

void endtui() {
	printf("\033[?1049l");
}

char getch() {
	char c;
	term.c_lflag &= ~ICANON;

	tcsetattr(fileno(stdin), TCSANOW, &term);
	c = getc(stdin);

	term.c_lflag |= ICANON;
	tcsetattr(fileno(stdin), TCSANOW, &term);
	return c;
}

void showecho(int echo) {
	if (!echo)
		term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
	else
		term.c_lflag |= ECHO | ECHOE | ECHOK | ECHONL;
	tcsetattr(fileno(stdin), TCSANOW, &term);
}

void showcursor(int show) {
	printf("\033[?25%c", show ? 'h' : 'l');
}

void printfxy(unsigned x, unsigned y, const char * fmt, ...) {
	va_list list;

	printf("\033[%d;%dH", y, x);

	va_start(list, fmt);
	vprintf(fmt, list);
	va_end(list);
}

void draw_window(Window * win) {
	for (int i = 0; i < win->height; ++i)
		printfxy(win->x, win->y + i, "%*s", win->width, "");

	if (win->has_borders) {
		printfxy(win->x, win->y, "%s", TLCORNER);
		for (int i = 1; i < win->width - 1; ++i)
			printfxy(win->x + i, win->y, "%s", HLINE);
		printfxy(win->x + win->width - 1, win->y, "%s", TRCORNER);

		printfxy(win->x, win->y + win->height - 1, "%s", BLCORNER);
		for (int i = 1; i < win->width - 1; ++i)
			printfxy(win->x + i, win->y + win->height - 1, "%s", HLINE);
		printfxy(win->x + win->width - 1, win->y + win->height - 1, "%s", BRCORNER);

		for (int i = 1; i < win->height - 1; ++i)
			printfxy(win->x, win->y + i, "%s", VLINE);

		for (int i = 1; i < win->height - 1; ++i)
			printfxy(win->x + win->width - 1, win->y + i, "%s", VLINE);
	}

	fflush(stdout);
}

void printfxy_to_window(Window * win, int x, int y, const char * fmt, ...) {
	va_list list;
	char buf[BUFSIZ];
	int cx;
	int cy;

	va_start(list, fmt);
	vsprintf(buf, fmt, list);
	va_end(list);

	cx = x + win->x + win->has_borders;
	cy = y + win->y + win->has_borders;

	if (cy >= (int)(win->y + win->height - win->has_borders))
		return;

	printf("\033[%d;%dH", cy, cx);

	for (char * c = buf; *c; ++c) {
		if (*c == '\n' || cx == win->x + win->width - win->has_borders) {
			if (++cy >= (int)(win->y + win->height - win->has_borders))
				break;
			cx = win->x + win->has_borders;
			printf("\033[%d;%dH", cy, cx);
		}

		if (*c != '\n') {
			if (cy >= (int)(win->y + win->has_borders))
				putc(*c, stdout);
			++cx;
		}
	}
}

