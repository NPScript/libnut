#include <stdio.h>
#include "args.h"

int main(int argc, char ** argv) {
	Args args;
	args.argc = argc;
	args.argv = argv;
	const char * num;
	
	if (has_flag(&args, "--help")) {
		printf("Usage help:\n--help: this dialog\n-n <num>: print this number\n-t <text>: print this text\n");
	} else if (num = get_argument(&args, "-n")) {
		printf("%s\n", num);
	}

	if (num = get_argument(&args, "-t")) {
		printf("%s\n", num);
	}


	return 0;
}
