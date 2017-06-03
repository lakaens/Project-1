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

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
		
	}
	
	LOG("Init the controller (search and asign)");
	gcontroller = nullptr;
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		if (SDL_IsGameController(i)) {
			gcontroller = SDL_GameControllerOpen(i);
			if (gcontroller) {
				break;
			}
		}
	}
	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for(int i = 0; i < MAX_KEYS; ++i)
	{
		if(keys[i] == 1)
		{
			if(keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if(keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	if(keyboard[SDL_SCANCODE_ESCAPE]|| gamepad.BACK==GAMEPAD_STATE::PAD_BUTTON_DOWN)
		return update_status::UPDATE_STOP;

	GamepadButtons();

	gamepad.movementJoystick.x = ((float)SDL_GameControllerGetAxis(gcontroller, SDL_CONTROLLER_AXIS_LEFTX) / 32767.0f);
	gamepad.movementJoystick.y = ((float)SDL_GameControllerGetAxis(gcontroller, SDL_CONTROLLER_AXIS_LEFTY) / 32767.0f);

	if (gamepad.movementJoystick.y > 0.25)
	{
		gamepad.joystickDown = true;
	}
	else
		gamepad.joystickDown = false;
	if (gamepad.movementJoystick.y < -0.25)
	{
		gamepad.joystickUp = true;
	}
	else
		gamepad.joystickUp = false;

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	for (int i = 0; i < SDL_NumJoysticks(); ++i) {
		if (SDL_IsGameController(i)) {
			SDL_GameController *gp = SDL_GameControllerOpen(i);
			if (gp) {
				SDL_GameControllerClose(gp);
			}
		}
	}
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}

void ModuleInput::GamepadButtons() {
	//BUTTON A
	if (SDL_GameControllerGetButton(gcontroller, SDL_CONTROLLER_BUTTON_A) == 1) {
		if (gamepad.A == PAD_BUTTON_IDLE)
			gamepad.A = PAD_BUTTON_DOWN;
		else
			gamepad.A = PAD_BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.A == PAD_BUTTON_REPEAT || (gamepad.A == PAD_BUTTON_DOWN))
			gamepad.A = PAD_BUTTON_KEY_UP;
		else
			gamepad.A = PAD_BUTTON_IDLE;
	}

	//BUTTON B
	if (SDL_GameControllerGetButton(gcontroller, SDL_CONTROLLER_BUTTON_B) == 1) {
		if (gamepad.B == PAD_BUTTON_IDLE)
			gamepad.B = PAD_BUTTON_DOWN;
		else
			gamepad.B = PAD_BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.B == PAD_BUTTON_REPEAT || (gamepad.B == PAD_BUTTON_DOWN))
			gamepad.B = PAD_BUTTON_KEY_UP;
		else
			gamepad.B = PAD_BUTTON_IDLE;
	}

	//BUTTON START
	if (SDL_GameControllerGetButton(gcontroller, SDL_CONTROLLER_BUTTON_START) == 1) {
		if (gamepad.START == PAD_BUTTON_IDLE)
			gamepad.START = PAD_BUTTON_DOWN;
		else
			gamepad.START = PAD_BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.START == PAD_BUTTON_REPEAT || (gamepad.START == PAD_BUTTON_DOWN))
			gamepad.START = PAD_BUTTON_KEY_UP;
		else
			gamepad.START = PAD_BUTTON_IDLE;
	}

	//BUTTON BACK
	if (SDL_GameControllerGetButton(gcontroller, SDL_CONTROLLER_BUTTON_BACK) == 1) {
		if (gamepad.BACK == PAD_BUTTON_IDLE)
			gamepad.BACK = PAD_BUTTON_DOWN;
		else
			gamepad.BACK = PAD_BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.BACK == PAD_BUTTON_REPEAT || (gamepad.BACK == PAD_BUTTON_DOWN))
			gamepad.BACK = PAD_BUTTON_KEY_UP;
		else
			gamepad.BACK = PAD_BUTTON_IDLE;
	}

	//BUTTON DPAD UP
	if (SDL_GameControllerGetButton(gcontroller, SDL_CONTROLLER_BUTTON_DPAD_UP) == 1) {
		if (gamepad.CROSS_UP == PAD_BUTTON_IDLE)
			gamepad.CROSS_UP = PAD_BUTTON_DOWN;
		else
			gamepad.CROSS_UP = PAD_BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.CROSS_UP == PAD_BUTTON_REPEAT || (gamepad.CROSS_UP == PAD_BUTTON_DOWN))
			gamepad.CROSS_UP = PAD_BUTTON_KEY_UP;
		else
			gamepad.CROSS_UP = PAD_BUTTON_IDLE;
	}

	//BUTTON DPAD DOWN
	if (SDL_GameControllerGetButton(gcontroller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) == 1) {
		if (gamepad.CROSS_DOWN == PAD_BUTTON_IDLE)
			gamepad.CROSS_DOWN = PAD_BUTTON_DOWN;
		else
			gamepad.CROSS_DOWN = PAD_BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.CROSS_DOWN == PAD_BUTTON_REPEAT || (gamepad.CROSS_DOWN == PAD_BUTTON_DOWN))
			gamepad.CROSS_DOWN = PAD_BUTTON_KEY_UP;
		else
			gamepad.CROSS_DOWN = PAD_BUTTON_IDLE;
	}

	//BUTTON DPAD LEFT
	if (SDL_GameControllerGetButton(gcontroller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) == 1) {
		if (gamepad.CROSS_LEFT == PAD_BUTTON_IDLE)
			gamepad.CROSS_LEFT = PAD_BUTTON_DOWN;
		else
			gamepad.CROSS_LEFT = PAD_BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.CROSS_LEFT == PAD_BUTTON_REPEAT || (gamepad.CROSS_LEFT == PAD_BUTTON_DOWN))
			gamepad.CROSS_LEFT = PAD_BUTTON_KEY_UP;
		else
			gamepad.CROSS_LEFT = PAD_BUTTON_IDLE;
	}

	//BUTTON DPAD UP
	if (SDL_GameControllerGetButton(gcontroller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) == 1) {
		if (gamepad.CROSS_RIGHT == PAD_BUTTON_IDLE)
			gamepad.CROSS_RIGHT = PAD_BUTTON_DOWN;
		else
			gamepad.CROSS_RIGHT = PAD_BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.CROSS_RIGHT == PAD_BUTTON_REPEAT || (gamepad.CROSS_RIGHT == PAD_BUTTON_DOWN))
			gamepad.CROSS_RIGHT = PAD_BUTTON_KEY_UP;
		else
			gamepad.CROSS_RIGHT = PAD_BUTTON_IDLE;
	}
}