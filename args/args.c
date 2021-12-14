#include "args.h"
#include "stddef.h"

int is_same(const char * a, const char * b) {
	while (1) {
		if (*a != *b)
			return 0;
		if (*a == 0)
			return 1;

		++a;
		++b;
	}
}

int has_flag(Args * args, const char * flag) {
	for (int i = 0; i < args->argc; ++i) {
		if (is_same(args->argv[i], flag))
			return 1;
	}
	return 0;
}

const char * get_argument(Args * args, const char * name) {
	for (int i = 0; i < args->argc - 1; ++i) {
		if (is_same(args->argv[i], name))
			return args->argv[i + 1];
	}
	return NULL;
}

