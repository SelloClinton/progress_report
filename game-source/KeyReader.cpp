#include "KeyReader.h"

Pressed KeyReader::readKey(shared_ptr<sf::RenderWindow> window){
	
	sf::Event event;
	
	while(window->pollEvent(event)){
	
			if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::S))
					return Pressed::S;
			if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Escape))
					return Pressed::ESCAPE;
		}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				return Pressed::LEFT;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				return Pressed::RIGHT;
		}

	return Pressed::NO_INPUT;

		
}