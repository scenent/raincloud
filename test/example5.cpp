/* window config demo */
//#include "raincloud.h"
//using namespace rc;
//
//Camera cam = Camera();
//
//void process(double deltaTime, FrameEvent event) {
//
//}
//
//void draw() {
//
//}
//
//int main() {
//	WindowConfig config;
//
//	config.allow_hidpi = true;
//	config.decorated = true;
//	config.focused = true;
//	config.fullscreen = false;
//	config.icon_path = "";
//	config.maximized = false;
//	config.resizeable = false;
//	config.visible = true;
//
//	if (init_window("hello world", vec2(160, 90), vec2(1600, 900), config) != WINDOW_CONDITION::SUCCESS) {
//		return EXIT_FAILURE;
//	}
//	register_process_func(process, draw);
//	start_main_loop();
//	uninit_window();
//}