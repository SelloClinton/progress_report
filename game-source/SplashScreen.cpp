#include "SplashScreen.h"


SplashScreen::SplashScreen(shared_ptr<sf::RenderWindow> window):
			window_(window),
			data_(make_unique<DataBank>()),
			font_(data_->getFont()),
			logo_(data_->getSprites()),
			start_(false)
{
	loadInstructions();
}

void SplashScreen::drawSplashScreen(){
	
		while((window_->isOpen())&&(!start_)){
				checkEvent();
				drawText();
				window_->display();
				window_->clear(sf::Color::Black);
			}

}

void SplashScreen::loadInstructions(){
    
	loadName();
	
    vector<string>instructions = {"---------INSTRUCTIONS-----------", 
								  "			START---S",
								  "MOVEMENT---LEFT/RIGHT ARROW",
								  "			PAUSE---P",
								  "			RESUME---R",
								  "			EXIT---ESCAPE"};
	
	    unsigned int  font_size = 25;
    for(const auto& instruction:instructions)
    {
		sf::Text text;
		text.setFont(font_);
		text.setString(instruction);
		text.setCharacterSize(font_size);
        text.setFillColor(sf::Color::Yellow);
        instructions_.push_back(text);
    }

    for(auto i  = 1; i != instructions_.size(); i++)
    {
        instructions_.at(i).setPosition(200,250+40*i);
    }
	
}

void SplashScreen::loadName(){
	string log = "CENTIPEDE";
    sf::Text log_;
    log_.setFont(font_);
    log_.setString(log);
    log_.setCharacterSize(25*3.5);
    log_.setFillColor(sf::Color::Yellow);
    instructions_.push_back(log_);
    instructions_.at(0).setPosition(120,150);
}


void SplashScreen::drawText(){
		for(auto& instruction:instructions_)
			window_->draw(instruction);
}

void SplashScreen::checkEvent(){
		Event event;
		while(window_->pollEvent(event)){
				if(event.type == Event::Closed)
					exit(0);
				if(Keyboard::isKeyPressed(Keyboard::Key::Escape))
					exit(0);
				if(Keyboard::isKeyPressed(Keyboard::Key::S))
					start_ = true;
		}
}
