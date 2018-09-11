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
#include "Constants.h"
#include "Box.h"
#include "Collision.h"
#include "CollisionReaction.h"

#include <memory>
#include <list>
using namespace std;
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
	shared_ptr<Position> position_;
    shared_ptr<Position> pos;
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
	
	bool checkCollision();
};

#endif