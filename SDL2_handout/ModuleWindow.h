#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__


// TODO 1: Create the declaration of ModuleWindow class
struct SDL_Window;

class ModuleWindow : public Module
{
public:
	bool Init();
	bool CleanUp();
public:

	SDL_Window* window = 0;
};


#endif // __ModuleWindow_H__