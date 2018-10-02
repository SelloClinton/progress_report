#include "DrawableLoader.h"

DrawableLoader::DrawableLoader(const EntityID& object):
			texture_(make_shared<sf::Texture>())
{
	loadTexture();
	loadSprite(object);
}

const sf::Sprite& DrawableLoader::getDrawable(){
	return sprite_;
}

void DrawableLoader::setPosition(float x, float y){
		sprite_.setPosition(x,y);
}
void DrawableLoader::loadTexture(){
	if (!texture_->loadFromFile("centipede_image.png"))
		throw PlayerImageLoadFailed();
}

void DrawableLoader::loadSprite(const EntityID& object){
	
	switch(object){
		case EntityID::PLAYER:
			sprite_.setTexture(*texture_);
			sprite_.setScale(2.5,2.5);
			sprite_.setTextureRect(sf::IntRect(21,9,8,8));	
			break;
		case EntityID::SEGMENT:
			sprite_.setTexture(*texture_);
			sprite_.setScale(2.5,2.5);
			sprite_.setTextureRect(sf::IntRect(4,18,7,8));
			break;
		case EntityID::LASER:
			sprite_.setTexture(*texture_);
			sprite_.setScale(2.5,2.5);
			sprite_.setTextureRect(sf::IntRect(24,1,1,7));
			break;
		case EntityID::MUSHROOM:
			sprite_.setTexture(*texture_);
			sprite_.setScale(2.5,2.5);
			sprite_.setTextureRect(sf::IntRect(68,72,8,8));
			break;
		default:
			assert(false);
		
	}

}