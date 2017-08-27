#include <pebble.h>
#include "fuel_price_window.h"

int main() {
	init();
	window_stack_push(main_window_get_window(), true);
	app_event_loop();
	deinit();
}