#include "GameEngine.h"

GameEngine::GameEngine():
			display_(make_shared<Display>())
			,position_(make_shared<Position>(Constants::DISPLAY_WIDTH/2,(Constants::DISPLAY_HEIGHT_-50)))
            ,pos(make_shared<Position>(0,0))
            ,mover(make_shared<Mover>(position_,5))
            ,mover2(make_shared<Mover>(pos,2))
			,player_(make_shared<Player>(mover))
			,centipede_(make_shared<Centipede>(mover2))
			,play_(false)
			,game_over_(false)
{
		if (display_== nullptr) throw WindowNotCreated();
}

void GameEngine::playGame(){

	splashScreen();
	
	while(display_->getWindow()->isOpen()){
			update();
			drawObjects();
			display_->getWindow()->display();
            display_->getWindow()->clear();
		}
}

void GameEngine::splashScreen(){
	SplashScreen welcome_screen(display_->getWindow());
	welcome_screen.drawSplashScreen();
}

void GameEngine::update(){

	checkInput();
    updateCentipede();
	player_->updateBullet();

}
void GameEngine::updateCentipede(){
//   centipede_->moveSegments();     
}

void GameEngine::checkInput(){
		KeyReader key_read;

		auto input = key_read.readKey(display_->getWindow());

		keyReaction(input);
}
void GameEngine::keyReaction(Pressed key){
	
	switch(key){
		case Pressed::LEFT:
				player_->attribute()->move(Direction::LEFT);
			break;
		case Pressed::RIGHT:
				player_->attribute()->move(Direction::RIGHT);
			break;
		case Pressed::S:
			play_ = true;
            break;
		case Pressed::SPACE:
			player_->shoot();
			break;
		case Pressed::ESCAPE:
			display_->getWindow()->close();
			break;
			
		}
}

void GameEngine::drawObjects(){
	
	Drawer drawer(display_->getWindow());
    drawer.drawPlayer(player_);
    drawer.drawCentipede(centipede_);
	drawer.drawBullet(player_->getBullet());
    
		
}