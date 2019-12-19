#pragma once
#include <string>
#include <map>
#include <functional>

class IScene;
namespace core {
	class SceneManager {
	private:
		std::map<std::string, std::function<void*()>> scenes;
		IScene* currentScene;
		std::string currentSceneSlug;
	public:
		void add(std::string slug, std::function<void*()> factory);
		void load(std::string slug);
		void update();
	};

	extern SceneManager sceneManager;
}