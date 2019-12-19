#include "Engine.hpp"
#include "Logger.hpp"
#include "Window.hpp"
#include "renderer/Renderer.hpp"
#include "core/SceneManager.hpp"
#include "core/Input.hpp"
#include "SDL.h"
#include <thread>
#include <chrono>

using namespace core;

Engine core::engine;

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::init() {
	core::logger.log("Init EGIN...");
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    logger.log("SDL_Init Error: %s", SDL_GetError());
    exit(1);
  }

	core::window.init();
	renderer::renderer.init();
}

void Engine::start(std::string defaultScene) {
	core::window.start();

	core::sceneManager.load(defaultScene);

	// fck.
	//std::thread drawThread(&Engine::tickLoop, this);
	//drawThread.detach();
	this->drawLoop();
}

void Engine::drawLoop() {
	this->deltaTime = 0.007;
	while(true) {
		core::window.frame();
		core::input.update();
		core::sceneManager.update();
		renderer::renderer.frame();
	}
}

void Engine::tickLoop() {
	/*int tickRate = 128;

	float tickSleep = 1000 / tickRate;
	float delta = 0;
	
	while(true) {
		auto start = std::chrono::high_resolution_clock::now();
		core::input.update(delta);
		core::sceneManager.update(delta);
		delta = 0.007;//(std::chrono::high_resolution_clock::now() - start).count() / 1000;
	}*/
}

void Engine::shutdown() {
	exit(0);
}