#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Display.h"
#include "Drawer.h"
#include "KeyReader.h"
#include "Mover.h"
#include "Player.h"
#include "Entity.h"
#include "Laser.h"
#include "Position.h"
#include "SplashScreen.h"
#include "Centipede.h"
#include "Constants.h"
#include "Box.h"
#include "CollisionDetection.h"
#include "CollisionReaction.h"
#include "Field.h"
#include "Mushroom.h"
#include "Update.h"

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
	shared_ptr<Drawer> drawer_;
	shared_ptr<Player> player_;
	shared_ptr<Centipede> centipede_;
	shared_ptr<Field> field_;
	Pressed key_;
	bool playing_;
	bool game_over_;

	
	void splashScreen();
	void update();
    void updateCentipede(shared_ptr<Field> field);
	void checkInput();
	void handleInput();
	void drawObjects();
	void displayPauseMessage();
	void displayGameOverMessage();
	bool checkCollision();
	void checkPlayerCollision();
	void gameStatus();
	void checkBulletMushroomCollision();
};

#endif