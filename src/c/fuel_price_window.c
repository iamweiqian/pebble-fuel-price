#include <pebble.h>
#include "fuel_price_window.h"

Window *mainWindow;

void main_window_load(Window *window) {
	
}

void main_window_unload(Window *window) {
	
}

void init() {
	mainWindow = window_create();
	window_set_window_handlers(mainWindow, (WindowHandlers) {
		.load = main_window_load,
		.unload = main_window_unload
	});
}

void deinit() {
	window_destroy(mainWindow);
}

Window *main_window_get_window() {
	return mainWindow;
}
