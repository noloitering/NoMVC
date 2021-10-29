#pragma once

#include <vector>

#include "Model.h"

namespace NoMVC
{
	class Controller;

	struct WindowConfig 
	{
		int width = 470; // pixels
		int height = 720; // pixels
		int fps = 60; // frames per second
		float spf = 1 / 60;
		bool full = false;  // fullscreen
	};

	class View
	{
	friend class Controller;
	protected:
		virtual void cleanup() = 0;
		std::vector< std::shared_ptr< Model > > models;
		Controller* game = nullptr;
		WindowConfig config;
		bool renderTexture = true; 
		bool paused = false;
		size_t frame = 0;
		void setPaused(bool paused) {paused = paused;}
	public:
		View(Controller *g, WindowConfig conf)
			: game(g), config(conf) {}
		virtual ~View() {}
		virtual std::shared_ptr< Model > addModel(const Model& model);
		virtual int removeModel(size_t index);
		virtual void update();
		virtual void render();
		virtual void run();
		std::shared_ptr< Model > getModel(size_t index);
		size_t currentFrame() {return frame;}
	};
}