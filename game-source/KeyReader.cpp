#include "KeyReader.h"

Pressed KeyReader::readKey(shared_ptr<sf::RenderWindow> window){
	
	sf::Event event;
	
	while(window->pollEvent(event)){
	
			if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::S))
					return Pressed::S;
			if ((event.type == sf::Event::Closed)||((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Escape)))
					return Pressed::ESCAPE;
			if ((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Space))
				return Pressed::SPACE;
			if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::P))
				return Pressed::P;			
			if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::R))
				return Pressed::R;	
		
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				return Pressed::LEFT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				return Pressed::RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				return Pressed::UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				return Pressed::DOWN;
	}
	return Pressed::NONE;

		
}