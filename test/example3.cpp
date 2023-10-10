/* playing audio demo */
//#include "raincloud.h"
//using namespace rc;
//
//Camera cam = Camera();
//Audio audio = Audio();
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
//	if (init_window("hello world", vec2(160, 90), vec2(1600, 900)) != WINDOW_CONDITION::SUCCESS) {
//		return EXIT_FAILURE;
//	}
//	audio.load("your audio path here");
//	audio.play();
//	//audio.play_fade(5.0);
//	//audio.play_loop();
//	//audio.play_loop_fade(5.0);
//
//	register_process_func(process, draw);
//	start_main_loop();
//	uninit_window();
//}