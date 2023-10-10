#pragma once
#ifndef __RAINCLOUD_H__
#define __RAINCLOUD_H__

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define MINIAUDIO_IMPLEMENTATION
#define GLM_ENABLE_EXPERIMENTAL

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/glm.hpp"
#include "miniaudio/include/miniaudio.h"
#include "freetype/include/freetype/freetype.h"
#include "freetype/include/freetype/ftstroke.h"
#include "glad/include/glad/glad.h"
#include "GLFW/include/GLFW/glfw3.h"
#include "stb/include/stb_image.h"
#include "stb/include/stb_image_write.h"

#include <thread>
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <codecvt>
#include <fstream>
#include <locale>
#include <map>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

enum {
	RC_RELEASE = 0,
	RC_PRESS = 1,
};

#define KEY_UNKNOWN            -1
#define KEY_SPACE              32
#define KEY_APOSTROPHE         39
#define KEY_COMMA              44
#define KEY_MINUS              45
#define KEY_PERIOD             46
#define KEY_SLASH              47
#define KEY_0                  48
#define KEY_1                  49
#define KEY_2                  50
#define KEY_3                  51
#define KEY_4                  52
#define KEY_5                  53
#define KEY_6                  54
#define KEY_7                  55
#define KEY_8                  56
#define KEY_9                  57
#define KEY_SEMICOLON          59
#define KEY_EQUAL              61
#define KEY_A                  65
#define KEY_B                  66
#define KEY_C                  67
#define KEY_D                  68
#define KEY_E                  69
#define KEY_F                  70
#define KEY_G                  71
#define KEY_H                  72
#define KEY_I                  73
#define KEY_J                  74
#define KEY_K                  75
#define KEY_L                  76
#define KEY_M                  77
#define KEY_N                  78
#define KEY_O                  79
#define KEY_P                  80
#define KEY_Q                  81
#define KEY_R                  82
#define KEY_S                  83
#define KEY_T                  84
#define KEY_U                  85
#define KEY_V                  86
#define KEY_W                  87
#define KEY_X                  88
#define KEY_Y                  89
#define KEY_Z                  90
#define KEY_LEFT_BRACKET       91
#define KEY_BACKSLASH          92
#define KEY_RIGHT_BRACKET      93
#define KEY_GRAVE_ACCENT       96
#define KEY_WORLD_1            161
#define KEY_WORLD_2            162
#define KEY_ESCAPE             256
#define KEY_ENTER              257
#define KEY_TAB                258
#define KEY_BACKSPACE          259
#define KEY_INSERT             260
#define KEY_DELETE             261
#define KEY_RIGHT              262
#define KEY_LEFT               263
#define KEY_DOWN               264
#define KEY_UP                 265
#define KEY_PAGE_UP            266
#define KEY_PAGE_DOWN          267
#define KEY_HOME               268
#define KEY_END                269
#define KEY_CAPS_LOCK          280
#define KEY_SCROLL_LOCK        281
#define KEY_NUM_LOCK           282
#define KEY_PRINT_SCREEN       283
#define KEY_PAUSE              284
#define KEY_F1                 290
#define KEY_F2                 291
#define KEY_F3                 292
#define KEY_F4                 293
#define KEY_F5                 294
#define KEY_F6                 295
#define KEY_F7                 296
#define KEY_F8                 297
#define KEY_F9                 298
#define KEY_F10                299
#define KEY_F11                300
#define KEY_F12                301
#define KEY_F13                302
#define KEY_F14                303
#define KEY_F15                304
#define KEY_F16                305
#define KEY_F17                306
#define KEY_F18                307
#define KEY_F19                308
#define KEY_F20                309
#define KEY_F21                310
#define KEY_F22                311
#define KEY_F23                312
#define KEY_F24                313
#define KEY_F25                314
#define KEY_KP_0               320
#define KEY_KP_1               321
#define KEY_KP_2               322
#define KEY_KP_3               323
#define KEY_KP_4               324
#define KEY_KP_5               325
#define KEY_KP_6               326
#define KEY_KP_7               327
#define KEY_KP_8               328
#define KEY_KP_9               329
#define KEY_KP_DECIMAL         330
#define KEY_KP_DIVIDE          331
#define KEY_KP_MULTIPLY        332
#define KEY_KP_SUBTRACT        333
#define KEY_KP_ADD             334
#define KEY_KP_ENTER           335
#define KEY_KP_EQUAL           336
#define KEY_LEFT_SHIFT         340
#define KEY_LEFT_CONTROL       341
#define KEY_LEFT_ALT           342
#define KEY_LEFT_SUPER         343
#define KEY_RIGHT_SHIFT        344
#define KEY_RIGHT_CONTROL      345
#define KEY_RIGHT_ALT          346
#define KEY_RIGHT_SUPER        347
#define KEY_MENU               348

namespace rc {
	void setWindowFullscreen(bool flag);
	void setWindowIcon(std::string filePath);

	const double PI = 3.14159265358979323846;
	static inline std::wstring s2ws(std::string s) { return std::wstring(s.begin(), s.end()); }
	static inline std::string ws2s(std::wstring s) { return std::string(s.begin(), s.end()); }
	static inline float rad2deg(float r) { return (r * (180.0f / PI)); }
	static inline float deg2rad(float d) { return (d * (PI / 180.0f)); }
	static inline double rad2deg(double r) { return (r * (180.0 / PI)); }
	static inline double deg2rad(double d) { return (d * (PI / 180.0f)); }
	static inline float clamp(float a, float low, float high) { return max(low, min(a, high)); }
	static inline float lerp(float from, float to, float weight) { return from * (1 - weight) + to * weight; }
	static double get_rand(double min, double max) {
		static const double fraction = 1.0 / (RAND_MAX + 1.0);
		return min + ((max - min + 1) * (std::rand() * fraction));
	}
	static void alert(std::wstring msg) {
		MessageBox(NULL, msg.c_str(), L"Error", MB_ICONERROR | MB_OK);
	}
	static void write_file(std::string filePath, std::string content) {
		std::ofstream writeFile(filePath.data());
		if (writeFile.is_open()) {
			writeFile << content;
			writeFile.close();
		}
	}
	static void write_file_w(std::string filePath, std::wstring content) {
		std::wofstream writeFile(filePath);
		if (writeFile.is_open()) {
			writeFile << content;
			writeFile.close();
		}
	}
	static std::string read_file(std::string filePath) {
		std::ifstream openFile(filePath.data());
		std::string content = "";
		if (openFile.is_open()) {
			std::string line;
			while (getline(openFile, line)) {
				content += line + "\n";
			}
			openFile.close();
		}
		return content;
	}
	static size_t get_size_of_file(const std::wstring& path) {
		struct _stat fileinfo;
		_wstat(path.c_str(), &fileinfo);
		return fileinfo.st_size;
	}
	static std::wstring read_file_w(const std::wstring& filename) {
		std::wstring buffer;
		FILE* f;
		_wfopen_s(&f, filename.c_str(), L"rtS, ccs=UTF-8");
		if (f == NULL) {
			return buffer;
		}
		size_t filesize = get_size_of_file(filename);
		if (filesize > 0) {
			buffer.resize(filesize);
			size_t wchars_read = fread(&(buffer.front()), sizeof(wchar_t), filesize, f);
			buffer.resize(wchars_read);
			buffer.shrink_to_fit();
		}
		fclose(f);
		return buffer;
	}
	static std::vector<std::wstring> get_filenames_in_folder(std::wstring folder) {
		std::vector<std::wstring> names;
		std::wstring search_path = folder + L"/*.*";
		WIN32_FIND_DATA fd;
		HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					names.push_back(fd.cFileName);
				}
			} while (::FindNextFile(hFind, &fd));
			::FindClose(hFind);
		}
		return names;
	}
	static std::string get_current_path() {
		char buffer[MAX_PATH];
		GetModuleFileNameA(NULL, buffer, MAX_PATH);
		std::string::size_type pos = std::string(buffer).find_last_of("\\/");
		return std::string(buffer).substr(0, pos);
	}
	static inline bool file_exists(const std::string name) {
		std::ifstream f(name.c_str());
		return f.good();
	}
	static inline std::string get_parent_folder_path(const std::string path) {
		return path.substr(0, path.find_last_of("/\\"));
	}
	static inline bool ends_with(std::string const& value, std::string const& ending) {
		if (ending.size() > value.size()) return false;
		return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
	}
	static inline bool ends_with(std::wstring const& value, std::wstring const& ending) {
		if (ending.size() > value.size()) return false;
		return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
	}
	static inline bool starts_with(std::string str, std::string prefix) {
		if (prefix.size() > str.size()) return false;
		return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
	}
	static inline bool starts_with(std::wstring str, std::wstring prefix) {
		if (prefix.size() > str.size()) return false;
		return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
	}
	static std::string multibyte_to_utf8(std::string str) {
		std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> utf8Conv;
		return utf8Conv.to_bytes(s2ws(str).c_str());
	}
	static std::string multibyte_to_utf8(std::wstring str) {
		std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> utf8Conv;
		return utf8Conv.to_bytes(str.c_str());
	}
	static inline std::vector<std::string> split(std::string input, char delimiter) {
		std::vector<std::string> answer;
		std::stringstream ss(input);
		std::string temp;
		while (getline(ss, temp, delimiter)) {
			answer.push_back(temp);
		}
		return answer;
	}
	static inline std::vector<std::wstring> split(std::wstring input, wchar_t delimiter) {
		std::vector<std::wstring> answer;
		std::wstringstream ss(input);
		std::wstring temp;
		while (getline(ss, temp, delimiter)) {
			answer.push_back(temp);
		}
		return answer;
	}
	static std::wstring replace_all(std::wstring str, const std::wstring from, const std::wstring to) {
		if (from.empty())
			return L"";
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::wstring::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
		return str;
	}
	struct vec2 {
		float x, y;
		vec2() : x(0.0f), y(0.0f) {};
		vec2(int _x, int _y) : x(_x), y(_y) {};
		vec2(unsigned int _x, unsigned int _y) : x(_x), y(_y) {};
		vec2(float _x, float _y) : x(_x), y(_y) {};
		vec2(double _x, double _y) : x(_x), y(_y) {};
		~vec2() {};
		inline void operator=(const vec2& v) { x = v.x; y = v.y; }
		inline vec2 operator+(vec2 v) { return { x + v.x, y + v.y }; }
		inline vec2 operator-(vec2 v) { return { x - v.x, y - v.y }; }
		inline vec2 operator-() { return { -x, -y }; }
		inline vec2 operator*(float f) { return { x * f, y * f }; }
		inline vec2 operator/(float f) { return { x / f, y / f }; }
		inline vec2 operator/(vec2 v) { return { x / v.x, y / v.y }; }
		inline vec2 operator*(vec2 v) { return { x * v.x, y * v.y }; }
		inline void operator+=(vec2 v) { x += v.x; y += v.y; }
		inline void operator-=(vec2 v) { x -= v.x; y -= v.y; }
		inline void operator*=(float f) { x *= f; y *= f; }
		inline void operator/=(float f) { x /= f; y /= f; }
		inline bool operator==(vec2 v) { return x == v.x && y == v.y; }
		inline bool operator!=(vec2 v) { return !(v == *this); }
		inline float length() { return (sqrtf(powf(x, 2.0f) + powf(y, 2.0f))); }
		inline float distance_to(vec2 v) { vec2 temp = (v - (*this)); return (sqrtf(powf(temp.x, 2.0f) + powf(temp.y, 2.0f))); }
		inline void normalize() { if (length() == 0) { return; }vec2 temp = *this;  temp.x /= length(); temp.y /= length(); *this = temp; }
		inline vec2 normalized() { if (length() == 0) { return { 0, 0 }; }return { x / length(), y / length() }; }
		inline void rotate(float rad) { float s = sin(rad), c = cos(rad); float _x = x * c - y * s; float _y = x * s + y * c; x = _x; y = _y; }
		inline void rotate_based(float deg, vec2 base) {
			vec2 ret = { 0, 0 };
			ret.x = (x - base.x) * cos(deg2rad(deg)) - (y - base.y) * sin(deg2rad(deg)) + base.x;
			ret.y = (x - base.x) * sin(deg2rad(deg)) + (y - base.y) * cos(deg2rad(deg)) + base.y;
			this->x = ret.x;
			this->y = ret.y;
		}
		inline vec2 rotated(float rad) { float s = sin(rad), c = cos(rad);  float _x = x * c - y * s; float _y = x * s + y * c; x = _x; y = _y; return { _x, _y }; }
		inline vec2 rotated_based(float deg, vec2 base) {
			vec2 ret = { 0, 0 };
			ret.x = (x - base.x) * cos(deg2rad(deg)) - (y - base.y) * sin(deg2rad(deg)) + base.x;
			ret.y = (x - base.x) * sin(deg2rad(deg)) + (y - base.y) * cos(deg2rad(deg)) + base.y;
			return ret;
		}
		inline void scale_based(vec2 amount, vec2 base) {
			vec2 result = (*this);
			result -= base;
			result.x *= amount.x;
			result.y *= amount.y;
			result += base;
			*this = result;
		}
		inline vec2 scaledBased(vec2 amount, vec2 base) {
			vec2 result = (*this);
			result -= base;
			result.x *= amount.x;
			result.y *= amount.y;
			result += base;
			return result;
		}
		inline float get_rad() { return atan2f(y, x); }
		inline float get_degree() { return rad2deg(atan2f(y, x)); }
		inline static float dot(vec2 v1, vec2 v2) { return v1.x * v2.x + v1.y * v2.y; }
		inline static float cross(vec2 v1, vec2 v2) { return v1.x * v2.y - v1.y * v2.x; }
		inline static vec2 cross(vec2 v, float f) { return { f * v.y, -f * v.x }; }
		inline static vec2 cross(float f, vec2 v) { return { -f * v.y, f * v.x }; }
		inline float scala() { return (x + y) / 2.0f; }
		inline void print() { std::cout << "( " << x << ", " << y << " )\n"; }
		inline std::wstring str() { return L"vec2(" + std::to_wstring(x) + L", " + std::to_wstring(y) + L")"; }
		inline float* data() { float* result = new float[2]; result[0] = x; result[1] = y; return result; }
	};
	struct rect {
		float x = 0, y = 0, w = 0, h = 0;
		rect() {};
		rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {};
		rect(vec2 pos, vec2 size) : x(pos.x), y(pos.y), w(size.x), h(size.y) {};
		vec2 xy() {
			return vec2(x, y);
		}
		vec2 wh() {
			return vec2(w, h);
		}
		vec2 getCenter() {
			return { x + w / 2, y + h / 2 };
		}
		bool empty() {
			return (x == 0 && y == 0 && w == 0 && h == 0);
		}
		inline static bool rect_vs_rect(rect r1, rect r2) {
			return (r1.x + r1.w >= r2.x && r1.x <= r2.x + r2.w && r1.y + r1.h >= r2.y && r1.y <= r2.y + r2.h);
		}
		inline static bool point_vs_rect(vec2 point, rect rect) {
			return (rect.x <= point.x) && (point.x <= rect.x + rect.w) && (rect.y <= point.y) && (point.y <= rect.y + rect.h);
		}
		inline void print() {
			std::cout << "\n";
			std::cout << "x = " << x << "\n";
			std::cout << "y = " << y << "\n";
			std::cout << "w = " << w << "\n";
			std::cout << "h = " << h << "\n";
			std::cout << "\n";
		}
	};
	struct polygon {
		std::vector<vec2> vertices{};
		static bool polygon_vs_polygon(polygon p1, polygon p2) {
			int next = 0;
			for (int current = 0; current < p1.vertices.size(); current++) {
				next = current + 1;
				if (next == p1.vertices.size()) next = 0;
				vec2 vc = p1.vertices[current];
				vec2 vn = p1.vertices[next];
				bool collision = polygon::polygon_vs_line(p2, vc.x, vc.y, vn.x, vn.y);
				if (collision) return true;
				collision = polygon::point_vs_polygon({ p2.vertices[0].x, p2.vertices[0].y }, p1);
				if (collision) return true;
			}

			return false;
		}


		static bool polygon_vs_line(polygon p1, float x1, float y1, float x2, float y2) {
			int next = 0;
			for (int current = 0; current < p1.vertices.size(); current++) {
				next = current + 1;
				if (next == p1.vertices.size()) next = 0;
				float x3 = p1.vertices[current].x;
				float y3 = p1.vertices[current].y;
				float x4 = p1.vertices[next].x;
				float y4 = p1.vertices[next].y;
				bool hit = polygon::line_vs_line(x1, y1, x2, y2, x3, y3, x4, y4);
				if (hit) {
					return true;
				}
			}
			return false;
		}


		static bool line_vs_line(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
			float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
			float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
			if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
				return true;
			}
			return false;
		}


		static bool point_vs_polygon(vec2 point, polygon poly) {
			bool result = false;
			int next = 0;
			std::vector<vec2> v = poly.vertices;
			for (int current = 0; current < v.size(); current++) {
				next = current + 1;
				if (next == v.size()) next = 0;
				vec2 vc = v[current];
				vec2 vn = v[next];
				if (((vc.y >= point.y && vn.y < point.y) || (vc.y < point.y && vn.y >= point.y)) &&
					(point.x < (vn.x - vc.x) * (point.y - vc.y) / (vn.y - vc.y) + vc.x)) {
					result = !result;
				}
			}
			return result;
		}
	};
	struct color {
		float r, g, b, a;
		color(int _r, int _g, int _b, int _a) : r(_r), g(_g), b(_b), a(_a) {};
		color(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {};
		color(double _r, double _g, double _b, double _a) : r(_r), g(_g), b(_b), a(_a) {};
	};

	struct KeyInfo {
		int scancode, action, mods;
	};

	struct MouseInfo {
		struct MousePosition { double x_pos, y_pos; };
		struct MouseButton { int action, mods; };
		struct MouseScroll { double x_offset, y_offset; };
		MousePosition pos;
		MouseButton buttons[3];
		MouseScroll scroll;
	};

	struct WindowInfo {
		struct WindowSize { int width, height; };
		WindowSize size;
	};

	struct FrameEvent {
		KeyInfo justKeys[349];
		bool pressedKeys[349];
		MouseInfo mouse;
		WindowInfo window;
		void clear() {
			for (int i = 0; i < 3; i++) mouse.buttons[i] = { -1, 0 };
			for (int i = 0; i < 349; i++) justKeys[i] = { 0, 0, 0 };
			for (int i = 0; i < 349; i++) pressedKeys[i] = false;
			mouse.scroll = {};
		}
	};
	
	class Camera {
	public:
		vec2 position = vec2(0, 0);
		vec2 offset = vec2(800, 450);
		float rotation = 0.0f;
		vec2 zoom = vec2(1, 1);
		bool modify_movement = true;
	public:
		Camera() {};
		~Camera() {};
		glm::mat4 getViewMatrix();
	};

	class Object {
	public:
		vec2 position = { 0, 0 };
		vec2 size = { 0, 0 };
		vec2 scale = { 1, 1 };
		float rotation = 0.0f;
		vec2 pivot_offset = { 0, 0 };
		int z_order = 0;
		bool visible = true;
	public:
		virtual void update() = 0;
		virtual void draw(Camera& cam) = 0;
	};

	class Sprite : public Object {
	private:
		uint32_t id = 0;
		std::string file_path = "";
	public:
		color modulate = { 1, 1, 1, 1 };
		bool pixel_filter = false;
	public:
		Sprite();
		~Sprite();
		bool load(std::string _path);
		void update() override;
		void draw(Camera& cam) override;
	};

	enum class LabelWrapMode {
		Normal = 0, Word = 1
	};

	enum class LabelAlignMode {
		Begin, Center, End
	};

	struct Character {
		long int     data;
		unsigned int id;
		vec2         size;
		vec2         bearing;
		unsigned int advance;
	};

	class Label : public Object {
	private:
		vec2 glyph_size = { 0, 0 };
		std::vector<Character> outline_characters{};
		std::vector<Character> characters{};
		std::wstring text = L"";
		std::string font_path = "";
		int font_size = 16;
	public:
		float font_scale = 1.0f;
		color font_color = { 0, 0, 0, 1 };
		color outline_color = { 1, 1, 1, 1 };
		float outline_size = 0;
		float y_separation = 0.1f;
		float shaking = 0.0f;
		rect clipping_rect = { 0, 0, 0, 0 };
		double percent_visible = 1.0;
		bool wrap_text = true;
		LabelAlignMode align_mode = LabelAlignMode::Center;
		LabelWrapMode wrap_mode = LabelWrapMode::Normal;
	public:
		vec2 get_glyph_size() { return glyph_size; }
		Label() {};
		~Label() { for (auto& p : characters) { glDeleteTextures(1, &p.id); } for (auto& p : outline_characters) { glDeleteTextures(1, &p.id); }};
		void load(std::wstring _text, std::string _font_path, int _font_size = 16, float _outline_size = 0.0f);
		void update() override;
		void draw(Camera& cam) override;
	};

	class Audio {
	private:
		ma_decoder decoder{};
		ma_device_config deviceConfig{};
		ma_device device{};
		ma_engine engine{};
		std::string file_path = "";
		bool playing{ false };
		float volume = 1.0f;
	public:
		Audio() {};
		~Audio() { ma_device_uninit(&device); ma_decoder_uninit(&decoder); };
		void load(std::string _path);
		void play();
		void play_loop();
		void play_fade(float dur);
		void play_loop_fade(float dur);
		void stop();
		void stop_fade(float dur);
		void set_volume(float v);

		float get_volume() { return volume; }
		bool get_is_playing() { return playing; }
	};


	class Sgt {
		private:
			Sgt() {};
		public:
			static Sgt& instantiate() {
				static Sgt instance;
				return instance;
			}
			GLFWwindow* window = nullptr;
			double current_time = 0.0, last_time = 0.0;
			
			std::string WINDOW_TITLE = u8"";
			std::string WINDOW_ICON_PATH = "";
			int WINDOW_XPOS = 160;
			int WINDOW_YPOS = 90;
			int WINDOW_WIDTH = 1600;
			int WINDOW_HEIGHT = 900;
			int WINDOW_WIDTH_ORIGIN = 1600;
			int WINDOW_HEIGHT_ORIGIN = 900;
			bool WINDOW_FULLSCREEN = false;
			double WINDOW_TARGET_FPS = 60.0;
			FrameEvent currentFrameEvent{};

			color background_color = { 0.310f, 0.310f, 0.310f, 1.0f };
			std::function<void(double, FrameEvent)> update_function;
			std::function<void()> draw_function;
	};

	glm::mat4 Camera::getViewMatrix() {
		vec2 off = offset;
		if (modify_movement == true) {
			vec2 pos = position;
			pos.rotate(rotation);
			glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-pos.x, pos.y, 0.0f));
			view = glm::translate(view, glm::vec3(pos.x + off.x, ((float)Sgt::instantiate().WINDOW_HEIGHT - pos.y - off.y), 0.0f));
			view = glm::rotate(view, rotation, glm::vec3(0, 0, 1));
			view = glm::scale(view, glm::vec3(zoom.x, zoom.y, 1.0f));
			view = glm::translate(view, glm::vec3(-(pos.x + off.x), -((float)Sgt::instantiate().WINDOW_HEIGHT - pos.y - off.y), 0.0f));
			return view;
		}
		else {
			glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-position.x, position.y, 0.0f));
			view = glm::translate(view, glm::vec3(position.x + off.x, ((float)Sgt::instantiate().WINDOW_HEIGHT - position.y - off.y), 0.0f));
			view = glm::rotate(view, rotation, glm::vec3(0, 0, 1));
			view = glm::scale(view, glm::vec3(zoom.x, zoom.y, 1.0f));
			view = glm::translate(view, glm::vec3(-(position.x + off.x), -((float)Sgt::instantiate().WINDOW_HEIGHT - position.y - off.y), 0.0f));
			return view;
		}
	}

	Sprite::Sprite() {

	}

	Sprite::~Sprite() {
		if (id != 0) glDeleteTextures(1, &id);
	}

	bool Sprite::load(std::string _path) {
		file_path = _path;
		if (file_path == "") return false;
		if (id != 0) glDeleteTextures(1, &id);
		int width, height, channels;
		unsigned char* data = stbi_load(file_path.c_str(), &width, &height, &channels, 0);
		this->size.x = width;
		this->size.y = height;
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, pixel_filter == true ? GL_LINEAR : GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, pixel_filter == true ? GL_LINEAR : GL_NEAREST);
		if (channels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		else if (channels == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		else {
			stbi_image_free(data);
			alert(s2ws(file_path + " :: cannot load image file :: invalid channels " + std::to_string(channels)));
			return false;
		}
		stbi_image_free(data);
		return true;
	}

	void Sprite::update() {

	}

	void Sprite::draw(Camera& cam) {
		if (!visible || file_path == "") return;
		glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, Sgt::instantiate().WINDOW_WIDTH_ORIGIN, 0, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, id);
		glPushMatrix();
		glMultMatrixf(glm::value_ptr(cam.getViewMatrix()));
		glTranslatef(position.x + (pivot_offset.x / scale.x), (Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - position.y - (pivot_offset.y / scale.y)), 0.0f);
		glScalef(scale.x, scale.y, 1.0f);
		glRotatef(rotation, 0, 0, 1);
		glTranslatef(-(position.x + (pivot_offset.x / scale.x)), -(Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - position.y - (pivot_offset.y / scale.y)), 0.0f);
		glColor4f(modulate.r, modulate.g, modulate.b, modulate.a);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(position.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(position.y + size.y));
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(position.x + size.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(position.y + size.y));
		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(position.x + size.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(position.y));
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(position.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(position.y));
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	void Label::load(std::wstring _text, std::string _font_path, int _font_size, float _outline_size) {
		text = _text;
		text = replace_all(text, L"\\n", L"\n");
		font_path = _font_path;
		font_size = _font_size;
		outline_size = _outline_size;
		for (auto& p : characters) glDeleteTextures(1, &p.id);
		for (auto& p : outline_characters) glDeleteTextures(1, &p.id);
		characters.clear();
		outline_characters.clear();
		FT_Library ft;
		FT_Init_FreeType(&ft);
		std::ifstream test(_font_path); 
		if (!test) alert(s2ws(_font_path + "cannot load font file. :: " + _font_path));
		FT_Face face;
		if (FT_New_Face(ft, _font_path.c_str(), 0, &face)) 
			alert(s2ws("cannot make new face :: " + font_path));
		FT_Set_Pixel_Sizes(face, 0, _font_size);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		FT_Stroker stroker;
		FT_Stroker_New(ft, &stroker);
		FT_Stroker_Set(stroker, outline_size * 64, FT_STROKER_LINECAP_ROUND, FT_STROKER_LINEJOIN_ROUND, 0);
		for (int c = 0; c < text.size(); c++) {
			if (FT_Load_Char(face, text[c], FT_LOAD_RENDER)) {
				alert(L"failed to load glyph");
				continue;
			}
			unsigned int texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexImage2D( GL_TEXTURE_2D, 0, GL_ALPHA, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
			Character character = { text[c], texture, vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows), vec2(face->glyph->bitmap_left, face->glyph->bitmap_top), static_cast<unsigned int>(face->glyph->advance.x)};
			characters.push_back(character);
			glBindTexture(GL_TEXTURE_2D, 0);
			if (outline_size == 0.0f) continue;
			FT_UInt glyphIndex = FT_Get_Char_Index(face, text[c]);
			FT_Load_Glyph(face, glyphIndex, FT_LOAD_DEFAULT);
			FT_Glyph glyph;
			FT_Get_Glyph(face->glyph, &glyph);
			FT_Glyph_StrokeBorder(&glyph, stroker, false, true);
			FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_NORMAL, nullptr, true);
			FT_BitmapGlyph bitmapGlyph = reinterpret_cast<FT_BitmapGlyph>(glyph);
			unsigned int texture1;
			glGenTextures(1, &texture1);
			glBindTexture(GL_TEXTURE_2D, texture1);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, bitmapGlyph->bitmap.width, bitmapGlyph->bitmap.rows, 0, GL_ALPHA,GL_UNSIGNED_BYTE, bitmapGlyph->bitmap.buffer);
			Character character1 = { text[c], texture1, vec2(bitmapGlyph->bitmap.width, bitmapGlyph->bitmap.rows), vec2(bitmapGlyph->left, bitmapGlyph->top), static_cast<unsigned int>(glyph->advance.x)};
			outline_characters.push_back(character1);
		}
		FT_Done_Face(face);
		FT_Done_FreeType(ft);
	}

	void Label::update() {

	}

	void Label::draw(Camera& cam) {
		if (!visible) return;
		if (percent_visible < 0.0) percent_visible = 0.0;
		if (percent_visible > 1.0) percent_visible = 1.0;

		int real_widths_index = 0;
		std::vector<float> real_widths{};
		float temp_real_width = 0.0f;
		for (int i = 0; i < characters.size(); i++) {
			if (characters[i].data == L'\n' || i == characters.size() - 1) {
				real_widths.push_back(temp_real_width);
				temp_real_width = 0.0f;
			}
			else {
				temp_real_width += characters[i].advance >> 6;
			}
		}
		
		float x = position.x, y = Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - position.y;
		if (align_mode == LabelAlignMode::Center) {
			x = (size.x / 2.0) - (real_widths[real_widths_index] / 2.0);
		}
		else if (align_mode == LabelAlignMode::End) {
			x = size.x - real_widths[real_widths_index];
		}
		float line = 1;
		float max_width = 0.0f;
		float width = 0;
		if (wrap_text == false) {
			glEnable(GL_SCISSOR_TEST);
			glScissor(position.x - cam.position.x, Sgt::instantiate().WINDOW_HEIGHT - (position.y + size.y - cam.position.y), size.x, size.y);
		}
		if (clipping_rect.empty() == false) {
			glEnable(GL_SCISSOR_TEST);
			glScissor(clipping_rect.x - cam.position.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - (clipping_rect.y + clipping_rect.h - cam.position.y), clipping_rect.w, clipping_rect.h);
		}
		for (int index = 0; index < int(text.size() * percent_visible); index++) {
			Character ch = characters[index];
			float xpos = (x + ch.bearing.x * font_scale);
			float ypos = (y - (ch.size.y - ch.bearing.y) * font_scale);
			float w = ch.size.x * font_scale;
			float h = ch.size.y * font_scale;
			Character o_ch{}; float o_xpos = 0, o_ypos = 0, o_w = 0, o_h = 0;
			if (outline_size != 0) {
				o_ch = outline_characters[index];
				o_xpos = (x + o_ch.bearing.x * font_scale);
				o_ypos = (y - (o_ch.size.y - o_ch.bearing.y) * font_scale);
				o_w = o_ch.size.x * font_scale;
				o_h = o_ch.size.y * font_scale;
				if (ch.data == L'\n') {
					width = 0;
					real_widths_index++;
					x = position.x;
					if (align_mode == LabelAlignMode::Center) {
						x = (size.x / 2.0) - (real_widths[real_widths_index] / 2.0);
					}
					else if (align_mode == LabelAlignMode::End) {
						x = size.x - real_widths[real_widths_index];
					}
					line++;
					line += y_separation;
					continue;
				}
				if (wrap_mode == LabelWrapMode::Word) {
					if (ch.data == ' ') {
						float rest_size = 0.0f;
						int k = index + 1;
						while (k < characters.size() && characters[k].data != ' ') {
							rest_size += characters[k].advance >> 6;
							k++;
						}
						if (rest_size + width > size.x) {
							width = 0;
							x = position.x;
							o_xpos = position.x + o_ch.bearing.x * font_scale;
							line++;
							line += y_separation;
						}
					}
				}
				if (wrap_text == true && index + 1 < characters.size() && width + w + characters[index + 1].size.x * font_scale > size.x) {
					width = 0;
					x = position.x;
					o_xpos = position.x + o_ch.bearing.x * font_scale;
					line++;
					line += y_separation;
				}
				glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glOrtho(0, Sgt::instantiate().WINDOW_WIDTH_ORIGIN, 0, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, 0, 1);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();

				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, o_ch.id);
				glPushMatrix();
				glMultMatrixf(glm::value_ptr(cam.getViewMatrix()));

				glTranslatef(position.x + (pivot_offset.x / scale.x), (Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - position.y - (pivot_offset.y / scale.y)), 0.0f);
				glRotatef(rotation, 0, 0, 1);
				glScalef(scale.x, scale.y, 1.0f);
				glTranslatef(-(position.x + (pivot_offset.x / scale.x)), -(Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - position.y - (pivot_offset.y / scale.y)), 0.0f);

				if (shaking != 0.0) glTranslated(get_rand(-shaking, shaking), get_rand(-shaking, shaking), 0);

				glColor4f(outline_color.r, outline_color.g, outline_color.b, outline_color.a);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 1.0f);
				glVertex2f(o_xpos, o_ypos - (line * font_size));
				glTexCoord2f(1.0f, 1.0f);
				glVertex2f(o_xpos + o_w, o_ypos - (line * font_size));
				glTexCoord2f(1.0f, 0.0f);
				glVertex2f(o_xpos + o_w, o_ypos + o_h - (line * font_size));
				glTexCoord2f(0.0f, 0.0f);
				glVertex2f(o_xpos, o_ypos + o_h - (line * font_size));
				glEnd();
				glPopMatrix();
				glDisable(GL_TEXTURE_2D);
				width += ch.advance >> 6;
				if (width > max_width) max_width = width;
				x += (ch.advance >> 6) * font_scale;
			}
		}
		x = position.x; y = Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - position.y;
		real_widths_index = 0;
		if (align_mode == LabelAlignMode::Center) {
			x = (size.x / 2.0) - (real_widths[real_widths_index] / 2.0);
		}
		else if (align_mode == LabelAlignMode::End) {
			x = size.x - real_widths[real_widths_index];
		}
		line = 1;
		max_width = 0.0f;
		width = 0;

		for (int index = 0; index < int(text.size() * percent_visible); index++) {
			Character ch = characters[index];
			float xpos = (x + ch.bearing.x * font_scale);
			float ypos = (y - (ch.size.y - ch.bearing.y) * font_scale);
			float w = ch.size.x * font_scale;
			float h = ch.size.y * font_scale;
			if (ch.data == L'\n') {
				width = 0;
				real_widths_index++;
				x = position.x;
				if (align_mode == LabelAlignMode::Center) {
					x = (size.x / 2.0) - (real_widths[real_widths_index] / 2.0);
				}
				else if (align_mode == LabelAlignMode::End) {
					x = size.x - real_widths[real_widths_index];
				}
				line++;
				line += y_separation;
				continue;
			}
			if (wrap_mode == LabelWrapMode::Word) {
				if (ch.data == ' ') {
					float rest_size = 0.0f;
					int k = index + 1;
					while (k < characters.size() && characters[k].data != ' ') {
						rest_size += characters[k].advance >> 6;
						k++;
					}
					if (rest_size + width > size.x) {
						width = 0;
						x = position.x;
						xpos = position.x + ch.bearing.x * font_scale;
						line++;
						line += y_separation;
					}
				}
			}
			if (wrap_text == true && index + 1 < characters.size() && width + w + characters[index + 1].size.x * font_scale > size.x) {
				width = 0;
				x = position.x;
				xpos = position.x + ch.bearing.x * font_scale;
				line++;
				line += y_separation;
			}
			glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(0, Sgt::instantiate().WINDOW_WIDTH_ORIGIN, 0, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, 0, 1);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ch.id);
			glPushMatrix();
			glMultMatrixf(glm::value_ptr(cam.getViewMatrix()));
			glTranslatef(position.x + (pivot_offset.x / scale.x), (Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - position.y - (pivot_offset.y / scale.y)), 0.0f);
			glRotatef(rotation, 0, 0, 1);
			glScalef(scale.x, scale.y, 1.0f);
			glTranslatef(-(position.x + (pivot_offset.x / scale.x)), -(Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - position.y - (pivot_offset.y / scale.y)), 0.0f);
			if (shaking != 0.0) glTranslated(get_rand(-shaking, shaking), get_rand(-shaking, shaking), 0);
			glColor4f(font_color.r, font_color.g, font_color.b, font_color.a);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f);
			glVertex2f(xpos, ypos - (line * font_size));
			glTexCoord2f(1.0f, 1.0f);
			glVertex2f(xpos + w, ypos - (line * font_size));
			glTexCoord2f(1.0f, 0.0f);
			glVertex2f(xpos + w, ypos + h - (line * font_size));
			glTexCoord2f(0.0f, 0.0f);
			glVertex2f(xpos, ypos + h - (line * font_size));
			glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
			width += ch.advance >> 6;
			if (width > max_width) max_width = width;
			x += (ch.advance >> 6) * font_scale;
		}
		if (wrap_text == false || clipping_rect.empty() == false) {
			glDisable(GL_SCISSOR_TEST);
		}
		glyph_size.x = max_width;
		glyph_size.y = line * font_size;
	}

	static void ma_data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
		ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
		if (pDecoder == NULL) {
			return;
		}
		ma_data_source_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);
		(void)pInput;
	}

	static void fadeout_audio(Audio* target, float duration) {
		float step = target->get_volume() / (duration * 10.0f);
		while (target->get_volume() > 0.0f) {
			target->set_volume(target->get_volume() - step);
			Sleep(100);
		}
		target->set_volume(0.0f);
		target->stop();
	}

	static void fadein_audio(Audio* target, float duration) {
		float end = target->get_volume();
		float step = target->get_volume() / (duration * 10.0f);
		target->set_volume(0.0f);
		while (target->get_volume() < end) {
			target->set_volume(target->get_volume() + step);
			Sleep(100);
		}
		target->set_volume(end);
	}

	void Audio::load(std::string _path) {
		file_path = _path;
		ma_result result;
		result = ma_decoder_init_file(file_path.c_str(), NULL, &decoder);
		if (result != MA_SUCCESS) { printf("Could not load file\n"); }
		deviceConfig = ma_device_config_init(ma_device_type_playback);
		deviceConfig.playback.format = decoder.outputFormat;
		deviceConfig.playback.channels = decoder.outputChannels;
		deviceConfig.sampleRate = decoder.outputSampleRate;
		deviceConfig.dataCallback = ma_data_callback;
		deviceConfig.pUserData = &decoder;
		if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
			std::cout << "failed to open playback device.\n";
			ma_decoder_uninit(&decoder);
		}
		if (ma_device_start(&device) != MA_SUCCESS) {
			std::cout << "Failed to start playback device.\n";
			ma_device_uninit(&device);
			ma_decoder_uninit(&decoder);
		}
		ma_device_stop(&device);
	}

	void Audio::play() {
		playing = true;
		ma_device_start(&device);
	}

	void Audio::play_loop() {
		ma_data_source_set_looping(&decoder, MA_TRUE);
		playing = true;
		ma_device_start(&device);
	}

	void Audio::play_fade(float dur) {
		std::thread t(fadein_audio, this, dur);
		t.detach();
		if (t.joinable())t.join();
		play();
	}

	void Audio::play_loop_fade(float dur) {
		std::thread t(fadein_audio, this, dur);
		t.detach();
		if (t.joinable())t.join();
		play_loop();
	}

	void Audio::stop() {
		ma_device_stop(&device);
		playing = false;
	}

	void Audio::stop_fade(float dur) {
		std::thread t(fadeout_audio, this, dur);
		t.detach();
		if (t.joinable())t.join();
	}

	void Audio::set_volume(float v) {
		ma_device_set_master_volume(&device, clamp(v, 0.0f, 1.0f));
		volume = v;
	}

	struct WindowConfig {
		bool resizeable = false;
		bool focused = true;
		bool visible = true;
		bool decorated = true;
		bool maximized = false;
		bool allow_hidpi = true;
		bool fullscreen = false;
		std::string icon_path = "";
	};

	static void bufferSizeCallback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
		Sgt::instantiate().currentFrameEvent.window.size = { width, height };
		Sgt::instantiate().WINDOW_WIDTH = width;
		Sgt::instantiate().WINDOW_HEIGHT = height;
	}

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Sgt::instantiate().currentFrameEvent.justKeys[key] = { scancode, action, mods };
	}
	
	static void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
		if (Sgt::instantiate().WINDOW_FULLSCREEN == true) {
			vec2 mousePos(xoffset, yoffset);
			mousePos.scale_based(vec2((float)Sgt::instantiate().WINDOW_WIDTH_ORIGIN / (float)Sgt::instantiate().WINDOW_WIDTH, (float)Sgt::instantiate().WINDOW_HEIGHT_ORIGIN / (float)Sgt::instantiate().WINDOW_HEIGHT), vec2(0, 0));
			Sgt::instantiate().currentFrameEvent.mouse.scroll.x_offset = mousePos.x;
			Sgt::instantiate().currentFrameEvent.mouse.scroll.y_offset = mousePos.y;
		}
		else {
			Sgt::instantiate().currentFrameEvent.mouse.scroll.x_offset = xoffset;
			Sgt::instantiate().currentFrameEvent.mouse.scroll.y_offset = yoffset;
		}
	}
	
	static void mousePosCallback(GLFWwindow* window, double xpos, double ypos) {
		Sgt::instantiate().currentFrameEvent.mouse.pos.x_pos = xpos;
		Sgt::instantiate().currentFrameEvent.mouse.pos.y_pos = ypos;
	}
	
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		Sgt::instantiate().currentFrameEvent.mouse.buttons[button] = { action, mods };
	}
	
	static void windowCloseCallback(GLFWwindow* window) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	
	static void setCharCallback(GLFWwindow* window, unsigned int codepoint) {

	}

	enum WINDOW_CONDITION {
		SUCCESS, GLFW_INIT_FAILURE, GLFW_CREATING_WINDOW_FAILURE, GLAD_LOAD_FAILURE 
	};

	static WINDOW_CONDITION init_window(std::string window_title, vec2 window_position, vec2 window_size, WindowConfig window_flags = {}) {
		Sgt::instantiate().WINDOW_XPOS = window_position.x;
		Sgt::instantiate().WINDOW_YPOS = window_position.y;
		Sgt::instantiate().WINDOW_WIDTH = window_size.x;
		Sgt::instantiate().WINDOW_HEIGHT = window_size.y;
		Sgt::instantiate().WINDOW_WIDTH_ORIGIN = window_size.x;
		Sgt::instantiate().WINDOW_HEIGHT_ORIGIN = window_size.y;
		if (glfwInit() == GLFW_FALSE) {
			return WINDOW_CONDITION::GLFW_INIT_FAILURE;
		}
		glfwWindowHint(GLFW_RESIZABLE, window_flags.resizeable);
		glfwWindowHint(GLFW_FOCUSED, window_flags.focused);
		glfwWindowHint(GLFW_VISIBLE, window_flags.visible);
		glfwWindowHint(GLFW_DECORATED, window_flags.decorated);
		glfwWindowHint(GLFW_MAXIMIZED, window_flags.maximized);
		glfwWindowHint(GLFW_SCALE_TO_MONITOR, window_flags.allow_hidpi);
		Sgt::instantiate().window = glfwCreateWindow(window_size.x, window_size.y, multibyte_to_utf8(window_title).c_str(), NULL, NULL);
		if (!Sgt::instantiate().window) return WINDOW_CONDITION::GLFW_CREATING_WINDOW_FAILURE;
		glfwMakeContextCurrent(Sgt::instantiate().window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return WINDOW_CONDITION::GLAD_LOAD_FAILURE;
		setWindowFullscreen(window_flags.fullscreen);
		if (window_flags.icon_path != "") {
			setWindowIcon(window_flags.icon_path);
		}
		glfwSetFramebufferSizeCallback(Sgt::instantiate().window, bufferSizeCallback);
		glfwSetKeyCallback(Sgt::instantiate().window, keyCallback);
		glfwSetScrollCallback(Sgt::instantiate().window, mouseScrollCallback);
		glfwSetCursorPosCallback(Sgt::instantiate().window, mousePosCallback);
		glfwSetMouseButtonCallback(Sgt::instantiate().window, mouseButtonCallback);
		glfwSetWindowCloseCallback(Sgt::instantiate().window, windowCloseCallback);
		glfwSetCharCallback(Sgt::instantiate().window, setCharCallback);
		glfwSwapInterval(1);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, Sgt::instantiate().WINDOW_WIDTH, 0, Sgt::instantiate().WINDOW_HEIGHT, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		return WINDOW_CONDITION::SUCCESS;
	}

	static void register_process_func(std::function<void(double, FrameEvent)> on_update, std::function<void()> on_draw) {
		Sgt::instantiate().update_function = on_update;
		Sgt::instantiate().draw_function = on_draw;
	}

	static void set_background_color(color _color) {
		Sgt::instantiate().background_color = _color;
	}

	static void start_main_loop() {
		while (glfwWindowShouldClose(Sgt::instantiate().window) == false) {
			Sgt::instantiate().current_time = Sgt::instantiate().last_time;
			while (glfwGetTime() <= Sgt::instantiate().last_time + 1.0 / Sgt::instantiate().WINDOW_TARGET_FPS);
			Sgt::instantiate().last_time += 1.0 / Sgt::instantiate().WINDOW_TARGET_FPS;
			glfwPollEvents();
			for (int i = 0; i < 349; i++) { Sgt::instantiate().currentFrameEvent.pressedKeys[i] = glfwGetKey(Sgt::instantiate().window, i); }
			Sgt::instantiate().update_function(Sgt::instantiate().last_time - Sgt::instantiate().current_time, Sgt::instantiate().currentFrameEvent);
			Sgt::instantiate().currentFrameEvent.clear();
			glClearColor(Sgt::instantiate().background_color.r, Sgt::instantiate().background_color.g, Sgt::instantiate().background_color.b, Sgt::instantiate().background_color.a);
			glClear(GL_COLOR_BUFFER_BIT);
			Sgt::instantiate().draw_function();
			glfwSwapBuffers(Sgt::instantiate().window);
		}
	}

	static void quit_main_loop() {
		glfwSetWindowShouldClose(Sgt::instantiate().window, true);
	}

	static void uninit_window() {
		glfwDestroyWindow(Sgt::instantiate().window);
		glfwTerminate();
	}

	static void setWindowFullscreen(bool flag) {
		Sgt::instantiate().WINDOW_FULLSCREEN = flag;
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);
		if (flag == true) {
			glfwSetWindowMonitor(Sgt::instantiate().window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
			Sgt::instantiate().WINDOW_WIDTH = mode->width;
			Sgt::instantiate().WINDOW_HEIGHT = mode->height;
		}
		else {
			glfwSetWindowMonitor(Sgt::instantiate().window, nullptr, (mode->width / 2) - (Sgt::instantiate().WINDOW_WIDTH_ORIGIN / 2), (mode->height / 2) - (Sgt::instantiate().WINDOW_HEIGHT_ORIGIN / 2), Sgt::instantiate().WINDOW_WIDTH_ORIGIN, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, GLFW_DONT_CARE);
			Sgt::instantiate().WINDOW_WIDTH = Sgt::instantiate().WINDOW_WIDTH_ORIGIN;
			Sgt::instantiate().WINDOW_HEIGHT = Sgt::instantiate().WINDOW_HEIGHT_ORIGIN;
		}
	}

	static void setWindowIcon(std::string filePath) {
		if (filePath.empty()) return;
		GLFWimage images[1];
		stbi_set_flip_vertically_on_load(false);
		images[0].pixels = stbi_load(filePath.c_str(), &images[0].width, &images[0].height, 0, 4);
		glfwSetWindowIcon(Sgt::instantiate().window, 1, images);
		stbi_image_free(images[0].pixels);
	}

	static void set_window_fullscreen(bool flag) {
		setWindowFullscreen(flag);
	}

	static void set_window_icon(std::string _path) {
		setWindowIcon(_path);
	}

	static void draw_line(Camera& cam, vec2 p1, vec2 p2, float width, color _color) {
		glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, Sgt::instantiate().WINDOW_WIDTH_ORIGIN, 0, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glMultMatrixf(glm::value_ptr(cam.getViewMatrix()));
		glLineWidth(width);
		glBegin(GL_LINES);
		glColor4f(_color.r, _color.g, _color.b, _color.a);
		glVertex2f(p1.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - p1.y);
		glVertex2f(p2.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - p2.y);
		glEnd();
		glPopMatrix();
	}

	static void draw_circle(Camera& cam, vec2 pos, float radius, color _color) {
		glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, Sgt::instantiate().WINDOW_WIDTH_ORIGIN, 0, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glMultMatrixf(glm::value_ptr(cam.getViewMatrix()));
		glBegin(GL_TRIANGLE_FAN);
		glColor4f(_color.r, _color.g, _color.b, _color.a);
		for (int ii = 0; ii < 360; ii++) {
			float theta = 2.0f * 3.1415926f * float(ii) / float(360);
			float x = radius * cosf(theta);
			float y = radius * sinf(theta);
			glVertex2f(x + pos.x - cam.position.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(y + pos.y) - cam.position.y);
		}
		glEnd();
		glPopMatrix();
	}

	static void draw_polygon(Camera& cam, std::vector<vec2> vertices, color _color) {
		glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, Sgt::instantiate().WINDOW_WIDTH_ORIGIN, 0, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glMultMatrixf(glm::value_ptr(cam.getViewMatrix()));
		glBegin(GL_TRIANGLE_FAN);
		glColor4f(_color.r, _color.g, _color.b, _color.a);
		for (auto& p : vertices) {
			glVertex2f(p.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - p.y);
		}
		glEnd();
		glPopMatrix();
	}

	static void draw_rect(Camera& cam, vec2 position, vec2 size, color _color) {
		glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, Sgt::instantiate().WINDOW_WIDTH_ORIGIN, 0, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glMultMatrixf(glm::value_ptr(cam.getViewMatrix()));
		glBegin(GL_QUADS);
		glColor4f(_color.r, _color.g, _color.b, _color.a);
		glVertex2f(position.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(position.y + size.y));
		glVertex2f(position.x + size.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(position.y + size.y));
		glVertex2f(position.x + size.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(position.y));
		glVertex2f(position.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(position.y));
		glEnd();
		glPopMatrix();
	}

	void draw_circle_ex(Camera& cam, vec2 pos, float radius, float rotation, vec2 pivot_offset, vec2 scale, color _color) {
		glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, Sgt::instantiate().WINDOW_WIDTH_ORIGIN, 0, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glMultMatrixf(glm::value_ptr(cam.getViewMatrix()));
		glTranslatef(pos.x + (pivot_offset.x / scale.x), (Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - pos.y - (pivot_offset.y / scale.y)), 0.0f);
		glRotatef(rotation, 0, 0, 1);
		glScalef(scale.x, scale.y, 1.0f);
		glTranslatef(-(pos.x + (pivot_offset.x / scale.x)), -(Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - pos.y - (pivot_offset.y / scale.y)), 0.0f);
		glBegin(GL_TRIANGLE_FAN);
		glColor4f(_color.r, _color.g, _color.b, _color.a);
		for (int ii = 0; ii < 360; ii++) {
			float theta = 2.0f * 3.1415926f * float(ii) / float(360);
			float x = radius * cosf(theta);
			float y = radius * sinf(theta);
			glVertex2f(x + pos.x + cam.position.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(y + pos.y) - cam.position.y);
		}
		glEnd();
		glPopMatrix();
	}

	void draw_rect_ex(Camera& cam, vec2 pos, vec2 size, float rotation, vec2 pivot_offset, vec2 scale, color _color) {
		glViewport(0.0f, 0.0f, Sgt::instantiate().WINDOW_WIDTH, Sgt::instantiate().WINDOW_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, Sgt::instantiate().WINDOW_WIDTH_ORIGIN, 0, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glMultMatrixf(glm::value_ptr(cam.getViewMatrix()));
		glTranslatef(pos.x + (pivot_offset.x / scale.x), (Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - pos.y - (pivot_offset.y / scale.y)), 0.0f);
		glRotatef(rotation, 0, 0, 1);
		glScalef(scale.x, scale.y, 1.0f);
		glTranslatef(-(pos.x + (pivot_offset.x / scale.x)), -(Sgt::instantiate().WINDOW_HEIGHT_ORIGIN - pos.y - (pivot_offset.y / scale.y)), 0.0f);
		glBegin(GL_QUADS);
		glColor4f(_color.r, _color.b, _color.g, _color.a);
		glVertex2f(pos.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(pos.y + size.y));
		glVertex2f(pos.x + size.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(pos.y + size.y));
		glVertex2f(pos.x + size.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(pos.y));
		glVertex2f(pos.x, Sgt::instantiate().WINDOW_HEIGHT_ORIGIN + -(pos.y));
		glEnd();
		glPopMatrix();
	}
}


#endif