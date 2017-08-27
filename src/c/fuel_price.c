#include <pebble.h>
#include "fuel_price_launch.h"

int main() {
	init();
	window_stack_push(launch_window_get_window(), true);
	app_event_loop();
	deinit();
}