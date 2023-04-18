#pragma once
#include "AComponent.h"

enum class RendererType { Custom, Sprite };
class Renderer : public AComponent
{
public:

	Renderer(string name);
	~Renderer();
	void assignTargetWindow(sf::RenderWindow* window);
	void assignDrawable(sf::Drawable* drawable);
	void setRenderStates(sf::RenderStates renderStates);

	void perform();

protected:
	sf::Drawable* drawable;
private:
	sf::RenderWindow* targetWindow;

	sf::RenderStates renderStates;
};
