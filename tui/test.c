#include "tui.h"

const char * lorem_ipsum =  "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris et dui sem. Sed semper sapien at turpis accumsan, sed pellentesque orci volutpat. Nulla volutpat risus vitae nisi dapibus, vel porttitor justo aliquet. Donec nec tortor quis elit consequat lacinia eget quis odio. Cras molestie eleifend orci et euismod. Fusce auctor dui erat, iaculis dapibus nunc hendrerit non. Nullam et egestas urna, quis congue metus. Mauris nunc est, blandit ac nisl sed, pharetra dignissim nisi.\n\nSuspendisse nec posuere mi, vel commodo arcu. Donec a cursus risus, eu commodo urna. Nam pulvinar molestie mollis. Quisque cursus ultrices ornare. Proin tristique quam eu ante posuere, nec tincidunt neque tempus. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur imperdiet orci eu tincidunt ullamcorper. Proin fringilla, leo sed dictum gravida, mauris ligula malesuada lectus, in fermentum quam ligula ac lectus. Pellentesque mollis, lacus at ornare bibendum, lectus ante vestibulum arcu, id blandit ligula quam in mauris. Pellentesque rutrum urna et massa hendrerit egestas. Vivamus nunc quam, hendrerit cursus risus id, varius mollis odio. Vestibulum velit sem, mattis eu mattis sit amet, porta a eros. Maecenas vel pulvinar nisl. In molestie ornare pharetra.\n\nUt lacinia bibendum orci. Nulla tempus ex vitae elit aliquet, ut elementum odio venenatis. Mauris nec nunc at nisi fringilla sodales non at velit. Aliquam sit amet erat eros. Vestibulum facilisis magna eu gravida ultricies. Suspendisse vitae luctus mi. Mauris convallis lacinia turpis, vel pellentesque purus imperdiet quis. Donec id nibh vitae ex fringilla ultrices ut et felis. Pellentesque vel sapien ornare enim aliquet finibus. Sed vehicula neque a metus maximus ultricies. In dapibus lorem ac velit congue, vitae vulputate lacus efficitur. Fusce sit amet tortor ante. Fusce commodo commodo pellentesque. In hac habitasse platea dictumst.";

int main() {
	Window win;

	win.width = 50;
	win.height = 20;
	win.x = 5;
	win.y = 2;
	win.has_borders = 1;

	inittui();
	showcursor(0);
	showecho(0);

	int scroll = 0;
	int running = 1;

	while (running) {
		draw_window(&win);
		printfxy_to_window(&win, 0, scroll, lorem_ipsum);

		switch(getch()) {
			case 'j':
				--scroll;
				break;
			case 'k':
				++scroll;
				break;
			case 'q':
				running = 0;
				break;
		}
	}

	showecho(1);
	showcursor(1);

	endtui();
	return 0;
}
