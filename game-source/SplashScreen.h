#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <tuple>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "DataBank.h"


class SplashScreen{
public:
	SplashScreen(shared_ptr<sf::RenderWindow> window);
	void drawSplashScreen();
private:
	shared_ptr<sf::RenderWindow> window_;
	unique_ptr<DataBank> data_;
	sf::Font font_;
	Sprites logo_;
	Texts instructions_;
	void loadInstructions();
	void loadName();
	void drawText();
	void checkEvent();
	bool start_;
};
#endif // SPLASHSCREEN_H