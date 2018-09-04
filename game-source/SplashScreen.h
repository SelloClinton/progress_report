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

//using std::shared_ptr;
//using std::unique_ptr;
//using std::make_unique;
//using std::make_shared;
//
//using std::tuple;
//
//using std::vector;
//using std::string

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
	void drawLogo();
	void drawText();
	void checkEvent();
	bool start_;
};
#endif // SPLASHSCREEN_H