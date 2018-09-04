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

				std::cout << "left key" << std::endl;
				return Pressed::LEFT;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				std::cout << "right key" << std::endl;
				return Pressed::RIGHT;
		}

		
		std::cout << "in key reader" << std::endl;

		
}