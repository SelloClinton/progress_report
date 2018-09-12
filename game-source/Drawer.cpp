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
	player_sprite.setPosition(x_position,y_position);
	window_->draw(player_sprite);
	
}

void Drawer::drawCentipede(shared_ptr<Centipede> centipede){
    
	auto segments = centipede->getCentipede();

	for(const auto& segment:segments){
			drawSegment(segment);
	}
        
}

void Drawer::drawBullets(shared_ptr<Player>player){
    
    auto bullets = player->getBullets();
    
    for(const auto& bullet:bullets){
            drawBullet(bullet);
    }	
		
}
void Drawer::drawField(shared_ptr<Field> field){
	
	auto mushrooms = field->getMushrooms();

	for(const auto& mushroom:mushrooms){
			drawMushroom(mushroom);
		}
}
void Drawer::drawSegment(shared_ptr<Segment> segment){
	
	auto[x_position,y_position] = segment->attribute()->position()->getPosition();
	auto segment_sprite = object_sprites_.at(1);
	segment_sprite.setPosition(x_position,y_position);
	window_->draw(segment_sprite);
}

void Drawer::drawBullet(shared_ptr<Bullet>bullet){
	auto[x_position,y_position] = bullet->attribute()->position()->getPosition();
	auto bullet_sprite = object_sprites_.at(2);
	bullet_sprite.setPosition(x_position,y_position);
	window_->draw(bullet_sprite);
}

void Drawer::drawMushroom(shared_ptr<Mushroom> mushroom){
	auto[x_position,y_position] = mushroom->position()->getPosition();
	auto mushroom_sprite = object_sprites_.at(3);
	mushroom_sprite.setPosition(x_position,y_position);
	window_->draw(mushroom_sprite);
}