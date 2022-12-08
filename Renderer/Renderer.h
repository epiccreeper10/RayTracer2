#pragma once
#include "Canvas.h"
#include<SDL.h>
#include "../Math/Ray.h"
#include "../Objects/Sphere.h"



class Renderer
{
public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();

	bool CreateWindow(int width, int height);

	void CopyCanvas(const Canvas& canvas);
	void Present();

	void Render(Canvas& canvas, class Scene& scene, class Camera& camera, int samples = 5);

	friend class Canvas;

private:
	color3 GetBackgroundFromRay(const struct Ray& ray);

	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
};