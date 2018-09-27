#include "PlayerSprite.h"

PlayerSprite::PlayerSprite():
			texture_(make_shared<sf::Texture>())
			,sprite_(make_shared<sf::Sprite>())
{
	loadTexture();
	loadSprite();
}

shared_ptr<sf::Sprite> PlayerSprite::getPlayerSprite(){
	return sprite_;
}

void PlayerSprite::setPosition(float x, float y){
		sprite_->setPosition(x,y);
}
void PlayerSprite::loadTexture(){
	if (!texture_->loadFromFile("centipede_image.png"))
		throw PlayerImageLoadFailed();
}

void PlayerSprite::loadSprite(){
	sprite_->setTexture(*texture_);
	sprite_->setTextureRect(sf::IntRect(21,9,8,8));
}