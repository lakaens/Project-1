#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 14

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleAudio;
class ModuleStage1;
class ModuleStage2;
class ModuleFadeToBlack;
class ModulePlayer;
class ModuleWelcome;
class ModuleGreetings;
class ModuleParticles;
class ModuleCollision;
class ModuleEnemies;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleAudio* audio;
	ModuleStage1* stage1;
	ModuleStage2* stage2;
	ModuleFadeToBlack* fade;
	ModulePlayer* player;
    ModuleWelcome* welcome;
	ModuleGreetings* greetings;
	ModuleParticles* particles;
	ModuleCollision* collision;
	ModuleEnemies* enemies;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__