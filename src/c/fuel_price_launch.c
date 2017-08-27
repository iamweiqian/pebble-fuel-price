#include <pebble.h>
#include "fuel_price_launch.h"

Window *launchWindow;
GBitmap *launchIcon;
BitmapLayer *launchIconLayer;
TextLayer *launchIconTitle;

void launch_window_load(Window *window) {
	Layer *window_layer = window_get_root_layer(window);
	
	launchIcon = gbitmap_create_with_resource(RESOURCE_ID_ICON_FUEL);
	launchIconLayer = bitmap_layer_create(GRect(0, 15, 144, 120));
	bitmap_layer_set_bitmap(launchIconLayer, launchIcon);
	bitmap_layer_set_compositing_mode(launchIconLayer, GCompOpSet);
	layer_add_child(window_layer, bitmap_layer_get_layer(launchIconLayer));
	
	launchIconTitle = text_layer_create(GRect(0, 120, 144, 50));
	text_layer_set_text(launchIconTitle, "Fuel Price");
	text_layer_set_text_alignment(launchIconTitle, GTextAlignmentCenter);
	layer_add_child(window_layer, text_layer_get_layer(launchIconTitle));
}

void launch_window_unload(Window *window) {
	gbitmap_destroy(launchIcon);
	bitmap_layer_destroy(launchIconLayer);
	text_layer_destroy(launchIconTitle);
}

void init() {
	launchWindow = window_create();
	window_set_window_handlers(launchWindow, (WindowHandlers) {
		.load = launch_window_load,
		.unload = launch_window_unload
	});
}

void deinit() {
	window_destroy(launchWindow);
}

Window *launch_window_get_window() {
	return launchWindow;
}
