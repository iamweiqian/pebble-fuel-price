#include <pebble.h>
#include "fuel_price_launch.h"
#include "fuel_price_main.h"
#include "fuel_price_error.h"

void launch_main_window(void *data) {
	window_stack_push(main_window_get_window(), true);
}

int main() {
	launch_window_create();
	main_window_create();
	error_window_create();
	
	window_stack_push(launch_window_get_window(), true);
	app_timer_register(1500, launch_main_window, NULL);
	
	app_event_loop();
	
	launch_window_destroy();
	main_window_destroy();
	error_window_destroy();
}