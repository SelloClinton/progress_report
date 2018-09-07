#include "Drawer.h"

Drawer::Drawer(shared_ptr<sf::RenderWindow> window):
		data_(make_unique<DataBank>()),
		window_(window),
		object_sprites_(data_->getSprites())
		
{
	if(window_ == nullptr) throw WindowNotCreated();
}

void Drawer::drawPlayer(shared_ptr<Player> player){
		auto[x_position,y_position] = player->attribute()->position()->getPosition();
	auto player_sprite = object_sprites_.at(0);
//    player_sprite.setPosition(player->getAttribute()->getPosition().getXPosition(),player->getAttribute()->getPosition().getYPosition());
	player_sprite.setPosition(x_position,y_position);
//S	player_sprite.setOrigin(Constants::PLAYER_WIDTH_/2,Constants::PLAYER_HEIGHT_/2);
	window_->draw(player_sprite);
	
}

void Drawer::drawCentipede(shared_ptr<Centipede> centipede){
    
	auto segments = centipede->getCentipede();

	for(const auto& segment:segments){
			drawSegment(segment);
	}
        
}

void Drawer::drawBullet(shared_ptr<Bullet> bullet){
	auto[x_position,y_position] = bullet->attribute()->position()->getPosition();
	auto bullet_sprite = object_sprites_.at(2);
	bullet_sprite.setPosition(x_position,y_position);
//    bullet_sprite.setPosition(bullet->getAttribute()->getPosition().getXPosition(),bullet->getAttribute()->getPosition().getYPosition());
	if(bullet->isShot())
		window_->draw(bullet_sprite);	
		
}

void Drawer::drawSegment(shared_ptr<Segment> segment){
	
	auto[x_position,y_position] = segment->attribute()->position()->getPosition();
	auto segment_sprite = object_sprites_.at(1);
	segment_sprite.setPosition(x_position,y_position);
//	segment_sprite.setPosition(segment->getAttribute()->getPosition().getXPosition(),segment->getAttribute()->getPosition().getYPosition());
	window_->draw(segment_sprite);
}