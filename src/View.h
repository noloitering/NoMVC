#pragma once

#include <vector>
#include <memory>

#include "Model.h"
#include "raylib.h"

namespace NoMVC
{
	class Controller;

	struct WindowConfig 
	{
		int width = 470; // pixels
		int height = 720; // pixels
		int fps = 60; // frames per second
		float spf = 1 / 60;
		unsigned int flags = 0x00000000;
		Color backCol = RAYWHITE;
	};
	
	
	// TODO: use templates to cast models to their derived counterparts on get or add
	class View
	{
	friend class Controller;
	protected:
		Controller* game = nullptr;
		WindowConfig config;
		bool renderTexture = true;
		bool paused = false;
		size_t frame = 0;
		void setPaused(bool paused) {paused = paused;}
		std::vector< std::shared_ptr< Model > > getModels();
		std::shared_ptr< Model > getModel(size_t index);
	public:
		View(Controller *g, WindowConfig conf)
			: game(g), config(conf) {}
		virtual ~View() {}
		virtual void render();
		virtual void run();
		WindowConfig getWindow();
		Vector2 getRes();
		int getTargetFPS();
		unsigned int getFlags();
		bool getAA();
		bool isFull();
		bool isSynced();
		Color getCol();
		void setWindow(const WindowConfig& conf);
		void setRes(int x, int y);
		void setRes(const Vector2& res);
		void setFPS(int fps);
		void setFlags(unsigned int flags);
		void setAA(bool AA);
		void setFull(bool full);
		void setSync(bool sync);
		void setCol(const Color& col);
		int size();
		size_t currentFrame() {return frame;}
	};
}