#include "Display.h"


//const int Display::DISPLAY_WIDTH_ = 800;
//const int Display::DISPLAY_HEIGHT_ = 600;

Display::Display():window_(make_shared<sf::RenderWindow>(sf::VideoMode(Constants::DISPLAY_WIDTH_,Constants::DISPLAY_HEIGHT_),"**CENTIPEDE**"))
{
		if (window_ == nullptr) throw WindowNotCreated();
		window_->setVerticalSyncEnabled(true);
}

shared_ptr<sf::RenderWindow> Display::getWindow()const{
		
	return window_;
}

void Display::checkEvent(){
		
		while(window_->isOpen()){
			sf::Event event;
			while(window_->pollEvent(event)){
				if ((event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
					window_->close();
				
			}
			
		}
}
