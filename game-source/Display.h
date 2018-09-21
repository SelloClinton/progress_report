#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Constants.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

class WindowNotCreated{};

class Display{
	
public:
	Display();
	shared_ptr<sf::RenderWindow> getWindow()const;
	void checkEvent();
private:
	shared_ptr<sf::RenderWindow> window_;

};
#endif 