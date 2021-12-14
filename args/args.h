#ifndef ARGS_H
#define ARGS_H

typedef struct {
	char ** argv;
	int argc;
} Args;

int has_flag(Args *, const char *);
const char * get_argument(Args *, const char *);

#endif
