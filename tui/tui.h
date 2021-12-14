#ifndef TUI_H
#define TUI_H

#define VLINE    "│" 
#define HLINE    "─" 
#define TLCORNER "┌"
#define BLCORNER "└"
#define TRCORNER "┐"
#define BRCORNER "┘"
#define LTEE     "├"
#define RTEE     "┤"
#define BTEE     "┴"
#define TTEE     "┬"
#define PLUS     "─"

typedef struct {
	unsigned width;
	unsigned height;
	unsigned x;
	unsigned y;
	unsigned has_borders;
} Window;

unsigned get_term_width();
unsigned get_term_height();

void inittui();
void endtui();

char getch();

void printfxy(unsigned x, unsigned y, const char * fmt, ...);

void printfxy_to_window(Window * win, int x, int y, const char * fmt, ...);
void draw_window(Window * win);

void showecho(int echo);
void showcursor(int show);

#endif
