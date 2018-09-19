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
using Sprites = vector<sf::Sprite> ;
using Textures = vector<sf::Texture>;

class ImageNotFound{};
class FontNotFound{};

class DataBank{
	
public:
	DataBank();	
	Sprites getSprites()const;
	Font getFont()const;
private:
	sf::Font font_;
	Texts texts_;
	sf::Texture texture_;
	Textures textures_;
	sf::Sprite sprite_;
	Sprites sprites_;

	bool fontLoaded();
	bool texturesLoaded();
	void loadSprites();

};

#endif // DATABANK_H_INCLUDED

