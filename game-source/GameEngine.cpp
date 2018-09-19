#include "GameEngine.h"

GameEngine::GameEngine():
			display_(make_shared<Display>())
			,drawer_(make_shared<Drawer>(display_->getWindow()))
			,position_(make_shared<Position>(Constants::DISPLAY_WIDTH_/2,(Constants::DISPLAY_HEIGHT_-50)))
            ,pos(make_shared<Position>(0,0))
            ,mover(make_shared<Mover>(position_,5))
            ,mover2(make_shared<Mover>(pos,2))
			,player_(make_shared<Player>(mover))
            ,centipede_(make_shared<Centipede>(Constants::INITIAL_SIZE_OF_CENTIPEDE_))
			,field_(make_shared<Field>(Constants::NUMBER_OF_MUSHROOMS))
			,playing_(true)
			,game_over_(false)
{
		if (display_== nullptr) throw WindowNotCreated();
}

void GameEngine::playGame(){

	splashScreen();

//	while(display_->getWindow()->isOpen()){
//			auto input = checkInput();
//			update();
//			drawObjects();
//			display_->getWindow()->display();
//            display_->getWindow()->clear();
//		}
		
		
	while(display_->getWindow()->isOpen()){
			
				if((playing_)&&(!game_over_)){//playing
					checkInput();
//					handleInput();
					update();
					drawObjects();
					display_->getWindow()->display();
					display_->getWindow()->clear();
					
				}
				else if ((!playing_)&&(!game_over_)){//paused
					checkInput();
//					handleInput();
					drawObjects();
					displayPauseMessage();
//					display_->getWindow()->display();
//					display_->getWindow()->clear();
				}
				else if(game_over_){//game over
				//	splashScreen();
					
					checkInput();
					handleInput();
					drawObjects();
					displayGameOverMessage();
//					display_->getWindow()->display();
//					display_->getWindow()->clear();
				}
	}
}

void GameEngine::splashScreen(){
	SplashScreen welcome_screen(display_->getWindow());
	welcome_screen.drawSplashScreen();
}

void GameEngine::update(){

//	checkInput();
//    updateCentipede(field_);
//	player_->updateBullet();
//	auto collision_status = checkCollision();
//	checkPlayerCollision();
//	checkBulletMushroomCollision();
//	gameStatus();
	
	
	
	auto updator = make_shared<Update>();
	updator->updateGame(player_,key_,centipede_,field_);
	
//	auto collision_status = checkCollision();
	checkPlayerCollision();
//	checkBulletMushroomCollision();
	gameStatus();

}
void GameEngine::updateCentipede(shared_ptr<Field> field){
   centipede_->moveSegments(field_);     
}

void GameEngine::checkInput(){
	
		KeyReader key_read;
		key_ = key_read.readKey(display_->getWindow());
		
}

void GameEngine::handleInput(){
	switch(key_){
//		case Pressed::RIGHT:
//			if(playing_)
//				player_->attribute()->move(Direction::RIGHT);
//			break;
//		case Pressed::LEFT:
//			if(playing_)
//				player_->attribute()->move(Direction::LEFT);
//			break;
//		case Pressed::SPACE:
//			if(playing_)
//				player_->shoot();
//			break;
		case Pressed::P:
			playing_ = false;
			break;
		case Pressed::R:
			playing_ = true;
            break;
		case Pressed::S:
			//playing_ = true;
			game_over_ = false;
			break;
		case Pressed::ESCAPE:
			display_->getWindow()->close();
			break;
		}	
		
}
//void GameEngine::keyReaction(Pressed key){	//take to Update, with pressed key
//	
//	switch(key){
//		case Pressed::LEFT:
//				player_->attribute()->move(Direction::LEFT);
//			break;
//		case Pressed::RIGHT:
//				player_->attribute()->move(Direction::RIGHT);
//			break;
//		case Pressed::S:
//			play_ = true;
//            break;
//		case Pressed::SPACE:
//			player_->shoot();
//			break;
//		case Pressed::ESCAPE:
//			display_->getWindow()->close();
//			break;
//			
//		}
//}

void GameEngine::drawObjects(){
	drawer_->drawField(field_);
    drawer_->drawPlayer(player_);
    drawer_->drawCentipede(centipede_);
	drawer_->drawBullets(player_);

}
void GameEngine::displayPauseMessage(){
	drawer_->drawPauseMessage();
	display_->getWindow()->display();
	display_->getWindow()->clear();
}
void GameEngine::displayGameOverMessage(){
	if(auto over = "won";player_->attribute()->isLive()){
		drawer_->drawGameOverMessage(over);
		display_->getWindow()->display();
		display_->getWindow()->clear();
	}
	else if(auto over = "lost";!player_->attribute()->isLive()){
		drawer_->drawGameOverMessage(over);
		display_->getWindow()->display();
		display_->getWindow()->clear();
	}
}
bool GameEngine::checkCollision(){
	
	auto centipede = centipede_->getCentipede();
	auto bullets = player_->getBullets();
	
	for(auto& segment:centipede){
		
		auto [segment_x_position,segment_y_position] = segment->attribute()->position()->getPosition();
	
		
			for(auto& bullet:bullets){
				
				auto [bullet_x_position,bullet_y_position] = bullet->attribute()->position()->getPosition();
				auto collision = make_shared<CollisionDetection>(bullet_x_position,bullet_y_position,Object::BULLET
																,segment_x_position,segment_y_position,Object::SEGMENT);
				auto status =  collision->collided();
				
				if(status){
					segment->attribute()->destroy();
					bullet->attribute()->destroy();
				}
			}
	}
	

	auto collision_reactor = make_shared<CollisionReaction>();
	collision_reactor->updateBullets(player_->getBullets());
	collision_reactor->updateSegments(centipede_->getCentipede(), field_->getMushrooms());
	
}

void GameEngine::checkPlayerCollision(){
		for (auto& segment:centipede_->getCentipede()){
			auto[seg_x_position,seg_y_position] = segment->attribute()->position()->getPosition();
			
			auto[player_x_position,player_y_position] = player_->attribute()->position()->getPosition();
			auto collision_detector = make_shared<CollisionDetection>(seg_x_position,seg_y_position,Object::SEGMENT
																	,player_x_position,player_y_position,Object::PLAYER); 
			auto status = collision_detector->collided();
			
			if(status){
				player_->attribute()->destroy();
				}

			}
}

void GameEngine::gameStatus(){
		if ((!player_->attribute()->isLive())||(centipede_->getCentipede().empty())){
						game_over_ = true;
						playing_ = false;
			
		}

}

void GameEngine::checkBulletMushroomCollision(){
	
	auto bullets = player_->getBullets();
	auto mushrooms = field_->getMushrooms();
		for(auto& bullet: bullets){
			auto[bullet_x,bullet_y] = bullet->attribute()->position()->getPosition();
		
			for(auto& mushroom: mushrooms){
					auto[mushroom_x,mushroom_y] = mushroom->position()->getPosition();
				
					auto collision_detector = make_shared<CollisionDetection>(bullet_x,bullet_y,Object::BULLET,
																			   mushroom_x,mushroom_y,Object::MUSHROOM);
					auto status = collision_detector->collided();
					
					if(status){
						bullet->attribute()->destroy();
						mushroom->weaken();
					}
					
			}
		}
	auto collision_reactor = make_shared<CollisionReaction>();
	collision_reactor->updateBullets(player_->getBullets());
	collision_reactor->updateMushrooms(field_->getMushrooms());				
}