#include "DataBank.h"

DataBank::DataBank()
			
{
	if(!fontLoaded())throw FontNotFound();
	if(!texturesLoaded())throw ImageNotFound();
	loadSprites();

}

Sprites DataBank::getSprites()const{
		return sprites_;
}
Font DataBank::getFont()const{
		return font_;
}
bool DataBank::fontLoaded(){
	if (!font_.loadFromFile("FFF.ttf"))
		return false;
	return true;
}

bool DataBank::texturesLoaded(){
	if(!texture_.loadFromFile("centipede_image.png"))
		return false;
	textures_.push_back(texture_);
	if(!texture_.loadFromFile("centipede_logo.png"))
		return false;
	textures_.push_back(texture_);
	return true;
}

void DataBank::loadSprites(){
	
	//player sprite
	sprite_.setTexture(textures_.at(0));
	sprite_.setTextureRect(sf::IntRect(21,9,8,8));
	sprite_.setScale(2.5,2.5);
	sprites_.push_back(sprite_);
	
	//head_segment sprite
	sprite_.setTexture(textures_.at(0));
	sprite_.setTextureRect(sf::IntRect(4,18,7,8));
	sprite_.setScale(2.5,2.5);
	sprites_.push_back(sprite_);
	
	//bullet sprite
	sprite_.setTexture(textures_.at(0));
	sprite_.setTextureRect(sf::IntRect(24,1,1,7));
	sprite_.setScale(2.5,2.5);
	sprites_.push_back(sprite_);
	
	//mushroom(full) sprite
	sprite_.setTexture(textures_.at(0));
	sprite_.setTextureRect(sf::IntRect(68,72,8,8));
	sprite_.setScale(2.5,2.5);
	sprites_.push_back(sprite_);
	
	//"logo" sprite
	sprite_.setTexture(textures_.at(1));
	sprites_.push_back(sprite_);
}
