#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Display.h"
#include "Drawer.h"
#include "KeyReader.h"
#include "Mover.h"
#include "Player.h"
#include "Position.h"
#include "SplashScreen.h"
#include "Centipede.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;

class GameEngine{
		
public:
	GameEngine();
	void playGame();
private:
	shared_ptr<Display> display_;
	Position position_;
    Position pos;
    shared_ptr<Mover> mover;
    shared_ptr<Mover> mover2;
	shared_ptr<Player> player_;
    shared_ptr<Centipede> centipede_;
	
	bool game_over_;
	bool play_;
	
	void splashScreen();
	void update();
    void updateCentipede();
	void checkInput();
	void keyReaction(Pressed key);
	void drawObjects();
};

#endif