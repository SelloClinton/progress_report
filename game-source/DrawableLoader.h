#ifndef DRAWABLELOADER_H
#define DRAWABLELOADER_H

#include "Enums.h"
#include <SFML/Graphics.hpp>
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <cassert>

class PlayerImageLoadFailed{};

class DrawableLoader{

public:
		DrawableLoader(Object object);
		shared_ptr<sf::Sprite> getDrawable();
		void setPosition(float x, float y);
		
private:
	shared_ptr<sf::Texture> texture_;
	shared_ptr<sf::Sprite> sprite_;
	void loadTexture();
	void loadSprite(Object object);
	
	
};
#endif