/* pong demo */
//#include "raincloud.h"
//using namespace rc;
//
//Camera cam = Camera();
//Label score = Label();
//Label end = Label();
//
//bool finished = false;
//
//struct Player {
//	int score = 0;
//	float direction = 0.0f;
//	rect area;
//	Player(rect a) : area(a) {};
//	void draw() { draw_rect(cam, area.xy(), area.wh(), color(1, 1, 1, 1)); }
//};
//
//struct Ball {
//	int to = -1;
//	vec2 velocity = vec2(-10, 0);
//	rect area;
//	Ball(rect a) : area(a) {};
//	void draw() { draw_rect(cam, area.xy(), area.wh(), color(1, 1, 1, 1)); }
//};
//
//Player p1 = Player(rect(vec2(50, 300), vec2(30, 300)));
//Player p2 = Player(rect(vec2(1520, 300), vec2(30, 300)));
//Ball ball = Ball(rect(vec2(800 - 10, 450 - 10), vec2(20, 20)));
//
//void process(double deltaTime, FrameEvent event) {
//	if (finished == true) {
//		return;
//	}
//	if (event.pressedKeys[KEY_W]) {
//		p1.area.y -= 1000 * deltaTime;
//		p1.direction = -1;
//	}
//	else if (event.pressedKeys[KEY_S]) {
//		p1.area.y += 1000 * deltaTime;
//		p1.direction = 1;
//	}
//	else {
//		p1.direction = 0;
//	}
//	if (event.pressedKeys[KEY_UP]) {
//		p2.area.y -= 1000 * deltaTime;
//		p2.direction = -1;
//	}
//	else if (event.pressedKeys[KEY_DOWN]) {
//		p2.area.y += 1000 * deltaTime;
//		p2.direction = 1;
//	}
//	else {
//		p2.direction = 0;
//	}
//	p1.area.y = clamp(p1.area.y, 0, 900 - 300);
//	p2.area.y = clamp(p2.area.y, 0, 900 - 300);
//	if (rect::rect_vs_rect(p1.area, ball.area) == true && ball.velocity.x < 0) {
//		ball.velocity.x = -ball.velocity.x;
//		ball.velocity.y = p1.direction * get_rand(1.0, 10.0);
//	}
//	if (rect::rect_vs_rect(p2.area, ball.area) == true && ball.velocity.x > 0) {
//		ball.velocity.x = -ball.velocity.x;
//		ball.velocity.y = p2.direction * get_rand(1.0, 10.0);
//	}
//	if (ball.area.y < 0 && ball.velocity.y < 0) {
//		ball.velocity.y = -ball.velocity.y;
//	}
//	if (ball.area.y + ball.area.h > 900 && ball.velocity.y > 0) {
//		ball.velocity.y = -ball.velocity.y;
//	}
//	ball.area.x += ball.velocity.x;
//	ball.area.y += ball.velocity.y;
//	if (ball.area.x > 1600 - 20) {
//		p1.score++;
//		score.load(std::to_wstring(p1.score) + L" : " + std::to_wstring(p2.score), "C:\\Windows\\Fonts\\arial.ttf", 48);
//		ball.to = 1;
//		ball.velocity = vec2(ball.to * 10, 0);
//		ball.area = rect(vec2(800 - 10, 450 - 10), vec2(20, 20));
//		p1.area = rect(vec2(50, 300), vec2(30, 300));
//		p2.area = rect(vec2(1520, 300), vec2(30, 300));
//	}
//	if (ball.area.x < 0) {
//		p2.score++;
//		score.load(std::to_wstring(p1.score) + L" : " + std::to_wstring(p2.score), "C:\\Windows\\Fonts\\arial.ttf", 48);
//		ball.to = -1;
//		ball.velocity = vec2(ball.to * 10, 0);
//		ball.area = rect(vec2(800 - 10, 450 - 10), vec2(20, 20));
//		p1.area = rect(vec2(50, 300), vec2(30, 300));
//		p2.area = rect(vec2(1520, 300), vec2(30, 300));
//	}
//	if (p1.score > 2) {
//		end.load(L"Game Finished\nplayer1 win", "C:\\Windows\\Fonts\\arial.ttf", 36);
//		finished = true;
//	}
//	else if (p2.score > 2) {
//		end.load(L"Game Finished\nplayer2 win", "C:\\Windows\\Fonts\\arial.ttf", 36);
//		finished = true;
//	}
//}
//
//void draw() {
//	score.draw(cam);
//	p1.draw();
//	p2.draw();
//	ball.draw();
//	if (finished) {
//		end.draw(cam);
//	}
//}
//
//int main() {
//	WindowConfig config;
//	if (init_window("hello world", vec2(160, 90), vec2(1600, 900), config) != WINDOW_CONDITION::SUCCESS) {
//		return EXIT_FAILURE;
//	}
//	{
//		score.size.x = 1600;
//		score.align_mode = LabelAlignMode::Center;
//		score.font_color = color(1, 1, 1, 1);
//		score.load(std::to_wstring(p1.score) + L" : " + std::to_wstring(p2.score), "C:\\Windows\\Fonts\\arial.ttf", 48);
//		end.position.y = 600;
//		end.size.x = 1600;
//		end.align_mode = LabelAlignMode::Center;
//		end.font_color = color(1, 1, 1, 1);
//	}
//	register_process_func(process, draw);
//	start_main_loop();
//	uninit_window();
//}