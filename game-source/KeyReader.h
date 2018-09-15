#ifndef KEYREADER_H
#define KEYREADER_H


#include "Enums.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
using std::shared_ptr;


//enum class Pressed{
//	
//		RIGHT,
//		LEFT,
//		S,
//		ESCAPE,
//		SPACE,
//		NO_INPUT
//		
//};

class KeyReader{
	
public:
	Pressed readKey(shared_ptr<sf::RenderWindow> window);
		
	
		
};

#endif // KEYREADER_H