#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/timer.h>
#include <bx/math.h>
#include <algorithm>
#include "Renderer.hpp"
#include "core/Logger.hpp"
#include <SDL.h>
#include <SDL_syswm.h>
#include "ShaderProgram.hpp"
#include "Camera.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "interfaces/Node.hpp"
#include "interfaces/Drawable.hpp"

using namespace renderer;
Renderer renderer::renderer;

ShaderProgram *m_program;

void Renderer::init() {
}

void Renderer::start() {
}

void Renderer::frame()
{
	bgfx::touch(0);
	bgfx::setViewRect(0, 0, 0, uint16_t(800), uint16_t(600) );

	if (!this->camera) {
		bgfx::dbgTextClear();
		bgfx::dbgTextPrintf(0, 0, 0x0f, "Please set the camera using 'renderer::renderer.setCamera(camera)'");
		bgfx::frame();
		return;
	}

	this->camera->setup();
	std::for_each(this->drawableNodes.begin(), this->drawableNodes.end(), [] (Node *node) {
		bgfx::setTransform(glm::value_ptr(node->toMatrix()));
		node->drawable->draw();
		bgfx::submit(0, m_program->getProgram());
	});

	bgfx::frame();
}

bool Renderer::setPlatformData(SDL_Window* window)
{
	SDL_SysWMinfo wmi;
	SDL_VERSION(&wmi.version);
	if (!SDL_GetWindowWMInfo(window, &wmi))
	{
		return false;
	}

	bgfx::PlatformData pd;
#if BX_PLATFORM_WINDOWS
	pd.ndt = NULL;
	pd.nwh = wmi.info.win.window;
#endif // TODO add other platforms
	pd.context = NULL;
	pd.backBuffer = NULL;
	pd.backBufferDS = NULL;

	bgfx::setPlatformData(pd);
	return true;
}

bool Renderer::initBgfx()
{
	using namespace bgfx;
	Init init;
	init.type = RendererType::Count;
	init.vendorId = BGFX_PCI_ID_NONE;
	init.resolution.width = 800;
	init.resolution.height = 600;
	init.resolution.reset = BGFX_RESET_VSYNC;

	return bgfx::init(init);
}

void Renderer::setupWindow(SDL_Window *window) {
  this->setPlatformData(window);
  this->initBgfx();

  m_program = new ShaderProgram("colored");
	m_program->load();

	bgfx::setDebug(BGFX_DEBUG_TEXT);
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000);
}

void Renderer::setCamera(Camera *camera)
{
	this->camera = camera;
}

void Renderer::addDrawable(Node *node)
{
	this->drawableNodes.push_back(node);
}

void Renderer::removeDrawable(Node *node)
{
	this->drawableNodes.remove(node);
}