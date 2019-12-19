#pragma once
#include "Engine.hpp"
#include "Logger.hpp"
#include "SceneManager.hpp"
#include "interfaces/IScene.hpp"
#include "interfaces/Node.hpp"

using namespace core;

SceneManager core::sceneManager;  

void SceneManager::add(std::string slug, std::function<void*()> factory) {
  this->scenes[slug] = factory;
}

void SceneManager::load(std::string slug) {
  auto it = this->scenes.find(slug);
	if (it == this->scenes.end())
		return;

  IScene *scene = (IScene*)it->second();
  scene->load();
  scene->start();

  this->currentScene = scene;
  this->currentSceneSlug = slug;
  core::logger.log("Loaded scene: %s", slug.c_str());
}

void SceneManager::update() {
  if (!this->currentScene)
    return;

  this->currentScene->update();
}