/* draw shapes demo */
#include "raincloud.h"
using namespace rc;

Camera cam = Camera();

void process(double deltaTime, FrameEvent event) {

}

void draw() {
	draw_line(cam, { 400, 400 }, { 600, 600 }, 2, { 1, 0, 0, 1 });
	draw_circle(cam, { 800, 450 }, 100, { 0, 1, 0, 1 });
	draw_rect(cam, { 500, 300 }, { 200, 80 }, { 0, 1, 1, 1 });
	draw_polygon(cam, { {500, 500}, {600, 400}, {650, 450}, {600, 500} }, { 1, 1, 0, 1 });
}

int main() {
	if (init_window("hello world", vec2(160, 90), vec2(1600, 900)) != WINDOW_CONDITION::SUCCESS) {
		return EXIT_FAILURE;
	}
	register_process_func(process, draw);
	set_background_color({ 0, 0, 0, 1 });
	start_main_loop();
	uninit_window();
}