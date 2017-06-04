#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
	for(uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	for (int i = 0; i < SDL_NumJoysticks(); i++) {
		if (SDL_IsGameController(i)) {
			if (i == 0) {
				controller = SDL_GameControllerOpen(i);
				joy = SDL_GameControllerGetJoystick(controller);
			}
			
			LOG("Index \'%i\' is a compatible controller, named \'%s\'\n", i, SDL_GameControllerNameForIndex(i));

		}
		else {
			LOG("Index \'%i\' is not a compatible controller.\n", i);
		}
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	Sint16 x_joy, y_joy;
	Sint16 x_joy2, y_joy2;

	x_joy = SDL_JoystickGetAxis(joy, 0);
	y_joy = SDL_JoystickGetAxis(joy, 1);

	x_joy2 = SDL_JoystickGetAxis(joy2, 0);
	y_joy2 = SDL_JoystickGetAxis(joy2, 1);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) == 1) {
		if (buttonA == KEY_IDLE)
			buttonA = KEY_DOWN;
		else
			buttonA = KEY_REPEAT;
	}
	else
	{
		if (buttonA == KEY_REPEAT || buttonA == KEY_DOWN)
			buttonA = KEY_UP;
		else
			buttonA = KEY_IDLE;
	}

	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) == 1) {
		if (buttonX == KEY_IDLE)
			buttonX = KEY_DOWN;
		else
			buttonX = KEY_REPEAT;
	}
	else
	{
		if (buttonX == KEY_REPEAT || buttonX == KEY_DOWN)
			buttonX = KEY_UP;
		else
			buttonX = KEY_IDLE;
	}

	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) == 1) {
		if (buttonStart == KEY_IDLE)
			buttonStart = KEY_DOWN;
		else
			buttonStart = KEY_REPEAT;
	}
	else
	{
		if (buttonStart == KEY_REPEAT || buttonStart == KEY_DOWN)
			buttonStart = KEY_UP;
		else
			buttonStart = KEY_IDLE;
	}

	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK) == 1) {
		if (buttonBack == KEY_IDLE)
			buttonBack = KEY_DOWN;
		else
			buttonBack = KEY_REPEAT;
	}
	else
	{
		if (buttonBack == KEY_REPEAT || buttonBack == KEY_DOWN)
			buttonBack = KEY_UP;
		else
			buttonBack = KEY_IDLE;
	}

	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) == 1) {
		if (buttonB == KEY_IDLE)
			buttonB = KEY_DOWN;
		else
			buttonB = KEY_REPEAT;
	}
	else
	{
		if (buttonB == KEY_REPEAT || buttonB == KEY_DOWN)
			buttonB = KEY_UP;
		else
			buttonB = KEY_IDLE;
	}

	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) == 1) {
		if (dpadUp == KEY_IDLE)
			dpadUp = KEY_DOWN;
		else
			dpadUp = KEY_REPEAT;
	}
	else
	{
		if (dpadUp == KEY_REPEAT || dpadUp == KEY_DOWN)
			dpadUp = KEY_UP;
		else
			dpadUp = KEY_IDLE;
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) == 1) {
		if (dpadDown == KEY_IDLE)
			dpadDown = KEY_DOWN;
		else
			dpadDown = KEY_REPEAT;
	}
	else
	{
		if (dpadDown == KEY_REPEAT || dpadDown == KEY_DOWN)
			dpadDown = KEY_UP;
		else
			dpadDown = KEY_IDLE;
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) == 1) {
		if (dpadLeft == KEY_IDLE)
			dpadLeft = KEY_DOWN;
		else
			dpadLeft = KEY_REPEAT;
	}
	else
	{
		if (dpadLeft == KEY_REPEAT || dpadLeft == KEY_DOWN)
			dpadLeft = KEY_UP;
		else
			dpadLeft = KEY_IDLE;
	}
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) == 1) {
		if (dpadRight == KEY_IDLE)
			dpadRight = KEY_DOWN;
		else
			dpadRight = KEY_REPEAT;
	}
	else
	{
		if (dpadRight == KEY_REPEAT || dpadRight == KEY_DOWN)
			dpadRight = KEY_UP;
		else
			dpadRight = KEY_IDLE;
	}

	if (x_joy >= -33000 && x_joy < -10000) {
		if (joy_left == KEY_IDLE)
			joy_left = KEY_DOWN;
		else
			joy_left = KEY_REPEAT;
	}
	else
	{
		if (joy_left == KEY_REPEAT || joy_left == KEY_DOWN)
			joy_left = KEY_UP;
		else
			joy_left = KEY_IDLE;
	}

	if (x_joy >= 10000 && x_joy < 33000) {
		if (joy_right == KEY_IDLE)
			joy_right = KEY_DOWN;
		else
			joy_right = KEY_REPEAT;
	}
	else
	{
		if (joy_right == KEY_REPEAT || joy_right == KEY_DOWN)
			joy_right = KEY_UP;
		else
			joy_right = KEY_IDLE;
	}
	if (y_joy >= -33000 && y_joy < -10000) {
		if (joy_up == KEY_IDLE)
			joy_up = KEY_DOWN;
		else
			joy_up = KEY_REPEAT;
	}
	else
	{
		if (joy_up == KEY_REPEAT || joy_up == KEY_DOWN)
			joy_up = KEY_UP;
		else
			joy_up = KEY_IDLE;
	}
	if (y_joy >= 10000 && y_joy < 33000) {
		if (joy_down == KEY_IDLE)
			joy_down = KEY_DOWN;
		else
			joy_down = KEY_REPEAT;
	}
	else
	{
		if (joy_down == KEY_REPEAT || joy_down == KEY_DOWN)
			joy_down = KEY_UP;
		else
			joy_down = KEY_IDLE;
	}
	return UPDATE_CONTINUE;
}


bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	if (controller != NULL) {
		SDL_GameControllerClose(controller);
	}
	controller = nullptr;
	return true;
}