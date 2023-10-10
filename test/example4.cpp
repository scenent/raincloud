/* render image demo */
//#include "raincloud.h"
//using namespace rc;
//
//Camera cam = Camera();
//Sprite sprite = Sprite();
//
//void process(double deltaTime, FrameEvent event) {
//
//}
//
//void draw() {
//	sprite.draw(cam);
//}
//
//int main() {
//	if (init_window("hello world", vec2(160, 90), vec2(1600, 900)) != WINDOW_CONDITION::SUCCESS) {
//		return EXIT_FAILURE;
//	}
//	sprite.load("your image path here");
//	//sprite.position = vec2(100, 100);
//	//sprite.scale = vec2(2, 1);
//	//sprite.pixel_filter = true;
//	//sprite.modulate = color(1, 0, 0, 1);
//
//	register_process_func(process, draw);
//	start_main_loop();
//	uninit_window();
//}