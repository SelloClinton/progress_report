#include "Drawer.h"

Drawer::Drawer(shared_ptr<sf::RenderWindow> window):
		data_(make_unique<DataBank>()),
		window_(window),
		object_sprites_(data_->getSprites())
		
{
	if(window_ == nullptr) throw WindowNotCreated();
}

//void Drawer::drawObjects(shared_ptr<Player>player){
//	
//		drawPlayer(player);
//}

void Drawer::drawPlayer(shared_ptr<Player> player){
		
	auto player_sprite = object_sprites_.at(0);
    player_sprite.setPosition(player->getAttribute()->getPosition().getXPosition(),player->getAttribute()->getPosition().getYPosition());
	window_->draw(player_sprite);
	
	
}

void Drawer::drawCentipede(shared_ptr<Centipede> centipede){
    
    auto head_sprite = object_sprites_.at(1);
//    auto tail_sprite = object_sprites_.at(0);
//    auto it = begin(centipede);
    auto head = centipede->getCentipede().at(0);
//    auto tail = centipede->getCentipede().at(1);
    head_sprite.setPosition(head.getAttribute()->getPosition().getXPosition(),head.getAttribute()->getPosition().getYPosition());
//    tail_sprite.setPosition(tail.getAttribute()->getPosition().getXPosition(),tail.getAttribute()->getPosition().getYPosition());
    window_->draw(head_sprite);
//    window_->draw(tail_sprite);


        
}