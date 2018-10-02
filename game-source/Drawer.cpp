#include "Drawer.h"

Drawer::Drawer(shared_ptr<sf::RenderWindow> window):
		data_(make_unique<DataBank>()),
		window_(window),
		object_sprites_(data_->getSprites())
		
{
	if(window_ == nullptr) throw WindowNotCreated();
}

void Drawer::drawPlayer(shared_ptr<Player> player){
	
	auto[x_position,y_position] = player->entityAttribute()->position()->getXYPosition();
	
	auto player_sprite = make_shared<DrawableLoader>(EntityID::PLAYER);
	player_sprite->setPosition(x_position,y_position);
	window_->draw(player_sprite->getDrawable());
}

void Drawer::drawCentipede(shared_ptr<Centipede> centipede){
    
	auto segments = centipede->getCentipede();

	for(const auto& segment:segments){
			drawSegment(segment);
	}
        
}

void Drawer::drawBullets(shared_ptr<Player>player){
    
    auto lasers = player->getLasers();
    
    for(const auto& laser:lasers){
            drawBullet(laser);
    }	
		
}
void Drawer::drawField(shared_ptr<Field> field){
	
	auto mushrooms = field->getMushrooms();

	for(const auto& mushroom:mushrooms){
			drawMushroom(mushroom);
		}
}

void Drawer::drawPauseMessage(){
	
	sf::Text text;
	auto font = data_->getFont();
	text.setFillColor(sf::Color::Green);
	text.setFont(font);
	text.setCharacterSize(25);
	text.setString("GAME PAUSED .... PRESS   P   TO RESUME");
	text.setPosition(100,250);
	window_->draw(text);

	
}
void Drawer::drawGameOverMessage(const string& wonOrLost){
	sf::Text text;
	auto font = data_->getFont();
	text.setFont(font);
	text.setFillColor(sf::Color::Green);
	text.setCharacterSize(25);
	if (auto str = "won"; wonOrLost == str)
		text.setString("YOU WON!...PRESS ESCAPE TO GO TO MAIN MENU");
	else{
	text.setFillColor(sf::Color::Red);
	text.setString("YOU LOST!...PRESS ESCAPE TO GO TO MAIN MENU");
	}
	text.setPosition(50,250);
	window_->draw(text);

}
void Drawer::drawSegment(shared_ptr<Segment> segment){
	
	auto[x_position,y_position] = segment->entityAttribute()->position()->getXYPosition();
	auto segment_sprite = make_shared<DrawableLoader>(EntityID::SEGMENT);//object_sprites_.at(1);
	segment_sprite->setPosition(x_position,y_position);
	window_->draw(segment_sprite->getDrawable());

}

void Drawer::drawBullet(shared_ptr<Laser>laser){
	auto[x_position,y_position] = laser->entityAttribute()->position()->getXYPosition();
	auto laser_sprite = make_shared<DrawableLoader>(EntityID::LASER);
	laser_sprite->setPosition(x_position,y_position);
	window_->draw(laser_sprite->getDrawable());

}

void Drawer::drawMushroom(shared_ptr<Mushroom> mushroom){
	auto[x_position,y_position] = mushroom->entityAttribute()->position()->getXYPosition();
	auto mushroom_sprite = make_shared<DrawableLoader>(EntityID::MUSHROOM);
	mushroom_sprite->setPosition(x_position,y_position); //setPosition(x_position,y_position);
	window_->draw(mushroom_sprite->getDrawable());
}