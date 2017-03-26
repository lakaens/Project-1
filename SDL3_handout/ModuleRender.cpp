#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

ModuleRender::ModuleRender() : Module()
{}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if(REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);
	
	if(renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	// TODO 9: load a texture "test.png" to test is everything works well
	
	if(App->textures->Load("test.png") == nullptr){
		LOG("Couldn't load texture: %s", SDL_GetError());
		ret = false;
	}
		

	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	update_status ret = UPDATE_CONTINUE;
	// TODO 7: Clear the screen to black before starting every frame
	if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0) != 0) {
		LOG("Renderer error: %s", SDL_GetError());
		ret = UPDATE_ERROR;
	}
	if (SDL_RenderClear(renderer)!=0) {
		LOG("Renderer error: %s", SDL_GetError());
		ret = UPDATE_ERROR;
	}
	// TODO 10: Blit our test texture to check functionality
	Blit(App->textures->textures[App->textures->last_texture - 1], 0, 0, nullptr);

	return ret;
}

update_status ModuleRender::PostUpdate()
{
	// TODO 8: Switch buffers so we actually render
	update_status ret = UPDATE_CONTINUE;
	if (renderer != nullptr) {
		SDL_RenderPresent(renderer);
	}
	else {
		ret = UPDATE_ERROR;
	}
	return ret;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if(renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	if(section != nullptr)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
	}

	if(SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}
