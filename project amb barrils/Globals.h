#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);
void log(const char file[], int line, const char* format, ...);

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Useful typedefs ---------
typedef unsigned int uint;

// Configuration -----------
#define SPAWN_MARGIN 50
#define SCREEN_SIZE 2
#define SCREEN_WIDTH 224
#define SCREEN_HEIGHT 300
#define SCREEN_SPEED 1.0f
#define WIN_FULLSCREEN 0
#define WIN_FULLSCREEN_DESKTOP 0
#define WIN_BORDERLESS 0
#define WIN_RESIZABLE 0
#define REN_VSYNC 1
#define Title "Gun.Smoke"
#endif // __GLOBALS_H__
