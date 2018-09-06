#include "DataBank.h"

DataBank::DataBank()
//		font_(make_shared<sf::Font>())
//		,texture_(make_shared<sf::Texture>())
//		,sprite_(make_shared<sf::Sprite>())
			
{
	if(!fontLoaded())throw FontNotFound();
//	if(!texturesLoaded())throw ImageNotFound();
//	loadSprites();

//	for(auto i = 0; i != 2; i++){
//		auto texture = make_shared<sf::Texture>();
		sf::Texture texture;
		textures_.push_back(texture);
		auto sprite = make_shared<sf::Sprite>();
		sprite->setTexture(texture);
		sprites_.push_back(sprite);
//	}

}

//tuple<Sprites,sf::Font> DataBank::loadData()const{
//	return{sprites_,font_};
//}
Sprites DataBank::getSprites()const{
//		loadSprites();
		return sprites_;
}
Font DataBank::getFont()const{
		return *font_;
}
bool DataBank::fontLoaded(){
	if (!font_->loadFromFile("FFF.ttf"))
		return false;
	return true;
}

void DataBank::loadTextures(){
//	auto texture = make_shared<sf::Texture>();
	sf::Texture texture;
	if(!texture.loadFromFile("centipede_image.png"))
		std::cerr << "image not found" << std::endl;
	textures_.at(0) = texture;
//	if(!texture_->loadFromFile("centipede_image.png"))
//		return false;
//	textures_.push_back(texture_);
//	if(!texture_->loadFromFile("centipede_logo.png"))
//		return false;
//	textures_.push_back(texture_);
//	return true;
}

void DataBank::loadSprites(){
//	loadTextures();
	//new player
	auto sprite = make_shared<sf::Sprite>();
	sprite->setTexture(textures_.at(0));
	sprite->setTextureRect(sf::IntRect(21,9,7,8));
	sprites_.at(0) = sprite; //sprites_.push_back(sprite);
	
//	//new head
//	sprite->setTexture(textures_.at(0));
//	sprite->setTextureRect(sf::IntRect(4,18,7,8));
//	sprites_.push_back(sprite);
//	
//	//new bullet
//	sprite->setTexture(textures_.at(0));
//	sprite->setTextureRect(sf::IntRect(24,1,2,7));
//	sprites_.push_back(sprite);
	
//	
//	//player sprite
//	sprite_->setTexture(*(textures_.at(0)));
//	sprite_->setTextureRect(sf::IntRect(21,9,7,8));
//	sprite_->setScale(2.5,2.5);
//	sprites_.push_back(sprite_);
//	
//	//head_segment sprite
//	sprite_->setTexture(*(textures_.at(0)));
//	sprite_->setTextureRect(sf::IntRect(4,18,7,8));
//	sprite_->setScale(2.5,2.5);
//	sprites_.push_back(sprite_);
//	
//	//bullet sprite
//	sprite_->setTexture(*(textures_.at(0)));
//	sprite_->setTextureRect(sf::IntRect(24,1,1,7));
//	sprite_->setScale(2.5,2.5);
//	sprites_.push_back(sprite_);
//	
//	//"logo" sprite
//	sprite_->setTexture(*(textures_.at(1)));
//	sprites_.push_back(sprite_);
}
