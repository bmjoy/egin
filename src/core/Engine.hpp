#pragma once
#include <string>

namespace core {
	class Engine {
	public:
		float deltaTime;

		Engine();
		~Engine();
		void init();
		void start(std::string defaultScene);
		void drawLoop();
		void tickLoop();
		void shutdown();
	protected:

	};

	extern Engine engine;
}