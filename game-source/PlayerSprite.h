#ifndef DRAWER_H
#define DRAWER_H

#include <SFML/Graphics.hpp>
#include <memory>
using std::shared_ptr;
using std::make_shared;

class PlayerImageLoadFailed{};

class PlayerSprite{

public:
		PlayerSprite();
		shared_ptr<sf::Sprite> getPlayerSprite();
		void setPosition(float x, float y);
		
private:
	shared_ptr<sf::Texture> texture_;
	shared_ptr<sf::Sprite> sprite_;
	void loadTexture();
	void loadSprite();
	
	
};
#endif