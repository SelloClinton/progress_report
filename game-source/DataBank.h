#ifndef DATABANK_H
#define DATABANK_H

#include <SFML/Graphics.hpp>
using namespace sf;



#include <iostream>
#include <memory>
using std::make_shared;
using std::shared_ptr;
using std::cout;
#include <vector>
using std::vector;
using std::tuple;

using Texts = vector<sf::Text>;
using Sprites = vector<shared_ptr<sf::Sprite>>;
using Textures = vector<sf::Texture>;

class ImageNotFound{};
class FontNotFound{};

class DataBank{
	
public:
	DataBank();
//	tuple<Sprites,sf::Font>loadData()const;	
	
//	Sprites getSprites()const;
	void loadTextures();
	void loadSprites();
	Sprites getSprites()const;
	Font getFont()const;
private:
	shared_ptr<sf::Font> font_;
	Texts texts_;
//	shared_ptr<sf::Texture> texture_;
//	shared_ptr<sf::Sprite> sprite_;
	Textures textures_;
	Sprites sprites_;

	bool fontLoaded();
//	void loadTextures();
//	void loadSprites();

};

#endif // DATABANK_H_INCLUDED

