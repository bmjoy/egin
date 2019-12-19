#include "Window.hpp"
#include "Logger.hpp"
#include "renderer/Renderer.hpp"
#include "SDL.h"

using namespace core;

Window core::window;

void Window::init() {
	this->width = 800;
	this->height = 600;
}

void Window::start() {
  this->window = SDL_CreateWindow(
		"EGIN",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		this->width,
		this->height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);

  if (this->window == nullptr){
    logger.log("SDL_CreateWindow Error: %s", SDL_GetError());
    exit(1);
  }

  renderer::renderer.setupWindow(this->window);
}

void Window::frame() {
  SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(1);
		if (event.type == SDL_WINDOWEVENT) {
			if (event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				// TODO
			}
		}
		break;
	}
}

int Window::getWidth() const
{
	return this->width;
}

int Window::getHeight() const
{
	return this->height;
}

SDL_Window *Window::getWindow() const
{
	return this->window;
}