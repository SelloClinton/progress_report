#include "Display.h"


Display::Display():window_(make_shared<sf::RenderWindow>(sf::VideoMode(Constants::DISPLAY_WIDTH_,Constants::DISPLAY_HEIGHT_),"**CENTIPEDE**"))
{
		if (window_ == nullptr) throw WindowNotCreated();
		window_->setVerticalSyncEnabled(true);
}

shared_ptr<sf::RenderWindow> Display::getWindow()const{
		
	return window_;
}

void Display::display()const{
		window_->display();
}

void Display::clear()const{
		window_->clear();
}
void Display::close()const{
		window_->close();
}
bool Display::isOpen()const{
		return window_->isOpen();
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
