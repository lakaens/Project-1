#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "Module.h"
#include"SDL/include/SDL_rect.h"

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status Update();
	update_status PreUpdate();
	bool CleanUp();

	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section = nullptr, float speed=2.0f);

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* tex;
	SDL_Rect camera;
};

#endif //__ModuleRenderer_H__